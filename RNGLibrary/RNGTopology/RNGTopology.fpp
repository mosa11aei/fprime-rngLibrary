module RNGTopology {
    instance rng: RNGLibrary.RNG base id RNGTopologyConfig.RNGTopology_BASE_ID + 0x1000 \
        queue size RNGTopologyConfig.Defaults.QUEUE_SIZE \
        stack size RNGTopologyConfig.Defaults.STACK_SIZE \
        priority RNGTopologyConfig.Priorities.RNG \
        {
            phase Fpp.ToCpp.Phases.configComponents """
            {
                RNGTopology_rng.setInitialSeed(state.RNGTopology_state.initialSeed);
            }
            """
        }

    instance rateGroup: Svc.ActiveRateGroup base id RNGTopologyConfig.RNGTopology_BASE_ID + 0x2000 \
        queue size RNGTopologyConfig.Defaults.QUEUE_SIZE \
        stack size RNGTopologyConfig.Defaults.STACK_SIZE \
        priority RNGTopologyConfig.Priorities.rateGroup \
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

    instance inputs: RNGTopology.Input base id RNGTopologyConfig.RNGTopology_BASE_ID + 0x3000
    instance outputs: RNGTopology.Output base id RNGTopologyConfig.RNGTopology_BASE_ID + 0x4000

    topology RNGTopology {
        # subtopology interface components
        instance inputs
        instance outputs

        instance rng # RNG component instance
        instance rateGroup # rate group instance

        connections Interface {
            # connect the input ports to the RNG
            inputs.clock -> rng.run
            rng.rngVal -> outputs.RNGValue
        }
    } # end topology
} # end MySubtopology