module RNGTopology {
    module Defaults {
        constant QUEUE_SIZE = 10
        constant STACK_SIZE = 64 * 1024
    }

    instance rng: RNGLibrary.RNG base id 0xFF2FF \
        queue size Defaults.QUEUE_SIZE \
        stack size Defaults.STACK_SIZE \
        priority 100

    instance rateGroup: Svc.ActiveRateGroup base id 0xFF4FF \
        queue size Defaults.QUEUE_SIZE \
        stack size Defaults.STACK_SIZE \
        priority 150 \
        {
            phase Fpp.ToCpp.Phases.configObjects """
                NATIVE_INT_TYPE rateGroupContext[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};
            """

            phase Fpp.ToCpp.Phases.configComponents """
            {
                RNGTopology_rateGroup.configure(ConfigObjects::RNGTopology_rateGroup::rateGroupContext, FW_NUM_ARRAY_ELEMENTS(ConfigObjects::RNGTopology_rateGroup::rateGroupContext));
                // Fw::Logger::logMsg("[RNGTopology] Rate Group configured");
            }
            """
        }

    topology RNGTopology {
        instance rng # RNG component instance
        instance rateGroup # rate group instance

        connections MyWiring {
            # we'll provide the rate group its cycle in our main deployment
            rateGroup.RateGroupMemberOut[0] -> rng.run
        }
    } # end topology
} # end MySubtopology