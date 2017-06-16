/* Header file */
#include "mos6502.h"
/* C library */
#include <stdio.h>
#include <stdlib.h>

const instr instruction_set_6502[0x100] = { { brk_6502,		addr_impl_6502,	NULL,	7 },
					    { ora_6502,		addr_xind_6502, NULL,	6 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { ora_6502,		addr_zp_6502,	NULL, 	3 },
					    { asl_6502,		addr_zp_6502,	NULL, 	5 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { php_6502,		addr_impl_6502,	NULL, 	3 },
					    { ora_6502,		addr_imm_6502,	NULL, 	2 },
					    { asl_6502,		addr_acc_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { ora_6502,		addr_abs_6502,	NULL, 	4 },
					    { asl_6502,		addr_abs_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { bpl_6502,		addr_rel_6502,	NULL,	2 },
					    { ora_6502,		addr_indy_6502, NULL,	5 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { ora_6502,		addr_zpx_6502,	NULL, 	4 },
					    { asl_6502,		addr_zpx_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { clc_6502,		addr_impl_6502,	NULL, 	2 },
					    { ora_6502,		addr_absy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { ora_6502,		addr_absx_6502,	NULL, 	4 },
					    { asl_6502,		addr_absx_6502,	NULL, 	7 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { jsr_6502,		addr_abs_6502,	NULL,	6 },
					    { and_6502,		addr_xind_6502, NULL,	6 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { bit_6502,		addr_zp_6502,	NULL, 	3 },
					    { and_6502,		addr_zp_6502,	NULL, 	3 },
					    { rol_6502,		addr_zp_6502,	NULL, 	5 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { plp_6502,		addr_impl_6502,	NULL, 	4 },
					    { and_6502,		addr_imm_6502,	NULL, 	2 },
					    { rol_6502,		addr_acc_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { bit_6502,		addr_abs_6502,	NULL, 	4 },
					    { and_6502,		addr_abs_6502,	NULL, 	4 },
					    { rol_6502,		addr_abs_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { bmi_6502,		addr_rel_6502,	NULL,	2 },
					    { and_6502,		addr_indy_6502, NULL,	5 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { and_6502,		addr_zpx_6502,	NULL, 	4 },
					    { rol_6502,		addr_zpx_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { sec_6502,		addr_impl_6502,	NULL, 	2 },
					    { and_6502,		addr_absy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { and_6502,		addr_abs_6502,	NULL, 	3 },
					    { rol_6502,		addr_abs_6502,	NULL, 	7 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { rti_6502,		addr_impl_6502,	NULL,	6 },
					    { eor_6502,		addr_xind_6502, NULL,	6 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { eor_6502,		addr_zp_6502,	NULL, 	3 },
					    { lsr_6502,		addr_zp_6502,	NULL, 	5 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { pha_6502,		addr_impl_6502,	NULL, 	3 },
					    { eor_6502,		addr_imm_6502,	NULL, 	2 },
					    { lsr_6502,		addr_acc_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { jmp_6502,		addr_abs_6502,	NULL, 	3 },
					    { eor_6502,		addr_abs_6502,	NULL, 	4 },
					    { lsr_6502,		addr_abs_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { bvc_6502,		addr_rel_6502,	NULL,	2 },
					    { eor_6502,		addr_indy_6502, NULL,	5 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { eor_6502,		addr_zpx_6502,	NULL, 	4 },
					    { lsr_6502,		addr_zpx_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { cli_6502,		addr_impl_6502,	NULL, 	2 },
					    { eor_6502,		addr_absy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { eor_6502,		addr_absx_6502,	NULL, 	4 },
					    { lsr_6502,		addr_absx_6502,	NULL, 	7 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { rts_6502,		addr_abs_6502,	NULL,	6 },
					    { adc_6502,		addr_xind_6502, NULL,	6 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_zp_6502,	NULL, 	0 },
					    { adc_6502,		addr_zp_6502,	NULL, 	3 },
					    { ror_6502,		addr_zp_6502,	NULL, 	5 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { pla_6502,		addr_impl_6502,	NULL, 	4 },
					    { adc_6502,		addr_imm_6502,	NULL, 	2 },
					    { ror_6502,		addr_acc_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { jmp_6502,		addr_abs_6502,	NULL, 	5 },
					    { adc_6502,		addr_abs_6502,	NULL, 	4 },
					    { ror_6502,		addr_abs_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { bvs_6502,		addr_rel_6502,	NULL,	2 },
					    { adc_6502,		addr_indy_6502, NULL,	5 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { adc_6502,		addr_zpx_6502,	NULL, 	4 },
					    { ror_6502,		addr_zpx_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { sei_6502,		addr_impl_6502,	NULL, 	2 },
					    { adc_6502,		addr_absy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { adc_6502,		addr_absx_6502,	NULL, 	4 },
					    { ror_6502,		addr_absx_6502,	NULL, 	7 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { illegal_6502,	addr_impl_6502,	NULL,	0 },
					    { sta_6502,		addr_xind_6502, NULL,	6 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { sty_6502,		addr_zp_6502,	NULL, 	3 },
					    { sta_6502,		addr_zp_6502,	NULL, 	3 },
					    { stx_6502,		addr_zp_6502,	NULL, 	3 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { dey_6502,		addr_impl_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { txa_6502,		addr_impl_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { sty_6502,		addr_abs_6502,	NULL, 	4 },
					    { sta_6502,		addr_abs_6502,	NULL, 	4 },
					    { stx_6502,		addr_abs_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { bcc_6502,		addr_rel_6502,	NULL,	2 },
					    { sta_6502,		addr_indy_6502, NULL,	6 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { sty_6502,		addr_zpx_6502,	NULL, 	4 },
					    { sta_6502,		addr_zpx_6502,	NULL, 	4 },
					    { stx_6502,		addr_zpy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { tya_6502,		addr_impl_6502,	NULL, 	2 },
					    { sta_6502,		addr_absy_6502,	NULL, 	5 },
					    { txs_6502,		addr_impl_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { sta_6502,		addr_abs_6502,	NULL, 	5 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { ldy_6502,		addr_imm_6502,	NULL,	2 },
					    { lda_6502,		addr_xind_6502, NULL,	6 },
					    { ldx_6502,		addr_imm_6502, NULL, 	2 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { ldy_6502,		addr_zp_6502,	NULL, 	3 },
					    { lda_6502,		addr_zp_6502,	NULL, 	3 },
					    { ldx_6502,		addr_zp_6502,	NULL, 	3 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { tay_6502,		addr_impl_6502,	NULL, 	2 },
					    { lda_6502,		addr_imm_6502,	NULL, 	2 },
					    { tax_6502,		addr_impl_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { ldy_6502,		addr_abs_6502,	NULL, 	4 },
					    { lda_6502,		addr_abs_6502,	NULL, 	4 },
					    { ldx_6502,		addr_abs_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { bcs_6502,		addr_rel_6502,	NULL,	2 },
					    { lda_6502,		addr_indy_6502, NULL,	5 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { ldy_6502,		addr_zpx_6502,	NULL, 	4 },
					    { lda_6502,		addr_zpx_6502,	NULL, 	4 },
					    { ldx_6502,		addr_zpy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { clv_6502,		addr_impl_6502,	NULL, 	2 },
					    { lda_6502,		addr_absy_6502,	NULL, 	4 },
					    { tsx_6502,		addr_impl_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { ldy_6502,		addr_absx_6502,	NULL, 	4 },
					    { lda_6502,		addr_absx_6502,	NULL, 	4 },
					    { ldx_6502,		addr_absy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { cpy_6502,		addr_imm_6502,	NULL,	2 },
					    { cmp_6502,		addr_xind_6502, NULL,	6 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { cpy_6502,		addr_zp_6502,	NULL, 	3 },
					    { cmp_6502,		addr_zp_6502,	NULL, 	3 },
					    { dec_6502,		addr_zp_6502,	NULL, 	5 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { iny_6502,		addr_impl_6502,	NULL, 	2 },
					    { cmp_6502,		addr_imm_6502,	NULL, 	2 },
					    { dex_6502,		addr_impl_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { cpy_6502,		addr_abs_6502,	NULL, 	4 },
					    { cmp_6502,		addr_abs_6502,	NULL, 	4 },
					    { dec_6502,		addr_abs_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { bne_6502,		addr_rel_6502,	NULL,	2 },
					    { cmp_6502,		addr_indy_6502, NULL,	5 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { cmp_6502,		addr_zpx_6502,	NULL, 	4 },
					    { dec_6502,		addr_zpx_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { cld_6502,		addr_impl_6502,	NULL, 	2 },
					    { cmp_6502,		addr_absy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { cmp_6502,		addr_absx_6502,	NULL, 	4 },
					    { dec_6502,		addr_absx_6502,	NULL, 	7 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { cpx_6502,		addr_imm_6502,	NULL,	2 },
					    { sbc_6502,		addr_xind_6502, NULL,	6 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { cpx_6502,		addr_zp_6502,	NULL, 	3 },
					    { sbc_6502,		addr_zp_6502,	NULL, 	3 },
					    { inc_6502,		addr_zp_6502,	NULL, 	5 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { inx_6502,		addr_impl_6502,	NULL, 	2 },
					    { sbc_6502,		addr_imm_6502,	NULL, 	2 },
					    { nop_6502,		addr_impl_6502,	NULL, 	2 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { cpx_6502,		addr_abs_6502,	NULL, 	4 },
					    { sbc_6502,		addr_abs_6502,	NULL, 	4 },
					    { inc_6502,		addr_abs_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    
					    { beq_6502,		addr_rel_6502,	NULL,	2 },
					    { sbc_6502,		addr_indy_6502, NULL,	5 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502, NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { sbc_6502,		addr_zpx_6502,	NULL, 	4 },
					    { inc_6502,		addr_zpx_6502,	NULL, 	6 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { sed_6502,		addr_impl_6502,	NULL, 	2 },
					    { sbc_6502,		addr_absy_6502,	NULL, 	4 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 },
					    { sbc_6502,		addr_absx_6502,	NULL, 	4 },
					    { inc_6502,		addr_absx_6502,	NULL, 	7 },
					    { illegal_6502,	addr_impl_6502,	NULL, 	0 } };
					    
void
exec6502(mos6502 *cpu)
{

}

/* Addressing modes */
void
addr_acc_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = &cpu->A;
}

void
addr_abs_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = (cpu->read(cpu->pc) << 8) | cpu->read(cpu->pc);
	cpu->pc += 2;
}

void
addr_absx_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = ((cpu->read(cpu->pc) << 8) | cpu->read(cpu->pc)) + cpu->X;
	cpu->pc += 2;
}

void
addr_absy_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = ((cpu->read(cpu->pc) << 8) | cpu->read(cpu->pc)) + cpu->Y;
	cpu->pc += 2;
}

void
addr_imm_6502(mos6502 *cpu, addr_data *data)
{
	/*
	 * Fake pointer, used as a signal which specifies that the value in 'data->addr'
	 * is not a memory address
	 */
	data->reg = &cpu->A;

	data->addr = cpu->read(cpu->pc) << 8;
	++cpu->pc;
}

void
addr_impl_6502(mos6502 *cpu, addr_data *data)
{
	/* Nothing to do here */
}

void
addr_ind_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = (cpu->read(cpu->pc) << 8) | cpu->read(cpu->pc);
	data->addr = cpu->read(data->addr);
	cpu->pc += 2;
}

void
addr_xind_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = cpu->read(cpu->pc) + cpu->X;
	data->addr = cpu->read(data->addr);
	++cpu->pc;
}

void
addr_indy_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = cpu->read(cpu->pc);
	data->addr = cpu->read(data->addr) + cpu->Y;
	cpu->pc += 2;
}

/*
 * "branch target is PC + offset (BB), bit 7 signifies negative offset"
 * Does that mean two's complement?
 */
void
addr_rel_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = cpu->read(cpu->pc);
}

void
addr_zp_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = cpu->read(cpu->pc);
}

void
addr_zpx_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = cpu->read(cpu->pc) + cpu->X;
}

void
addr_zpy_6502(mos6502 *cpu, addr_data *data)
{
	data->reg = NULL;

	data->addr = cpu->read(cpu->pc) + cpu->Y;
}


/* Operations */
void
adc_6502(mos6502 *cpu, addr_data *data)
{
}

void
and_6502(mos6502 *cpu, addr_data *data)
{
}

void
asl_6502(mos6502 *cpu, addr_data *data)
{
}

void
bcc_6502(mos6502 *cpu, addr_data *data)
{
}

void
bcs_6502(mos6502 *cpu, addr_data *data)
{
}

void
beq_6502(mos6502 *cpu, addr_data *data)
{
}

void
bit_6502(mos6502 *cpu, addr_data *data)
{
}

void
bmi_6502(mos6502 *cpu, addr_data *data)
{
}

void
bne_6502(mos6502 *cpu, addr_data *data)
{
}

void
bpl_6502(mos6502 *cpu, addr_data *data)
{
}

void
brk_6502(mos6502 *cpu, addr_data *data)
{
}

void
bvc_6502(mos6502 *cpu, addr_data *data)
{
}

void
bvs_6502(mos6502 *cpu, addr_data *data)
{
}

void
clc_6502(mos6502 *cpu, addr_data *data)
{
}

void
cld_6502(mos6502 *cpu, addr_data *data)
{
}

void
cli_6502(mos6502 *cpu, addr_data *data)
{
}

void
clv_6502(mos6502 *cpu, addr_data *data)
{
}

void
cmp_6502(mos6502 *cpu, addr_data *data)
{
}

void
cpx_6502(mos6502 *cpu, addr_data *data)
{
}

void
cpy_6502(mos6502 *cpu, addr_data *data)
{
}

void
dec_6502(mos6502 *cpu, addr_data *data)
{
}

void
dex_6502(mos6502 *cpu, addr_data *data)
{
}

void
dey_6502(mos6502 *cpu, addr_data *data)
{
}

void
eor_6502(mos6502 *cpu, addr_data *data)
{
}

void
inc_6502(mos6502 *cpu, addr_data *data)
{
}

void
inx_6502(mos6502 *cpu, addr_data *data)
{
}

void
iny_6502(mos6502 *cpu, addr_data *data)
{
}

void
jmp_6502(mos6502 *cpu, addr_data *data)
{
}

void
jsr_6502(mos6502 *cpu, addr_data *data)
{
}

void
lda_6502(mos6502 *cpu, addr_data *data)
{
}

void
ldx_6502(mos6502 *cpu, addr_data *data)
{
}

void
ldy_6502(mos6502 *cpu, addr_data *data)
{
}

void
lsr_6502(mos6502 *cpu, addr_data *data)
{
}

void
nop_6502(mos6502 *cpu, addr_data *data)
{
}

void
ora_6502(mos6502 *cpu, addr_data *data)
{
}

void
pha_6502(mos6502 *cpu, addr_data *data)
{
}

void
php_6502(mos6502 *cpu, addr_data *data)
{
}

void
pla_6502(mos6502 *cpu, addr_data *data)
{
}

void
plp_6502(mos6502 *cpu, addr_data *data)
{
}

void
rol_6502(mos6502 *cpu, addr_data *data)
{
}

void
ror_6502(mos6502 *cpu, addr_data *data)
{
}

void
rti_6502(mos6502 *cpu, addr_data *data)
{
}

void
rts_6502(mos6502 *cpu, addr_data *data)
{
}

void
sbc_6502(mos6502 *cpu, addr_data *data)
{
}

void
sec_6502(mos6502 *cpu, addr_data *data)
{
}

void
sed_6502(mos6502 *cpu, addr_data *data)
{
}

void
sei_6502(mos6502 *cpu, addr_data *data)
{
}

void
sta_6502(mos6502 *cpu, addr_data *data)
{
}

void
stx_6502(mos6502 *cpu, addr_data *data)
{
}

void
sty_6502(mos6502 *cpu, addr_data *data)
{
}

void
tax_6502(mos6502 *cpu, addr_data *data)
{
}

void
tay_6502(mos6502 *cpu, addr_data *data)
{
}

void
tsx_6502(mos6502 *cpu, addr_data *data)
{
}

void
txa_6502(mos6502 *cpu, addr_data *data)
{
}

void
txs_6502(mos6502 *cpu, addr_data *data)
{
}

void
tya_6502(mos6502 *cpu, addr_data *data)
{
}

void
illegal_6502(mos6502 *cpu, addr_data *data)
{
}

