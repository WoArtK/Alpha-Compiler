#include "quads.h"
#include <string.h>

#include <assert.h>



int num_counter=0;
int instruction_counter=0;
int str_counter = 0;
int libfunc_counter = 0;
int userfunc_counter = 0;



void append(returnList *retList){
	printf("append\n");
	returnList *tmp;
	returnList *nd=malloc(sizeof(returnList));
	nd->index=nextinstructionlabel()-1;
	if(retList->head==NULL){
		retList->head=nd;
	}else{
		tmp=retList->head;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=nd;
	}
	printf("append out\n");
}


void backpatch(returnList *retList){

	returnList *tmp=retList->head;
		
		while(tmp!=NULL){
			instructions[tmp->index].result.val=nextinstructionlabel();
				printf("backpatch index %d : \n",tmp->index);
			tmp=tmp->next;
		}
	
	
}

int getInstructions(){
	return instruction_counter;
}
unsigned nextinstructionlabel(){
	return instruction_counter+1;
}
unsigned const_newnumber(double num){
	numbers[num_counter]=num;
	num_counter++;
	return (num_counter-1);
}

unsigned const_newstring(char * s){
	strings[str_counter] = strdup(s);
	str_counter++;
	return (str_counter-1);
}

unsigned libfuncs_newused(char * s){
	libfuncs[libfunc_counter] = strdup(s);
	libfunc_counter++;
	return (libfunc_counter - 1);
}

unsigned userfuncs_newfunc(node *symbol){
	funcs[userfunc_counter].taddress = symbol->taddress;
	funcs[userfunc_counter].local_size = symbol->locals_count;
	funcs[userfunc_counter].id = strdup(symbol->name);
	userfunc_counter++;
	return (userfunc_counter - 1);
}

void make_operand(expr_e *e,vmarg* arg){
	
	switch (e->type){
		case var_e:
		case tableitem_e:
		case arithmexpr_e:
		case boolexpr_e:
		case assignexpr_e:
		case newtable_e:{
			
			if(e->symbol!=NULL){
				arg->val=e->symbol->offset;
			switch (e->symbol->scope_space){
				case program_var:arg->type=global_a;
					break;
				case function_local:arg->type=local_a;
					break;
				case formal_arg:arg->type=formal_a;
					break;
				default:assert(0);
			}
			break;
		}
		}
		
		case constbool_e: {
			arg->val = e->boolConst;
			arg->type = bool_a;
			break;
		}
		
		case constnum_e: {
			arg->val=const_newnumber(e->numConst);
			arg->type=number_a;
			break;
		}
		
		case conststring_e: {
			arg->val = const_newstring(e->strConst);
			arg->type = string_a;
			break;
		}
		
		case nil_e:{
		 arg->type = nil_a; 
		 break;	
		}
		
		case programfunc_e: {
			arg->type = userfunc_a;
			arg->val = e->symbol->taddress;
			break;
		}
		
		case libraryfunc_e: {
			printf("EIMAI EDW PERA\n");
			arg->type = libfunc_a;
			arg->val = libfuncs_newused(e->symbol->name);
			break;
		}
		
		default: assert(0);
	}
}

void make_numberoperand(vmarg * arg, double val){
	arg->val = const_newnumber(val);
	arg->type = number_a;
}

void make_booloperand(vmarg * arg, unsigned val){
	arg->val = val;
	arg->type = bool_a;
}

void make_retvaloperand(vmarg* arg){
	arg->type = retval_a;
}

void emitInst(instruction t){
	
	instructions[instruction_counter]=t;
	instructions[instruction_counter].srcLine=instruction_counter;
	if(t.opcode!=nop_v){
	instruction_counter++;
	}
}

void generate(vmopcode opcode,quad *q){
	instruction t;
	t.opcode=opcode;
	
	if(q->arg1 != NULL) {
		printf("before arg1\n");
		make_operand(q->arg1,&t.arg1);
		printf("prin arg2\n");
	}else{
		printf("ar1\n");
		
		reset_operand(&t.arg1);
	}
	if(q->arg2 != NULL){
		printf("einai type %d  \n",q->arg2->type);
		make_operand(q->arg2,&t.arg2);
		printf("prin result\n");
	}else{
			printf("ar2\n");
		reset_operand(&t.arg2);
	}
	if(q->result != NULL){
		printf("before result\n");
		make_operand(q->result,&t.result);
		printf("meta operand\n");
	}else{
			printf("res\n");
		reset_operand(&t.result);
	}
	q->taddress =nextinstructionlabel()-1;
	printf("before emit\n");
	emitInst(t); 
	printf("after emit\n");
}

