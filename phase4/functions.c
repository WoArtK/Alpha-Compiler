#include "avm.h"
#define AVM_NUMACTUALS_OFFSET 	+4
#define AVM_SAVEDPC_OFFSET		+3
#define AVM_SAVEDTOP_OFFSET		+2
#define AVM_SAVEDTOPSP_OFFSET	+1

unsigned	totalActuals=0;
avm_table *insert(avm_table *table, avm_memcell *index, avm_memcell *content){
	contents *newtemp;
	assert(table && index && content);
	contents *newcont = malloc(sizeof(contents));
	newcont->index=malloc(sizeof( content));
	newcont->content=malloc(sizeof( content));
	
	
	
	
	if(index->type==number_m){
		newcont->index->data.numVal = index->data.numVal;
		newcont->index->type=number_m;
		
	}else{
		newcont->index->data.strVal= strdup(index->data.strVal);
		newcont->index->type=string_m;
	}
	
	
	if(content->type==number_m){
		newcont->content->data.numVal = content->data.numVal;
		newcont->content->type=number_m;
	}
	if(content->type==string_m){
		
		newcont->content->data.strVal=malloc(strlen(content->data.strVal));
		strcpy(newcont->content->data.strVal,content->data.strVal);
		newcont->content->type=string_m;
	}
	if(content->type==bool_m){
		newcont->content->data.boolVal = content->data.boolVal;
		newcont->content->type=bool_m;
	}
	if(content->type==userfunc_m){
		newcont->content->data.funcVal = content->data.funcVal;
		newcont->content->type=userfunc_m;
	}
	if(content->type==libfunc_m){
		newcont->content->data.libfuncVal = strdup(content->data.libfuncVal);
		newcont->content->type=libfunc_m;
	}
	if(content->type==table_m){
		newcont->content->data.tableVal = content->data.tableVal;
		newcont->content->type=table_m;
	}
	
	if(table->head == NULL){
		table->head = newcont;
		
	}else{
		contents *temp = table->head;
		
		if(index->type==number_m){
			while((temp!= NULL) && (temp->index->data.numVal != index->data.numVal)){
				newtemp = temp;
				temp = temp->next;
			}
		}else{
			
			while((temp!= NULL) ){
				if(temp->index->type!=string_m){
					newtemp = temp;
					temp = temp->next;
					continue;
				}
				if((strcmp(temp->index->data.strVal,index->data.strVal))!=0){				
					newtemp = temp;
					temp = temp->next;
				}else{
					break;
				}
			}
			
		}
		if(temp== NULL){
			
			newcont->next = NULL;
			newcont->previous = temp;
			newtemp->next = newcont;
			return table;
		}
		if(content->type==number_m){
		newcont->content->data.numVal = content->data.numVal;
		newcont->content->type=number_m;
		}
	if(content->type==string_m){
		
		newcont->content->data.strVal=malloc(strlen(content->data.strVal));
		strcpy(newcont->content->data.strVal,content->data.strVal);
		newcont->content->type=string_m;
	}
	if( newcont->content->type==number_m){
		temp->content->data.numVal = newcont->content->data.numVal;
		temp->content->type = number_m;
	}
	if(newcont->content->type==string_m){
		temp->content->data.strVal =strdup( newcont->content->data.strVal);
		temp->content->type = string_m;
	}
	if(newcont->content->type==bool_m){
	temp->content->data.boolVal = newcont->content->data.boolVal;
		temp->content->type = bool_m;
	}
	if(newcont->content->type==table_m){
		temp->content->data.tableVal = newcont->content->data.tableVal;
		temp->content->type = table_m;
	}
	if(newcont->content->type==userfunc_m){
	temp->content->data.funcVal = newcont->content->data.funcVal;
		temp->content->type = userfunc_m;
	}
	if(newcont->content->type==libfunc_m){
		temp->content->data.libfuncVal = strdup(newcont->content->data.libfuncVal);
		temp->content->type = libfunc_m;
	}

	}
	
	//printf("vgainei apo thn insert\n");
	return table;
}
contents *get(avm_table * table, avm_memcell *index){

	assert(table && index);
	assert(index->type==string_m || index->type==number_m);
	contents *temp = table->head;
	
	if(index->type==number_m){
			
		while(temp->index->data.numVal != index->data.numVal){
		
			temp = temp->next;
			if(temp == NULL) break;
		} 
	}else if(index->type==string_m){
		int found=0;
		while(found==0){
			
			if(temp->index->type==number_m){
				
				temp = temp->next;
				
			}else if(strcmp(temp->index->data.strVal,index->data.strVal)!=0){
				temp = temp->next;
			}else{
				found=1;
			}
			
			if(temp == NULL) break;
		} 
	}
	
	
	if(temp == NULL){
	
		return NULL;
	} 

	
	
	return temp;	
	
}

