// ======================================================================
// \title  RNG.cpp
// \author Ali Mosallaei (ali.mosallaei@jpl.nasa.gov)
// \brief  cpp file for RNG component implementation class
// ======================================================================

#include "FpConfig.hpp"
#include "Fw/Logger/Logger.hpp"
#include "Os/Log.hpp"
#include "RNGLibrary/RNG/RNG.hpp"
#include "random"

namespace RNGLibrary
{

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  RNG ::
      RNG(const char *const compName) : RNGComponentBase(compName)
  {
  }

  RNG ::
      ~RNG()
  {
  }

  void RNG ::
      setInitialSeed(U32 seed)
  {
    srand(seed);
    Os::Log::logMsg("[RNG]: Seed initially set to %d\n", seed);
  }

  void RNG ::
      run_handler(
          NATIVE_INT_TYPE portNum,
          NATIVE_UINT_TYPE context)
  {
    U32 value = rand();
    this->tlmWrite_RNGValue(value);
    this->rngVal_out(0, value);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void RNG ::
      SET_RNG_SEED_cmdHandler(
          FwOpcodeType opCode,
          U32 cmdSeq,
          U32 seed)
  {
    srand(seed);
    Fw::Logger::logMsg("[RNG]: Seed set to %d\n", seed);
    this->tlmWrite_RNGSeed(seed);
  }
}
