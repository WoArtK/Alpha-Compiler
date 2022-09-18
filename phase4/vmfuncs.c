
#include "avm.h"
execute_func_t executeFuncs[]={
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_jump,
	execute_pusharg,
	execute_call,
	execute_enterfunc,
	execute_exitfunc,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	execute_nop	
};


memclear_func_t memclearFuncs[]={
	0, /*opcode*/
	memclear_string,
	0, /*bool*/
	memclear_table,
	0, /*userfunc*/
	0, /*livfunc*/
	0, /*nil*/
	0  /*undef*/
};

unsigned char executionFinished=0;
unsigned pc=0;
unsigned currLine=0;
instruction* code=instructions;
unsigned top=4091;

void execute_cycle(void){
	top=4091-getTotalGlobals();
	N = 4095;
	while(1){
		if(executionFinished)	return;
		else{
			if(pc==AVM_ENDING_PC){
				executionFinished=1;
				return;
			}
			else{
				assert(pc< AVM_ENDING_PC );
				instruction* instr= (code+pc);
				
				assert((instr->opcode>=0) && (instr->opcode<=AVM_MAX_INSTRUCTIONS));
				if(instr->srcLine)	currLine=instr->srcLine;
				unsigned oldPC=pc;
				(*executeFuncs[instr->opcode])(instr);
				if(pc==oldPC)	++pc;
			}
	
		}
	}
}
void avm_memcellclear (avm_memcell* m){
	if(m->type!=undef_m){
		memclear_func_t f=memclearFuncs[m->type];
		if(f){
			(*f)(m);
			m->type=undef_m;
		}
	}
	
}
void memclear_string (avm_memcell* m){
	assert(m->data.strVal);
	//free(m->data.strVal);
}

void memclear_table(avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}

