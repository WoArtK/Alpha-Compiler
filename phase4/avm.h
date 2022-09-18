#include "quads.h"
#include <stdio.h>
#include <assert.h>
#define AVM_STACKENV_SIZE 4
#define AVM_STACK_SIZE 4096

#define AVM_ENDING_PC	codeSize
#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic
unsigned char executionFinished;
unsigned pc;
unsigned currLine;
instruction* code;






unsigned top,topsp;
int N;
typedef enum {
	number_m,string_m,bool_m,table_m,
	userfunc_m,libfunc_m,nil_m,undef_m
}avm_memcell_t;




unsigned codeSize;

typedef struct avm_memcell{
	avm_memcell_t type;
	union data{
		double numVal;
		char * strVal;
		unsigned char boolVal;
		struct avm_table *tableVal;
		unsigned funcVal;
		char * libfuncVal;
	}data;
}avm_memcell;

typedef struct contents{
		avm_memcell *index;
		avm_memcell *content;
		struct contents *next;
		struct contents *previous;
}contents;

typedef struct avm_table{
	unsigned rc;
	contents *head;
}avm_table;


avm_table *insert(avm_table *table, avm_memcell *index, avm_memcell *content);
contents *get(avm_table * table, avm_memcell *index);
contents *delete_cont(avm_table *table, avm_memcell *index);
avm_memcell ax,bx,cx,retval;
avm_memcell stack[AVM_STACK_SIZE];

typedef void (*memclear_func_t)(avm_memcell*);

avm_memcell* avm_translate_operand(vmarg* arg,avm_memcell* reg);
void avm_memcellclear (avm_memcell* m);

void memclear_string (avm_memcell* m);

void memclear_table(avm_memcell* m);

typedef void(*execute_func_t)(instruction*);

#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v

void avm_warning(char * format);
void avm_tableincrefcounter(avm_table *lv);
void avm_assign(avm_memcell* iv,avm_memcell*rv);

  void execute_assign (instruction*);

  void execute_add (instruction*);
  void execute_sub (instruction*);
  void execute_mul (instruction*);
  void execute_div (instruction*);
  void execute_mod (instruction*);
//  void execute_uminus (instruction*);

//  void execute_and (instruction*);
//  void execute_or (instruction*);
//  void execute_not (instruction*);

  void execute_jeq (instruction*);
  void execute_jne (instruction*);
  void execute_jle (instruction*);
  void execute_jge (instruction*);
  void execute_jlt (instruction*);
  void execute_jgt (instruction*);
  void execute_jump (instruction*);
  void execute_call (instruction*);
  void execute_pusharg (instruction*);
  void execute_enterfunc (instruction*);
  void execute_exitfunc (instruction*);

  void execute_newtable (instruction*);
  void execute_tablegetelem (instruction*);
  void execute_tablesetelem (instruction*);

  void execute_nop (instruction*);
 
void avm_error(char* format);
char* avm_tostring (avm_memcell*);
void avm_calllibfunc(char *funcName);
void avm_callsaveenviroment(void);
 userfuncs* avm_getfuncinfo(unsigned address);
void execute_enterfunc(instruction* instr);
unsigned avm_get_envvalue(unsigned i);
void execute_funcexit(instruction* unused);
typedef void(*library_func_t)(void);
void avm_calllibfunc(char* id);
library_func_t avm_getlibraryfunc(char* id);
unsigned avm_totalactuals(void);
avm_memcell* avm_getactual(unsigned i);

void libfunc_print(void);
void *libfunc_input();


void avm_registerlibfunc(char* id,library_func_t addr);
void execute_pusharg(instruction* instr);

typedef char* (*tostring_func_t)(avm_memcell*);
 char* number_tostring(avm_memcell*);
 char* string_tostring(avm_memcell*);
 char* bool_tostring(avm_memcell*);
 char* table_tostring(avm_memcell*);
 char* userfunc_tostring(avm_memcell*);
 char* libfunc_tostring(avm_memcell*);
 char* nil_tostring(avm_memcell*);
 char* undef_tostring(avm_memcell*);
 
 typedef double(*arithmetic_func_t)(double x,double y);
double add_impl(double x,double y);
 double sub_impl(double x,double y);
 double mul_impl(double x,double y);
 double div_impl(double x,double y);
 double mod_impl(double x,double y);
 
 
 
 void execute_arithmetic(instruction* instr);
 typedef unsigned char(*tobool_func_t)(avm_memcell*);
 unsigned char number_tobool(avm_memcell* m);
 unsigned char string_tobool(avm_memcell* m);
 
 void libfunc_argument();
 unsigned char bool_tobool(avm_memcell* m);
unsigned char table_tobool(avm_memcell* m);
unsigned char userfunc_tobool(avm_memcell* m);
unsigned char libfunc_tobool(avm_memcell* m);
unsigned char nil_tobool(avm_memcell* m);
unsigned char undef_tobool(avm_memcell* m);
unsigned char avm_tobool(avm_memcell *m);
void execute_jeq(instruction* instr);
void libfunc_typeof(void);
void execute_newtable(instruction* instr);

void avm_initialize(void);
unsigned libfunc_totalarguments(void);
avm_table *avm_tablenew();
avm_memcell* avm_tablegetelem(avm_table *tableVal,avm_memcell* i);
void avm_tablesetelem(avm_table* table,avm_memcell* index,avm_memcell* content);
char* avm_tostring(avm_memcell* m);