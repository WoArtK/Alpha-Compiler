
#include <stdio.h>
#include <stdlib.h>
#include "temporaries.h"


node *func_stack[1000];
node *topFunc();
node *pushFuncStack(node *sym);
node *popFunc();

void pop_j();
int func_jcounter;

int instruction_counter;
int userfunc_counter;

void append(returnList *retList);
void backpatch(returnList *retList);



typedef struct {
	int array_stack[50][2];
	int top;
	char * name;
} s_stack;
s_stack ifstack;
s_stack loopstack;
s_stack breakstack;
s_stack continuestack;


enum iopcode{
	assign,add,sub,
	mul,div_op,mod,
	uminus,and,or,
	not,if_eq,if_noteq,
	if_lesseq,if_greatereq,if_less,
	if_greater,call,param,
	ret,getretval,funcstart,
	funcend,tablecreate,tablegetelem,tablesetelem,jump,noop
};

enum expr_t{
	var_e,
	tableitem_e,
	programfunc_e,
	libraryfunc_e,
	arithmexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,
	constnum_e,
	constbool_e,
	conststring_e,
	nil_e
};

typedef struct methodcalls{
	int method;
	char *name;
	struct expr_e *elist;
}methodcalls;

typedef struct expr_e{
	enum expr_t type;
	node * symbol;
	struct expr_e * index;
	double numConst;
	char * strConst;
	unsigned char boolConst;
	struct expr_e *next;
	methodcalls methodCalls;
	int j_label;

}expr_e;


typedef struct quad{
  enum iopcode op;
  struct expr_e* result;
  struct expr_e* arg1;
  struct expr_e* arg2;
  unsigned label;
  unsigned line;
  unsigned taddress;
  unsigned current;
}quad;
quad *quad_table;
typedef enum {
	assign_v,//5
 	add_v, //7
    sub_v, //7
	mul_v,//7
	div_v,//7 
	mod_v,//7 
	jeq_v,//7
	jne_v,
	jle_v,
	jge_v,
	jlt_v,
	jgt_v,//7
	jump_v,//3
	pusharg_v,//3
	callfunc_v,//3
	entefunc_v,//3
	exitfunc_v,//3
	newtable_v,//3
	tablegetelem_v,//7
	tablesetelem_v,//7
		nop_v
}vmopcode;

enum vmarg_t{
	label_a,
   	global_a,
   	formal_a,
   	local_a,
    number_a,
   	string_a ,
   	bool_a,
   	nil_a,
   	userfunc_a,
   	libfunc_a,
   	retval_a
};

typedef struct vmarg{
	enum vmarg_t type;
	unsigned val;
}vmarg;

typedef struct instruction{
	vmopcode opcode;
	struct vmarg result;
	struct vmarg arg1;
	struct vmarg arg2;
	unsigned srcLine;
}instruction;
int unc_jumps[50];

void push_j(int index);


typedef struct incomplete_jump{
	unsigned instrNo;
	unsigned iaddress;
	struct incomplete_jump *next;
}incomplete_jump;

void add_incomplete_jump(unsigned instrNo,unsigned iaddress);

incomplete_jump *ij_head;

typedef struct userfuncs {
	int taddress;
	int local_size;
	char *id;
}userfuncs;

double numbers[1000];
char * strings[1000];
char * libfuncs[1000];
userfuncs funcs[1000];

instruction instructions[100];

unsigned const_newnumber(double num);
unsigned const_newstring(char * s);
unsigned libfuncs_newused(char * s);
unsigned userfuncs_newfunc(node *symbol);

void make_operand(expr_e *e,vmarg* arg);
void make_numberoperand(vmarg * arg, double val);
void make_booloperand(vmarg * arg, unsigned val);
void make_retvaloperand(vmarg* arg);
void generate(vmopcode opcode,quad *q);
void generate_ADD(quad *q);
void generate_SUB(quad *q);
void generate_MUL(quad *q);
void generate_DIV(quad *q);
void generate_MOD(quad *q);
void generate_relational(vmopcode op,quad *q);
void generate_JUMP(quad *q);
void generate_IF_EQ(quad *q);
void generate_IF_NOTEQ(quad *q);
void generate_GREATER(quad *q);
void generate_GREATEREQ(quad *q);
void generate_LESS(quad *q);
void generate_LESSEQ(quad *q);
void generate_NOT(quad *q);
void generate_AND(quad *q);
void generate_FUNCEND(quad *q);
void generate_OR(quad *q);
unsigned nextinstructionlabel();
void emitInst(instruction t);
int getInstructions();
int nextquad();
int check_if_arithm(expr_e *exp1,expr_e *exp2); 
void check_if_constNum(expr_e *exp1,expr_e *exp2,expr_e *exp);
expr_e *make_call(expr_e *lvalue,expr_e *elist,int line);
void emit(enum iopcode opcode,expr_e *arg1,expr_e * arg2, expr_e* result, unsigned line);
expr_e *member_item(expr_e  *lvalue,char *name,int line);
expr_e* emit_iftableitem(expr_e *e,int line);
expr_e * newexpr(enum expr_t);
char *opcode_toString(enum iopcode opcode);
void print_quads();
void patchlabel(int index, unsigned label); 
unsigned programVarOffset;
unsigned functionLocalOffset;
unsigned formalArgOffset;
unsigned scopeSpaceCounter;
int quad_count;
enum scope_spc currscopespace();
int *offsets_table;
int push(s_stack *stack,int data);
int pop(s_stack *stack);
void set_loop(int l);
int peek(s_stack *stack);
void reset_operand(vmarg * arg);
double consts_getnumber(int index);
char *consts_getstring(int index);
char * libfuncs_getused(int index);