void generate_ADD(quad *q){printf("mpainei sth gen_add\n");generate(add_v,q);}
void generate_SUB(quad *q){printf("mpainei sth gen_sub\n");generate(sub_v,q);}
void generate_MUL(quad *q){generate(mul_v,q);}
void generate_DIV(quad *q){generate(div_v,q);}
void generate_MOD(quad *q){generate(mod_v,q);}
void generate_ASSIGN(quad *q){generate(assign_v,q);}
void generate_NEWTABLE(quad *q){generate(newtable_v,q);}
void generate_TABLEGETELEM(quad *q){generate(tablegetelem_v,q);}
void generate_TABLESETELEM(quad *q){generate(tablesetelem_v,q);}
void generate_NOP(){instruction t;t.opcode=nop_v;emitInst(t);}

void generate_PARAM(quad *q){
	q->taddress=nextinstructionlabel();
	instruction t;
	t.opcode=pusharg_v;
	make_operand(q->arg1,&t.arg1);
	emitInst(t);
}

void generate_CALL(quad *q){
	q->taddress=nextinstructionlabel();
	instruction t;
	t.opcode=callfunc_v;
	make_operand(q->arg1,&t.arg1);
	emitInst(t);
}

void generate_GETRETVAL(quad *q){
	q->taddress=nextinstructionlabel();
	instruction t;
	t.opcode=assign_v;
	make_operand(q->result,&t.result);
	make_retvaloperand(&t.arg1);
	emitInst(t);
}

void generate_FUNCSTART(quad *q){
	printf("funcstart start\n");
	node *f =q->arg1->symbol;
	f->retList = malloc(sizeof(returnList));
	f->taddress=nextinstructionlabel();
	q->taddress=nextinstructionlabel();
	 userfuncs_newfunc(f);
	 pushFuncStack(f);
	 instruction t;
	 t.opcode=entefunc_v;
	 make_operand(q->arg1,&t.result);
	 emitInst(t);
	 printf("funcstar\n");
}

void generate_RETURN(quad *q){
	q->taddress=nextinstructionlabel();
	instruction t;
	t.opcode=assign_v;
	make_retvaloperand(&t.result);
	make_operand(q->arg1,&t.arg1);
	emitInst(t);
	node* f=topFunc();
	append(f->retList);
	t.opcode=jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type=label_a;
	emitInst(t);
	printf("return\n");
}

void generate_FUNCEND(quad *q){
	node* f=popFunc();
	backpatch(f->retList);
	q->taddress=nextinstructionlabel();
	instruction t;
	t.opcode=exitfunc_v;
	make_operand(q->arg1,&t.result);
	emitInst(t);
	printf("funcend\n");
}

void quadToInst(quad *q){
	switch (q->op){
		case add:{
			generate_ADD(q);
			break;
		}
		case sub:{
			generate_SUB(q);
			break;
		}
		case mul:{
			generate_MUL(q);
			break;
		}
		case div_op:{
			generate_DIV(q);
			break;
		}
		case mod:{
			generate_MOD(q);
			break;
		}
		case assign:{
			generate_ASSIGN(q);
			break;
		}
		case and:{
			generate_AND(q);
			break;
		}
		case or:{
			generate_OR(q);
			break;
		}
		case jump:{
			generate_JUMP(q);
			break;
		}
		case if_eq:{
			generate_IF_EQ(q);
			break;
		}
		case if_noteq:{
			generate_IF_NOTEQ(q);
			break;
		}
		case if_greater:{
			generate_GREATER(q);
			break;
		}
		case if_greatereq:{
			generate_GREATEREQ(q);
			break;
		}
		case if_less:{
			generate_LESS(q);
			break;
		}
		case if_lesseq:{
			generate_LESSEQ(q);
			break;
		}
		case tablecreate:{
		
			 generate_NEWTABLE(q);
			 break;
		}
		case tablegetelem:{
			generate_TABLEGETELEM(q);
			 break;
		}
		case tablesetelem:{
			 generate_TABLESETELEM(q);
			 break;
		}
		case call:{
			generate_CALL(q);
			break;
		}
		case param:{
			generate_PARAM(q);
			break;
		}
		case getretval:{
			generate_GETRETVAL(q);
			break;
		}
		case funcstart:{
			generate_FUNCSTART(q);
			break;
		}
		case funcend:{
			generate_FUNCEND(q);
			break;
			}
		case ret:{
			generate_RETURN(q);
			break;
		}
		case noop:{
			generate_NOP();
			break;
		}
		case uminus:{
			generate_MUL(q);
			break;
		}
		case not:{
			generate_NOT(q);
			break;
		}
		default:assert(0);
	}
	
	
	
}

