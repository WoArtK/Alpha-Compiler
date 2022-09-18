#include "quads.h"
#include <assert.h>
#define SIZE 1024
int off_size = 100;
quad *quad_table=NULL;
int *offsets_table=NULL;
int quad_count=-1;
int loop;
int MAXSIZE = 50;       
int func_counter= -1;

void init_stacks(){
	ifstack.top = -1;   
	ifstack.name = strdup("ifstack");
	loopstack.top = -1;
	loopstack.name = strdup("loopstack");
	breakstack.top = -1;
	breakstack.name = strdup("breakstack");
	continuestack.top = -1;
	continuestack.name = strdup("continuestack");
}

unsigned programVarOffset=0;
unsigned functionLocalOffset=0;
unsigned formalArgOffset=0;
unsigned scopeSpaceCounter=1;

void init_offsets_table(){
	int i=0;
	offsets_table=malloc(sizeof(int)*off_size);
	for(i; i<100;i++ ){
		offsets_table[i]=0;
	}
}

int nextquad(){
	return quad_count;
}


void expand_offsets_table(){
	int i=off_size;
	off_size=2*off_size;
	offsets_table=realloc(offsets_table,sizeof(int)*off_size);
	for(i;i<off_size;i++){
		offsets_table[i]=0;
	}
}


unsigned currscopeoffset(){
	switch(currscopespace()){
		case program_var:return programVarOffset;
		case function_local:return functionLocalOffset;
		case formal_arg:return formalArgOffset;
		default:assert(0);
	}
}

 enum scope_spc currscopespace(){
	if(scopeSpaceCounter==1){
			
		return program_var;
		
	}else if(scopeSpaceCounter%2==0){
		
		return formal_arg;
		
	}else{
		
		return function_local;
	}
}

void inccurrscopeoffset(){
	switch (currscopespace()){
		case program_var:
		
			++programVarOffset;break;
		case function_local:++functionLocalOffset;break;
		case formal_arg:++formalArgOffset;break;
		default:assert(0);
	}
}

void enterscopespace(){
	
	++scopeSpaceCounter;
	
}


void checkuminus(expr_e *expr){
	if(expr->type==constbool_e||expr->type==conststring_e||expr->type==nil_e||expr->type==newtable_e||
	expr->type==programfunc_e||expr->type==libraryfunc_e||expr->type==boolexpr_e){
		
					printf("\n\n Illegal expr to unary-\n\n");
		
				}
}


void exitscopespace(){
	assert(scopeSpaceCounter>1);
	--scopeSpaceCounter;
}



expr_e* emit_iftableitem(expr_e *e,int line){
	printf("hello234\n");
	if(e->type !=tableitem_e){
		printf("mpainei sto 1o\n");
		return e;
	}
	else{
		printf("mpainei sto 2o\n");
		expr_e	*result=newexpr(var_e);
		result->symbol=newtemp();
		emit(tablegetelem,e,e->index,result,line);
	
		return result;
	}
}
expr_e *member_item(expr_e  *lvalue,char *name,int line){
	lvalue=emit_iftableitem(lvalue,line);
	expr_e *item= newexpr(tableitem_e);
	item->symbol=lvalue->symbol;
	item->index=newexpr(conststring_e);
	item->index->strConst=strdup(name);
	return item;
}


void emit(enum iopcode opcode,expr_e *arg1,expr_e * arg2, expr_e* result, unsigned line){
	quad q;
	if(quad_table==NULL){
		quad_table=malloc(sizeof(quad)*SIZE);
	}
	if(quad_count==SIZE){
		quad_table=realloc(quad_table,2*sizeof(quad)*SIZE);
	}
		quad_count++;
		q.op=opcode;
		q.arg1=arg1;
		q.arg2=arg2;
		q.result=result;
		q.label=quad_count;
		q.line=line;
		q.current=quad_count;
			//quadToInst(&q);
	    quad_table[quad_count]=q;
		//q.taddress=getInstructions();
	
		
}

