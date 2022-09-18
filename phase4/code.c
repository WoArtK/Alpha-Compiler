avm_memcell* avm_translate_operand(vmarg* arg,avm_memcell* reg){
	
	switch(arg->type){
		
		case global_a:	return &stack[(AMV_STACKSIZE-1)-(arg->val)];
		case local_a:	return &stack[topsp-arg->val];
		case formal_a: 	return &stack[(topsp+AVM_STACKENV_SIZE+1)+arg->val];
		case retval_a:	return &retval;
		
		case number_a:{
			reg->type=number_m;
			reg->data.numVal=consts_getnumber(arg->val);
			return reg;
		}
		
		case string_a:{
			reg->type=string_m;
			reg->data.strVal=strdup(consts_getstring(arg->val));
			return reg;		
		}
		
		case bool_a:{
			reg->type=bool_m;
			reg->data.boolVal=arg->val;
			return reg;
		}
		
		case nil_a:{
			reg->type=nil_m;
			return reg;	
		}
		
		case userfunc_a:{
			reg->type=userfunc_m;
			reg->data.funcVal=arg->val;
			return reg;
		}
		
		case libfunc_a:{
			reg->type=libfunc_m;
			reg->data.libfuncVal=libfuncs_getused(arg->val);
			return reg;
		}
		default: addert(0);
	}
	
}











typedef void(*execute_func_t)(instruction*);

#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v


extern void execute_assign (instruction*);

extern void execute_add (instruction*);
extern void execute_sub (instruction*);
extern void execute_mul (instruction*);
extern void execute_div (instruction*);
extern void execute_mod (instruction*);
//extern void execute_uminus (instruction*);

//extern void execute_and (instruction*);
//extern void execute_or (instruction*);
//extern void execute_not (instruction*);

extern void execute_jeq (instruction*);
extern void execute_jne (instruction*);
extern void execute_jle (instruction*);
extern void execute_jge (instruction*);
extern void execute_jlt (instruction*);
extern void execute_jgt (instruction*);

extern void execute_call (instruction*);
extern void execute_pusharg (instruction*);
extern void execute_funcenter (instruction*);
extern void execute_funcexit (instruction*);

extern void execute_newtable (instruction*);
extern void execute_tablegetelem (instruction*);
extern void execute_tablesetelem (instruction*);

extern void execute_nop (instruction*);

/*
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
	nop_v,
	newtable_v,//3
	tablegetelem_v,//7
	tablesetelem_v,//7
}vmopcode;
*/

execute_func_t executeFuncs[]={
/*
	vlepe opcodes apo panw den exoun ta and or not
	
	execute_and,
	execute_or,
	execute_not,
	

*/

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
	execute_callfunc,
	execute_entefunc,
	execute_exitfunc,
	execute_nop,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem	
};









unsigned char executionFinished=0;
unsigned pc=0;
unsigned currLine=0;
unsigned codeSize=0;
instruction* code=(instruction*)0;
#define AVM_ENDING_PC	codeSize
void execute_cycle(void);
void execute_cycle(void){
	
	if(executionFinished)	return;
	else{
		if(pc==AVM_ENDING_PC){
			executionFinished=1;
			return;
		}
		else{
			assert(pc< AVM_ENDING_PC );
			instruction* instr= code+pc;
			assert((instr->opcode>=0) && (instr->opcode<=AVM_MAX_INSTRUCTIONS));
			if(instr->srcLine)	currLine=instr->srcLine;
			unsigned oldPC=pc;
			(*executeFuncs[instr->opcode])(instr);
			if(pc==oldPC)	++pc;
		}
	
	}
}


//	16/36

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

void avm_memcellclear (avm_memcell* m);
void avm_memcellclear (avm_memcell* m){
	if(m->type!=undef_m){
		memclear_func_t f=memclearFuncs[m->type];
		if(f)	(*f)(m);
		m->type=undef_m;
	}
}

typedef void (*memclear_func_t)(avm_memcell*);

extern void memclear_string (avm_memcell* m);
extern void memclear_string (avm_memcell* m){
	assert(m->data.strVal);
	free(m->data.strVal);
}
extern void memclear_table(avm_memcell* m);
extern void memclear_table(avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}




//	17

extern void avm_warning(char * format,......);

extern	void avm_assign(avm_memcell* iv,avm_memcell*rv);

void execute_assign(instruction* instr);
void execute_assign(instruction* instr){
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*) 0);
	avm_memcell* rv=avm_translate_operand(&instr->arg1,&ax);
	
	assert(	lv && 	(	(&stack[N-1]>=lv)	&&	(lv>&stack[top]) || (lv==&retval)	)	);
	assert( rv && 	(	(&stack[N-1]>=rv)	&&	(rv>&stack[top]) || (rv==&retval)	)	);
	
	avm_assign(lv,rv);
}




