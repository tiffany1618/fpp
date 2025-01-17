// ======================================================================
// \title  Enum1ArrayAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Enum1 array
// ======================================================================

#include <cstdio>
#include <cstring>

#include "Enum1ArrayAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

Enum1 ::
  Enum1() :
    Serializable()
{
  // Construct using element-wise constructor
  *this = Enum1(
    M::E1::X,
    M::E1::Y
  );
}

Enum1 ::
  Enum1(const ElementType (&a)[SIZE]) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = a[index];
  }
}

Enum1 ::
  Enum1(const ElementType& e) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = e;
  }
}

Enum1 ::
  Enum1(
      const ElementType& e1,
      const ElementType& e2
  ) :
    Serializable()
{
  this->elements[0] = e1;
  this->elements[1] = e2;
}

Enum1 ::
  Enum1(const Enum1& obj) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = obj.elements[index];
  }
}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

Enum1::ElementType& Enum1 ::
  operator[](const U32 i)
{
  FW_ASSERT(i < SIZE);
  return this->elements[i];
}

const Enum1::ElementType& Enum1 ::
  operator[](const U32 i) const
{
  FW_ASSERT(i < SIZE);
  return this->elements[i];
}

Enum1& Enum1 ::
  operator=(const Enum1& obj)
{
  if (this == &obj) {
    return *this;
  }

  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = obj.elements[index];
  }
  return *this;
}

Enum1& Enum1 ::
  operator=(const ElementType (&a)[SIZE])
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = a[index];
  }
  return *this;
}

Enum1& Enum1 ::
  operator=(const ElementType& e)
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = e;
  }
  return *this;
}

bool Enum1 ::
  operator==(const Enum1& obj) const
{
  for (U32 index = 0; index < SIZE; index++) {
    if (!((*this)[index] == obj[index])) {
      return false;
    }
  }
  return true;
}

bool Enum1 ::
  operator!=(const Enum1& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const Enum1& obj) {
  Fw::String s;
  obj.toString(s);
  os << s;
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus Enum1 ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
  for (U32 index = 0; index < SIZE; index++) {
    status = buffer.serialize((*this)[index]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }
  return status;
}

Fw::SerializeStatus Enum1 ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
  for (U32 index = 0; index < SIZE; index++) {
    status = buffer.deserialize((*this)[index]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }
  return status;
}

#if FW_ARRAY_TO_STRING

void Enum1 ::
  toString(Fw::StringBase& sb) const
{
  static const char *formatString = "[ "
    "%s "
    "%s ]";

  // Declare strings to hold any serializable toString() arguments
  Fw::String str0;
  Fw::String str1;

  // Call toString for arrays and serializable types
  this->elements[0].toString(str0);
  this->elements[1].toString(str1);

  char outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_ARRAY_TO_STRING_BUFFER_SIZE,
    formatString,
    str0.toChar(),
    str1.toChar()
  );

  outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif
