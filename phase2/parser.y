%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "symtable.h"
extern int yylex(void);
extern int yylineno;
extern char *yytext;
int scope=0;
int funcDef=0;	//flag gia anoixto orismo sunarthshs (active vars)
int funCall=0;
int loop=0;
//node *last_func=malloc(sizeof(node));
%}

%error-verbose
%start program
%union
{
	int intval;
	char* strval;
	float realval;
}
%token <intval> INTEGER;
%token <strval> STRING;
%token <strval> WHILE FOR IF ELSE FUNCTION RETURN BREAK CONTINUE AND OR NOT LOCAL TRUE FALSE NIL PLUS MINUS MUL MOD DIV EQUALS N_EQL PLUSPLUS MINUSMINUS 
%token <strval> ID;
%token <strval> ASSIGN;
%token <realval> REALNUMBER;
%token <strval> GRTR_EQL LESS_EQL GRTR LESS L_BRACKET R_BRACKET L_BRACE R_BRACE L_PAR R_PAR COMMA SEMCOL COLON DOT DBL_DOT WRONG_DEFINITION GLOB

%type <strval> stmt 
%type <intval> expr
%type <strval> ifstmt whilestmt forstmt returnstmt block funcdef
%type <strval> assignexpr term
%type <strval> lvalue primary call objectdef const member
%type <strval> elist callsuffix normcall methodcall indexed indexedelem

%left ASSIGN
%left OR
%left AND
%nonassoc EQUALS N_EQL
%nonassoc GRTR GRTR_EQL LESS LESS_EQL
%left PLUS MINUS
%left  MUL DIV MOD
%left NOT PLUSPLUS MINUSMINUS
%left DOT DBL_DOT
%left L_BRACKET R_BRACKET
%left L_PAR R_PAR



%%
program: stmt program 
	|	{
			printf("finished\n");
		}
        ;
stmt:	 expr SEMCOL {printf("stmt <- Expression \n");}
	| ifstmt {printf("stmt <- ifstatement\n");}
	| whilestmt {printf("stmt <- whilestatement\n");}
	| forstmt {printf("stmt <- forstatement\n");}
	| returnstmt {if(funcDef==0)printf("\n Error return outside a function \n\n"); printf("stmt <- retstatement\n");}
	| BREAK  SEMCOL { if(loop==0)printf("\n Error break not in an active loop \n\n"); printf("stmt <- break\n");}
	| CONTINUE SEMCOL {if(loop==0)printf("\n Error Continue not in an active loop \n\n");  printf("stmt <- continue\n");}
	| block {printf("stmt <- block\n");}
	| funcdef {printf("stmt <- funcdef\n");}
	|SEMCOL
;
expr: assignexpr { printf("expr <- assign expression\n");}
        | expr PLUS expr {printf("expr <- expression  + expression \n");}
	| expr MINUS expr {printf("expr <- expression - expression \n");}
	| expr MUL expr { printf("expr <- expression * expression  \n");}
	| expr DIV expr {printf("expr <- expression / expression  \n");}
	| expr MOD expr {printf("expr <- expression % expression \n");}
	| expr GRTR expr {printf("expr <- expression > expression %d>%d \n");}
	| expr GRTR_EQL expr	{printf("expr <- expression >= expression  \n");}
	| expr LESS expr	{printf("expr <- expression  < expression  \n");}
	| expr LESS_EQL expr	{printf("expr <- expression <= expression  \n");}
	| expr EQUALS expr		{printf("expr <- expression == expression \n");}
	| expr N_EQL expr	{printf("expr <- expression != expression  \n");}
	| expr AND expr		{printf("expr <- expression && expression  \n");}
	| expr OR expr		{printf("expr <- expression || expression \n");}

	| term { 
			
		
	printf("expr <- term\n");}
	;
term: L_PAR expr R_PAR {printf("term <- (expr)\n");}
	| MINUS expr { printf("term <- -expr\n");}
	| NOT expr { printf("term <- oxiexpr\n");}
	| PLUSPLUS lvalue {if(lookupLib(yylval.strval,yylineno)==1 || lookup_func(yylval.strval,scope,yylineno)==1 || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot ++value to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}	printf("term <- ++lvalue\n");}
	| lvalue{
		if(lookupLib(yylval.strval,yylineno)==1 || lookup_func(yylval.strval,scope,yylineno)==1 || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot  value++ to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}
	} PLUSPLUS {printf("term <- lvalue++\n");}
	| MINUSMINUS lvalue {if(lookupLib(yylval.strval,yylineno)==1 || lookup_func(yylval.strval,scope,yylineno)==1 || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot  --value to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}    printf("term <- --lvalue\n");}
	| lvalue{
		if(lookupLib(yylval.strval,yylineno)==1 || lookup_func(yylval.strval,scope,yylineno)==1 || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot value -- to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}
		
	} MINUSMINUS {printf("term <- lvalue--\n");}
	| primary { printf("term <- termprimary\n");}
	;
