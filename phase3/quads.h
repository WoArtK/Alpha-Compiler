#include <stdio.h>
#include <stdlib.h>
#include "temporaries.h"
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
	funcend,tablecreate,tablegetelem,tablesetelem,jump
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
}quad;
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
