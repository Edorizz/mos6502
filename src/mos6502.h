#ifndef MOS6502_H
#define MOS6502_H













































#include <stdint.h>

/* MOS 6502 CPU */
typedef struct {
	/* CPU registers */
	uint8_t	       	A, X, Y;
	uint8_t		flags;
	uint8_t		sp;
	uint16_t	pc;

	/* READ/WRITE function pointers */
	uint8_t 	(*read)(uint8_t addr);
	void 		(*write)(uint8_t addr, uint8_t val);
} mos6502;

/* Data type used by 'addr_x_6502()' functions */
typedef struct {
	uint16_t	addr;
	uint8_t		*reg;
} addr_data;

/* CPU Instruction */
typedef struct {
	void		(*op)(mos6502*, addr_data*);
	void		(*addr)(mos6502*, addr_data*);
	void		(*ext)(mos6502*);
	int cycles;
} instr;

/* CPU functions */
void exec_6502(mos6502 *cpu);

/* Addressing modes */
void addr_acc_6502(mos6502 *cpu, addr_data *data);
void addr_abs_6502(mos6502 *cpu, addr_data *data);
void addr_absx_6502(mos6502 *cpu, addr_data *data);
void addr_absy_6502(mos6502 *cpu, addr_data *data);
void addr_imm_6502(mos6502 *cpu, addr_data *data);
void addr_impl_6502(mos6502 *cpu, addr_data *data);
void addr_ind_6502(mos6502 *cpu, addr_data *data);
void addr_xind_6502(mos6502 *cpu, addr_data *data);
void addr_indy_6502(mos6502 *cpu, addr_data *data);
void addr_rel_6502(mos6502 *cpu, addr_data *data);
void addr_zp_6502(mos6502 *cpu, addr_data *data);
void addr_zpx_6502(mos6502 *cpu, addr_data *data);
void addr_zpy_6502(mos6502 *cpu, addr_data *data);

/* Operations */
void adc_6502(mos6502 *cpu, addr_data *data);
void and_6502(mos6502 *cpu, addr_data *data);
void asl_6502(mos6502 *cpu, addr_data *data);
void bcc_6502(mos6502 *cpu, addr_data *data);
void bcs_6502(mos6502 *cpu, addr_data *data);
void beq_6502(mos6502 *cpu, addr_data *data);
void bit_6502(mos6502 *cpu, addr_data *data);
void bmi_6502(mos6502 *cpu, addr_data *data);
void bne_6502(mos6502 *cpu, addr_data *data);
void bpl_6502(mos6502 *cpu, addr_data *data);
void brk_6502(mos6502 *cpu, addr_data *data);
void bvc_6502(mos6502 *cpu, addr_data *data);
void bvs_6502(mos6502 *cpu, addr_data *data);
void clc_6502(mos6502 *cpu, addr_data *data);
void cld_6502(mos6502 *cpu, addr_data *data);
void cli_6502(mos6502 *cpu, addr_data *data);
void clv_6502(mos6502 *cpu, addr_data *data);
void cmp_6502(mos6502 *cpu, addr_data *data);
void cpx_6502(mos6502 *cpu, addr_data *data);
void cpy_6502(mos6502 *cpu, addr_data *data);
void dec_6502(mos6502 *cpu, addr_data *data);
void dex_6502(mos6502 *cpu, addr_data *data);
void dey_6502(mos6502 *cpu, addr_data *data);
void eor_6502(mos6502 *cpu, addr_data *data);
void inc_6502(mos6502 *cpu, addr_data *data);
void inx_6502(mos6502 *cpu, addr_data *data);
void iny_6502(mos6502 *cpu, addr_data *data);
void jmp_6502(mos6502 *cpu, addr_data *data);
void jsr_6502(mos6502 *cpu, addr_data *data);
void lda_6502(mos6502 *cpu, addr_data *data);
void ldx_6502(mos6502 *cpu, addr_data *data);
void ldy_6502(mos6502 *cpu, addr_data *data);
void lsr_6502(mos6502 *cpu, addr_data *data);
void nop_6502(mos6502 *cpu, addr_data *data);
void ora_6502(mos6502 *cpu, addr_data *data);
void pha_6502(mos6502 *cpu, addr_data *data);
void php_6502(mos6502 *cpu, addr_data *data);
void pla_6502(mos6502 *cpu, addr_data *data);
void plp_6502(mos6502 *cpu, addr_data *data);
void rol_6502(mos6502 *cpu, addr_data *data);
void ror_6502(mos6502 *cpu, addr_data *data);
void rti_6502(mos6502 *cpu, addr_data *data);
void rts_6502(mos6502 *cpu, addr_data *data);
void sbc_6502(mos6502 *cpu, addr_data *data);
void sec_6502(mos6502 *cpu, addr_data *data);
void sed_6502(mos6502 *cpu, addr_data *data);
void sei_6502(mos6502 *cpu, addr_data *data);
void sta_6502(mos6502 *cpu, addr_data *data);
void stx_6502(mos6502 *cpu, addr_data *data);
void sty_6502(mos6502 *cpu, addr_data *data);
void tax_6502(mos6502 *cpu, addr_data *data);
void tay_6502(mos6502 *cpu, addr_data *data);
void tsx_6502(mos6502 *cpu, addr_data *data);
void txa_6502(mos6502 *cpu, addr_data *data);
void txs_6502(mos6502 *cpu, addr_data *data);
void tya_6502(mos6502 *cpu, addr_data *data);
void illegal_6502(mos6502 *cpu, addr_data *data);

#endif /* MOS6502_H */

