// ======================================================================
// lab3.v generated from TopDesign.cysch
// 07/16/2021 at 09:26
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC5LP 2
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 3
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_TMA4 4
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 5
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC6ABLE2 6
`define CYDEV_CHIP_REV_PSOC6ABLE2_ES 17
`define CYDEV_CHIP_REV_PSOC6ABLE2_PRODUCTION 33
`define CYDEV_CHIP_REV_PSOC6ABLE2_NO_UDB 33
`define CYDEV_CHIP_DIE_VOLANS 7
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 8
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 9
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 10
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 11
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 2
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 2
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 14
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 15
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 16
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 17
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 18
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 19
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 20
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 21
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 22
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 23
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 24
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 25
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 26
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 27
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 28
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 29
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 30
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 31
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 32
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 2
`define CYDEV_CHIP_REVISION_USED 0
// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Timer_v2_80(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=false, CaptureMode=0, CONTROL3=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeviceFamily=PSoC5, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, HWCaptureCounterEnabled=false, InterruptOnCapture=false, InterruptOnFIFOFull=false, InterruptOnTC=true, IntOnCapture=0, IntOnFIFOFull=0, IntOnTC=1, NumberOfCaptures=1, param45=1, Period=65535, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=rstSts, RunMode=0, SiliconRevision=0, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UsesHWEnable=0, VerilogSectionReplacementString=sT16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Timer_v2_80, CY_CONFIG_TITLE=Timer_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Timer_1, CY_INSTANCE_SHORT_NAME=Timer_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=80, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Timer_1, )
module Timer_v2_80_0 (
    reset,
    interrupt,
    enable,
    trigger,
    capture,
    capture_out,
    tc,
    clock);
    input       reset;
    output      interrupt;
    input       enable;
    input       trigger;
    input       capture;
    output      capture_out;
    output      tc;
    input       clock;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC5";
    parameter InterruptOnCapture = 0;
    parameter InterruptOnTC = 1;
    parameter Resolution = 16;
    parameter SiliconRevision = "0";

          wire  Net_261;
          wire  Net_260;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    cy_psoc3_timer_v1_0 TimerHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_266),
        .kill(Net_260),
        .clock(clock),
        .tc(Net_51),
        .compare(Net_261),
        .interrupt(Net_57));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_57;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_51;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = Net_102;



endmodule

// top
module top ;

          wire  Net_60;
          wire  Net_121;
          wire  Net_120;
          wire  Net_119;
          wire  Net_118;
          wire  Net_122;
          wire  Net_117;
          wire  Net_29;
          wire  Net_10;

	wire [0:0] tmpOE__LED_net;
	wire [0:0] tmpFB_0__LED_net;
	wire [0:0] tmpIO_0__LED_net;
	wire [0:0] tmpINTERRUPT_0__LED_net;
	electrical [0:0] tmpSIOVREF__LED_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		LED
		 (.oe(tmpOE__LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__LED_net[0:0]}),
		  .io({tmpIO_0__LED_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_net),
		  .interrupt({tmpINTERRUPT_0__LED_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_29));


	cy_clock_v1_0
		#(.id("c0fb34bd-1044-4931-9788-16b01ce89812"),
		  .source_clock_id("315365C3-2E3E-4f04-84A2-BB564A173261"),
		  .divisor(0),
		  .period("1000000000000"),
		  .is_direct(0),
		  .is_digital(1))
		timer_clock
		 (.clock_out(Net_10));


    Timer_v2_80_0 Timer_1 (
        .reset(Net_29),
        .interrupt(Net_117),
        .enable(1'b1),
        .trigger(1'b1),
        .capture(1'b0),
        .capture_out(Net_121),
        .tc(Net_60),
        .clock(Net_10));
    defparam Timer_1.CaptureCount = 2;
    defparam Timer_1.CaptureCounterEnabled = 0;
    defparam Timer_1.DeviceFamily = "PSoC5";
    defparam Timer_1.InterruptOnCapture = 0;
    defparam Timer_1.InterruptOnTC = 1;
    defparam Timer_1.Resolution = 16;
    defparam Timer_1.SiliconRevision = "0";


	cy_isr_v1_0
		#(.int_type(2'b00))
		isr_TC
		 (.int_signal(Net_117));




endmodule

