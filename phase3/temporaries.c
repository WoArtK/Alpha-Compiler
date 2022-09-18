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
	
	if(temp != NULL){
		temp->isActive=1;
		return temp;
	}else{
		temp_count--;
		return insertNode(newtempname(),-1,-1,TMP,-1,1);
		
	}
	
}

void resettemp(){
	temp_count=-1;
	hide_Temp();
}