assignexpr: lvalue{
					if(lookupLib(yylval.strval,yylineno)==1 || (lookup_func(yylval.strval,scope,yylineno)==1 && lookup_localRedef(yylval.strval,scope,yylineno)==1) || lookup_prevScope(yylval.strval,scope,yylineno)==2){
						printf("\nERROR:  Cannot assign value to %s in line %d!!!\n\n",yylval.strval,yylineno);
					}
					} ASSIGN expr {
					
			printf("assignexpr <- lvalue=expr\n");};
primary: lvalue {printf("primary <- lvalue\n");}
	| call {printf("primary <- call\n");}
	| objectdef {printf("primary <- objectdef\n");}
	| L_PAR funcdef R_PAR {printf("primary <- (funcdef)\n");}
	| const {printf("primary <- const\n");}
	;
	
	
lvalue: ID {
				
	
					
						if(funcDef>0){
							
							if(lookup_currScope(yytext,scope,yylineno)==0){
								
								if(lookup_prevScope(yytext,scope,yylineno)==1){
									if((funcDef-1)>0){
										printf("\nERROR variable %s is not accessible in line : %d\n\n",yytext,yylineno);
									}
									else if(loop==0 && lookup_global(yytext)==0){
										printf("\nERROR variable %s is not accessible in line : %d\n\n",yytext,yylineno);
									}
									else{
										printf("einai i else edw\n");
									}
									
								}else if( lookup_prevScope(yytext,scope,yylineno)==2){
									printf("\nERROR:	 %s already in use as function in line %d!!!\n\n",yytext,yylineno);
								}else if(lookup_prevScope(yytext,scope,yylineno)==4){
									
								}
								else if(lookup_prevScope(yytext,scope,yylineno)!=3){
									if(lookup_global(yytext)==0 ){
									insertNode(yytext,scope,yylineno,LOCL);
									}
								}
								
								
							}
	
						}else{
								
							if(lookup_global(yytext)==0 && lookup_prevScope(yytext,scope,yylineno)==0){
							
								if(scope==0){
									insertNode(yytext,scope,yylineno,GLOBL);
								}
								else{
									insertNode(yytext,scope,yylineno,LOCL);		
								}
							}
							printf("after %d\n",yylineno);
						}
					
				
					
					
				
				
				printf("lvalue <- identifier\n"); 
			} 
	|GLOB ID {
				if(lookup_global(yytext)==0){
					printf("\nERROR GLOBAL VAR %s doesn't exist \n\n",yytext);
				}
				printf("lvalue <- global id\n");
			}  
	|LOCAL ID{ 
	             if(scope==0){
					 if(lookup_localRedef(yytext,scope,yylineno)==1){
						insertNode(yytext,scope,yylineno,GLOBL);
					 }
					 else{
						printf("\nERROR LOCAL VAR %s redefinition in line %d\n\n",yytext,yylineno);
					 }
				
				}else{
					if(lookup_localRedef(yytext,scope,yylineno)==1){
						insertNode(yytext,scope,yylineno,LOCL);
					
					}
					else{
						printf("\nERROR LOCAL VAR %s redefinition in line %d\n\n",yytext,yylineno);
					}
				}
				 
				
				printf("lvalue <- |LOCAL ID\n");
			
			}
			
		
	| member {printf("lvalue <- member\n");}
	;
member: lvalue DOT ID {printf("member <- lvalue.identifier\n");}
	| lvalue L_BRACKET expr R_BRACKET {printf("member <- lvalue expr\n");}
	| call DOT ID {printf("member <- call.identifier\n");}
	| call L_BRACKET expr R_BRACKET {printf("member <- call expr\n");}
	;
call: call L_PAR elist R_PAR {printf("call <- (elist)\n");}
	|lvalue callsuffix {printf("call <- lvaluecallsuffix\n");} 
	|L_PAR funcdef R_PAR L_PAR elist R_PAR {printf("call <- (funcdef)(elist)\n");}
	;
callsuffix: normcall {printf("callsuffix <- normcall\n");}
	| methodcall {printf("callsuffix <- methodcall\n");}
	;
