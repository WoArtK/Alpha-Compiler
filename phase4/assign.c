#include "avm.h"



void execute_assign(instruction* instr){
	
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*) 0);
	avm_memcell* rv=avm_translate_operand(&instr->arg1,&ax);

	//assert(	lv && 	(	(&stack[N]>=lv)	&&	(lv>&stack[top]) || (lv==&retval)	)	);
	
	if(instr->arg1.type!=number_a){
		//assert(rv && ( (&stack[N] >= rv) && (rv>&stack[top]) || (rv==&retval)));
	}
	assert(rv);
	
	avm_assign(lv,rv);
}

  userfuncs *avm_getfuncinfo(unsigned address){

	  return &funcs[address];
  }
  void avm_error(char *s){
	  printf("%s \n",s);
	  executionFinished=1;
	  
  }
  
  
 unsigned char DispatchRv(avm_memcell *rv1,avm_memcell *rv2){
	
	 unsigned result=0;
	
		if(rv1->type==number_m){
			result=rv1->data.numVal==rv2->data.numVal;
			return result;
		}
		if(rv1->type==string_m){
			 
			if(strcmp(rv1->data.strVal,rv2->data.strVal)==0){
				result =1;
			}
			 
			return result;
		}
		
	
 }
void execute_jeq(instruction* instr){
	assert(instr->result.type==label_a);

	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&bx);
	
	unsigned char result=0;
	
	if(rv1->type==undef_m || rv2->type==undef_m){
		avm_error("'undef' involved in equality!\n");
	}else if(rv1->type==nil_m || rv2->type==undef_m){
			result= ((rv1->type==nil_m) && (rv2->type==nil_m));
	}else if(rv1->type==bool_m || rv2->type==bool_m){
			result= (avm_tobool(rv1)==avm_tobool(rv2));
	}else if(rv1->type!=rv2->type){
		avm_error("%s == %s is illegal!\n");//,typeStrings[rv1->type],typeStrings[rv2->type]);
	}else{
		result=DispatchRv(rv1,rv2);
	
	}
	
	if(!(executionFinished==1) && result){
		pc=instr->result.val;
	}
	
}
  void execute_jne (instruction* instr ){
	  assert(instr->result.type==label_a);

	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&bx);
	
	unsigned char result=0;
	
	
	if(rv1->type==undef_m || rv2->type==undef_m){
		avm_error("'undef' involved in equality!\n");
	}else if(rv1->type==nil_m || rv2->type==undef_m){
			result= ((rv1->type==nil_m) && (rv2->type==nil_m));
	}else if(rv1->type==bool_m || rv2->type==bool_m){
			result= (avm_tobool(rv1)==avm_tobool(rv2));
	}else if(rv1->type!=rv2->type){
		avm_error("%s == %s is illegal!\n");//,typeStrings[rv1->type],typeStrings[rv2->type]);
	}else{
		result=DispatchRv(rv1,rv2);
		
	}
	
	if(!(executionFinished==1) && !result){
		pc=instr->result.val;
	}
  }
  
  void execute_jle (instruction* instr){
	  assert(instr->result.type==label_a);

	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&bx);
	
	unsigned char result=0;
	
	
	if(rv1->type==undef_m || rv2->type==undef_m){
		avm_error("Not a number in comparison\n");
	}else if(rv1->type==nil_m || rv2->type==undef_m){
			avm_error("Not a number in comparison\n");
	}else if(rv1->type==bool_m || rv2->type==bool_m){
		avm_error("Not a number in comparison\n");
	}else if(rv1->type!=rv2->type){
	avm_error("Not a number in comparison\n");//,typeStrings[rv1->type],typeStrings[rv2->type]);
	}else{
		result = rv1->data.numVal <= rv2->data.numVal;
	
	}
	
	if(!(executionFinished==1) && result){
		pc=instr->result.val;
	}
	  
  }
  void execute_jge (instruction* instr){
	    assert(instr->result.type==label_a);

	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&bx);
	
	unsigned char result=0;
	
	
	if(rv1->type==undef_m || rv2->type==undef_m){
		avm_error("Not a number in comparison\n");
	}else if(rv1->type==nil_m || rv2->type==undef_m){
			avm_error("Not a number in comparison\n");
	}else if(rv1->type==bool_m || rv2->type==bool_m){
		avm_error("Not a number in comparison\n");
	}else if(rv1->type!=rv2->type){
	avm_error("Not a number in comparison\n");//,typeStrings[rv1->type],typeStrings[rv2->type]);
	}else{
		result = rv1->data.numVal >= rv2->data.numVal;
		
	}
	
	if(!(executionFinished==1) && result){
		pc=instr->result.val;
	}
	  
  }
  void execute_jlt (instruction* instr){
	    assert(instr->result.type==label_a);

	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&bx);
	
	unsigned char result=0;
	
	
	if(rv1->type==undef_m || rv2->type==undef_m){
		avm_error("Not a number in comparison\n");
	}else if(rv1->type==nil_m || rv2->type==undef_m){
			avm_error("Not a number in comparison\n");
	}else if(rv1->type==bool_m || rv2->type==bool_m){
		avm_error("Not a number in comparison\n");
	}else if(rv1->type!=rv2->type){
	avm_error("Not a number in comparison\n");//,typeStrings[rv1->type],typeStrings[rv2->type]);
	}else{
		result = rv1->data.numVal < rv2->data.numVal;
		
	}
	
	if(!(executionFinished==1) && result){
		pc=instr->result.val;
	}
	  
	  
  }
  void execute_jgt (instruction* instr){
	    assert(instr->result.type==label_a);

	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&bx);
	
	unsigned char result=0;
	
	
	if(rv1->type==undef_m || rv2->type==undef_m){
		avm_error("Not a number in comparison\n");
	}else if(rv1->type==nil_m || rv2->type==undef_m){
			avm_error("Not a number in comparison\n");
	}else if(rv1->type==bool_m || rv2->type==bool_m){
		avm_error("Not a number in comparison\n");
	}else if(rv1->type!=rv2->type){
	avm_error("Not a number in comparison\n");//,typeStrings[rv1->type],typeStrings[rv2->type]);
	}else{
		result = rv1->data.numVal >rv2->data.numVal;
	
	}
	
	if(!(executionFinished==1) && result){
		pc=instr->result.val;
	}
  }
  
  void execute_jump (instruction* instr){
	  assert(instr!=NULL);
	 pc=instr->result.val;
  }
 

 



  void execute_nop (instruction*h){}
  void avm_warning(char * gamiesai){}
