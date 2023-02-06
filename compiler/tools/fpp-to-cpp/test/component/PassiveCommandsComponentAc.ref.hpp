// ======================================================================
// \title  PassiveCommandsComponentAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for PassiveCommands component base class
// ======================================================================

#ifndef PassiveCommandsComponentAc_HPP
#define PassiveCommandsComponentAc_HPP

#include "AArrayAc.hpp"
#include "EEnumAc.hpp"
#include "FpConfig.hpp"
#include "Fw/Cmd/CmdPortAc.hpp"
#include "Fw/Cmd/CmdRegPortAc.hpp"
#include "Fw/Cmd/CmdResponsePortAc.hpp"
#include "Fw/Cmd/CmdString.hpp"
#include "Fw/Comp/ActiveComponentBase.hpp"
#include "Fw/Log/LogPortAc.hpp"
#if FW_ENABLE_TEXT_LOGGING == 1
#include "Fw/Log/LogTextPortAc.hpp"
#endif
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Port/OutputSerializePort.hpp"
#include "Fw/Prm/PrmGetPortAc.hpp"
#include "Fw/Prm/PrmSetPortAc.hpp"
#include "Fw/Time/TimePortAc.hpp"
#include "Fw/Tlm/TlmPortAc.hpp"
#include "Os/Mutex.hpp"
#include "SSerializableAc.hpp"
#include "TypedPortAc.hpp"

//! \class PassiveCommandsComponentBase
//! \brief Auto-generated base for PassiveCommands component
//! 
//! An passive component with commands
class PassiveCommandsComponentBase :
  public Fw::PassiveComponentBase
{

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    friend class PassiveCommandsComponentBaseFriend;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    //! Enumerations for numbers of special input ports
    enum {
      NUM_CMDIN_INPUT_PORTS = 1,
    };

    //! Enumerations for numbers of typed input ports
    enum {
      NUM_TYPEDSYNC_INPUT_PORTS = 3,
      NUM_TYPEDGUARDED_INPUT_PORTS = 1,
    };

    //! Enumerations for numbers of serial input ports
    enum {
      NUM_SERIALSYNC_INPUT_PORTS = 1,
      NUM_SERIALGUARDED_INPUT_PORTS = 1,
    };

    //! Enumerations for numbers of special output ports
    enum {
      NUM_CMDREGOUT_OUTPUT_PORTS = 1,
      NUM_CMDRESPONSEOUT_OUTPUT_PORTS = 1,
      NUM_EVENTOUT_OUTPUT_PORTS = 1,
      NUM_TEXTEVENTOUT_OUTPUT_PORTS = 1,
      NUM_TLMOUT_OUTPUT_PORTS = 1,
      NUM_PRMGETOUT_OUTPUT_PORTS = 1,
      NUM_PRMSETOUT_OUTPUT_PORTS = 1,
      NUM_TIMEGETOUT_OUTPUT_PORTS = 1,
    };

    //! Enumerations for numbers of typed output ports
    enum {
      NUM_TYPEDOUT_OUTPUT_PORTS = 1,
    };

    //! Enumerations for numbers of serial output ports
    enum {
      NUM_SERIALOUT_OUTPUT_PORTS = 5,
    };

    //! Command opcodes
    enum {
      OPCODE_CMD_SYNC = 0x0, //! A sync command with no params
      OPCODE_CMD_SYNC_PRIMITIVE = 0x10, //! An async command with primitive params
      OPCODE_CMD_SYNC_STRING = 0x11, //! A sync command with string params
      OPCODE_CMD_ASYNC_ENUM = 0x12, //! A sync command with enum params
      OPCODE_CMD_SYNC_ARRAY = 0x13, //! A sync command with array params
      OPCODE_CMD_SYNC_STRUCT = 0x14, //! A sync command with struct params
    };

  public:

    // ----------------------------------------------------------------------
    // Getters for special input ports
    // ----------------------------------------------------------------------

    //! Get special input port at index
    //! 
    //! \return cmdIn[portNum]
    Fw::InputCmdPort* get_cmdIn_InputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get typed input port at index
    //! 
    //! \return typedSync[portNum]
    InputTypedPort* get_typedSync_InputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get typed input port at index
    //! 
    //! \return typedGuarded[portNum]
    InputTypedPort* get_typedGuarded_InputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  public:

    // ----------------------------------------------------------------------
    // Getters for serial input ports
    // ----------------------------------------------------------------------

    //! Get serial input port at index
    //! 
    //! \return serialSync[portNum]
    Fw::InputSerializePort* get_serialSync_InputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get serial input port at index
    //! 
    //! \return serialGuarded[portNum]
    Fw::InputSerializePort* get_serialGuarded_InputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  public:

    // ----------------------------------------------------------------------
    // Connect special input ports to special output ports
    // ----------------------------------------------------------------------

    //! Connect port to cmdRegOut[portNum]
    void set_cmdRegOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputCmdRegPort* port //!< The input port
    );

    //! Connect port to cmdResponseOut[portNum]
    void set_cmdResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputCmdResponsePort* port //!< The input port
    );

    //! Connect port to eventOut[portNum]
    void set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputLogPort* port //!< The input port
    );

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Connect port to textEventOut[portNum]
    void set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputLogTextPort* port //!< The input port
    );

