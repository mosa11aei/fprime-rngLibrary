module RNGTopology {
    instance rng: RNGLibrary.RNG base id RNGTopologyConfig.RNG_TOPOLOGY_BASE_ID + 0x1000 \
        queue size RNGTopologyConfig.Defaults.QUEUE_SIZE \
        stack size RNGTopologyConfig.Defaults.STACK_SIZE \
        priority RNGTopologyConfig.RNG_PRIORITY

    topology RNGTopology {
        instance rng # RNG component instance
        instance RNGTopologyConfig.rateGroup # rate group instance

        connections MyWiring {
            # we'll provide the rate group its cycle in our main deployment
            RNGTopologyConfig.rateGroup.RateGroupMemberOut[0] -> rng.run
        }
    } # end topology
} # end MySubtopology