library_func_t avm_getlibraryfunc(char *c){}




//helper function get str length of int
int getl(double value){
  int l=!value;
  while(value){ l++; value/=10; }
  return l;
}


char* number_tostring(avm_memcell* m){
	int size=getl(m->data.numVal);
	char *ret =malloc(size);
	sprintf(ret,"%f",m->data.numVal);
	return ret;
	
}

 char* string_tostring(avm_memcell*m){
	 assert(m->data.strVal!=NULL);
	 return m->data.strVal;	 
 }
 
 char* bool_tostring(avm_memcell* m){
	
	  unsigned char value=m->data.boolVal;
	  char *true=strdup("true");
	  char *false=strdup("false");
	  if(value==1)return true;
	  return false;
 }
 
 char* table_tostring(avm_memcell*m){
	 
	 
 }//todo
 
 char* userfunc_tostring(avm_memcell*m){
	 int index =m->data.funcVal;
	 int i=0;
	 for(i;i<userfunc_counter;i++){
		 if(funcs[i].taddress==index){
			 break;
		 }
	 }
	 char t[12];
	 sprintf(t," %d",funcs[i].taddress);
	 char *name=strdup(strcat(funcs[i].id,t));
	 assert(name!=NULL);
	 return name;
 }
 
 char* libfunc_tostring(avm_memcell*m){
	
	 assert(m->data.libfuncVal!=NULL);
	 return m->data.libfuncVal;
 }
 char* nil_tostring(avm_memcell*m){
	 assert(m!=NULL);
	 char *n=strdup("NILL");
	 return n;
 }
 char* undef_tostring(avm_memcell*m){
	 assert(m!=NULL);
	 char *n=strdup("undef");
	 return n;
	 
 }


//	18

void avm_assign	(avm_memcell* lv, avm_memcell*rv){
	
	if(lv==rv)	return;
	if(lv->type==table_m && rv->type==table_m && lv->data.tableVal==rv->data.tableVal){	
	
		

		return;
	}
	
	if(rv->type ==undef_m)	avm_warning("assigning	from	'undef'	content!\n");
	avm_memcellclear(lv);

	memcpy(lv,rv,sizeof(avm_memcell));
		if(rv->type==table_m){
			avm_tableincrefcounter(lv->data.tableVal);
			
		}	
		
	}