void emit_Realop(enum iopcode opcode,expr_e *arg1,expr_e * arg2, unsigned label){
	quad q;
	if(quad_table==NULL){
		quad_table=malloc(sizeof(quad)*SIZE);
	}
	if(quad_count==SIZE){
		quad_table=realloc(quad_table,2*sizeof(quad)*SIZE);
	}
		quad_count++;
		q.op=opcode;
		q.arg1=arg1;
		q.arg2=arg2;
		q.result=NULL;
		q.label=label;
		q.current=quad_count;
		if(opcode==noop)q.taddress=getInstructions();
		printf("hello iron man \n");
		//quadToInst(&q);
	    quad_table[quad_count]=q;
}


expr_e * newexpr(enum expr_t type){
	expr_e* exp=malloc(sizeof(expr_e));
	exp->type=type;
    
	return exp;
}

void make_call_emit(expr_e *elist){
	expr_e *temp = elist;
	printf("kalispera\n");
	if(temp->next != NULL){
		printf("ela mou\n");
		make_call_emit(temp->next);
	}
	printf("peradwna\n");
	if(temp != NULL){
	
		emit(param,temp,NULL,NULL,-1);
		
	}
}

expr_e *make_call(expr_e *lvalue,expr_e *elist,int line){
	if(elist != NULL) make_call_emit(elist);
	expr_e *func=emit_iftableitem(lvalue,line);
	emit(call,func,NULL,NULL,0);
	 expr_e *result=newexpr(var_e);
	 result->symbol=newtemp();
	 emit(getretval,NULL,NULL,result,0);
	 return result;
	
}
void print_quads(){
	int i=0;
	if(quad_count==-1)return;
	FILE *file=fopen("quads.txt","w");
	
	printf("%-10s%-25s%-20s%-15s%-10s%-10s\n","#Quad","Opcode", "Arg1", "Arg2", "Result","Label");
	fprintf(file,"%-10s%-25s%-20s%-15s%-10s%-10s\n","#Quad","Opcode", "Arg1", "Arg2", "Result","Label");
	printf("---------------------------------------------------------------------------------------------------------------\n");
	fprintf(file,"---------------------------------------------------------------------------------------------------------------\n");
	while(i<=quad_count){
		if(strcmp(opcode_toString(quad_table[i].op),"noop")!=0){
		printf("%-10d",i+1);
		printf("%-25s",opcode_toString(quad_table[i].op));
		fprintf(file,"%-10d",i+1);
		fprintf(file,"%-25s",opcode_toString(quad_table[i].op));
		
			
		if(quad_table[i].op==or){
			if(quad_table[i].arg1==NULL){
				printf("arg1==NULL\n");
			}
			if(quad_table[i].arg2==NULL){
				printf("arg2==NULL\n");
			}
			if(quad_table[i].result==NULL){
				printf("result==NULL\n");
			}
		}
		if(quad_table[i].arg1!=NULL){
		
			
			if((quad_table[i].arg1->type==var_e) ||(quad_table[i].arg1->type==programfunc_e)  ||(quad_table[i].arg1->type==newtable_e) || (quad_table[i].arg1->type==tableitem_e)||(quad_table[i].arg1->type==libraryfunc_e)){
				printf("%-20s",quad_table[i].arg1->symbol->name);
				fprintf(file,"%-20s",quad_table[i].arg1->symbol->name);
			}
			
			
			if((quad_table[i].arg1->type==constnum_e)){
				printf("%-20lf",quad_table[i].arg1->numConst);
				fprintf(file,"%-20lf",quad_table[i].arg1->numConst);
			}
			
			if((quad_table[i].arg1->type==arithmexpr_e)){
				printf("%-20s",quad_table[i].arg1->symbol->name);
				fprintf(file,"%-20s",quad_table[i].arg1->symbol->name);
			
			}
			if((quad_table[i].arg1->type==conststring_e)){
				printf("%-20s",quad_table[i].arg1->strConst);
				fprintf(file,"%-20s",quad_table[i].arg1->strConst);
			
			}
			if((quad_table[i].arg1->type==assignexpr_e) || (quad_table[i].arg1->type==boolexpr_e) ){
				printf("%-20s",quad_table[i].arg1->symbol->name);
				fprintf(file,"%-20s",quad_table[i].arg1->symbol->name);
			
			}
				
			if((quad_table[i].arg1->type==constbool_e)){
				if(quad_table[i].arg1->boolConst==1){
					printf("%-20s","TRUE");
					fprintf(file,"%-20s","TRUE");
				}else if(quad_table[i].arg1->boolConst==0){
					printf("%-20s","FALSE");
					fprintf(file,"%-20s","FALSE");
				}
			}
			
			
		}else{
		
				printf("%-20s "," ");
				fprintf(file,"%-20s "," ");
			}
		
		
		
		if(quad_table[i].arg2!=NULL){
		
			if((quad_table[i].arg2->type==var_e) ||(quad_table[i].arg2->type==programfunc_e)||(quad_table[i].arg2->type==newtable_e)|| (quad_table[i].arg2->type==tableitem_e)){
				printf("%-15s",quad_table[i].arg2->symbol->name);
				fprintf(file,"%-15s",quad_table[i].arg2->symbol->name);
			}
			if((quad_table[i].arg2->type==constnum_e)){
				printf("%-15lf",quad_table[i].arg2->numConst);
				fprintf(file,"%-15lf",quad_table[i].arg2->numConst);
			}
			if((quad_table[i].arg2->type==arithmexpr_e)){
				printf("%-15s",quad_table[i].arg2->symbol->name);
				fprintf(file,"%-15s",quad_table[i].arg2->symbol->name);
			}
			if((quad_table[i].arg2->type==conststring_e) ){
				printf("%-15s",quad_table[i].arg2->strConst);
				fprintf(file,"%-15s",quad_table[i].arg2->strConst);
			}
			if((quad_table[i].arg2->type==assignexpr_e) || (quad_table[i].arg2->type==boolexpr_e)){
				if(quad_table[i].arg2->symbol==NULL){
					if(quad_table[i].arg2->boolConst==1){
					printf("%-20s","TRUE");
					fprintf(file,"%-20s","TRUE");
					}else if(quad_table[i].arg2->boolConst==0){
						printf("%-20s","FALSE");
						fprintf(file,"%-20s","FALSE");
					}
					
				}else{	
					printf("%-20s",quad_table[i].arg2->symbol->name);
					fprintf(file,"%-20s",quad_table[i].arg2->symbol->name);
				}
				
			}
			if((quad_table[i].arg2->type==constbool_e)){
				if(quad_table[i].arg2->boolConst==1){
					printf("%-20s","TRUE");
					fprintf(file,"%-20s","TRUE");
				}else if(quad_table[i].arg2->boolConst==0){
					printf("%-20s","FALSE");
					fprintf(file,"%-20s","FALSE");
				}
			}
	}else{
		
				printf("%-15s "," ");
				fprintf(file,"%-15s "," ");
			}
		

		
		if(quad_table[i].result!=NULL ){
			
			if((quad_table[i].result->type==var_e) ||(quad_table[i].result->type==programfunc_e) ||(quad_table[i].result->type==newtable_e)|| (quad_table[i].result->type==tableitem_e)){
				printf("%-10s",quad_table[i].result->symbol->name);
				fprintf(file,"%-10s",quad_table[i].result->symbol->name);
			}
			if((quad_table[i].result->type==constnum_e)){
				printf("%-10lf",quad_table[i].result->numConst);
				fprintf(file,"%-10lf",quad_table[i].result->numConst);
			}
			if((quad_table[i].result->type==arithmexpr_e)){

				printf("%-10s",quad_table[i].result->symbol->name);
				fprintf(file,"%-10s",quad_table[i].result->symbol->name);
			}
			if((quad_table[i].result->type==conststring_e) ){
				printf("%-10s",quad_table[i].result->strConst);
				fprintf(file,"%-10s",quad_table[i].result->strConst);
			}
			if((quad_table[i].result->type==assignexpr_e) || (quad_table[i].result->type==boolexpr_e)){
				printf("%-20s",quad_table[i].result->symbol->name);
				fprintf(file,"%-20s",quad_table[i].result->symbol->name);
			}
			if((quad_table[i].result->type==constbool_e)){
				if(quad_table[i].result->boolConst==1){
					printf("%-20s","TRUE");
					fprintf(file,"%-20s","TRUE");
				}else{
					printf("%-20s","FALSE");
					fprintf(file,"%-20s","FALSE");
				}
			}
		}else{
			printf("%-10s"," ");
			fprintf(file,"%-10s"," ");
		}
			if(quad_table[i].op==jump || quad_table[i].op==if_greater || quad_table[i].op==if_less || quad_table[i].op==if_greatereq || quad_table[i].op==if_lesseq
				|| quad_table[i].op==if_eq || quad_table[i].op==if_noteq){
				printf("%-10d \n",quad_table[i].label);
				fprintf(file,"%-10d \n",quad_table[i].label);
			}else{
				printf("\n");
				fprintf(file,"\n");
			}
		}		
		//printf("\n");
		i++;
	
	}
	
	
	fclose(file);
}