contents *delete_cont(avm_table *table, avm_memcell *index){

	assert(table && index);
	contents *temp = get(table,index);

	if(temp == NULL){
		
		return NULL;
	} 
	/*(temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
		*/
		
		temp->content->type=undef_m;
		
	return temp;
}




void avm_tableincrefcounter(avm_table *lv){
	
	lv->rc++;
}

void avm_tabledecrefcounter(avm_table *lv){

	lv->rc--;
	
}

void execute_newtable(instruction* instr){
	
	
	avm_memcell* lv=avm_translate_operand(&instr->arg1,(avm_memcell*)0);
	//assert((lv && (&stack[N-1]>=lv && lv>&stack[top] || lv==&retval)));
	
	avm_memcellclear(lv);
	
	lv->type=table_m;
	lv->data.tableVal=avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);
}


avm_table *avm_tablenew(){
	
	avm_table *newtable=malloc(sizeof(avm_table));
	newtable->head = NULL;
	newtable->rc=0;
	return newtable;
	
}

avm_memcell *avm_tablegetelem(avm_table * table,avm_memcell* cell){

	if(get(table, cell)!=NULL){
	
		return get(table, cell)->content;
	}

	return NULL;
}

void execute_tablegetelem(instruction* instr){
	
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*) 0);
	
	avm_memcell* t=avm_translate_operand(&instr->arg1,(avm_memcell*) 0);

	avm_memcell* i=avm_translate_operand(&instr->arg2,&ax);
	
	
	
	//assert(lv && &stack[N-1] >= lv && lv>&stack[top] || lv==&retval));
	//assert(t && &stack[N-1] >= t && t>&stack[top]);
	assert(i);
	
	
	avm_memcellclear(lv);
	lv->type=nil_m;
	
	if(t->type!=table_m){
		avm_error("illegal use of type %s as table!\n");
	}
	else{
	
		avm_memcell* content=avm_tablegetelem(t->data.tableVal,i);
		
		if(content->type==string_m)lv->type=string_m;
		
		if(content!=NULL){
			
			avm_assign(lv,content);
			
		
		}	
		else{
	
			char* ts=avm_tostring(t);
			
			char* is=avm_tostring(i);
			avm_warning("not found!\n");
			
			free(ts);
			free(is);
		}
	}
}
void avm_tablesetelem(avm_table * table, avm_memcell *index,avm_memcell *content){

	if(content->type==nil_m){
		delete_cont(table,index);
		avm_tabledecrefcounter(table);
		
		return;
	}
	insert(table, index,content);
	
	
	avm_tableincrefcounter(table);

}







void execute_call(instruction* instr){
	avm_memcell* func=avm_translate_operand(&instr->arg1,&ax);
	assert(func);
	
	avm_callsaveenviroment();
	switch(func->type){
		case userfunc_m:{
			pc=func->data.funcVal;
			assert(pc<AVM_ENDING_PC);
			assert(code[pc].opcode=entefunc_v);
			break;
		}
		case string_m: avm_calllibfunc(func->data.strVal);	break;
		case libfunc_m: avm_calllibfunc(func->data.libfuncVal);	break;
		
		default:{
			char * s=avm_tostring(func);
			avm_error("call: cannot bind '%s' to function! \n");
			free(s);
			executionFinished=1;
		}
	}
}



