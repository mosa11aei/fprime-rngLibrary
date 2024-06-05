module RNGTopologyConfig {
    constant RNGTopology_BASE_ID = 0xABCD

    module Defaults {
        constant QUEUE_SIZE = 10
        constant STACK_SIZE = 64 * 1024
    }

    module Priorities {
        constant RNG = 100
        constant rateGroup = 150
    }

    port RNGp (
        m_value: U32
    )
}