module RNGLibrary {
    @ A component that releases random numbers to the GDS. Connected to a rate group.
    active component RNG {

        # command to set RNG seed
        async command SET_RNG_SEED(seed: U32)
        
        # telemetry from the component
        telemetry DataIn: U32
        telemetry RNGSeed: U32
        telemetry Clock: U32

        sync input port data: RNGTopologyConfig.MessagePort
        output port processed: RNGTopologyConfig.MessagePort

        sync input port run: Svc.Sched

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        # async command COMMAND_NAME(param_name: U32)

        # @ Example telemetry counter
        # telemetry ExampleCounter: U64

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

    }
}