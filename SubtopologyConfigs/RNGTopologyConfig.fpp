module RNGTopologyConfig {
    module Defaults {
        constant QUEUE_SIZE = 10
        constant STACK_SIZE = 64 * 1024
    }

    constant RNG_TOPOLOGY_BASE_ID = 0xABCD
    constant RNG_QUEUE_SIZE = Defaults.QUEUE_SIZE
    constant RNG_STACK_SIZE = Defaults.STACK_SIZE
    constant RNG_PRIORITY = 100
    # RNG_RG_QUEUE_SIZE
    # RNG_RG_STACK_SIZE
    # RNG_RG_PRIORITY

    instance rateGroup: Svc.ActiveRateGroup base id RNGTopologyConfig.RNG_TOPOLOGY_BASE_ID + 0x2000 \
        queue size RNGTopologyConfig.Defaults.QUEUE_SIZE \
        stack size RNGTopologyConfig.Defaults.STACK_SIZE \
        priority 150 \
        {
            phase Fpp.ToCpp.Phases.configObjects """
                NATIVE_INT_TYPE rateGroupContext[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};
            """

            phase Fpp.ToCpp.Phases.configComponents """
            {
                RNGTopologyConfig_rateGroup.configure(ConfigObjects::RNGTopologyConfig_rateGroup::rateGroupContext, FW_NUM_ARRAY_ELEMENTS(ConfigObjects::RNGTopologyConfig_rateGroup::rateGroupContext));
                // Fw::Logger::logMsg("[RNGTopology] Rate Group configured");
            }
            """
        }
    
    # topology RNGTopologyConfig{
    #     instance rateGroup
    # }
}