#endif

    //! Connect port to tlmOut[portNum]
    void set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputTlmPort* port //!< The input port
    );

    //! Connect port to prmGetOut[portNum]
    void set_prmGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputPrmGetPort* port //!< The input port
    );

    //! Connect port to prmSetOut[portNum]
    void set_prmSetOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputPrmSetPort* port //!< The input port
    );

    //! Connect port to timeGetOut[portNum]
    void set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputTimePort* port //!< The input port
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serial input ports to special output ports
    // ----------------------------------------------------------------------

    //! Connect port to cmdRegOut[portNum]
    void set_cmdRegOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to cmdResponseOut[portNum]
    void set_cmdResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to eventOut[portNum]
    void set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Connect port to textEventOut[portNum]
    void set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

#endif

    //! Connect port to tlmOut[portNum]
    void set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to prmGetOut[portNum]
    void set_prmGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to prmSetOut[portNum]
    void set_prmSetOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to timeGetOut[portNum]
    void set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to typedOut[portNum]
    void set_typedOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedPort* port //!< The input port
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serial input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to typedOut[portNum]
    void set_typedOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

#endif

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serial input ports to serial output ports
    // ----------------------------------------------------------------------

    //! Connect port to serialOut[portNum]
    void set_serialOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to serialOut[portNum]
    void set_serialOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputPortBase* port //!< The port
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Command registration
    // ----------------------------------------------------------------------

    //! \brief Register commands with the Command Dispatcher
    //! 
    //! Connect the dispatcher first
    void regCommands();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct PassiveCommandsComponentBase object
    PassiveCommandsComponentBase(
        const char* compName = "" //!< The component name
    );

    //! Initialize PassiveCommandsComponentBase object
    void init(
        NATIVE_INT_TYPE instance = 0 //!< The instance number
    );

    //! Destroy PassiveCommandsComponentBase object
    virtual ~PassiveCommandsComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of special input ports
    // ----------------------------------------------------------------------

    //! Get the number of cmdIn input ports
    //! 
    //! \return The number of cmdIn input ports
    NATIVE_INT_TYPE getNum_cmdIn_InputPorts();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of typed input ports
    // ----------------------------------------------------------------------

    //! Get the number of typedSync input ports
    //! 
    //! \return The number of typedSync input ports
    NATIVE_INT_TYPE getNum_typedSync_InputPorts();

    //! Get the number of typedGuarded input ports
    //! 
    //! \return The number of typedGuarded input ports
    NATIVE_INT_TYPE getNum_typedGuarded_InputPorts();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of serial input ports
    // ----------------------------------------------------------------------

    //! Get the number of serialSync input ports
    //! 
    //! \return The number of serialSync input ports
    NATIVE_INT_TYPE getNum_serialSync_InputPorts();

    //! Get the number of serialGuarded input ports
    //! 
    //! \return The number of serialGuarded input ports
    NATIVE_INT_TYPE getNum_serialGuarded_InputPorts();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of special output ports
    // ----------------------------------------------------------------------

    //! Get the number of cmdRegOut output ports
    //! 
    //! \return The number of cmdRegOut output ports
    NATIVE_INT_TYPE getNum_cmdRegOut_OutputPorts();

    //! Get the number of cmdResponseOut output ports
    //! 
    //! \return The number of cmdResponseOut output ports
    NATIVE_INT_TYPE getNum_cmdResponseOut_OutputPorts();

    //! Get the number of eventOut output ports
    //! 
    //! \return The number of eventOut output ports
    NATIVE_INT_TYPE getNum_eventOut_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Get the number of textEventOut output ports
    //! 
    //! \return The number of textEventOut output ports
    NATIVE_INT_TYPE getNum_textEventOut_OutputPorts();

