/*
name 
scope
type: userfunc
		libfunc
		global
		formal
		local
*/
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
}

int HashFunction(char * id){
	int id_value=0;
	while(*id != '\0'){
		id_value += (int)*id;
		id++;
	}
	
	
	return id_value/11;
}


node * insertNode(char *id,int scope,int line,enum tp type){
	
	int index=HashFunction(id);
	node * tmplast=malloc(sizeof(node));
	node * temp=malloc(sizeof(node));
	temp->name=malloc(strlen(id)+1);
	
	strcpy(temp->name,id);
	
	temp->scope=scope;
	temp->type=type;
	temp->line=line;
	temp->isActive=1;
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
					printf("name: %s  scope: %d type: %s isActive: %d line : %d list of args: ",traverse->name,traverse->scope,type_toString(traverse->type),traverse->isActive,traverse->line);
					
					while(argtemp!=NULL){
						printf("%s ",argtemp->name);
						argtemp=argtemp->nextargs;
					}
					printf("\n");
				}else{
					printf("name: %s  scope: %d type: %s isActive: %d line : %d \n",traverse->name,traverse->scope,type_toString(traverse->type),traverse->isActive,traverse->line);
				}
				traverse=traverse->next;
			}
		}
	}
}





void insert_libfunc(){
	
	insertNode("print",0,0,LIBFUNC);
	insertNode("input",0,0,LIBFUNC);
	insertNode("objectmemberkeys",0,0,LIBFUNC);
	insertNode("objecttotalmembers",0,0,LIBFUNC);
	insertNode("objectcopy",0,0,LIBFUNC);
	insertNode("totalarguments",0,0,LIBFUNC);
	insertNode("typeof",0,0,LIBFUNC);
	insertNode("strtonum",0,0,LIBFUNC);
	insertNode("sqrt",0,0,LIBFUNC);
	insertNode("cos",0,0,LIBFUNC);
	insertNode("sin",0,0,LIBFUNC);
	
}

int lookupLib(char * id,int line){
	
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				if(strcmp(traverse->name,id)==0 && traverse->type==1){
					return 1;
				}
				
				traverse=traverse->next;
			}
		}
	}
	return 0;
}

/*
	psaxnei na vrei an uparxei global metavliti
*/
int lookup_global(char *id){
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				if(strcmp(traverse->name,id)==0 && traverse->scope==0 && traverse->type!=USERFUNC){
					return 1;
					
				}
				
				traverse=traverse->next;
			}
		}
	}
	//printf("\nERROR GLOBAL VAR %s doesn't exist \n\n",id);
	return 0;
}


/*
 psaxnei na vrei an uparxei active metavliti se prohgoumena kai sto idio scope 

*/
int lookup_prevScope(char *id,int scope,int line){
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				/*
				idio h mikrotero scope kai den einai func kai einai active
				*/
				
				if(strcmp(traverse->name,id)==0 && traverse->scope==scope && traverse->type!=USERFUNC && traverse->isActive==1 && traverse->type!=FORMAL && scope!=0 ){
					printf("bkpt5\n");
					return 1;
					
				}
				else if(strcmp(traverse->name,id)==0 && traverse->scope==scope && traverse->type==USERFUNC && traverse->isActive==1 ){
					printf("bkpt1\n");
					return 3;
				}else if(strcmp(traverse->name,id)==0 && traverse->scope==scope && traverse->type!=USERFUNC && traverse->isActive==1 && traverse->type==FORMAL){
					printf("bkpt2\n");
					return 4;
				}
				else if(strcmp(traverse->name,id)==0 && traverse->type==USERFUNC && traverse->scope==scope && traverse->isActive==1 ){
						//printf("\nERROR:	 %s already in use as function in line %d!!!\n\n",id,line);
						printf("bkpt4\n");
						return 2;
				}
				
				
				traverse=traverse->next;
				scope--;
			}
		}
	}
	return 0;
}
	


/*
 vriskei an uparxei se ena sugkekrimeno scope idio active local id 
*/

int lookup_localRedef(char *id,int scope,int line){
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				if(strcmp(traverse->name,id)==0 && traverse->scope==scope && traverse->type!=USERFUNC && traverse->isActive==1){
					//printf("\nERROR LOCAL VAR %s redefinition in line %d\n\n",id,line);
					return 0;
					
				}
				
				traverse=traverse->next;
			}
		}
	}
	return 1;
}
/*
vriskei an uparxei idio active id sto sugkeekrimeno scope(xrisi me th def) 
*/

int lookup_currScope(char *id,int scope,int line){
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				if(strcmp(traverse->name,id)==0 && traverse->scope==scope && traverse->type!=USERFUNC && traverse->isActive==1){
					
					return 1;
					
				}
				
				traverse=traverse->next;
			}
		}
	}
	return 0;
}


int lookup_name(char *id,int scope,int line){
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				if(strcmp(traverse->name,id)==0 && traverse->scope==scope && traverse->isActive==1){
					if(traverse->type==USERFUNC){
						
						return 1;
					}
					else{
					
						return 2;
					}
					
					//return 1;
					
				}
				
				traverse=traverse->next;
			}
		}
	}
	return 0;
}

int lookup_func(char *id,int scope,int line){
	int i=0;
	node *traverse;
	for(i;i<1000;i++){
		if(HashTable[i]!=NULL){
			traverse=HashTable[i];
			while(traverse!=NULL){
				/*
				idio h mikrotero scope kai den einai func kai einai active
				*/
				if(strcmp(traverse->name,id)==0 && traverse->scope==scope && traverse->type==USERFUNC && traverse->isActive==1 ){
					return 1;
					
				}
				else{
					/*
					eimaste sto idio scope alla uparxei func me auto to id
					*/
					if(strcmp(traverse->name,id)==0 && traverse->type==USERFUNC && traverse->scope==scope && traverse->isActive==1 ){
						
						return 2;
					}
				}
				traverse=traverse->next;
				scope--;
			}
		}
	}
	return 0;
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

node * insertAnon(int scope,int line){
	char str[10];
	
	char *name=strdup("anonymous");
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

int lookupArgs(char * name){
	node * temp = lastFunc->arguments;
	while(temp != NULL){
		if(strcmp(temp->name,name) == 0){
			return 1;
		}
		temp = temp->nextargs;
	}
	return 0;
}
/*

int main(){
		
		insert_libfunc();
		print();
		
		
}
*/