char *opcode_toString(enum iopcode opcode){
	switch(opcode){
	case assign :return "ASSIGN";
	case add : return "ADD";
	case sub : return "SUB";
	case mul: return "MUL";
	case div_op: return "DIV_OP";
	case mod: return "MOD";
	case uminus :return "UMINUS";
	case and :return "AND";
	case or:return "OR";
	case not :return "NOT";
	case if_eq:return "IF_EQ";
	case if_noteq :return "IF_NOTEQ";
	case if_lesseq :return "IF_LESSEQ";
	case if_greatereq: return "IF_GREATEREQ";
	case if_less: return "IF_LESS";
	case if_greater :return "IF_GREATER";
	case call :return "CALL";
	case param :return "PARAM";
	case ret :return "RET";
	case getretval :return "GETRETVAL" ;
	case funcstart :return "FUNCSTART";
	case funcend: return "FUNCEND";
	case tablecreate :return "TABLECREATE";
	case tablegetelem :return "TABLEGETELEM";
	case tablesetelem :return "TABLESETELEM";
	case jump:return "JUMP";
	case noop:return "noop";
	default:return "NON VALID";
	}
}


int check_if_arithm(expr_e *exp1,expr_e *exp2){
	if( (exp1->type==programfunc_e) || (exp1->type==	libraryfunc_e )|| (exp1->type== boolexpr_e )|| (exp1->type== newtable_e)
		|| (exp1->type==constbool_e) || (exp1->type== conststring_e) || (exp1->type== nil_e)||
		(exp2->type==programfunc_e) || (exp2->type==	libraryfunc_e )|| (exp2->type== boolexpr_e )|| (exp2->type== newtable_e)
		|| (exp2->type==constbool_e) || (exp2->type== conststring_e) || (exp2->type== nil_e))
		
		
		{
			return 0;
		}
return 1;
}