#endif

    //! Get the number of tlmOut output ports
    //! 
    //! \return The number of tlmOut output ports
    NATIVE_INT_TYPE getNum_tlmOut_OutputPorts();

    //! Get the number of prmGetOut output ports
    //! 
    //! \return The number of prmGetOut output ports
    NATIVE_INT_TYPE getNum_prmGetOut_OutputPorts();

    //! Get the number of prmSetOut output ports
    //! 
    //! \return The number of prmSetOut output ports
    NATIVE_INT_TYPE getNum_prmSetOut_OutputPorts();

    //! Get the number of timeGetOut output ports
    //! 
    //! \return The number of timeGetOut output ports
    NATIVE_INT_TYPE getNum_timeGetOut_OutputPorts();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of typed output ports
    // ----------------------------------------------------------------------

    //! Get the number of typedOut output ports
    //! 
    //! \return The number of typedOut output ports
    NATIVE_INT_TYPE getNum_typedOut_OutputPorts();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of serial output ports
    // ----------------------------------------------------------------------

    //! Get the number of serialOut output ports
    //! 
    //! \return The number of serialOut output ports
    NATIVE_INT_TYPE getNum_serialOut_OutputPorts();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for special output ports
    // ----------------------------------------------------------------------

    //! Check whether port cmdRegOut is connected
    //! 
    //! \return Whether port cmdRegOut is connected
    bool isConnected_cmdRegOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port cmdResponseOut is connected
    //! 
    //! \return Whether port cmdResponseOut is connected
    bool isConnected_cmdResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port eventOut is connected
    //! 
    //! \return Whether port eventOut is connected
    bool isConnected_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Check whether port textEventOut is connected
    //! 
    //! \return Whether port textEventOut is connected
    bool isConnected_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

