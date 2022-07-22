// ======================================================================
// \title  E1EnumAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for E1 enum
// ======================================================================

#include <cstring>
#include <limits>

#include "Fw/Types/Assert.hpp"
#include "E1EnumAc.hpp"

namespace M {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  E1 ::
    E1()
  {
    this->e = X;
  }

  E1 ::
    E1(const T e)
  {
    this->e = e;
  }

  E1 ::
    E1(const E1& obj)
  {
    this->e = obj.e;
  }

  // ----------------------------------------------------------------------
  // Operators
  // ----------------------------------------------------------------------

  E1& E1 ::
    operator=(const E1& obj)
  {
    this->e = obj.e;
    return *this;
  }

  E1& E1 ::
    operator=(T e)
  {
    this->e = e;
    return *this;
  }

  E1 ::
    operator T() const
  {
    return this->e;
  }

  bool E1 ::
    operator==(T e) const
  {
    return this->e == e;
  }

  bool E1 ::
    operator!=(T e) const
  {
    return !(*this == e);
  }

#ifdef BUILD_UT

  std::ostream& operator<<(std::ostream& os, const E1& obj) {
    Fw::String s;
    obj.toString(s);
    os << s;
    return os;
  }

#endif

  // ----------------------------------------------------------------------
  // Member functions
  // ----------------------------------------------------------------------

  bool E1 ::
    isValid() const
  {
    return ((e >= X) && (e <= Y))
      || ((e >= Z) && (e <= Z));
  }

  Fw::SerializeStatus E1 ::
    serialize(Fw::SerializeBufferBase& buffer) const
  {
    const Fw::SerializeStatus status = buffer.serialize(
        static_cast<SerialType>(this->e)
    );
    return status;
  }

  Fw::SerializeStatus E1 ::
    deserialize(Fw::SerializeBufferBase& buffer)
  {
    SerialType es;
    Fw::SerializeStatus status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK) {
      this->e = static_cast<T>(es);
      if (!this->isValid()) {
        status = Fw::FW_DESERIALIZE_FORMAT_ERROR;
      }
    }
    return status;
  }

#if FW_SERIALIZABLE_TO_STRING || BUILD_UT

  void E1 ::
    toString(Fw::StringBase& sb) const
  {
    Fw::String s;
    switch (e) {
      case X:
        s = "X";
        break;
      case Y:
        s = "Y";
        break;
      case Z:
        s = "Z";
        break;
      default:
        s = "[invalid]";
        break;
    }
    sb.format("%s (%d)", s.toChar(), e);
  }

#endif

}
