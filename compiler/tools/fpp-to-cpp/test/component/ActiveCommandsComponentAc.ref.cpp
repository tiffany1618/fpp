// ======================================================================
// \title  ActiveCommandsComponentAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveCommands component base class
// ======================================================================

#include <cstdio>

#include "ActiveCommandsComponentAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/String.hpp"

// ----------------------------------------------------------------------
// Getters for special input ports
// ----------------------------------------------------------------------

Fw::InputCmdPort* ActiveCommandsComponentBase ::
  get_cmdIn_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_cmdIn_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_cmdIn_InputPort[portNum];
}

// ----------------------------------------------------------------------
// Getters for typed input ports
// ----------------------------------------------------------------------

InputTypedPort* ActiveCommandsComponentBase ::
  get_typedSync_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_typedSync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_typedSync_InputPort[portNum];
}

InputTypedPort* ActiveCommandsComponentBase ::
  get_typedGuarded_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_typedGuarded_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_typedGuarded_InputPort[portNum];
}

InputTypedPort* ActiveCommandsComponentBase ::
  get_typedAsync_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_typedAsync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_typedAsync_InputPort[portNum];
}

// ----------------------------------------------------------------------
// Getters for serial input ports
// ----------------------------------------------------------------------

Fw::InputSerializePort* ActiveCommandsComponentBase ::
  get_serialSync_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_serialSync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_serialSync_InputPort[portNum];
}

Fw::InputSerializePort* ActiveCommandsComponentBase ::
  get_serialGuarded_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_serialGuarded_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_serialGuarded_InputPort[portNum];
}

Fw::InputSerializePort* ActiveCommandsComponentBase ::
  get_serialAsync_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_serialAsync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_serialAsync_InputPort[portNum];
}

// ----------------------------------------------------------------------
// Connect special input ports to special output ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  set_cmdRegOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputCmdRegPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_cmdRegOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_cmdRegOut_OutputPort[portNum].addCallPort(port);
}

void ActiveCommandsComponentBase ::
  set_cmdResponseOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputCmdResponsePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_cmdResponseOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_cmdResponseOut_OutputPort[portNum].addCallPort(port);
}

void ActiveCommandsComponentBase ::
  set_eventOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputLogPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_eventOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_eventOut_OutputPort[portNum].addCallPort(port);
}

#if FW_ENABLE_TEXT_LOGGING == 1

void ActiveCommandsComponentBase ::
  set_textEventOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputLogTextPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_textEventOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_textEventOut_OutputPort[portNum].addCallPort(port);
}

#endif

void ActiveCommandsComponentBase ::
  set_tlmOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputTlmPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_tlmOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_tlmOut_OutputPort[portNum].addCallPort(port);
}

void ActiveCommandsComponentBase ::
  set_prmGetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputPrmGetPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_prmGetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_prmGetOut_OutputPort[portNum].addCallPort(port);
}

void ActiveCommandsComponentBase ::
  set_prmSetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputPrmSetPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_prmSetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_prmSetOut_OutputPort[portNum].addCallPort(port);
}

void ActiveCommandsComponentBase ::
  set_timeGetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputTimePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_timeGetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_timeGetOut_OutputPort[portNum].addCallPort(port);
}

#if FW_PORT_SERIALIZATION

// ----------------------------------------------------------------------
// Connect serial input ports to special output ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  set_cmdRegOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveCommandsComponentBase ::
  set_cmdResponseOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveCommandsComponentBase ::
  set_eventOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

#if FW_ENABLE_TEXT_LOGGING == 1

void ActiveCommandsComponentBase ::
  set_textEventOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

#endif

void ActiveCommandsComponentBase ::
  set_tlmOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveCommandsComponentBase ::
  set_prmGetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveCommandsComponentBase ::
  set_prmSetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveCommandsComponentBase ::
  set_timeGetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

#endif

// ----------------------------------------------------------------------
// Connect typed input ports to typed output ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  set_typedOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      InputTypedPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_typedOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_typedOut_OutputPort[portNum].addCallPort(port);
}

#if FW_PORT_SERIALIZATION

// ----------------------------------------------------------------------
// Connect serial input ports to typed output ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  set_typedOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

#endif

#if FW_PORT_SERIALIZATION

// ----------------------------------------------------------------------
// Connect serial input ports to serial output ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  set_serialOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveCommandsComponentBase ::
  set_serialOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputPortBase* port
  )
{

}

#endif

// ----------------------------------------------------------------------
// Command registration
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  regCommands()
{

}

// ----------------------------------------------------------------------
// Component construction, initialization, and destruction
// ----------------------------------------------------------------------

ActiveCommandsComponentBase ::
  ActiveCommandsComponentBase(const char* compName) :
    Fw::ActiveComponentBase(compName)
{

}