#endif

    //! Check whether port tlmOut is connected
    //! 
    //! \return Whether port tlmOut is connected
    bool isConnected_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port prmGetOut is connected
    //! 
    //! \return Whether port prmGetOut is connected
    bool isConnected_prmGetOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port prmSetOut is connected
    //! 
    //! \return Whether port prmSetOut is connected
    bool isConnected_prmSetOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port timeGetOut is connected
    //! 
    //! \return Whether port timeGetOut is connected
    bool isConnected_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for typed output ports
    // ----------------------------------------------------------------------

    //! Check whether port typedOut is connected
    //! 
    //! \return Whether port typedOut is connected
    bool isConnected_typedOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for serial output ports
    // ----------------------------------------------------------------------

    //! Check whether port serialOut is connected
    //! 
    //! \return Whether port serialOut is connected
    bool isConnected_serialOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port typedSync
    virtual void typedSync_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    ) = 0;

    //! Handler for input port typedGuarded
    virtual void typedGuarded_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports
    // 
    // Call these functions directly to bypass the corresponding ports
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port typedSync
    void typedSync_handlerBase(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler base-class function for input port typedGuarded
    void typedGuarded_handlerBase(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for serial input ports
    // ----------------------------------------------------------------------

    //! Handler for input port serialSync
    virtual void serialSync_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    ) = 0;

    //! Handler for input port serialGuarded
    virtual void serialGuarded_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for serial input ports
    // 
    // Call these functions directly to bypass the corresponding ports
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port serialSync
    void serialSync_handlerBase(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

    //! Handler base-class function for input port serialGuarded
    void serialGuarded_handlerBase(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port typedOut
    void typedOut_out(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for serial output ports
    // ----------------------------------------------------------------------

    //! Invoke output port serialOut
    Fw::SerializeStatus serialOut_out(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command response
    // ----------------------------------------------------------------------

    //! Emit command response
    void cmdResponse_out(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdResponse response //!< The command response
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command CMD_SYNC
    //! 
    //! A sync command with no params
    virtual void CMD_SYNC_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    ) = 0;

    //! Handler for command CMD_SYNC_PRIMITIVE
    //! 
    //! An async command with primitive params
    virtual void CMD_SYNC_PRIMITIVE_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b //!< A boolean
    ) = 0;

    //! Handler for command CMD_SYNC_STRING
    //! 
    //! A sync command with string params
    virtual void CMD_SYNC_STRING_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        const Fw::CmdStringArg& str1, //!< A string
        const Fw::CmdStringArg& str2 //!< Another string
    ) = 0;

    //! Handler for command CMD_ASYNC_ENUM
    //! 
    //! A sync command with enum params
    virtual void CMD_ASYNC_ENUM_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        E e //!< An enum
    ) = 0;

    //! Handler for command CMD_SYNC_ARRAY
    //! 
    //! A sync command with array params
    virtual void CMD_SYNC_ARRAY_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        A a //!< An array
    ) = 0;

    //! Handler for command CMD_SYNC_STRUCT
    //! 
    //! A sync command with struct params
    virtual void CMD_SYNC_STRUCT_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        S s //!< A struct
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions
    // 
    // Call these functions directly to bypass the command input port
    // ----------------------------------------------------------------------

    //! Base-class handler function for command CMD_SYNC
    //! 
    //! A sync command with no params
    void CMD_SYNC_cmdHandlerBase(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& args //!< The command argument buffer
    );

    //! Base-class handler function for command CMD_SYNC_PRIMITIVE
    //! 
    //! An async command with primitive params
    void CMD_SYNC_PRIMITIVE_cmdHandlerBase(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& args //!< The command argument buffer
    );

    //! Base-class handler function for command CMD_SYNC_STRING
    //! 
    //! A sync command with string params
    void CMD_SYNC_STRING_cmdHandlerBase(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& args //!< The command argument buffer
    );

    //! Base-class handler function for command CMD_ASYNC_ENUM
    //! 
    //! A sync command with enum params
    void CMD_ASYNC_ENUM_cmdHandlerBase(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& args //!< The command argument buffer
    );

    //! Base-class handler function for command CMD_SYNC_ARRAY
    //! 
    //! A sync command with array params
    void CMD_SYNC_ARRAY_cmdHandlerBase(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& args //!< The command argument buffer
    );

    //! Base-class handler function for command CMD_SYNC_STRUCT
    //! 
    //! A sync command with struct params
    void CMD_SYNC_STRUCT_cmdHandlerBase(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& args //!< The command argument buffer
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for async commands
    // 
    // Each of these functions is invoked just before processing the
    // corresponding command. By default they do nothing. You can
    // override them to provide specific pre-command behavior.
    // ----------------------------------------------------------------------

  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //!  Get the time
    //! 
    //! \return The current time
    Fw::Time getTime();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Mutex operations for guarded ports
    // 
    // You can override these operations to provide more sophisticated
    // synchronization
    // ----------------------------------------------------------------------

    //! Lock the guarded mutex
    virtual void lock();

    //! Unlock the guarded mutex
    virtual void unLock();

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on special input ports
    // ----------------------------------------------------------------------

    //! Callback for port cmdIn
    static void m_p_cmdIn_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        FwOpcodeType opCode, //!< Command Op Code
        U32 cmdSeq, //!< Command Sequence
        Fw::CmdArgBuffer& args //!< Buffer containing arguments
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port typedSync
    static void m_p_typedSync_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Callback for port typedGuarded
    static void m_p_typedGuarded_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on serial input ports
    // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

    //! Callback for port serialSync
    static void m_p_serialSync_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

    //! Callback for port serialGuarded
    static void m_p_serialGuarded_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

#endif

  PRIVATE:

    // ----------------------------------------------------------------------
    // Special input ports
    // ----------------------------------------------------------------------

    //! Input port cmdIn
    Fw::InputCmdPort m_cmdIn_InputPort[NUM_CMDIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port typedSync
    InputTypedPort m_typedSync_InputPort[NUM_TYPEDSYNC_INPUT_PORTS];

    //! Input port typedGuarded
    InputTypedPort m_typedGuarded_InputPort[NUM_TYPEDGUARDED_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Serial input ports
    // ----------------------------------------------------------------------

    //! Input port serialSync
    Fw::InputSerializePort m_serialSync_InputPort[NUM_SERIALSYNC_INPUT_PORTS];

    //! Input port serialGuarded
    Fw::InputSerializePort m_serialGuarded_InputPort[NUM_SERIALGUARDED_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Special output ports
    // ----------------------------------------------------------------------

    //! Output port cmdRegOut
    Fw::OutputCmdRegPort m_cmdRegOut_OutputPort[NUM_CMDREGOUT_OUTPUT_PORTS];

    //! Output port cmdResponseOut
    Fw::OutputCmdResponsePort m_cmdResponseOut_OutputPort[NUM_CMDRESPONSEOUT_OUTPUT_PORTS];

    //! Output port eventOut
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Output port textEventOut
    Fw::OutputLogTextPort m_textEventOut_OutputPort[NUM_TEXTEVENTOUT_OUTPUT_PORTS];

#endif

    //! Output port tlmOut
    Fw::OutputTlmPort m_tlmOut_OutputPort[NUM_TLMOUT_OUTPUT_PORTS];

    //! Output port prmGetOut
    Fw::OutputPrmGetPort m_prmGetOut_OutputPort[NUM_PRMGETOUT_OUTPUT_PORTS];

    //! Output port prmSetOut
    Fw::OutputPrmSetPort m_prmSetOut_OutputPort[NUM_PRMSETOUT_OUTPUT_PORTS];

    //! Output port timeGetOut
    Fw::OutputTimePort m_timeGetOut_OutputPort[NUM_TIMEGETOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port typedOut
    OutputTypedPort m_typedOut_OutputPort[NUM_TYPEDOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Serial output ports
    // ----------------------------------------------------------------------

    //! Output port serialOut
    Fw::OutputSerializePort m_serialOut_OutputPort[NUM_SERIALOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    Os::Mutex m_guardedPortMutex;

};

#endif
