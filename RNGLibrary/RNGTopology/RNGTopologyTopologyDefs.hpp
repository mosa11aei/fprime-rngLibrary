#ifndef RNGTOPOLOGY_DEFS_HPP
#define RNGTOPOLOGY_DEFS_HPP

namespace RNGTopology
{
    struct RNGTopologyState {
        U32 initialSeed;
    };

    struct TopologyState {
        RNGTopologyState rng_topology_state;
    };
}

namespace Globals
{
    namespace PingEntries
    {
        namespace RNGTopology_rateGroup
        {
            enum
            {
                WARN = 3,
                FATAL = 5
            };
        }
    }
}

#endif