void avm_dec_top(void){
	if(!top){
		avm_error("stack overflow\n");
		executionFinished=1;
	}
	else{
		--top;
	}
} 

void avm_push_envvalue(unsigned val){
	stack[top].type=number_m;
	stack[top].data.numVal=val;
	avm_dec_top();
}

void avm_callsaveenviroment(void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top+totalActuals+2);
	avm_push_envvalue(topsp);
}

void execute_enterfunc(instruction* instr){

	avm_memcell* func=avm_translate_operand(&instr->result,&ax);
	assert(func);

	
	assert(pc==func->data.funcVal);
	
	totalActuals=0;
	
	userfuncs* funcInfo=avm_getfuncinfo(pc);
	topsp=top;
	top=top-funcInfo->local_size;
}


unsigned avm_get_envvalue(unsigned i){
	assert(stack[i].type==number_m);
	unsigned val=(unsigned) stack[i].data.numVal;
	assert(stack[i].data.numVal==((double) val));
	return val;
}



void execute_exitfunc(instruction* unused){
	unsigned oldTop=top;
	top=avm_get_envvalue(topsp+AVM_SAVEDTOP_OFFSET);
	pc=avm_get_envvalue(topsp+AVM_SAVEDPC_OFFSET);
	topsp=avm_get_envvalue(topsp+AVM_SAVEDTOPSP_OFFSET);
	
	while(++oldTop<=top)	avm_memcellclear(&stack[oldTop]);
}


void avm_calllibfunc(char* id){
			
	library_func_t f=avm_getlibraryfunc(id);
	if(strcmp(id,"print")==0){
		
		topsp=top;
		totalActuals=0;
		libfunc_print();
	}
	else if(strcmp(id,"input")==0){
		topsp=top;
		totalActuals=0;
		libfunc_input();
	}else if(strcmp(id,"typeof")==0){
		topsp=top;
		totalActuals=0;
		libfunc_typeof();
	}else if(strcmp(id,"totalarguments")==0){
		topsp=top;
		totalActuals=0;
		libfunc_totalarguments();
	}else if(strcmp(id,"argument")==0){
		
		topsp=top;
		totalActuals=0;
		libfunc_argument();
	}
	//if(strcmp(id,"input")==0)libfunc_input();
	//if(strcmp(id,"objectmemberkeys")==0)libfunc_objectmemberkeys();
	//if(strcmp(id,"objecttotalmembers")==0)libfunc_objecttotalmembers();
	//if(strcmp(id,"objectcopy")==0)libfunc_objectcopy();
	//if(strcmp(id,"totalarguments")==0)libfunc_totalarguments();
	//if(strcmp(id,"argument")==0)libfunc_argument();
	//if(strcmp(id,"typeof")==0)libfunc_typeof();
	/*if(strcmp(id,"strtonum")==0)libfunc_strtonum();
	if(strcmp(id,"sqrt")==0)libfunc_sqrt();
	if(strcmp(id,"cos")==0)libfunc_cos();
	if(strcmp(id,"sin")==0)libfunc_sin();*/
	
	
	else{
	
		avm_error("unsupported lib func called!\n");
		executionFinished=1;
	}
	

		if(!executionFinished)	execute_exitfunc((instruction*)0);
		
	
}

//	23


