#include "symtable.h"


node *HashTable[1000];
int an_count=0;
node *lastFunc;

char *type_toString(enum tp type){
	if(type==0)return "USERFUNC";
    if(type==1)return "LIBFUNC";
	if(type==2)return "GLOBAL";
	if(type==3)return "FORMAL";
	if(type==4)return "LOCAL";
	if(type==5)return "TMP";
}

int HashFunction(char * id){
	int id_value=0;
	
	while(*id != '\0'){
		id_value += (int)*id;
		id++;
	}
		
	return id_value/11;
}


node * insertNode(char *id,int scope,int line,enum tp type,int offset,enum scope_spc scope_space){
	
	int index=HashFunction(id);
	node * tmplast=malloc(sizeof(node));
	node * temp=malloc(sizeof(node));
	temp->name=malloc(strlen(id)+1);
	
	strcpy(temp->name,id);
	
	temp->scope=scope;
	temp->type=type;
	temp->line=line;
	temp->isActive=1;
	temp->offset=offset;
	temp->scope_space=scope_space;
	temp->next=NULL;
	//temp->nextargs=NULL;
	
	node * traverse=HashTable[index];
	
	if(HashTable[index]==NULL){
		HashTable[index]=malloc(sizeof(node));
		HashTable[index]=temp;
	}else{
		while(traverse->next!=NULL){
			traverse=traverse->next;
		}
		traverse->next=temp;
	}
	if(type==USERFUNC) lastFunc = temp;
	
	if(type==FORMAL){
		node *temporary = lastFunc->arguments;
		if(lastFunc->arguments == NULL){
			lastFunc->arguments = temp;
		}else{
			while(temporary->nextargs != NULL){
				temporary = temporary->nextargs;
			}
			temporary->nextargs = temp;
		}
	}
	/*if(type==FORMAL){
		if(last->arguments!=NULL){
			temp->nextargs=last->arguments;
			last->arguments=temp;
			
			
		}
		else{
			last->arguments=temp;
			
		}
		
	}*/
	
	return temp;
	
}



void print(){
	int i=0;
	node *traverse;
	node *argtemp;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				if(traverse->type==USERFUNC){
					argtemp=traverse->arguments;
					printf("name: %s  scope: %d type: %s isActive: %d line : %d list of args: offset: %d scopespace: %d",traverse->name,traverse->scope,type_toString(traverse->type),traverse->isActive,traverse->line,traverse->offset,traverse->scope_space);
					
					while(argtemp!=NULL){
						printf("%s ",argtemp->name);
						argtemp=argtemp->nextargs;
					}
					printf("iadress: %d  locals count :%d\n",traverse->iadress,traverse->locals_count);
				}else{
					printf("name: %s  scope: %d type: %s isActive: %d line : %d offset: %d scopespace: %d \n",traverse->name,traverse->scope,type_toString(traverse->type),traverse->isActive,traverse->line,traverse->offset,traverse->scope_space);
				}
				traverse=traverse->next;
			}
		}
	}
}





void insert_libfunc(){
	
	insertNode("print",0,0,LIBFUNC,-1,1);
	insertNode("input",0,0,LIBFUNC,-1,1);
	insertNode("objectmemberkeys",0,0,LIBFUNC,-1,1);
	insertNode("objecttotalmembers",0,0,LIBFUNC,-1,1);
	insertNode("objectcopy",0,0,LIBFUNC,-1,1);
	insertNode("totalarguments",0,0,LIBFUNC,-1,1);
	insertNode("typeof",0,0,LIBFUNC,-1,1);
	insertNode("strtonum",0,0,LIBFUNC,-1,1);
	insertNode("sqrt",0,0,LIBFUNC,-1,1);
	insertNode("cos",0,0,LIBFUNC,-1,1);
	insertNode("sin",0,0,LIBFUNC,-1,1);
	
}



/*
	isActive=0 gia to dothen scope
*/

int hide(int scope){
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				if(traverse->scope==scope){
					traverse->isActive=0;
				}
				
				traverse=traverse->next;
			}
		}
	}
	return 0;
}


int hide_Temp(){
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				if(traverse->type==TMP){
					traverse->isActive=0;
				}
				
				traverse=traverse->next;
			}
		}
	}
	return 0;
}

node * insertAnon(int scope,int line,int offset, enum scope_spc scope_space){
	char str[10]; 
	
	char *name=strdup("_anonymous");
	int index=0;

	an_count++;
	
	sprintf(str,"%d",an_count);

	name=(char *)realloc(name,strlen(name)+strlen(str));
	
	strcat(name,str);
	
	node * temp=malloc(sizeof(node));
	temp->name=malloc(strlen(name));
	
	index=HashFunction(name);

	strcpy(temp->name,name);
	
	temp->scope=scope;
	temp->type=USERFUNC;
	temp->line=line;
	temp->isActive=1;
	temp->offset=offset;
	temp->scope_space=scope_space;
	temp->next=NULL;
	
	node * traverse=HashTable[index];
	
	if(HashTable[index]==NULL){
		HashTable[index]=malloc(sizeof(node));
		HashTable[index]=temp;
	}else{
		while(traverse->next!=NULL){
			traverse=traverse->next;
		}
		traverse->next=temp;
	}
	
	lastFunc=temp;
	return temp;
	
}

node * lookup_CertScope(char *name, int scope){
	int i = HashFunction(name);
	node * temp = HashTable[i];
	while(temp != NULL){
		if((strcmp(name,temp->name)==0) && (scope == temp->scope) && (temp->isActive == 1)) return temp;
		temp = temp->next;
	}
	return NULL;
}

node * lookup_AllScopes(char *name, int scope){
	int i = HashFunction(name);
	while(scope >=0){
		node * temp = HashTable[i];
		while(temp != NULL){
			if((strcmp(name,temp->name)==0) && (scope == temp->scope) && (temp->isActive == 1)) return temp;
			temp = temp->next;
		}
		scope--;
	}
	return NULL;
}

node * lookup_Temp(char *name){
	int i=0;
	for(i; i<1000; i++){
		node * temp = HashTable[i];
		while(temp != NULL){
			if((temp->isActive == 0 ) && (temp->type==TMP)&& (strcmp(temp->name,name)==0 )) return temp;
			temp = temp->next;
		}
	}
	return NULL;
}