//	18
void avm_assign		(avm_memcell* lv, avm_memcell*rv);
void avm_assign		(avm_memcell* lv, avm_memcell*rv){
	if(lv==rv)	return;
	if(lv->type==table_m && rv->type==table_m && lv->data.tableVal==rv->data.tableVal)	return;
	if(rv->type ==undef_m)	avm_warning("assigning	from	'undef'	content!\n");
	avm_memcellclear(lv);
	memccpy(lv,rv,sizeof(avm_memcell));
	
	if(lv->type==string_m)	lv->data.strVal=strdup(rv->data.strVal);
	else {
		if(lv->type==table_m)	avm_tabledecrefcounter(lv->data.tableVal);
	}
}



//	19

extern void avm_error(char* format,...);
extern char* avm_tostring (avm_memcell*);
extern void avm_calllibfunc(char *funcName);
extern void avm_callsaveenviroment(void);

void execute_call(instruction* instr);
void execute_call(instruction* instr){
	avm_memcell* func=avm_translate_operand(&instr->result,&ax);
	assert(func);
	avm_callsaveenviroment();
	
	switch(func->type){
		case userfunc_m:{
			pc=func->data.funcVal;
			assert(pc<AVM_ENDING_PC);
			assert(code[pc].opcode==funcenter_v);
			break;
		}
		case string_m: avm_calllibfunc(func->data.strVal);	break;
		case libfunc_m: avm_calllibfunc(func->data.libfuncVal);	break;
		
		default:{
			char * s=avm_tostring(func);
			avm_error("call: cannot bind '%s' to function! \n",s);
			free(s);
			executionFinished=1;
		}
	}
}


//	20

unsigned	totalActuals=0;
void avm_dec_top(void);
void avm_dec_top(void){
	if(!top){
		avm_error("stack overflow\n");
		executionFinished=1;
	}
	else{
		--top;
	}
}

void avm_push_envvalue(unsigned val);
void avm_push_envvalue(unsigned val){
	stack[top].type=number_m;
	stack[top].data.numVal=val;
	avm_dec_top();
}

void avm_callsaveenviroment(void);
void avm_callsaveenviroment(void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top+totalActuals+2);
	avm_push_envvalue(topsp);
}


//21


#define AVM_NUMACTUALS_OFFSET 	+4
#define AVM_SAVEDPC_OFFSET		+3
#define AVM_SAVEDTOP_OFFSET		+2
#define AVM_SAVEDTOPSP_OFFSET	+1

extern userfunc* avm_getfuncinfo(unsigned address);

void execute_funcenter(instruction* instr);
void execute_funcenter(instruction* instr){
	avm_memcell* func=avm_translate_operand(&instr->result,&ax);
	assert(func);
	assert(pc==func->data.funcVal);
	
	totalActuals=0;
	userfunc* funcInfo=avm_getfuncinfo(pc);
	topsp=top;
	top=top-funcInfo-localSize;
	
}