unsigned avm_totalactuals(void){
	return avm_get_envvalue(topsp+AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual(unsigned i){
	assert (i<avm_totalactuals());
	return	&stack[topsp+AVM_STACKENV_SIZE+i+1];
	
}



void libfunc_print(void){
	
	unsigned n=avm_totalactuals();
	int i=0;
	//printf("print result \n");
	for ( i=0;i<n;++i){
		avm_memcell * temp = avm_getactual(i);

		char* s=avm_tostring(avm_getactual(i));
		
		puts(s);
		
		//free(s);
		//printf("print free \n");
	}
//printf("after print \n");
}
void * libfunc_input(){
	char* line=NULL;
	size_t len=0;
	ssize_t read;
	int i;
    int flag=0;
	double * num;
	unsigned char * st;
	int f=0;
	double actual;
	unsigned char c;	
	read=getline(&line,&len,stdin);

    for(i=0;i<strlen(line)-1;i++){
        flag=isdigit(line[i]);
        if(flag==0)     break;
    }
	if(flag==1){
		actual=atof(line);
		
		num=&actual;
		
		retval.type=number_m;
		retval.data.numVal=actual;
		return num;
	}
	else {
		if(strncmp(line,"true",4)==0){
			c=1;
			st=&c;
			retval.type=bool_m;
			retval.data.boolVal=c;
			return st; 		
			
		}
		else if(strncmp(line,"false",5)==0){
			c=0;
			st=&c;
			retval.type=bool_m;
			retval.data.boolVal=c;
			return st; 		
		}else if(strncmp(line,"nil",3)==0){
			retval.type=nil_m;
			retval.data.strVal=strdup("NIL");
			return "NIL";
		
		}
		
		line[strlen(line)-1]=' ';
		if(line[0]=='"' && line[strlen(line)-2]=='"'){
			retval.type=string_m;
			retval.data.strVal=strdup(line);
			return line;
		}
		
		avm_error("illegal input\n");
	}
}


void execute_pusharg(instruction* instr){
	avm_memcell*arg=avm_translate_operand(&instr->arg1,&ax);
	assert(arg);
	avm_assign(&stack[top],arg);
	++totalActuals;
	avm_dec_top();
}


tostring_func_t tostringFuncs[]={
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring,	
};


char* avm_tostring(avm_memcell* m){
	
	assert(m->type>=0 && m->type<=undef_m);
	return (*tostringFuncs[m->type])(m);
}


//25


double add_impl(double x,double y)	{return x+y;}


double sub_impl(double x,double y)	{return x-y;}


double mul_impl(double x,double y)	{return x*y;}


double div_impl(double x,double y)	{
	if(y==0){
		avm_error("Cannot divide by zero\n");
	}   
	return (int)x/(int)y;
}


double mod_impl(double x,double y)	{
	if(y==0){
		avm_error("Cannot mod by zero\n");
	}
	
	
	return (((unsigned)x) % ((unsigned)y)) ;
	}


arithmetic_func_t arithmeticFuncs[]={
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl	
};



void execute_arithmetic(instruction* instr){
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*) 0);
	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&bx);
	

	
	//assert(lv && (&stack[N] >= lv && lv>&stack[top] || lv==&retval));
	assert(rv1 &&rv2);
	printf("typ1 typ2 %f %f \n",rv1->data.numVal,rv2->data.numVal);
	if(rv1->type != number_m || rv2->type !=number_m){
		avm_error("not a number in arithmetic!\n");
		executionFinished=1;
	}
	else{
		//printf("arg1 %f  arg2 %f \n",instr->arg1.numVal,instr->arg2.numVal);
		arithmetic_func_t op=arithmeticFuncs[instr->opcode-add_v];
		avm_memcellclear(lv);
		lv->type=number_m;
		lv->data.numVal=(*op)(rv1->data.numVal,rv2->data.numVal);
	}
}


//28




unsigned char number_tobool(avm_memcell* m){return m->data.numVal!=0;}


unsigned char string_tobool(avm_memcell* m){return m->data.strVal[0]!=0;}

unsigned char bool_tobool(avm_memcell* m){return m->data.boolVal;}

unsigned char table_tobool(avm_memcell* m){return 1;}


unsigned char userfunc_tobool(avm_memcell* m){return 1;}


unsigned char libfunc_tobool(avm_memcell* m){return 1;}


unsigned char nil_tobool(avm_memcell* m){return 0;}


unsigned char undef_tobool(avm_memcell* m){assert(0);return 0;}


tobool_func_t toboolFuncs[]={
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool	
};



