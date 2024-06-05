// ======================================================================
// \title  RNGRelay.hpp
// \author amosalla
// \brief  hpp file for RNGRelay component implementation class
// ======================================================================

#ifndef RNGLibrary_RNGRelay_HPP
#define RNGLibrary_RNGRelay_HPP

#include "RNGLibrary/RNGRelay/RNGRelayComponentAc.hpp"

namespace RNGLibrary {

  class RNGRelay :
    public RNGRelayComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct RNGRelay object
      RNGRelay(
          const char* const compName //!< The component name
      );

      //! Destroy RNGRelay object
      ~RNGRelay();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for receive
      //!
      //! TODO
      void receive_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          U32 m_value
      ) override;

  };

}

#endif