void add_incomplete_jump(unsigned instrNo,unsigned iaddress){
	incomplete_jump *temp = ij_head;
	incomplete_jump *new_node = malloc(sizeof(incomplete_jump));
	new_node->instrNo = instrNo;
	new_node->iaddress = iaddress;
	if(ij_head == NULL){
		ij_head = new_node;
		return;
	}
	while(temp->next != NULL) temp = temp->next;
	temp->next = new_node;
}


void patch_incomplete_jumps(){
		incomplete_jump *temp=ij_head;
		while(temp!=NULL){
			printf("iaddress %d\n",temp->iaddress);
			if(temp->iaddress == nextquad()){
				printf("first\n");
				instructions[temp->instrNo].result.val = getInstructions();
			}else{
				instructions[temp->instrNo].result.val=quad_table[temp->iaddress].taddress;
				printf("second \n");
			}
			temp=temp->next;
		}
}

void generate_relational(vmopcode op,quad *q){
	instruction t;
	t.opcode=op;
	
	if(q->arg1!=NULL)make_operand(q->arg1,&t.arg1);
	
	printf("hello superman \n");
	if(q->arg2!=NULL)make_operand(q->arg2,&t.arg2);
	printf("hello spiderman \n");
	t.result.type=label_a;
	if(q->label-1<q->current){
		printf("FIRST \n");
		t.result.val=quad_table[q->label-1].taddress;
	}else{
		printf("SECOND \n");
		printf("instr %d \n",nextinstructionlabel()-1);
		printf("q->label %d \n", q->label);
		add_incomplete_jump(nextinstructionlabel()-1,q->label-1);
		
	}
	q->taddress=nextinstructionlabel()-1;
	emitInst(t);
	
}

void generate_JUMP(quad *q){generate_relational(jump_v,q);}
void generate_IF_EQ(quad *q){generate_relational(jeq_v,q);}
void generate_IF_NOTEQ(quad *q){generate_relational(jne_v,q);}
void generate_GREATER(quad *q){generate_relational(jgt_v,q);}
void generate_GREATEREQ(quad *q){generate_relational(jge_v,q);}
void generate_LESS(quad *q){generate_relational(jlt_v,q);}
void generate_LESSEQ(quad *q){generate_relational(jle_v,q);}

void reset_operand(vmarg *arg){
	arg->type=-1;
	arg->val=-1;
}
void generate_NOT(quad *q){
	q->taddress=nextinstructionlabel();
	instruction t;
	t.opcode=jeq_v;
	make_operand(q->arg1,&t.arg1);
	make_booloperand(&t.arg2,0);
	t.result.type=label_a;
	t.result.val=nextinstructionlabel()+3;
	emitInst(t);
	
	t.opcode=assign_v;
	make_booloperand(&t.arg1,0);
	reset_operand(&t.arg2);
	make_operand(q->result,&t.result);
	emitInst(t);
	
	t.opcode=jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type=label_a;
	t.result.val=nextinstructionlabel()+2;
	emitInst(t);
	
	t.opcode=assign_v;
	make_booloperand(&t.arg1,1);
	reset_operand(&t.arg2);
	make_operand(q->result,&t.result);
	emitInst(t);
}

void generate_OR(quad *q){
	q->taddress=nextinstructionlabel();
	instruction t;
	
	t.opcode=jeq_v;
	if(q->arg1!=NULL)make_operand(q->arg1,&t.arg1);
	make_booloperand(&t.arg2,1);
	t.result.type=label_a;
	t.result.val=nextinstructionlabel()+4;
	emitInst(t);
	
	if(q->arg2!=NULL)make_operand(q->arg2,&t.arg1);
	t.result.val=nextinstructionlabel()+3;
	emitInst(t);
	
	t.opcode=assign_v;
	make_booloperand(&t.arg1,0);
	reset_operand(&t.arg2);
	if(q->result!=NULL)make_operand(q->result,&t.result);
	emitInst(t);
	
	t.opcode=jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type=label_a;
	t.result.val=nextinstructionlabel()+2;
	emitInst(t);
	
	t.opcode=assign_v;
	make_booloperand(&t.arg1,1);
	reset_operand(&t.arg2);
	if(q->result!=NULL)make_operand(q->result,&t.result);
	emitInst(t);
	
	
}


void generate_AND(quad *q){
	q->taddress=nextinstructionlabel();
	instruction t;
	
	t.opcode=jeq_v;
	if(q->arg1!=NULL)make_operand(q->arg1,&t.arg1);
	make_booloperand(&t.arg2,0);
	t.result.type=label_a;
	t.result.val=nextinstructionlabel()+4;
	emitInst(t);
	
	if(q->arg2!=NULL)make_operand(q->arg2,&t.arg1);
	t.result.val=nextinstructionlabel()+3;
	emitInst(t);
	
	t.opcode=assign_v;
	make_booloperand(&t.arg1,1);
	reset_operand(&t.arg2);
	if(q->result!=NULL)make_operand(q->result,&t.result);
	emitInst(t);
	
	t.opcode=jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type=label_a;
	t.result.val=nextinstructionlabel()+2;
	emitInst(t);
	
	t.opcode=assign_v;
	make_booloperand(&t.arg1,0);
	reset_operand(&t.arg2);
	if(q->result!=NULL)make_operand(q->result,&t.result);
	emitInst(t);
	
	
}




