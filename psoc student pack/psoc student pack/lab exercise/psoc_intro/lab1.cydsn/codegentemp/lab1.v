// ======================================================================
// lab1.v generated from TopDesign.cysch
// 07/16/2021 at 09:25
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
// Component: Debouncer_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Debouncer_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Debouncer_v1_0\Debouncer_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Debouncer_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Debouncer_v1_0\Debouncer_v1_0.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// top
module top ;

          wire  Net_24;
          wire  Net_16;
          wire  Net_15;
          wire  Net_14;
          wire  Net_25;
          wire  Net_26;
          wire  Net_12;
          wire  Net_11;

	wire [0:0] tmpOE__SW1_net;
	wire [0:0] tmpIO_0__SW1_net;
	wire [0:0] tmpINTERRUPT_0__SW1_net;
	electrical [0:0] tmpSIOVREF__SW1_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
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
		  .pin_mode("I"),
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
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SW1
		 (.oe(tmpOE__SW1_net),
		  .y({1'b0}),
		  .fb({Net_11}),
		  .io({tmpIO_0__SW1_net[0:0]}),
		  .siovref(tmpSIOVREF__SW1_net),
		  .interrupt({tmpINTERRUPT_0__SW1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SW1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

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
		  .output_conn(1'b1),
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
		  .y({Net_25}),
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

    Debouncer_v1_0 Debouncer (
        .d(Net_11),
        .clock(Net_12),
        .q(Net_26),
        .neg(Net_14),
        .either(Net_15),
        .pos(Net_16));
    defparam Debouncer.EitherEdgeDetect = 0;
    defparam Debouncer.NegEdgeDetect = 1;
    defparam Debouncer.PosEdgeDetect = 0;
    defparam Debouncer.SignalWidth = 1;


	cy_clock_v1_0
		#(.id("dc145c89-f626-44a9-88d3-30a37d1b019a"),
		  .source_clock_id("315365C3-2E3E-4f04-84A2-BB564A173261"),
		  .divisor(0),
		  .period("10000000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_12));



    assign Net_25 = ~Net_26;



endmodule