normcall: L_PAR elist R_PAR {printf("normcall <- (elist)\n");};
methodcall: DBL_DOT ID L_PAR elist R_PAR {printf("methodcall <- method call\n");};
elist:	expr			{ printf("elist <- Expr\n");}
	| elist COMMA expr	{printf("elist <- Expr,..,Expr\n");} 
	|			{printf("elist <- Empty Elist\n");}
	;
objectdef:	L_BRACKET elist R_BRACKET	{printf("objectdef <- [ Elist ] \n");}
	| L_BRACKET indexed R_BRACKET		{printf("objectdef <- [ Indexed ] \n");}
	;
indexed:	indexedelem		{printf("indexed <- Idexedelem\n");}
	|indexed COMMA indexedelem	{printf("indexed <- indexedelem , indexedelem\n");}
	;

indexedelem:	L_BRACE expr COLON expr R_BRACE	{printf("indexedelem <- { Expr : Expr }\n");};
temp_id: ID{ 
				if(lookupLib(yytext,yylineno)==0){
					if(lookup_name(yytext,scope,yylineno)==0){
						insertNode(yytext,scope,yylineno,USERFUNC);
						
					}
					else if(lookup_name(yytext,scope,yylineno)==1){
						printf("\nERROR func %s redefinition in line %d\n\n",yytext,yylineno);
					}
					else{
						printf("\nERROR in line %d %s is already defined as var\n\n",yylineno,yytext);
					}
								
				}
				else{
					printf("\nERROR:	shadowing is not permitted in line %d!!!\n\n",yylineno);
				}
		
		  }
	|{ insertAnon(scope,yylineno); printf("temp_id <- empty\n");}
;
temp_st: temp_st stmt {}
	|{}
;
block: L_BRACE {scope++;}temp_st R_BRACE{hide(scope);scope--;} {printf("block\n");};
funcdef: FUNCTION temp_id {funcDef++; } L_PAR idlist R_PAR block {funcDef--;printf("funcdef <- function def \n");};
const:	INTEGER			{printf("const <- |NUMBER %s\n",yytext);} 
	| REALNUMBER		{printf("const <- |REALNUMBER %s\n",yytext);}
	| STRING		{printf("const <- |STRING\n");}
	| NIL			{printf("const <- |NIL\n");}
	| TRUE			{printf("const <- |TRUE\n");}
	| FALSE			{printf("const <- |FALSE\n");}
	;
idlist:ID {	printf("to id einai %s\n",yytext);

			if(lookupLib(yytext,yylineno)==1){
				printf("\nERROR: Library function used as argument in line %d \n\n",yylineno);
			}else{
				insertNode(yytext,scope+1,yylineno,FORMAL);
			}

			printf("idlist <- ID\n");
			}
	|idlist COMMA ID {
		
		if(lookupLib(yytext,yylineno)==1){
			printf("\nERROR: Library function used as argument in line %d \n\n",yylineno);
		}else if(lookupArgs(yytext)==1){
			printf("\n ERROR : Argument %s redefinition in line %d \n\n",yytext,yylineno);
		}else{
			insertNode(yytext,scope+1,yylineno,FORMAL);
			
		}

		printf("idlist <- idlist comma \n");
		}
	|{;}
;
ifstmt: IF L_PAR{} expr R_PAR stmt{printf("ifstmt <- if()\n");}
	| ELSE stmt {printf("ifstmt <- ifelse stmt \n");}
	;
whilestmt: WHILE L_PAR{ scope++;loop++;} expr R_PAR stmt {scope--;loop--;printf("whilestmt <- while()stmt\n");};
forstmt: FOR L_PAR{scope++;loop++;} elist SEMCOL expr SEMCOL elist R_PAR stmt {loop--;scope--;printf("forstmt <- |FOR (ELIST;EXPR;ELIST)STMT\n");};
returnstmt: RETURN SEMCOL {printf("returnstmt <- return;\n");}
	|RETURN expr SEMCOL {printf("returnstmt <- RETURN EXPR;\n");};
%%
int yyerror (const char * YaccProvidedMessage)
{	
	if ((strstr(YaccProvidedMessage,"$end")))
		printf("Unexpected reach of the EOF.\n");
	else
		printf("%s -- in line %d , token %s \n ",YaccProvidedMessage,yylineno,yytext);
	return 0;
}


int main(int argc,char **argv)
{
	
	insert_libfunc();

	
	yyparse();
	print();
	return 0;
}