void ActiveCommandsComponentBase ::
  init(
      NATIVE_INT_TYPE queueDepth,
      NATIVE_INT_TYPE msgSize,
      NATIVE_INT_TYPE instance
  )
{
  // Initialize base class
  Fw::ActiveComponentBase::init(instance);

  // Connect input port cmdIn
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_cmdIn_InputPorts());
    port++
  ) {
    this->m_cmdIn_InputPort[port].init();
    this->m_cmdIn_InputPort[port].addCallComp(
      this,
      m_p_cmdIn_in
    );
    this->m_cmdIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_cmdIn_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_cmdIn_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port typedSync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_typedSync_InputPorts());
    port++
  ) {
    this->m_typedSync_InputPort[port].init();
    this->m_typedSync_InputPort[port].addCallComp(
      this,
      m_p_typedSync_in
    );
    this->m_typedSync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_typedSync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_typedSync_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port typedGuarded
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_typedGuarded_InputPorts());
    port++
  ) {
    this->m_typedGuarded_InputPort[port].init();
    this->m_typedGuarded_InputPort[port].addCallComp(
      this,
      m_p_typedGuarded_in
    );
    this->m_typedGuarded_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_typedGuarded_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_typedGuarded_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port typedAsync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_typedAsync_InputPorts());
    port++
  ) {
    this->m_typedAsync_InputPort[port].init();
    this->m_typedAsync_InputPort[port].addCallComp(
      this,
      m_p_typedAsync_in
    );
    this->m_typedAsync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_typedAsync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_typedAsync_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port serialSync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_serialSync_InputPorts());
    port++
  ) {
    this->m_serialSync_InputPort[port].init();
    this->m_serialSync_InputPort[port].addCallComp(
      this,
      m_p_serialSync_in
    );
    this->m_serialSync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_serialSync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_serialSync_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port serialGuarded
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_serialGuarded_InputPorts());
    port++
  ) {
    this->m_serialGuarded_InputPort[port].init();
    this->m_serialGuarded_InputPort[port].addCallComp(
      this,
      m_p_serialGuarded_in
    );
    this->m_serialGuarded_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_serialGuarded_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_serialGuarded_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port serialAsync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_serialAsync_InputPorts());
    port++
  ) {
    this->m_serialAsync_InputPort[port].init();
    this->m_serialAsync_InputPort[port].addCallComp(
      this,
      m_p_serialAsync_in
    );
    this->m_serialAsync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_serialAsync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_serialAsync_InputPort[port].setObjName(portName);
#endif
  }

  // Connect output port cmdRegOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_cmdRegOut_OutputPorts());
    port++
  ) {
    this->m_cmdRegOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_cmdRegOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_cmdRegOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port cmdResponseOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_cmdResponseOut_OutputPorts());
    port++
  ) {
    this->m_cmdResponseOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_cmdResponseOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_cmdResponseOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port eventOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_eventOut_OutputPorts());
    port++
  ) {
    this->m_eventOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_eventOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_eventOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port textEventOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_textEventOut_OutputPorts());
    port++
  ) {
    this->m_textEventOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_textEventOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_textEventOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port tlmOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_tlmOut_OutputPorts());
    port++
  ) {
    this->m_tlmOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_tlmOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_tlmOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port prmGetOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_prmGetOut_OutputPorts());
    port++
  ) {
    this->m_prmGetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_prmGetOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_prmGetOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port prmSetOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_prmSetOut_OutputPorts());
    port++
  ) {
    this->m_prmSetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_prmSetOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_prmSetOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port timeGetOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_timeGetOut_OutputPorts());
    port++
  ) {
    this->m_timeGetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_timeGetOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_timeGetOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port typedOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_typedOut_OutputPorts());
    port++
  ) {
    this->m_typedOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_typedOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_typedOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port serialOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_serialOut_OutputPorts());
    port++
  ) {
    this->m_serialOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_serialOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_serialOut_OutputPort[port].setObjName(portName);
#endif
  }
}

ActiveCommandsComponentBase ::
  ~ActiveCommandsComponentBase()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of special input ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_cmdIn_InputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of typed input ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_typedSync_InputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_typedGuarded_InputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_typedAsync_InputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of serial input ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_serialSync_InputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_serialGuarded_InputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_serialAsync_InputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of special output ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_cmdRegOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_cmdResponseOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_eventOut_OutputPorts()
{

}

#if FW_ENABLE_TEXT_LOGGING == 1

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_textEventOut_OutputPorts()
{

}

#endif

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_tlmOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_prmGetOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_prmSetOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_timeGetOut_OutputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of typed output ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_typedOut_OutputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of serial output ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveCommandsComponentBase ::
  getNum_serialOut_OutputPorts()
{

}

// ----------------------------------------------------------------------
// Connection status queries for special output ports
// ----------------------------------------------------------------------

bool ActiveCommandsComponentBase ::
  isConnected_cmdRegOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveCommandsComponentBase ::
  isConnected_cmdResponseOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveCommandsComponentBase ::
  isConnected_eventOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

#if FW_ENABLE_TEXT_LOGGING == 1

bool ActiveCommandsComponentBase ::
  isConnected_textEventOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

#endif

