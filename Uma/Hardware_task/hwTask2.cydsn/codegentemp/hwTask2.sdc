# THIS FILE IS AUTOMATICALLY GENERATED
# Project: H:\Documents\301 proj\COMPSYS301\Uma\Hardware_task\hwTask2.cydsn\hwTask2.cyprj
# Date: Sat, 23 Sep 2023 04:01:15 GMT
#set_units -time ns
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {Clock_QENC} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_PWM} -source [get_pins {ClockBlock/clk_sync}] -edges {1 25 49} [list [get_pins {ClockBlock/dclk_glb_1}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for H:\Documents\301 proj\COMPSYS301\Uma\Hardware_task\hwTask2.cydsn\TopDesign\TopDesign.cysch
# Project: H:\Documents\301 proj\COMPSYS301\Uma\Hardware_task\hwTask2.cydsn\hwTask2.cyprj
# Date: Sat, 23 Sep 2023 04:00:18 GMT
