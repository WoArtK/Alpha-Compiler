
#include "avm.h"
#include <string.h>
#include <assert.h>

int *globals;
int cursize=50;
int actualsize=0;
void initStack(){
	int i=0;
	for(i;i<AVM_STACK_SIZE;i++)stack[i].type=undef_m;
	ax = stack[4095];
	bx = stack[4094];
	cx = stack[4093];
	retval = stack[4092];
}

avm_memcell* avm_translate_operand(vmarg* arg,avm_memcell* reg){
	
	switch(arg->type){
		case global_a:{
			return &stack[(AVM_STACK_SIZE-1)-(arg->val)];
		}
				
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
			printf("mpainw edw \n");
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
		
		default: assert(0);
	}
	
}


int user_counter=0;
int nums=0;
void insertUser(char *buffer){
	userfuncs func;
	func.taddress=atoi(strtok(buffer," "));
	func.local_size= atoi(strtok(NULL," "));
	func.id=strdup(strtok(NULL," "));
	funcs[user_counter]=func;
	user_counter++;
}
void insertInst(char *buffer){
	
	char *opcode = strdup(strtok(buffer," "));


	vmopcode op=atoi(opcode);
	
	switch (op){
		case add_v: //OLA
		case sub_v:
		case mul_v:
		case div_v:
		case mod_v:
		case jeq_v:
		case jne_v:
		case jle_v:
		case jge_v:
		case jlt_v:
		case tablegetelem_v:
		case tablesetelem_v:
		case jgt_v:{
			instruction t;
			t.opcode=op;
			t.arg1.type = atoi(strtok(NULL," "));
			t.arg1.val = atoi(strtok(NULL," "));
			t.arg2.type = atoi(strtok(NULL," "));
			t.arg2.val = atoi(strtok(NULL," "));
			t.result.type = atoi(strtok(NULL," "));
			t.result.val=atoi(strtok(NULL," "));
			
			emitInst(t);
			break;
		}
		
		case jump_v: //op result
		case entefunc_v:	
		case exitfunc_v:{
			instruction t;
			t.opcode=op;
			t.arg1.type=-1;
			t.arg2.type=-1;
			t.result.type = atoi(strtok(NULL," "));
			t.result.val=atoi(strtok(NULL," "));
			emitInst(t);
			break;
		}
		case newtable_v:{
			
			instruction t;
			t.opcode=op;
			t.arg1.type = atoi(strtok(NULL," "));			
			t.arg2.type=-1;
			t.result.type=-1;
			
			t.arg1.val=atoi(strtok(NULL," "));
			
			emitInst(t);
			break;
		}
		case assign_v:{ //op arg1 result
			instruction t;
			t.opcode=op;
			
			t.arg1.type = atoi(strtok(NULL," "));
			if(!(t.arg1.type == 10))t.arg1.val = atoi(strtok(NULL," "));
			t.result.type=-1;
			t.arg2.type=-1;
			t.result.type = atoi(strtok(NULL," "));
			if(!(t.result.type == 10))t.result.val=atoi(strtok(NULL," "));
			emitInst(t);
			break;
		}
	case callfunc_v:		
	case pusharg_v:{
			instruction t;
			t.opcode=op;
			t.arg1.type = atoi(strtok(NULL," "));
			t.arg1.val=atoi(strtok(NULL," "));
			t.result.type=-1;
			t.arg2.type=-1;
			emitInst(t);
			break;
		}
		
	}
	
	
}