bool ActiveCommandsComponentBase ::
  isConnected_tlmOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveCommandsComponentBase ::
  isConnected_prmGetOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveCommandsComponentBase ::
  isConnected_prmSetOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveCommandsComponentBase ::
  isConnected_timeGetOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

// ----------------------------------------------------------------------
// Connection status queries for typed output ports
// ----------------------------------------------------------------------

bool ActiveCommandsComponentBase ::
  isConnected_typedOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

// ----------------------------------------------------------------------
// Connection status queries for serial output ports
// ----------------------------------------------------------------------

bool ActiveCommandsComponentBase ::
  isConnected_serialOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

// ----------------------------------------------------------------------
// Handlers to implement for typed input ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  typedSync_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveCommandsComponentBase ::
  typedGuarded_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveCommandsComponentBase ::
  typedAsync_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Port handler base-class functions for typed input ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  typedSync_handlerBase(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveCommandsComponentBase ::
  typedGuarded_handlerBase(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveCommandsComponentBase ::
  typedAsync_handlerBase(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Handlers to implement for serial input ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  serialSync_handler(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveCommandsComponentBase ::
  serialGuarded_handler(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveCommandsComponentBase ::
  serialAsync_handler(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

// ----------------------------------------------------------------------
// Port handler base-class functions for serial input ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  serialSync_handlerBase(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveCommandsComponentBase ::
  serialGuarded_handlerBase(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveCommandsComponentBase ::
  serialAsync_handlerBase(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

// ----------------------------------------------------------------------
// Pre-message hooks for typed async input ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  typedAsync_preMsgHook(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Pre-message hooks for serial async input ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  serialAsync_preMsgHook(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

// ----------------------------------------------------------------------
// Invocation functions for typed output ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  typedOut_out(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Invocation functions for serial output ports
// ----------------------------------------------------------------------

Fw::SerializeStatus ActiveCommandsComponentBase ::
  serialOut_out(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

// ----------------------------------------------------------------------
// Command response
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  cmdResponse_out(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdResponse response
  )
{

}

// ----------------------------------------------------------------------
// Command handlers to implement
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  CMD_SYNC_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_SYNC_PRIMITIVE_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq,
      U32 u32,
      F32 f32,
      bool b
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_SYNC_STRING_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq,
      const Fw::CmdStringArg& str1,
      const Fw::CmdStringArg& str2
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_ASYNC_ENUM_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq,
      E e
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_SYNC_ARRAY_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq,
      A a
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_SYNC_STRUCT_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq,
      S s
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_ASYNC_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PRIORITY_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PARAMS_PRIORITY_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq,
      U32 u32
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_DROP_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PARAMS_PRIORITY_DROP_cmdHandler(
      FwOpcodeType opCode,
      U32 cmdSeq,
      U32 u32
  )
{

}

// ----------------------------------------------------------------------
// Command handler base-class functions
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  CMD_SYNC_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_SYNC_PRIMITIVE_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_SYNC_STRING_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_ASYNC_ENUM_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_SYNC_ARRAY_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_SYNC_STRUCT_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_ASYNC_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PRIORITY_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PARAMS_PRIORITY_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_DROP_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PARAMS_PRIORITY_DROP_cmdHandlerBase(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

// ----------------------------------------------------------------------
// Pre-message hooks for async commands
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  CMD_ASYNC_preMsgHook(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PRIORITY_preMsgHook(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PARAMS_PRIORITY_preMsgHook(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_DROP_preMsgHook(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

void ActiveCommandsComponentBase ::
  CMD_PARAMS_PRIORITY_DROP_preMsgHook(
      FwOpcodeType opCode,
      U32 cmdSeq
  )
{

}

// ----------------------------------------------------------------------
// Time
// ----------------------------------------------------------------------

Fw::Time ActiveCommandsComponentBase ::
  getTime()
{

}

// ----------------------------------------------------------------------
// Mutex operations for guarded ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  lock()
{

}

void ActiveCommandsComponentBase ::
  unLock()
{

}

// ----------------------------------------------------------------------
// Message dispatch functions
// ----------------------------------------------------------------------

Fw::QueuedComponentBase::MsgDispatchStatus ActiveCommandsComponentBase ::
  doDispatch()
{

}

// ----------------------------------------------------------------------
// Calls for messages received on special input ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  m_p_cmdIn_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

// ----------------------------------------------------------------------
// Calls for messages received on typed input ports
// ----------------------------------------------------------------------

void ActiveCommandsComponentBase ::
  m_p_typedSync_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveCommandsComponentBase ::
  m_p_typedGuarded_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveCommandsComponentBase ::
  m_p_typedAsync_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Calls for messages received on serial input ports
// ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

void ActiveCommandsComponentBase ::
  m_p_serialSync_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveCommandsComponentBase ::
  m_p_serialGuarded_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveCommandsComponentBase ::
  m_p_serialAsync_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

#endif

#if FW_ENABLE_TEXT_LOGGING == 1

#endif
