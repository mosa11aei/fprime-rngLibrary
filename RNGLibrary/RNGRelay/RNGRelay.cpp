// ======================================================================
// \title  RNGRelay.cpp
// \author amosalla
// \brief  cpp file for RNGRelay component implementation class
// ======================================================================

#include "FpConfig.hpp"
#include "RNGLibrary/RNGRelay/RNGRelay.hpp"

namespace RNGLibrary {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  RNGRelay ::
    RNGRelay(const char* const compName) :
      RNGRelayComponentBase(compName)
  {

  }

  RNGRelay ::
    ~RNGRelay()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void RNGRelay ::
    receive_handler(
        NATIVE_INT_TYPE portNum,
        U32 m_value
    )
  {
    this->log_ACTIVITY_HI_ReceivedNumber(m_value);
  }

}
