// ======================================================================
// \title  Output.hpp
// \author amosalla
// \brief  hpp file for Output component implementation class
// ======================================================================

#ifndef RNGTopology_Output_HPP
#define RNGTopology_Output_HPP

#include "RNGLibrary/RNGTopology/Interface/Output/OutputComponentAc.hpp"

namespace RNGTopology {

  class Output :
    public OutputComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Output object
      Output(
          const char* const compName //!< The component name
      );

      //! Destroy Output object
      ~Output();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for RNGValue
      void RNGValue_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          U32 m_value
      ) override;

  };

}

#endif