char * TypetoString(enum vmarg_t arg){
	switch (arg){
		case label_a:{
		      return "label";
		}
		case global_a:{
		      return "global";
		}
		case formal_a:{
		      return "formal";
		}
		case local_a:{
		      return "local";
		}
		case number_a:{
		      return "number";
		}
		case string_a:{
		      return "string";
		}
		case bool_a:{
		      return "bool";
		}
		case nil_a:{
		      return "nil";
		}
		case userfunc_a:{
		      return "userfunc";
		}
		case libfunc_a:{
		      return "libfunc";
		}
		case retval_a:{
		      return "retval";
		}
		default:return "invalid";
	}	
}


char *OptoString(vmopcode op){
	switch (op){
		case assign_v:{
			return "assign";
		}
		case add_v:{
			return "add";
		}
		case sub_v:{
			return "sub";
		}
		case mul_v:{
			return "mul";
		}
		case div_v:{
			return "div";
		}
		case mod_v:{
			return "mod";
		}
		case jeq_v:{
			return "jeq";
		}
		case jne_v:{
			return "jne";
		}
		case jle_v:{
			return "jle";
		}
		case jge_v:{
			return "jge";
		}
		case jlt_v:{
			return "jlt";
		}
		case jgt_v:{
			return "jgt";
		}
		case jump_v:{
			return "jump";
		}
		case pusharg_v:{
			return "pusharg";
		}
		case callfunc_v:{
			return "callfunc";
		}
		case entefunc_v:{
			return "enterfunc";
		}
		case exitfunc_v:{
			return "exitfunc";
		}
		case nop_v:{
			return "nop";
		}
		case newtable_v:{
			return "newtable";
		}
		case tablegetelem_v:{
			return "tablegetelem";
		}
		case tablesetelem_v:{
			return "tablesetelem";
		}
		default:return "invalid OP";
	}
}




void printInst(){
	int i=0;
	//PINAKES
	printf("Const Numbers Array \n");
	for(i;i<num_counter;i++){
		
		printf("%d: %lf\n",i,numbers[i]);
	}
	printf("\n");
	printf("Const Strings Array \n");
	for(i=0;i<str_counter;i++){
		
		printf("%d: %s \n",i,strings[i]);
	}
	printf("\n");
		printf("Libfuncs  Array \n");
	for(i=0;i<libfunc_counter;i++){
	
		printf("%d: %s\n",i,libfuncs[i]);
	}
	printf("\n");
	printf("Userfuncs  Array \n");
	for(i=0;i<userfunc_counter;i++){
	
		printf("%d: | taddress: %d local_size: %d id: %s \n",i,funcs[i].taddress,funcs[i].local_size,funcs[i].id);
	}
	printf("\n");
	 for(i=0;i<instruction_counter;i++){
		 printf("%d :",i);
		 if(instructions[i].opcode!=nop_v){
		  printf("%s ",OptoString(instructions[i].opcode));
		if(strcmp(TypetoString(instructions[i].arg1.type),"invalid")!=0  && instructions[i].opcode!=exitfunc_v && instructions[i].opcode!=jump_v  && instructions[i].opcode!=entefunc_v){
			printf("%s,%d ",TypetoString(instructions[i].arg1.type),instructions[i].arg1.val);
		}
		if(strcmp(TypetoString(instructions[i].arg2.type),"invalid")!=0  && instructions[i].opcode!=exitfunc_v && instructions[i].opcode!=assign_v && instructions[i].opcode!=jump_v  && instructions[i].opcode!=entefunc_v){
			printf("%s",TypetoString(instructions[i].arg2.type));
			if(instructions[i].arg2.type!=retval_a){
				printf(",%d ",instructions[i].arg2.val);
			}
		
		}
		
		if(strcmp(TypetoString(instructions[i].result.type),"invalid")!=0  ){
			printf("%s",TypetoString(instructions[i].result.type));
			if(instructions[i].result.type!=retval_a){
				printf(",%d ",instructions[i].result.val);
			}
		}
		
		printf("\n");
		 }
	 }
	
	//TELOS PINAKES
	
	
	
}


void getInst(){
	int i=0;
	while(i<=nextquad()){
		quadToInst(&quad_table[i]);
		i++;
	}
	
	
}
