// ======================================================================
// \title  RNG.hpp
// \author Ali Mosallaei (ali.mosallaei@jpl.nasa.gov)
// \brief  hpp file for RNG component implementation class
// ======================================================================

#ifndef RNGLibrary_RNG_HPP
#define RNGLibrary_RNG_HPP

#include "RNGLibrary/RNG/RNGComponentAc.hpp"

namespace RNGLibrary {

  class RNG :
    public RNGComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct RNG object
      RNG(
          const char* const compName //!< The component name
      );

      //! Destroy RNG object
      ~RNG();

      void setInitialSeed(U32 seed);

    PRIVATE:

      void run_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      ) override;

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command SET_RNG_SEED
      void SET_RNG_SEED_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          U32 seed
      ) override;

  };

}

#endif
