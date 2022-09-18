#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum tp{USERFUNC,LIBFUNC,GLOBL,FORMAL,LOCL,TMP};

enum scope_spc{program_var,function_local,formal_arg};

//enum var_type{String,Boolean,Number,Nil,FunctionAdress,LibraryFunction,Table};


typedef struct nod{
	char *name;
	int scope;
	int line;
	enum tp type;
	enum scope_spc scope_space;
	int offset;
	struct nod *next;
	struct nod *arguments; //krataei ti lista me ta arguments
	struct nod *nextargs;
	int locals_count;
	unsigned iadress;
	int isActive;
	/*struct var{
		void *value;
		enum var_type;
	}*/
}node;



char *type_toString(enum tp type);

int HashFunction(char * id);

node * insertNode(char *id,int scope,int line,enum tp type,int offset,enum scope_spc scope_space);


void print();

void insert_libfunc();

node * insertAnon(int scope,int line,int offset, enum scope_spc scope_space);

int hide(int scope);
int hide_Temp();
node * lookup_CertScope(char *name, int scope);
node * lookup_AllScopes(char *name, int scope);
node * lookup_Temp();


