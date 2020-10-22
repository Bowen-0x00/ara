// Copyright 2020 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

module ctrl_registers #(
    parameter int DataWidth                      = 32,
    parameter int unsigned AddrWidth             = 32,
    // Parameters
    parameter logic [DataWidth-1:0] DRAMBaseAddr = 0,
    parameter logic [DataWidth-1:0] DRAMLength   = 0,
    // AXI Structs
    parameter type axi_lite_req_t                = logic,
    parameter type axi_lite_resp_t               = logic
  ) (
    input  logic                           clk_i,
    input  logic                           rst_ni,
    // AXI Bus
    input  axi_lite_req_t                  axi_lite_slave_req_i,
    output axi_lite_resp_t                 axi_lite_slave_resp_o,
    // Control registers
    output logic           [DataWidth-1:0] exit_o,
    output logic           [DataWidth-1:0] dram_base_addr_o,
    output logic           [DataWidth-1:0] dram_end_addr_o
  );

  /*****************
   *  Definitions  *
   *****************/

  localparam int unsigned NumRegs          = 3;
  localparam int unsigned DataWidthInBytes = (DataWidth + 7) / 8;
  localparam int unsigned RegNumBytes      = NumRegs * DataWidthInBytes;

  localparam logic [DataWidthInBytes-1:0] ReadOnlyReg  = {DataWidthInBytes{1'b1}};
  localparam logic [DataWidthInBytes-1:0] ReadWriteReg = {DataWidthInBytes{1'b0}};

  // Memory map
  // [23:24]: dram_end_addr  (ro)
  // [15:8]:  dram_base_addr (ro)
  // [7:0]:   exit           (rw)
  localparam logic [NumRegs-1:0][DataWidth-1:0] RegRstVal = '{
    DRAMBaseAddr + DRAMLength,
    DRAMBaseAddr,
    0
  };
  localparam logic [0:NumRegs-1][DataWidthInBytes-1:0] AxiReadOnly = '{
    ReadOnlyReg,
    ReadOnlyReg,
    ReadWriteReg
  };

  /***************
   *  Registers  *
   ***************/

  logic [RegNumBytes-1:0] wr_active;

  logic [DataWidth-1:0] dram_base_address;
  logic [DataWidth-1:0] dram_end_address;
  logic [DataWidth-1:0] exit;

  axi_lite_regs #(
    .RegNumBytes (RegNumBytes    ),
    .AxiAddrWidth(AddrWidth      ),
    .AxiDataWidth(DataWidth      ),
    .AxiReadOnly (AxiReadOnly    ),
    .RegRstVal   (RegRstVal      ),
    .req_lite_t  (axi_lite_req_t ),
    .resp_lite_t (axi_lite_resp_t)
  ) i_axi_lite_regs (
    .clk_i      (clk_i                                      ),
    .rst_ni     (rst_ni                                     ),
    .axi_req_i  (axi_lite_slave_req_i                       ),
    .axi_resp_o (axi_lite_slave_resp_o                      ),
    .wr_active_o(wr_active                                  ),
    .rd_active_o(/* Unused */                               ),
    .reg_d_i    ('0                                         ),
    .reg_load_i ('0                                         ),
    .reg_q_o    ({dram_end_address, dram_base_address, exit})
  );

  /***************
   *   Signals   *
   ***************/

  assign dram_base_addr_o = dram_base_address                   ;
  assign dram_end_addr_o  = dram_end_address                    ;
  assign exit_o           = {exit << 1, logic'(|wr_active[7:0])};

endmodule : ctrl_registers
