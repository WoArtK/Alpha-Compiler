#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum tp{USERFUNC,LIBFUNC,GLOBL,FORMAL,LOCL};

typedef struct nod{
	char *name;
	int scope;
	int line;
	enum tp type;
	struct nod *next;
	struct nod *arguments; //krataei ti lista me ta arguments
	struct nod *nextargs;
	int isActive;
}node;



char *type_toString(enum tp type);

int HashFunction(char * id);

node * insertNode(char *id,int scope,int line,enum tp type);

void print();

void insert_libfunc();

int lookupLib(char * id,int line);

int lookup_prevScope(char *id,int scope,int line);
int lookup_localRedef(char *id,int scope,int line);
int lookup_currScope(char *id,int scope,int line);
int lookup_name(char *id,int scope,int line);
node * insertAnon(int scope,int line);

int hide(int scope);


int lookup_global(char *id);

