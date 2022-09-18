
%{
//#define YY_DECL int alpha_yylex(void* yyval)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "y.tab.h"
extern YYSTYPE yylval;

int count=0;
int com_counter=0;
char *str;
typedef struct token{
	int line; //line number
	int numToken;//token number
	char *token_value; //token content
	char *type; //type eg. operator,keyword
	struct token *next; 
	struct token *head;
} alpha_token_t ;


alpha_token_t * insert(alpha_token_t * list,int line,int numToken,char *token_value,char *type);
void print_list(alpha_token_t *list);
%}
%option noyywrap
%option yylineno



intconst (0[xX][0-9a-fA-F]+)|[0-9]+

id [a-zA-Z][a-zA-Z_0-9]*


realconst ([0-9]+)\.([0-9](e|E)?[0-9]*)

whitespace [\r\n \t\v]

commentline "//".*

wrong_identifier [0-9][a-zA-Z_0-9]*



%x comment1 string
%% 
"or"		{return OR;}
"and"		{return AND;}
"not"		{return NOT;}
"for"		{return FOR;}
"return"	{return RETURN;}
"continue"	{return CONTINUE;}
"break"		{return BREAK;}
"while"		{return WHILE;} 
"function" 	{return FUNCTION;}
"="             {return ASSIGN;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return MUL;}
"/"             {return DIV;}
"%"             {return MOD;}
"=="            {return EQUALS;}
"!="            {return N_EQL;}
"++"            {return PLUSPLUS;}
"--"            {return MINUSMINUS;}
">"             {return GRTR;}
"<"             {return LESS;}
">="            {return GRTR_EQL;}
"<="            {return LESS_EQL;}
"if"		{return IF;}
"local"		{return LOCAL;}
"else"		{return ELSE;}
"{"             {return L_BRACE;}
"}"             {return R_BRACE;}
"["             {return L_BRACKET;}
"]"             {return R_BRACKET;}
"("             {return L_PAR;}
")"             {return R_PAR;}
";"             {return SEMCOL;}
","             {return COMMA;}
":"             {return COLON;}
"."             {return DOT;}
".."            {return DBL_DOT;}
"::"		{return GLOB;}

{id} {yylval.strval=strdup(yytext);return ID;}
{intconst} {yylval.intval = atoi(yytext);return INTEGER;}
{whitespace} {;}
{realconst} {yylval.realval=atof(yytext);return REALNUMBER;}
{commentline} {;}
{wrong_identifier} {;}
<INITIAL><<EOF>> {return EOF;}
"/*" { com_counter++;count++;BEGIN(comment1);}
<comment1>{
"/*"           { com_counter++;count++;}
"*"+"/"        { com_counter--;if(com_counter==0)BEGIN(INITIAL);}
"*"+           ;
  [^/*\n]+      ;  
  [/]           ; 
  \n             ; 

}
<comment1><<EOF>> {if(com_counter!=0)printf("UNCLOSED COMMENT %d \n",com_counter);BEGIN(INITIAL);}
\"  { str=NULL;BEGIN(string);}

<string>\" { count++;
			if(str==NULL)str=strdup("");
			yylval.strval=strdup(str);
			BEGIN(INITIAL);
			return STRING;
			}
<string>\\n {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\n';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\n';
				}
			}
<string>\\t {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\t';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\t';
				}
			}
<string>\\\" { 
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\"';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\"';
				}
			 }  

<string>\\a {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\a';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\a';
				}

			}
			

<string>\\b {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='b';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='b';
				}
				printf("WARNING: Illegal escape character b in line %d \n:",yylineno);
			}
<string>\\m {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='m';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='m';
				}
				printf("WARNING: Illegal escape character  m in line %d \n:",yylineno);
			}		
			
<string>\\f {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\f';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\f';
				}

			}
			
			
<string>\\r {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\r';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\r';
				}

			}
			
			
<string>\\v {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\v';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\v';
				}

			}
             
			 
<string>\\' {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\'';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\'';
				}

			}
			
			
<string>\\? {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\?';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\?';
				}

			}
<string>\\e {
				if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\e';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\e';
				}

			}
<string>[^\\\n\"\\\t\\\\]+ {if(str==NULL){
							str=strdup(yytext);
						}else{
							str=realloc(str,strlen(str)+strlen(yytext));
							//printf("%c\n",*(str+strlen(str)-2));
							strcat(str,yytext);
							str[strlen(str)+1]='\0';
						}
	
	
	}
<string>\\\\ {
		if(str!=NULL){
					str=realloc(str,strlen(str)+2);
					str[strlen(str)]='\\';
					str[strlen(str)+1]='\0';
				}else{
					str=malloc(sizeof(char));
					str[0]='\\';
				}
}
<string><<EOF>> {printf("unclosed string in line %d \n",yylineno);BEGIN(INITIAL);return EOF;}
.	{ printf("UNDEFINED CHARACTER ON LINE %d : %s \n",yylineno,yytext);}
%%

alpha_token_t * insert(alpha_token_t * list,int line,int numToken,char *token_value,char *type){
	int size;
	alpha_token_t *temp;
	alpha_token_t *token1 = malloc(sizeof(alpha_token_t));
	token1->line=line;
	token1->numToken=numToken;
	size=strlen(token_value)+2;
	token1->token_value=malloc(strlen(token_value)+2);
	token1->token_value[0]='\"';
	strncpy((token1->token_value)+1,token_value,strlen(token_value));
	token1->token_value[size-1]='\"';
	token1->token_value[size]='\0';
	token1->type=malloc(strlen(type)+1);
	strcpy(token1->type,type);
	token1->next = NULL;
	temp = list->head;
	if(temp == NULL){
		list->head = token1;
	}else{
		while(temp->next != NULL) temp = temp->next;
		temp->next = token1;
	}
	return token1;
	
}

void print_list(alpha_token_t *list){
	alpha_token_t *tmp = list->head;
	while(tmp!=NULL){
		printf("%d: #%d     %s     %s \n",tmp->line,tmp->numToken,tmp->token_value,tmp->type);
		tmp = tmp->next;
	}
}





