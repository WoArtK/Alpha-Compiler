#include <string.h>
#include "temporaries.h"

int temp_count=-1;

char *newtempname(){
	char str[10]; 
	char *name=strdup("_t");
	
	temp_count++;
	sprintf(str,"%d",temp_count);
	name=(char *)realloc(name,strlen(name)+strlen(str));
	strcat(name,str);
	return name;
}

node *newtemp(){
	
	node *temp=lookup_Temp(newtempname());
	node *ret;
	if(temp != NULL){
		node *temp2;
		temp2 = malloc(sizeof(node));
		temp2->name = malloc(strlen(temp->name));
		strcpy(temp2->name,temp->name);
		temp2->isActive=1;
		temp2->scope_space=currscopespace();
		temp2->offset=currscopeoffset();
		return temp2;
		
	}else{
		temp_count--;
		inccurrscopeoffset();
		ret=insertNode(newtempname(),-1,-1,TMP,currscopeoffset(),currscopespace());
		
		return ret;
	}
	
}

void resettemp(){
	temp_count=-1;
	hide_Temp();
}

