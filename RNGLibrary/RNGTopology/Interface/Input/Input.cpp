// ======================================================================
// \title  Input.cpp
// \author amosalla
// \brief  cpp file for Input component implementation class
// ======================================================================

#include "FpConfig.hpp"
#include "RNGLibrary/RNGTopology/Interface/Input/Input.hpp"

namespace RNGTopology {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Input ::
    Input(const char* const compName) :
      InputComponentBase(compName)
  {

  }

  Input ::
    ~Input()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void Input ::
    clock_in_handler(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    this->clock_out(portNum, context);
  }
}