unsigned avm_get_envvalue(unsigned i);
unsigned avm_get_envvalue(unsigned i){
	assert(stack[i].type=number_m);
	unsigned val=(unsigned) stack[i].data.numVal;
	assert(stack[i].data.numVal==((double) val);
	return val;
}


void execute_funcexit(instruction* unused);
void execute_funcexit(instruction* unused){
	unsigned oldTop=top;
	top=avm_get_envvalue(topsp+AVM_SAVEDTOP_OFFSET);
	pc=avm_get_envvalue(topsp+AVM_SAVEDPC_OFFSET);
	topsp=avm_get_envvalue(topsp+AVM_SAVEDTOPSP_OFFSET);

	while(++oldTop<=top)	avm_memcellclear(&stack[oldTop]);
}


//	22

typedef void(*library_func_t)(void);
library_func_t avm_getlibraryfunc(char* id);

void avm_calllibfunc(char* id);
void avm_calllibfunc(char* id){
	library_func_t f=avm_getlibraryfunc(id);
	if(!f){
		avm_error("unsupported lib func '%s' called!\n",id);
		executionFinished=1;
	}
	else{
		topsp=top;
		totalActuals=0;
		(*f)();
		if(!executionFinished)	execute_funcexit({instruction*}0);
		
	}
}

//	23

unsigned avm_totalactuals(void);
unsigned avm_totalactuals(void){
	return avm_get_envvalue(topsp+AVM_NUMACTUALS_OFFSET);
}


avm_memcell* avm_getactual(unsigned i);
avm_memcell* avm_getactual(unsigned i){
	assert (i<avm_totalactuals());
	return	$stack[topsp+AVM_STACKENV_SIZE+1+i];
	
}

void libfunc_print(void);
void libfunc_print(void){
	unsigned n=avm_totalactuals();
	for (unsigned i=0;i<n;++i){
		char* s=avm_tostring(avm_getactual(i));
		puts(s);
		free(s);
	}
}

void avm_registerlibfunc(char* id,library_func_t addr);


// 24

void execute_pusharg(instruction* instr);
void execute_pusharg(instruction* instr){
	avm_memcell*arg=avm_translate_operand(&instr->arg1,&ax);
	assert(arg);
	avm_assign(&stack[top],arg);
	++totalActuals;
	avm_dec_top();
}

typedef char* (*tostring_func_t)(avm_memcell*);
extern char* number_tostring(avm_memcell*);
extern char* string_tostring(avm_memcell*);
extern char* bool_tostring(avm_memcell*);
extern char* table_tostring(avm_memcell*);
extern char* userfunc_tostring(avm_memcell*);
extern char* libfunc_tostring(avm_memcell*);
extern char* nil_tostring(avm_memcell*);
extern char* undef_tostring(avm_memcell*);

tostirng_func_t tostringFuncs[]={
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring,	
};

char* avm_tostring(avm_memcell* m);
char* avm_tostring(avm_memcell* m){
	assert(m->type>=0 && m->type<=undef_m);
	return (*tostringFuncs[m->type])(m);
}


//25

typedef double(*arithmetic_func_t)(double x,double y);
double add_impl(double x,double y);
double add_impl(double x,double y)	{return x+y;}

double sub_impl(double x,double y);
double sub_impl(double x,double y)	{return x-y;}

double mul_impl(double x,double y);
double mul_impl(double x,double y)	{return x*y;}

double div_impl(double x,double y);
double div_impl(double x,double y)	{return x/y;}

double mod_impl(double x,double y);
double mod_impl(double x,double y)	{return (((unsigned)x) % ((unsigned)y)) ;}


arithmetic_func_t arithmeticFuncs[]={
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl	
};


void execute_arithmetic(instruction* instr);
void execute_arithmetic(instruction* instr){
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*) 0);
	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&ax);

	assert(lv && (&stack[N-1] >= lv && lv>&stack[top] || lv==&retval));
	assert(rv1 &&rv2);
	
	if(rv1->type != number_m || rv2->type !=number_m){
		avm_error("not a number in arithmetic!\n");
		executionFinished=1;
	}
	else{
		arithmetic_func_t op=arithmeticFuncs[instr->opcode-add];
		avm_memcellclear(lv);
		lv->type=number_m;
		lv->data.numVal=(*op)(rv1->data.numVal,rv2->data.numVal);
	}
}


//28

typedef unsigned char(*toboot_func_t)(avm_memcell*);

unsigned char number_tobool(avm_memcell* m);
unsigned char number_tobool(avm_memcell* m){return m->data.numVal!=0;}

unsigned char stirng_tobool(avm_memcell* m);
unsigned char stirng_tobool(avm_memcell* m){return m->data.strVal[0]!=0;}

unsigned char bool_tobool(avm_memcell* m);
unsigned char bool_tobool(avm_memcell* m){return m->data.boolVal;}

unsigned char table_tobool(avm_memcell* m);
unsigned char table_tobool(avm_memcell* m){return 1;}

unsigned char userfunc_tobool(avm_memcell* m);
unsigned char userfunc_tobool(avm_memcell* m){return 1;}

unsigned char libfunc_tobool(avm_memcell* m);
unsigned char libfunc_tobool(avm_memcell* m){return 1;}

unsigned char nil_tobool(avm_memcell* m);
unsigned char nil_tobool(avm_memcell* m){return 0;}

unsigned char undef_tobool(avm_memcell* m);
unsigned char undef_tobool(avm_memcell* m){assert(0);return 0;}


toboot_func_t toboolFuncs[]={
	number_tobool,
	stirng_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool	
};


unsigned char avm_tobool(avm_memcell *m);
unsigned char avm_tobool(avm_memcell *m){
	assert((m->type<=0) (&& m->type< undef_m));
	return (*toboolFuncs[m->type])(m);
}




//29

char* typeStrings[]={
	"number";
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"
};