void check_if_constNum(expr_e *exp1,expr_e *exp2,expr_e *exp){
	if( (exp1->type==constnum_e) && (exp2->type==constnum_e)){
		exp->type=constnum_e;

	}	
		
}


void patchlabel(int index, unsigned label){
	
		quad_table[index].label=label;	
}


int isempty(s_stack *stack) {

   if(stack->top == -1)
      return 1;
   else
      return 0;
}
   
int isfull(s_stack *stack) {

   if(stack->top == MAXSIZE)
      return 1;
   else
      return 0;
}



int pop(s_stack *stack) {
   int data;
   
	if((strcmp(stack->name,"breakstack") != 0) || (strcmp(stack->name, "continuestack") != 0)){
   if(!isempty(stack)) {
	 
      data = stack->array_stack[stack->top][0];
      stack->top = stack->top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
	  return -1;
	}
	}else{
		  
		if(stack->array_stack[stack->top][1] == loop){
			
		   if(!isempty(stack)) {
			  data = stack->array_stack[stack->top][0];
			  stack->top = stack->top - 1;
			 
			  return data;
		   }else{
			   printf("Could not retrieve data, Stack is empty.\n");
			   return -1;
		   }
		}else{
			return -1;
		}
	}
}



int push(s_stack *stack,int data) {

   if(!isfull(stack)) {
      stack->top = stack->top + 1;   
      stack->array_stack[stack->top][0] = data;
	  stack->array_stack[stack->top][1] = loop;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}


void set_loop(int loop_c){
	loop = loop_c;
}
int peek(s_stack *stack) {
   return stack->array_stack[stack->top][0];
}

node *func_stack[1000];

node *topFunc(){
	if(func_counter > -1)return func_stack[func_counter];
	return NULL;
}

node *pushFuncStack(node *sym){
	if(sym!=NULL){
		func_counter++;
		func_stack[func_counter]=sym;
		return sym;
	}
	return NULL;
}
node *popFunc(){
	if(func_counter > -1){
		 func_counter--;
		 return func_stack[func_counter+1];
	}
	return NULL;
}

