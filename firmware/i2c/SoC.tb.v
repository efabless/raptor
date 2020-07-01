`timescale 1ns/1ns
/*
	This testbench is used to test the following related components
		+ DAC
		+ DAC Vref (BG)
		+ ADC
		+ ADC MUX
		+ ADC Vref (BG)
        + i2c
        + spi
        + pwm
        + tmr
        + comp
*/

module  SoC_tb ;
	
	
	
	reg real   VDD3V3;
	//reg real   VSSA;
	//reg real   VDDA;
	reg real   VSS;

	
	wire real AN0;
	wire real AN1;
	wire real AN2;
	wire real AN3;
	wire real AN4;
	wire real AN5;
	wire real AN6;
	wire real AN7;
	wire real AN8;
	wire real AN9;
	wire real AN10;
	wire real AN11;
	wire real AN12;
	wire real AN13;
	
	


	reg real   VREFL;
	reg real   VREFH;

    reg real    XI;
	wire real   XO;

	
	wire real OUT0;
	
	//wire real OUT1;
	

	wire [31:0] DBGIO0;

	
	wire [7:0] AHB_GPIO0;
	
	// APB GPIO Ports
	

	
	output wire PWMO_0;
	
	output wire PWMO_1;
	

	tri1 i2c_da;
	tri1 i2c_cl;

	wire SPI_MSI, SPI_MSO, SPI_SSn, SPI_SCLK;

	wire TOUT0;

    // DBGIO Fields Extraction
	wire[7:0] test_id = DBGIO0[7:0];
	wire test_running = DBGIO0[16];
	wire test_passed = DBGIO0[17];

`ifdef MONITORS
	
    wire [9: 0] dac_data    = uut.dac_data_0;
	wire [9: 0] adc_data    = uut.adc_data_0;

	wire real amuxa         = uut.adc_input_0_a;
	wire real amuxb         = uut.adc_input_0_b;
	wire real amux          = uut.adc_input_0;

	wire [2:0] adc_mux_sel  = uut.adc_mux_sel_0;

