#!/bin/sh

# ----------------------------------------------------------------------
# Compile ref C++ files, to check them for validity
#
# By default, each file is compiled with three different sets of values of F
# Prime guards: 
# - Default values as found in fprime/config/FpConfig.h
# - All guards turned on
# - All guards turned off (except FW_PORT_SERIALIZATION for components
#   containing serial ports)
#
# If this script is run with the --all flag, each file is compiled with all
# possible combinations of values of F Prime guards with these exceptions:
# - FW_SERIALIZABLE_TO_STRING and FW_ARRAY_TO_STRING always have the same value
# - FW_PORT_SERIALIZATION is always on for components containing serial ports
# ----------------------------------------------------------------------

fprime_gcc=../../../../../scripts/fprime-gcc
export FPRIME_GCC_FLAGS="-I../../fprime"
warning_flags="-Wno-gnu-zero-variadic-macro-arguments -Wno-unused-parameter -Wno-zero-length-array -Wno-sign-conversion -Wno-vla-extension"

# Parse command line arguments
all_flag=false
test_flag=false
for i in "$@"
do
  if [[ "$i" = "--all" ]]
  then
    all_flag=true
  elif [[ "$i" = "--test" ]]
  then
    test_flag=true
  fi
done

# Set compiler flags
include_flags="-I../../../.. -I.."
define_flags=""
if [[ "$test_flag" = true ]]
then
  include_flags="-I../../../.. -I.. -I../impl -I$FPRIME/gtest/googletest-src/googletest/include"
  define_flags="-DPROTECTED="public" -DPRIVATE="public" -DBUILD_UT=1"
fi
gcc_flags="$include_flags $define_flags $warning_flags"

# Find all guards used in generated component base class files
guards=`grep '#if FW_' *.ref.hpp *.ref.cpp | cut -f 2 -d ' ' | sort -u | sed 's/^/-D/g'`
# All guards set to 1
guards_on=`echo $guards | sed 's/ /\n/g' | sed 's/$/=1/g'`
# All guards set to 0
guards_off=`echo $guards | sed 's/ /\n/g' | sed 's/$/=0/g'`
# All guards except FW_PORT_SERIALIZATION set to 0
guards_off_serial_on=`echo $guards_off | sed 's/FW_PORT_SERIALIZATION=0/FW_PORT_SERIALIZATION=1/g'`

compile_cpp() {
  files=$*
  echo "compiling $files"

  if [ "$all_flag" = true ]
  then
    for g in `python3 ../gen_guards.py $guards`
    do
      g=`echo $g | sed 's/,/ /g'`

      if grep -q -s static_assert ${base}ComponentAc.hpp
      then
        g=`echo $g | sed 's/FW_PORT_SERIALIZATION=0/FW_PORT_SERIALIZATION=1/g'`
      fi
      echo "compiling $files with $g"
      $fprime_gcc -c $files $gcc_flags $g
     done
  else
    echo "compiling $files with default guards"
    $fprime_gcc -c $files $gcc_flags

    g=`echo $guards_on`
    echo "compiling $files with $g"
    $fprime_gcc -c $files $gcc_flags $g

    g=`echo $guards_off`
    if grep -q -s static_assert ${base}ComponentAc.hpp
    then
      g=$guards_off_serial_on
    fi
    echo "compiling $files with $g"
    $fprime_gcc -c $files $gcc_flags $g
  fi
}

# Generate framework C++ files
. ../generate_cpp.sh

# Compile type files
for fpp_type in Enum Array Serializable Port
do
  for file in `find . -name "*${fpp_type}Ac.ref.cpp"`
  do
    base=`echo $file | sed 's;.ref.cpp;;'`
    cp $base.ref.hpp $base.hpp
    cp $base.ref.cpp $base.cpp
  done
  files="$base.cpp"
  
  compile_cpp $files
done

# Compile component files
for file in `find . -name '*ComponentAc.ref.cpp'`
do
  base=`echo $file | sed 's;ComponentAc.ref.cpp;;'`
  cp ${base}ComponentAc.ref.hpp ${base}ComponentAc.hpp
  cp ${base}ComponentAc.ref.cpp ${base}ComponentAc.cpp
  files="${base}ComponentAc.cpp"

  if [[ "$test_flag" = true ]]
  then
    cp ${base}TesterBase.ref.hpp ${base}TesterBase.hpp
    cp ${base}TesterBase.ref.cpp ${base}TesterBase.cpp
    cp ${base}GTestBase.ref.hpp ${base}GTestBase.hpp
    cp ${base}GTestBase.ref.cpp ${base}GTestBase.cpp
    files="${base}ComponentAc.cpp ${base}TesterBase.cpp ${base}GTestBase.cpp"
  fi

  compile_cpp $files
done