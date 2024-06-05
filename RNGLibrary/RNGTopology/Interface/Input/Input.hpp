// ======================================================================
// \title  Input.hpp
// \author amosalla
// \brief  hpp file for Input component implementation class
// ======================================================================

#ifndef RNGTopology_Input_HPP
#define RNGTopology_Input_HPP

#include "RNGLibrary/RNGTopology/Interface/Input/InputComponentAc.hpp"

namespace RNGTopology {

  class Input :
    public InputComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Input object
      Input(
          const char* const compName //!< The component name
      );

      //! Destroy Input object
      ~Input();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for clock_in
      void clock_in_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      ) override;

  };

}

#endif