void parsefile(){
	FILE *fp=fopen("alpha.bin","rb");
	char c;
	int magicnumber , j,i, stringmagic;
	char magicbuffer[12]={'\0'};
	char buffer[50];
	int s,k;
	//numbers
	fread(&c,sizeof(char),1,fp);
	i = 0;
	while(c != '\n'){
		
		magicbuffer[i] = c;
		
		fread(&c,sizeof(char),1,fp);
		i++;
	}
	
	magicnumber =atoi(magicbuffer);

	for(i = 0; i < magicnumber; i++){
		fread(&c,sizeof(char),1,fp);
		j = 0;
		while(c != '\n'){
			
			
			buffer[j] = c;
			
			fread(&c,sizeof(char),1,fp);
			j++;
		}
		
		const_newnumber(atof(buffer));
	
	}

	//strings
	i = 0;
	for(s=0;s<12;s++)magicbuffer[s]='\0';
	fread(&c,sizeof(char),1,fp);
	while(c != '\n'){
		
		magicbuffer[i] = c;
		fread(&c,sizeof(char),1,fp);
		i++;
	}
	magicnumber = atoi(magicbuffer);
	
	for(i = 0; i < magicnumber; i++){
		k = 0;
		
		for(s=0;s<12;s++)magicbuffer[s]='\0';
		fread(&c,sizeof(char),1,fp);
		while(c != '\n'){
		
			magicbuffer[k] = c;
			fread(&c,sizeof(char),1,fp);
			k++;
		}
		stringmagic = atoi(magicbuffer);
		char *string=malloc(sizeof(char)*stringmagic);
		for(j = 0; j < stringmagic; j++){
			fread(&c,sizeof(char),1,fp);
			string[j] = c;
		}
		const_newstring(string);
		//free(string);
		for(j=0;j<stringmagic;j++)string[j]='\0';
		
		fread(&c,sizeof(char),1,fp);
	}
	
	//libfucs
	
	i = 0;
	for(s=0;s<12;s++)magicbuffer[s]='\0';
	fread(&c,sizeof(char),1,fp);
	
	while(c != '\n'){
		
		magicbuffer[i] = c;
		fread(&c,sizeof(char),1,fp);
		i++;
	}
	magicnumber = atoi(magicbuffer);

	for(i = 0; i < magicnumber; i++){
		k = 0;
		
		for(s=0;s<12;s++)magicbuffer[s]='\0';
		fread(&c,sizeof(char),1,fp);
		while(c != '\n'){
		
			magicbuffer[k] = c;
			fread(&c,sizeof(char),1,fp);
			k++;
		}
		stringmagic=0;
		stringmagic = atoi(magicbuffer);
		
		char *string=malloc(sizeof(char)*stringmagic);
		for(j = 0; j < stringmagic; j++){
			fread(&c,sizeof(char),1,fp);
			string[j] = c;
		}
		libfuncs_newused(string);
	
		//free(string);
		for(j=0;j<stringmagic;j++)string[j]='\0';
	
		fread(&c,sizeof(char),1,fp);
	}
	
	//userfuncs
	fread(&c,sizeof(char),1,fp);
	
	i = 0;
    for(s=0;s<12;s++)magicbuffer[s]='\0';
	while(c != '\n'){
		
		magicbuffer[i] = c;
		fread(&c,sizeof(char),1,fp);
		i++;
	}
	magicnumber = atoi(magicbuffer);
	for(i = 0; i < magicnumber; i++){
		fread(&c,sizeof(char),1,fp);
		for(s=0;s<50;s++)buffer[s]='\0';
		j = 0;
		while(c != '\n'){
			
			
			buffer[j] = c;
			
			fread(&c,sizeof(char),1,fp);
			j++;
		}
		insertUser(buffer);
		
	}
	
	//instructions
	fread(&c,sizeof(char),1,fp);
	i = 0;
	while(c != '\n'){
		
		magicbuffer[i] = c;
		fread(&c,sizeof(char),1,fp);
		i++;
	}
	magicnumber = atoi(magicbuffer);

	for(i = 0; i < magicnumber; i++){
		fread(&c,sizeof(char),1,fp);
		j = 0;
		while(c != '\n'){
			
			
			buffer[j] = c;
			
			fread(&c,sizeof(char),1,fp);
			j++;
		}
		insertInst(buffer);
		codeSize = magicnumber;
	}
}

unsigned int getTotalGlobals(){
	int i=0,j;
	unsigned total=0;
	for(i;i<actualsize;i++){
		for(j=0;j<i;j++){
			if(globals[i]==globals[j]){
				break;
			}
			
		}
		if(i==j){
				total++;	
			}
		
	}

	return total;
}
void getglobals(){
	int i=0;
	int j=0;
	for(i;i<instruction_counter;i++){
		
			if(instructions[i].arg1.type==global_a){
				if(j==cursize){
					globals=realloc(globals,2*cursize*sizeof(int));
					cursize=2*cursize;
				}
				globals[j]=instructions[i].arg1.val;
				j++;
				actualsize++;
			}
		
		
			if(instructions[i].arg2.type==global_a){
				if(j==cursize){
					globals=realloc(globals,2*cursize*sizeof(int));
					cursize=2*cursize;
				}
				globals[j]=instructions[i].arg2.val;
				j++;
				actualsize++;
			}
		
	
			if(instructions[i].result.type==global_a){
				if(j==cursize){
					globals=realloc(globals,2*cursize*sizeof(int));
					cursize=2*cursize;
				}
				globals[j]=instructions[i].result.val;
				j++;
				actualsize++;
			}
		
			 
	}
	
}

void main(){
	globals=malloc(sizeof(int)*50);
	parsefile();
	initStack();
	getglobals();
	unsigned x;
	execute_cycle();
	int i;
	/*for(i=4040;i<4096;i++){		
		printf("timi %f in %d\n",stack[i].data.numVal,i);
	}*/

	
}
























