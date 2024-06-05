// ======================================================================
// \title  Output.cpp
// \author amosalla
// \brief  cpp file for Output component implementation class
// ======================================================================

#include "FpConfig.hpp"
#include "RNGLibrary/RNGTopology/Interface/Output/Output.hpp"

namespace RNGTopology {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Output ::
    Output(const char* const compName) :
      OutputComponentBase(compName)
  {

  }

  Output ::
    ~Output()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void Output ::
    RNGValue_handler(
        NATIVE_INT_TYPE portNum,
        U32 m_value
    )
  {
    this->RNGValue_out_out(portNum, m_value);
  }

}