`endif

    wire HRESETn            = uut.HRESETn;
	wire CLK                = uut.HCLK;

	assign AN0 = OUT0;
	assign AN1 = 0.5;
	assign AN2 = 1.0;
	assign AN3 = 1.5;
	assign AN4 = 2.0;
	assign AN5 = 1.25;
	assign AN6 = 0.75;
	assign AN7 = OUT0;
	
	assign AN8 = 1.3;
	
	assign AN9 = 1.3;
	

	wire [3:0] qspi_io;
	wire qspi_sclk;
	wire qspi_ce;
	
	raptor uut (
		.VDD3V3(VDD3V3),
		//.VDD(VDD),
		//.VSSA(VSSA),
		//.VDDA(VDDA),
		.VSS(VSS),
		
		.jtag_en(1'b0),

		.AN0(AN0),
		.AN1(AN1),
		.AN2(AN2),
		.AN3(AN3),
		.AN4(AN4),
		.AN5(AN5),
		.AN6(AN6),
		.AN7(AN7),
		.AN8(AN8),
		.AN9(AN9),
		.AN10(AN10),
		.AN11(AN11),
		.AN12(AN12),
		.AN13(AN13),

		.VREFL(VREFL),
		.VREFH(VREFH),
		.TOUT0(TOUT0),
		
		.OUT0(OUT0),
		
	//	.OUT1(OUT1),
		
		.DBGIO0(DBGIO0),
		.XI(XI),
		.qspi_io(qspi_io),
		.qspi_sclk(qspi_sclk),
		.qspi_ce(qspi_ce),
		.XO(XO),

		// GPIO
		.AHB_GPIO0(AHB_GPIO0),
		
		
		// SPI Master Interface
		.tck__APB_SPI_MSI_0(SPI_MSI),
		.APB_SPI_MSO_0(SPI_MSO),
		.APB_SPI_SSn_0(SPI_SSn),
		.APB_SPI_SCLK_0(SPI_SCLK),
		
		// I2C
		.i2c_cl_0(i2c_cl),
		.i2c_da_0(i2c_da),
		
		// PWM
		.PWMO_0(PWMO_0),
		.PWMO_1(PWMO_1),
		

		// UART
 		.tms__RsRx_0(1'b0),
 		.tdo__RsTx_0(),
 		.tdi__RsRx_1(1'b0),
 		.RsTx_1()
		 /*
		 ,

		// TAP Controller
		.tms_pad(1'b0),      // JTAG test mode select pad
		.tck_pad(1'b0),      // JTAG test clock pad
		.trstn_pad(1'b0),    // JTAG test reset pad
		.tdi_pad(1'b0)      // JTAG test data input pad
		*/
	);
	
	// Program Flash
	sst26vf064b flash(
		.SCK(qspi_sclk),
		.SIO(qspi_io),
		.CEb(qspi_ce)
	);


	// SPI Flash connected to the SPI master
	wire spi_flash_hold;
    assign spi_flash_hold = 1'b1;
    M23LC512 SPI_Slave (
        .SI_SIO0(SPI_MSO),
        .SO_SIO1(SPI_MSI),
        .SCK(SPI_SCLK),
        .CS_N(SPI_SSn),
        .SIO2(),
        .HOLD_N_SIO3(spi_flash_hold),
        .RESET(~HRESETn)
    );


	// Power up the system
	initial begin
		XI = 0.0;
		VREFH = 2.046;
		VREFL = 0.0;
		VDD3V3 = 0.0;
		// VDDA = 0.0;
		#150
		repeat (33) begin
			#3;
			VDD3V3 = VDD3V3 + 0.1;
		end	
		// VDD3V3 = 3.3;
		// VDDA = 3.3;
		VREFH = 2.046;
		VREFL = 0.0;
		//XI = VDD3V3;
	end

    // 4-MHZ XTAL
    always begin
        #125;
        if(XI == 0.0)
            XI = VDD3V3;
        else
            XI = 0.0;
    end
    
	
	//initial $monitor(OUT0);
	
	//initial $monitor(OUT1);
	

	// Stop the simulation after 5M ticks
	// The test fails if we reach this point.
	initial begin
	//	#10_000_000;          // Max simulation time is 10msec
	//	#3_000_000;          // Max simulation time is 3msec
		#1_000_000;          // Max simulation time is 1msec
		$display("Test: %0X failed - Timeout", test_id );
		$finish();
	end

	/** Load S/W **/
	initial begin
	  $readmemh("./i2c.hex", flash.I0.memory);
	end
	/** End Load S/W **/

	// exits the simulation when the test code terminates the test
	initial begin
		#100;
		@(posedge test_running);
		@(negedge test_running);
		if (test_passed) begin
			$display("Test: %0X passed", test_id );
			#100;
			$finish;
		end else begin
			$display("Test: %0X failed - Failure Code", test_id );
			#100;
			$finish;
		end
	end
	
    // ~~~~~~~~~~~~~~~
	// GPIO Loopback
    // ~~~~~~~~~~~~~~~
	
	assign  AHB_GPIO0[7:4] = AHB_GPIO0[3:0] + 7;
	
	


    // ~~~~~~~~~~~~~~~
	// PWM Verifier
    // ~~~~~~~~~~~~~~~
	reg [7:0] pwm_edge_count = 0;
	
	always @ (posedge PWMO_0)
		pwm_edge_count = pwm_edge_count + 1;
	
	always @(pwm_edge_count)
		if(pwm_edge_count==5)begin
			$display("Test: %0X passed", test_id );
			#100;
			$finish;
		end

    // ~~~~~~~~~~~~~~~
	// I2C Verifier
    // ~~~~~~~~~~~~~~~
	wire [15:0] i2c_data;

	// MCP79410 I2CSVIP(
	// 	.SCL(i2c_cl), .SDA(i2c_da),
	// 	.RESET(~HRESETn)
	// );

	i2c_slave_vip I2CSVIP(
	    .scl(i2c_cl), .sda(i2c_da),
	    .rst(~HRESETn), .clk(CLK),
		.i2c_data(i2c_data)
	);

	// Wait for 69 to be produced by the i2c master controller
	// always@(i2c_data)
	//	if(i2c_data==69) begin
	//		$display("Test: %0X passed", test_id );
	//		#100;
	//		$finish;
	//	end


    // Performance reporting
    integer st,et,tm;
    initial begin
        @(posedge test_running);
        st=$time;
        @(negedge test_running);
        et=$time;
        tm = et - st;
        if(test_id=='he0) 
            $display("Performance Test took: %0d ns (%0d cycles - %0d Cycles/iterations)",tm, tm/100, tm/50000);
    end

	`ifdef CREATE_DUMPS
		`ifndef VCD_NAME
			`define VCD_NAME "SoC.tb.vcd"
		`endif
		initial begin 
			$dumpfile(`VCD_NAME);
			$dumpvars(0, SoC_tb);
			//$dumpvars(1, SoC_tb); 
			//$dumpvars(2, uut);
			//$dumpvars(0, uut.core);
		end
	`endif

endmodule