void exequte_jeq(instruction* instr);
void exequte_jeq(instruction* instr){
	assert(instr->result.type==label_a);
	
	avm_memcell* rv1=avm_translate_operand(&instr-arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr-arg2,&bx);
	
	unsigned char result=0;
	
	if(rv1->type==undef_m||rv2->type==undef_m){
		avm_error("'undef' involved in equality!\n");
	}else if(rv1->type==nil_m || rv2->type==undef_m){
			result= ((rv1->type==nill_m) && (rv2->type==nill_m));
	}else if(rv1->type==bool_m || rv2->type==bool_m){
			result= (avm_tobool(rv1)==avm_tobool(rv2));
	}else if(rv1->type!=rv2->type){
		avm_error("%s == %s is illegal!\n",typeStrings[rv1->type],typeStrings[rv2->type]);
	}else{
		/*
		
			edw prepei na valoume kwdika des 29
			
		*/
	}
	if(!executionFinished&&result){
		pc=instr->result.val;
	}
	
}

//	30


void libfunc_typeof(void);
void libfunc_typeof(void){
	unsigned n=avm_totalactuals();
	if(n!=1){
		avm_error("one argument (not %d) expected in 'typeof'!\n",n);
	}
	else{
		avm_memcellclear(&retval);
		retval.type=string_m;
		retval.data.strVal=strdup(typeStrings[avm_getactual(0)->type]);
	}
}

// 31

void execute_newtable(instruction* instr);
void execute_newtable(instruction* instr){
	avm_memcell* lv=avm_translate_operand(&instr-result,(avm_memcell*)0);
	assert(lv && (&stack[N-1]>=lv && lv>&stack[top] || lv=&retval));
	
	avm_memcellclear(lv);
	
	lv->type=table_m;
	lv->data.tableVal=avm_tablenew();
	avm_tabledecrefcounter(lv->data.tableVal);
	
}


avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index);
void avm_tablesetelem(avm_table* table,avm_memcell* index,avm_memcell* content);


//32

void execute_tablegetelem(instruction* instr);
void execute_tablegetelem(instruction* instr){
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*) 0);
	avm_memcell* t=avm_translate_operand(&instr->arg1,(avm_memcell*) 0);
	avm_memcell* i=avm_translate_operand(&instr->arg2,&ax);
	
	
	assert(lv && &stack[N-1] >= lv && lv>&stack[top] || lv==&retval));
	assert(t && &stack[N-1] >= t && t>&stack[top]);
	assert(i);
	
	
	avm_memcellclear(lv);
	lv->type=nil_m;
	
	if(t->type!=table_m){
		avm_error("illegal use of type %s as table!\n",typeStrings[t->type1]);
	}
	else{
		avm_memcell* content=avm_tablegetelem(t->data.tableVal,i);
		if(content)	avm_assign(lv,content);
		else{
			char* ts-avm_tostring(t);
			char* is-avm_tostring(i);
			avm_warning("%s[%e] not found!\n",ts,is);
			free(ts);
			free(is);
		}
	}
}



//	33

void execute_tablesetelem(instruction* instr);
void execute_tablesetelem(instruction* instr){
	avm_memcell* t=avm_translate_operand(&instr->result,(avm_memcell*) 0);
	avm_memcell* i=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* c=avm_translate_operand(&instr->arg2,&bx);
	
	asser(t && &stack[N-1]>=t && t>&stack[top]);
	assert(i&&c);
	
	if(t->type !=table_m)	avm_error("Illegal use of type %s as table!\n",typeStrings[t->type]);
	else avm_tablesetelem(t>data.tableVal,i,c);
}


//35

void avm_initialize(void);
void avm_initialize(void){
	initStack();
	avm_registerlibfunc("print",libfunc_print);
	avm_registerlibfunc("typeof",libfunc_typeof);
	avm_registerlibfunc("input",libfunc_input);
	avm_registerlibfunc("objectmemberkeys",libfunc_objectmemberkeys);
	avm_registerlibfunc("objecttotalmembers",libfunc_objecttotalmembers);
	avm_registerlibfunc("objectcopy",libfunc_objectcopy);
	avm_registerlibfunc("totalarguments",libfunc_totalarguments);
	avm_registerlibfunc("strtonum",libfunc_strtonum);
	avm_registerlibfunc("sqrt",libfunc_sqrt);
	avm_registerlibfunc("cos",libfunc_cos);
	avm_registerlibfunc("sin",libfunc_sin);	
}


//36

//prosoxi thelei kai thn argument(i)

function f();
function f(){
	n=totalarguments();
}

void libfunc_totalarguments(void);
void libfunc_totalarguments(void){
	unsigned p_topsp=avm_envvalue(topsp +AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);
	
	if(lp_topsp){
		avm_error("'totalarguments' called outside a function!\n");
		retval.type=nil_m;
	}
	else{
		retval.type=number_m;
		retval.data.numVal=avm_get_envvalue(p_topsp+AVM_NUMACTUALS_OFFSET);
	}
	
}