unsigned char avm_tobool(avm_memcell *m){
	assert((m->type>=0) &&( m->type< undef_m));
	return (*toboolFuncs[m->type])(m);
}




//29

char* typeStrings[]={
	"number",
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"
};




//	30



void libfunc_typeof(void){
	unsigned n=avm_totalactuals();
	if(n!=1){
		avm_error("one argument (not %d) expected in 'typeof'!\n");
	}
	else{
		avm_memcellclear(&retval);
		retval.type=string_m;
		retval.data.strVal=strdup(typeStrings[avm_getactual(0)->type]);
	}
}




void execute_tablesetelem(instruction* instr){
	
	avm_memcell* t=avm_translate_operand(&instr->arg1,(avm_memcell*) 0);
	
	avm_memcell* i=avm_translate_operand(&instr->arg2,&ax);
	
	avm_memcell* c=avm_translate_operand(&instr->result,&bx);
	if(c->type==nil_m)printf("eimai nil \n");
	//assert(t && &stack[N-1]>=t && t>&stack[top]);
	assert(i&&c);
	
	if(t->type !=table_m)	avm_error("Illegal use of type %s as table!\n");
	else {
		
		avm_tablesetelem(t->data.tableVal,i,c);
		if(t->data.tableVal->rc==0)avm_memcellclear(t);
		}
	
}


//35


void avm_initialize(void){
	initStack();
	//avm_registerlibfunc("print",libfunc_print);
	/*avm_registerlibfunc("typeof",libfunc_typeof);
	avm_registerlibfunc("input",libfunc_input);
	avm_registerlibfunc("objectmemberkeys",libfunc_objectmemberkeys);
	avm_registerlibfunc("objecttotalmembers",libfunc_objecttotalmembers);
	avm_registerlibfunc("objectcopy",libfunc_objectcopy);
	avm_registerlibfunc("totalarguments",libfunc_totalarguments);
	avm_registerlibfunc("strtonum",libfunc_strtonum);
	avm_registerlibfunc("sqrt",libfunc_sqrt);
	avm_registerlibfunc("cos",libfunc_cos);
	avm_registerlibfunc("sin",libfunc_sin);	*/
}


//36

//prosoxi thelei kai thn argument(i)


//void avm_registerlibfunc(char *name, int libfunc_print)

void libfunc_argument(){
	unsigned p_topsp=avm_get_envvalue(topsp +AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);
	int index=avm_getactual(0)->data.numVal;//i
	avm_memcell cell=stack[p_topsp+AVM_NUMACTUALS_OFFSET+1-avm_totalactuals()+index+1];//teleutaio arg
	
	if(!p_topsp){
		avm_error("'totalarguments' called outside a function!\n");
		retval.type=nil_m;
	}
	else{
		if(cell.type==number_m){
			retval.type=number_m;
			retval.data.numVal=cell.data.numVal;
			return;
		}
		if(cell.type==string_m){
			retval.type=string_m;
			retval.data.strVal=strdup(cell.data.strVal);
			return;
		}
		if(cell.type==bool_m){
			retval.type=bool_m;
			retval.data.boolVal=cell.data.boolVal;
			return;
		}
		if(cell.type==nil_m){
			retval.type=nil_m;
			retval.data.strVal=strdup("nil");
			return;
		}
		if(cell.type==table_m){
			retval.type=table_m;
			retval.data.tableVal=cell.data.tableVal;
			return;
		}
		if(cell.type==undef_m){
			retval.type=undef_m;
			return;
		}
	}
		
	
	
}
unsigned libfunc_totalarguments(void){
	unsigned p_topsp=avm_get_envvalue(topsp +AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);
	
	if(!p_topsp){
		avm_error("'totalarguments' called outside a function!\n");
		retval.type=nil_m;
	}
	else{
		retval.type=number_m;
		retval.data.numVal=avm_get_envvalue(p_topsp+AVM_NUMACTUALS_OFFSET);
		return retval.data.numVal;
	}
	
}


