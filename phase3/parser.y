%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "quads.h"
#include <assert.h>


extern int yylex(void);
extern int yylineno;
extern char *yytext;
int scope=0;
int funcDef=0;	//flag gia anoixto orismo sunarthshs (active vars)
int funCall=0;
int loop=0;
int flag=0;
expr_e *elist_tmp = NULL;
expr_e *indexed_tmp = NULL;
int t=0;


//node *last_func=malloc(sizeof(node));
%}

%error-verbose
%start program
%union
{
	int intval;
	char* strval;
	float realval;
	 expr_e *exprval;
	 int method;
	 char *name;
	 expr_e *elist;
	 struct {
		 int test;
		 int enter;
		 
	 }forprefix;
	
}


%token <strval> WHILE FOR BREAK CONTINUE;
%token <strval> IF ELSE;
%token <strval>	FUNCTION RETURN ;
%token <strval> AND OR NOT ;
%token <strval> LOCAL TRUE FALSE NIL ;
%token <strval> '+' '-' '*' '%' '/' ;
%token <strval> EQUALS NOT_EQUALS PLUS_PLUS MINUS_MINUS ;
%token <strval> ID;
%token <strval> '=';
%token <intval> INTEGER;
%token <strval> STRING;
%token <realval> REALNUMBER;
%token <strval> GREATER_EQUAL LESS_EQUAL '>' '<' '[' ']' ';' '{' '}' '(' ')' ',' ':' '.' DOUBLE_DOT GLOB;

%type <strval> stmt assignexpr term ;
%type <exprval> expr elist ;
%type <strval> forp returnstmt block funcdef ifstmt whilestmt forstmt;
%type <strval> lvalue primary call objectdef const member indexed indexedelem callsuffix normcall methodcall ;
%type <intval> M N;
%left '=';
%left OR;
%left AND;
%nonassoc EQUALS NOT_EQUALS;
%nonassoc '>' GREATER_EQUAL '<' LESS_EQUAL;
%left '+' '-';
%left  '*' '/' '%';
%left NOT PLUS_PLUS MINUS_MINUS;
%left '.' DOUBLE_DOT;
%left '[' ']';
%left '(' ')';



%%
program: stmt program 
	|	{
			printf("finished flag=%d\n\n\n",flag);
			
		}
        ;
stmt:	expr{elist_tmp=NULL; indexed_tmp = NULL;	printf("$expr  \n");} ';' {printf("Expression to Statement\n"); resettemp();}
	| ifstmt {	
				printf("ifstatement to Statement\n"); resettemp();} 
	| whilestmt {printf("whilestatement to Statement\n");resettemp();}
	| forstmt {printf("forstatement to Statement\n");resettemp();}
	| returnstmt { if(funcDef==0)printf("\n ERROR in line %d . Return outside function definition \n\n",yylineno);
					printf("retstatement to Statement\n");
						resettemp();
						}
	| BREAK  ';' { 			if(loop>0){
							emit_Realop(jump,NULL,NULL,0);
							push(&breakstack,nextquad());
							
							}else{
							printf("\n\nBreak not inside loop in line %d \n\n",yylineno);	
							return 0;
							}
							 printf("break to Statement\n");}
	| CONTINUE ';' { 
					if(loop>0){
					emit_Realop(jump,NULL,NULL,0); 
					push(&continuestack,nextquad());
					}else{
							printf("\n\nContinue not inside loop in line %d \n\n",yylineno);	
							return 0;
							}
					printf("continue to Statement\n");}
	| block {printf("block to Statement\n");resettemp();}
	| funcdef {printf("funcdef to Statement\n");resettemp();}
	|';'
;


expr: assignexpr { 
		
		
		
		printf("assign expression to expression\n");}
    | expr '+' expr {if(check_if_arithm($<exprval>1,$<exprval>3)==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}
				
							
					$<exprval>$ =newexpr(arithmexpr_e);
					//check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
					  $<exprval>$->symbol=newtemp();
					 emit(add,$<exprval>1,$<exprval>3, $<exprval>$, yylineno);

				printf("expression  + expression to expression\n");
				}
	| expr '-' expr {
		if(check_if_arithm($<exprval>1,$<exprval>3)==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}			
		$<exprval>$ =newexpr(arithmexpr_e);
	  // check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
		$<exprval>$->symbol=newtemp();
		emit(sub,$<exprval>1,$<exprval>3, $<exprval>$, yylineno);
		printf("expression - expression to expression\n");
		}
	| expr '*' expr {
		if(check_if_arithm($<exprval>1,$<exprval>3)==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}		
		$<exprval>$ =newexpr(arithmexpr_e);
	//  check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
		$<exprval>$->symbol=newtemp();
		emit(mul,$<exprval>1,$<exprval>3, $<exprval>$, yylineno);
		printf("expression * expression  to expression\n");
		}
	| expr '/' expr {
		if(check_if_arithm($<exprval>1,$<exprval>3)==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}		
		$<exprval>$ =newexpr(arithmexpr_e);
		//check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
		$<exprval>$->symbol=newtemp();
		emit(div_op,$<exprval>1,$<exprval>3, $<exprval>$, yylineno);
		printf("expression / expression to expression \n");
		}
	| expr '%'expr {
	if(check_if_arithm($<exprval>1,$<exprval>3)==0){
									
						printf("This type of expr cannot be part of arithm expression in line %d \n",yylineno);		
						exit(0);
						}		
		$<exprval>$ =newexpr(arithmexpr_e);
		//check_if_constNum($<exprval>1,$<exprval>3,$<exprval>$);
		$<exprval>$->symbol=newtemp();
		emit(mod,$<exprval>1,$<exprval>3, $<exprval>$, yylineno);
		printf("expression % expression to expression\n");
		}
	| expr '>' expr {	
						$<exprval>$=newexpr(boolexpr_e);
						$<exprval>$->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_greater,$<exprval>1,$<exprval>3,nextquad()+5);
						emit(assign,falseExp,NULL,$<exprval>$,yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,$<exprval>$,yylineno);
						
							
						printf(" expression > expression to expression\n");
						}
	| expr GREATER_EQUAL expr	{
						$<exprval>$=newexpr(boolexpr_e);
						$<exprval>$->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_greatereq,$<exprval>1,$<exprval>3,nextquad()+5);
						emit(assign,falseExp,NULL,$<exprval>$,yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,$<exprval>$,yylineno);
		      printf("expression >= expression  to expression\n");
			  }
	| expr '<' expr	{
						$<exprval>$=newexpr(boolexpr_e);
						$<exprval>$->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_less,$<exprval>1,$<exprval>3,nextquad()+5);
						emit(assign,falseExp,NULL,$<exprval>$,yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,$<exprval>$,yylineno);
						printf(" expression  < expression to expression \n");
				}
	| expr LESS_EQUAL expr	{
						$<exprval>$=newexpr(boolexpr_e);
						$<exprval>$->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_lesseq,$<exprval>1,$<exprval>3,nextquad()+5);
						emit(assign,falseExp,NULL,$<exprval>$,yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,$<exprval>$,yylineno);
						printf("expression <= expression  to expression\n");
			}
	| expr EQUALS expr		{
						$<exprval>$=newexpr(boolexpr_e);
						$<exprval>$->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_eq,$<exprval>1,$<exprval>3,nextquad()+5);
						emit(assign,falseExp,NULL,$<exprval>$,yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,$<exprval>$,yylineno);
						printf("expression == expression to expression\n");
			}
	| expr NOT_EQUALS expr	{
						$<exprval>$=newexpr(boolexpr_e);
						$<exprval>$->symbol=newtemp();
						expr_e *falseExp=newexpr(constbool_e);
						falseExp->boolConst=0;
						expr_e *trueExp=newexpr(constbool_e);
						trueExp->boolConst=1;
						emit_Realop(if_noteq,$<exprval>1,$<exprval>3,nextquad()+5);
						emit(assign,falseExp,NULL,$<exprval>$,yylineno);
						emit_Realop(jump,NULL,NULL,nextquad()+4);
						emit(assign,trueExp,NULL,$<exprval>$,yylineno);
						printf(" expression != expression  to expression\n");}
	| expr AND expr		{
						$<exprval>$=newexpr(boolexpr_e);
						$<exprval>$->symbol=newtemp();
						emit(and,$<exprval>1,$<exprval>3,$<exprval>$,yylineno);
						printf("expression && expression  to expression\n");
						}
	| expr OR expr		{
						$<exprval>$=newexpr(boolexpr_e);
						$<exprval>$->symbol=newtemp();
						emit(or,$<exprval>1,$<exprval>3,$<exprval>$,yylineno);
						printf("expression || expression to expression\n");
						}
	| term { 
    $<exprval>$=$<exprval>term;
		    
	printf("term to expression\n");}
	
	;
term: '(' expr ')' { $<exprval>$=$<exprval>expr;
					printf("(expr) to term\n");}
	| '-' expr {
		checkuminus($<exprval>expr);
		$<exprval>$ =newexpr(arithmexpr_e);
					  $<exprval>$->symbol=newtemp();
					 emit(uminus,$<exprval>2,NULL, $<exprval>$, yylineno);
		printf("-expr to term\n");}
	| NOT expr { 
				printf("oxiexpr to term\n");
					 $<exprval>term = newexpr(boolexpr_e);
					 $<exprval>term->symbol = newtemp();
					 emit(not, $<exprval>expr,NULL,$<exprval>term,yylineno);
				}
	| PLUS_PLUS lvalue {
				if($<exprval>lvalue->symbol->name!=NULL){
					node *temp=lookup_CertScope($<exprval>lvalue->symbol->name,0);
					node *temp2=lookup_AllScopes($<exprval>lvalue->symbol->name,scope);
					int valid=1; //holds if errors found 0=false 1 true
					if (temp==NULL && temp2==NULL)valid=0;
					if(temp!=NULL){
						if(temp->type==LIBFUNC){
							printf("\n ERROR in line %d. Cannot assign ++value to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign ++value to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(valid==1){
						
						if ($<exprval>lvalue->type == tableitem_e) {
							expr_e *value = emit_iftableitem($<exprval>lvalue,yylineno);
							$<exprval>$=value;
							expr_e *num=newexpr(constnum_e);
							num->numConst=1;
							emit(add, value, num, value,yylineno);
							emit( tablesetelem, $<exprval>lvalue, $<exprval>lvalue->index, value,yylineno);
						}
						else {
							expr_e *num=newexpr(constnum_e);
							num->numConst=1;
							emit(add, $<exprval>lvalue, num, $<exprval>lvalue,yylineno);
							$<exprval>term=newexpr(arithmexpr_e);
							$<exprval>term->symbol=newtemp();
							emit(assign, $<exprval>lvalue,NULL,$<exprval>term,yylineno);

						}
					}
                }

		  printf("++lvalue to term\n");}
	| lvalue{ 
			if($<exprval>lvalue->symbol->name!=NULL){
					node *temp=lookup_CertScope($<exprval>lvalue->symbol->name,0);
					node *temp2=lookup_AllScopes($<exprval>lvalue->symbol->name,scope);
					int valid=1;
					if (temp==NULL && temp2==NULL)valid=0;
					if(temp!=NULL){
						if(temp->type==LIBFUNC){
							printf("\n ERROR in line %d. Cannot assign value++ to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign value++ to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					
                }
	       } PLUS_PLUS {
							$<exprval>term=newexpr(var_e);
							$<exprval>term->symbol=newtemp();
							if($<exprval>lvalue->type==tableitem_e){
								expr_e * value=emit_iftableitem($<exprval>lvalue,yylineno);
								expr_e *incr_exp=newexpr(constnum_e);
								incr_exp->numConst=1;
								emit(assign,value,NULL,$<exprval>term,yylineno);
								emit(add,value,incr_exp,value,yylineno);
								emit(tablesetelem,$<exprval>lvalue,$<exprval>lvalue->index,value,yylineno);
								
							}else{
							
								expr_e *incr_exp=newexpr(constnum_e);
								incr_exp->numConst=1;
								emit(assign,$<exprval>lvalue,NULL,$<exprval>term,yylineno);
								emit(add,$<exprval>lvalue,incr_exp,$<exprval>lvalue,yylineno);
							}
							printf(" lvalue++ to term\n");
							}
	| MINUS_MINUS lvalue {  
	if($<exprval>lvalue->symbol->name!=NULL){
					node *temp=lookup_CertScope($<exprval>lvalue->symbol->name,0);
					node *temp2=lookup_AllScopes($<exprval>lvalue->symbol->name,scope);
					int valid=1;
					if (temp==NULL && temp2==NULL)valid=0;
					if(temp!=NULL){
						if(temp->type==LIBFUNC){
							printf("\n ERROR in line %d. Cannot assign --value to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign --value to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
					if(valid==1){
							
						if ($<exprval>lvalue->type == tableitem_e) {
							expr_e *value = emit_iftableitem($<exprval>lvalue,yylineno);
							$<exprval>term=value;
							expr_e *num=newexpr(constnum_e);
							num->numConst=1;
							emit(sub, value, num, value,yylineno);
							emit( tablesetelem, $<exprval>lvalue, $<exprval>lvalue->index, value,yylineno);
						}
						else {
							expr_e *num=newexpr(constnum_e);
							num->numConst=1;
							emit(sub, $<exprval>lvalue, num, $<exprval>lvalue,yylineno);
							$<exprval>term=newexpr(arithmexpr_e);
							$<exprval>term->symbol=newtemp();
							emit(assign, $<exprval>lvalue,NULL,$<exprval>term,yylineno);

						}
					}
                

	}
 
        printf("--lvalue to term\n");}
	| lvalue  { 
				if($<exprval>lvalue->symbol->name!=NULL){
					node *temp=lookup_CertScope($<exprval>lvalue->symbol->name,0);
					node *temp2=lookup_AllScopes($<exprval>lvalue->symbol->name,scope);
					int valid=1;
					if (temp==NULL && temp2==NULL)valid=0;
					if(temp!=NULL){
						if(temp->type==LIBFUNC){
							printf("\n ERROR in line %d. Cannot assign value-- to %s \n\n",yylineno,temp->name);
							valid=0;
						}
						
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign value-- to %s \n\n",yylineno,temp->name);
							valid=0;
						}
					}
				
                }
		   }MINUS_MINUS {
						    $<exprval>term=newexpr(var_e);
							$<exprval>term->symbol=newtemp();
							if($<exprval>lvalue->type==tableitem_e){
								expr_e * value=emit_iftableitem($<exprval>lvalue,yylineno);
								expr_e *incr_exp=newexpr(constnum_e);
								incr_exp->numConst=1;
								emit(assign,value,NULL,$<exprval>term,yylineno);
								emit(sub,value,incr_exp,value,yylineno);
								emit(tablesetelem,$<exprval>lvalue,$<exprval>lvalue->index,value,yylineno);
								
							}else{
							
								expr_e *incr_exp=newexpr(constnum_e);
								incr_exp->numConst=1;
								emit(assign,$<exprval>lvalue,NULL,$<exprval>term,yylineno);
								emit(sub,$<exprval>lvalue,incr_exp,$<exprval>lvalue,yylineno);
							}
							printf("lvalue-- to term\n");
							}
	| primary { printf("termprimary to term\n");}
	;
assignexpr: lvalue {
					if($<exprval>lvalue->symbol->name!=NULL){
					node *temp=lookup_CertScope($<exprval>lvalue->symbol->name,0);
					node *temp2=lookup_AllScopes($<exprval>lvalue->symbol->name,scope);
					if(temp!=NULL){
						if(temp->type==LIBFUNC)printf("\n ERROR in line %d. Cannot assign value to %s \n\n",yylineno,temp->name);
					}
					if(temp2!=NULL){
						if(temp2->type==USERFUNC){
							printf("\n ERROR in line %d. Cannot assign value to %s \n\n",yylineno,temp->name);
						}
					}
                    }
					} '=' expr {
						if ($<exprval>lvalue->type ==tableitem_e) {
							emit(tablesetelem, $<exprval>lvalue, $<exprval>lvalue->index, $<exprval>expr,yylineno);
							$<exprval>$ = emit_iftableitem($<exprval>lvalue,yylineno);
							$<exprval>$->type=assignexpr_e;
						
						//ela kai pou sai
						  
						}else{
							emit(assign, $<exprval>expr, NULL, $<exprval>lvalue,yylineno);
							
						}
							expr_e * tmp_exp=newexpr(var_e);
							tmp_exp->symbol=newtemp();
							emit(assign, $<exprval>$, NULL, tmp_exp,yylineno);
					//$<exprval>$lvalue->symbol.var.type=Number;
			printf("lvalue=expr to assign expression\n");
			
			};
primary: lvalue { printf("iiii\n"); $<exprval>primary = emit_iftableitem($<exprval>lvalue,yylineno);printf("lvalue to primary\n");}
	| call {printf("call to primary\n");}
	| objectdef {printf("objectdef to primary\n");}
	| '(' funcdef ')'{ $<exprval>primary=$<exprval>funcdef; printf("(funcdef) to primary\n");}
	| const {printf("const to primary\n");}
	;
	
	
lvalue: ID {	
				node * temp = lookup_AllScopes(yytext,scope);
				node *symbol;
				if(temp != NULL){
					symbol=temp;
					if((temp->scope<scope) && (funcDef-1)>0 &&(temp->scope!=0) && (temp->type!=USERFUNC)){
						printf("\n ERROR in line :%d cannot access variable %s \n\n",yylineno,yytext);
					}
				}else{
					if(scope == 0){
						symbol=insertNode(yytext,scope,yylineno,GLOBL,currscopeoffset(),currscopespace()); 
						inccurrscopeoffset();
						
						
					}else{
						symbol=insertNode(yytext,scope,yylineno,LOCL,currscopeoffset(),currscopespace());//cursscopeoffset >2 kai oxi akairaio pollaplasio 
						inccurrscopeoffset();
					}
				}
				$<exprval>$ = newexpr(var_e);
				$<exprval>$->symbol = symbol;
				
				printf("id to lvalue %s\n",yytext ); 
			} 
	|GLOB ID {
				node * temp = lookup_CertScope(yytext,0);
				if(temp == NULL){
					printf("\n ERROR in line :%d GLOBal variable %s does not exists \n\n",yylineno,yytext);
				}else{
					$<exprval>$ = newexpr(var_e);
				$<exprval>$->symbol = temp;
				}
				
				
				printf(" ::id to lvalue\n");
			}  
	|LOCAL ID{ 
				node * temp = lookup_CertScope(yytext,scope);
				node *symbol;
	             if(temp == NULL){
					 if(scope == 0){
						symbol= insertNode(yytext,scope,yylineno,GLOBL,currscopeoffset(),currscopespace());
						 inccurrscopeoffset();
					 }else{
						symbol= insertNode(yytext,scope,yylineno,LOCL,currscopeoffset(),currscopespace());
						 inccurrscopeoffset();
					 }
					 $<exprval>$ = newexpr(var_e);
				$<exprval>$->symbol = symbol;
				 }else{
					 printf("\n ERROR in line :%d local variable %s redefinition \n\n",yylineno,yytext);
				 }
				printf("LOCAL ID to lvalue\n");
			
			}
			
		
	| member {printf("member to lvalue\n"); }
	;
member: lvalue '.' ID {
						$<exprval>$=member_item($<exprval>lvalue,$<strval>ID,yylineno);
						printf("lvalue.identifier to member\n");
						}
	| lvalue '[' expr ']' {$<exprval>lvalue = emit_iftableitem($<exprval>lvalue,yylineno);
							$<exprval>member = newexpr (tableitem_e);
							$<exprval>member->symbol = $<exprval>lvalue->symbol;
							$<exprval>member->index = $<exprval>expr;
							
								printf("lvalue expr to member\n");
						  }
	| call '.' ID {printf("call.identifier to member\n");}
	| call '[' expr ']'	{printf("call expr to member\n");}
	;
call:  call '(' elist ')' { 
							$<exprval>$=make_call($<exprval>1,$<exprval>elist,yylineno);//edw//
							printf("(elist)to call\n");
							elist_tmp = NULL;
							}
	|lvalue callsuffix {printf("lvaluecallsuffix to call\n"); 
						if($<exprval>callsuffix->methodCalls.method==1){
							expr_e *self=$<exprval>lvalue;
							
							
							$<exprval>lvalue=emit_iftableitem(member_item(self,$<exprval>callsuffix->methodCalls.name,yylineno),yylineno);//edw
							self->next = $<exprval>callsuffix->methodCalls.elist;
							$<exprval>callsuffix->methodCalls.elist = self;
							
						}
						printf("!!!!!!!!!lvalue null %s \n",$<strval>lvalue);
						
						$<exprval>$=make_call($<exprval>lvalue,$<exprval>callsuffix->methodCalls.elist,yylineno);
						printf("telos \n");} 
	|'(' funcdef ')' '(' elist ')' {
							expr_e* func=newexpr(programfunc_e);
							func->symbol=$<exprval>funcdef->symbol;
							$<exprval>$=make_call(func,$<exprval>elist,yylineno);//eedw
							elist_tmp = NULL;
							printf("(funcdef)(elist)to call\n");		
							}
	;
callsuffix: normcall {	
						$$=$normcall;
						printf("normcall to call suffix \n");//edw
						}
	| methodcall {
					$$=$methodcall;
					printf(" methodcall to call suffix\n");//edw
						}
	;
normcall: '(' elist ')' {									
						$<exprval>$ = newexpr(programfunc_e);
						if($<exprval>$->methodCalls.elist == NULL);
						$<exprval>$->methodCalls.elist=$<exprval>elist;
						 $<exprval>$->methodCalls.method=0;
						$<exprval>$->methodCalls.name=NULL;//edw
						elist_tmp = NULL;
				printf("(elist)to normcall\n");
				};
methodcall: DOUBLE_DOT ID '(' elist ')' {
						$<exprval>methodcall->methodCalls.elist=$<exprval>elist; //edw//
						$<exprval>methodcall->methodCalls.method=1;
						$<exprval>methodcall->methodCalls.name=strdup($<strval>ID);
						elist_tmp = NULL;
						printf("method call");
						};
elist:	expr  {elist_tmp = NULL;}			
	| elist ',' expr { 
					  if(elist_tmp == NULL){
											elist_tmp = $<exprval>1;
											while(elist_tmp->next != NULL) elist_tmp = elist_tmp->next;
											elist_tmp->next = $<exprval>expr;
											
					  }
					  elist_tmp->next = $<exprval>expr;
					  elist_tmp = $<exprval>expr;
											//printf("string %s \n",$<exprval>expr->symbol->name);
					  // tmp= elist->next=expr; elist->next-=expr; 
	}
	|{$<exprval>$ = NULL; printf("helloooo\n");}			
	;
objectdef:	'[' elist ']'	{
					printf("[elist] to objectdef \n");
					expr_e * t=newexpr(newtable_e);
					t->symbol=newtemp();
					emit(tablecreate, t,NULL,NULL,yylineno); 
					int i=0;
					expr_e *temp = $<exprval>elist;
					expr_e *index_exp;
					while(temp != NULL){
						index_exp=newexpr(constnum_e);
						index_exp->numConst=i;
						emit(tablesetelem,t,index_exp,temp,yylineno);
						temp = temp->next;
						i++;
					}
					$<exprval>$=t;
					elist_tmp = NULL;
					}
	| '[' indexed  ']'	{
							expr_e * t=newexpr(newtable_e);
					t->symbol=newtemp();
					emit(tablecreate, t,NULL,NULL,yylineno); 
					expr_e *temp = $<exprval>indexed;
					expr_e *index_exp;
					while(temp != NULL){
						emit(tablesetelem,t,temp->index,temp,yylineno);
						temp = temp->next;
						
					}
					$<exprval>$=t;
					
						printf("[indexed] to objectdef \n");}
	;
indexed:	indexedelem		{ printf("indexedelem to indexed \n");}
	|indexed ',' indexedelem {
						  if(indexed_tmp == NULL){indexed_tmp = $<exprval>1;
											indexed_tmp->next = $<exprval>3;}
					  indexed_tmp->next = $<exprval>3;
					  indexed_tmp = $<exprval>3;
				
					printf("indexe,indexelem to indexed\n");}	
	;

indexedelem:	'{' expr ':' expr '}'	{
				$<exprval>$ = $<exprval>4;
				$<exprval>$->index = $<exprval>2;
				
				printf("{ Expr : Expr } to indexed\n");
				};

temp_st: temp_st stmt {}
	|{}
;
block: '{' {scope++;if(funcDef>0)enterscopespace();}temp_st '}'{
																	hide(scope);  
																	scope--;} 
																{printf("block\n");};
funcdef: FUNCTION ID {
			node * temp = lookup_AllScopes(yytext,scope);
			node * temp2=lookup_CertScope(yytext,scope);
			if(temp == NULL){
				temp=insertNode(yytext,scope,yylineno,USERFUNC,currscopeoffset(),currscopespace());
				
				expr_e *exp = newexpr(programfunc_e);
				exp->symbol=temp;
				$<exprval>1=exp;
				emit(funcstart,exp,NULL,NULL,yylineno);
				temp->iadress=quad_count+1;
				inccurrscopeoffset();
			}else if(temp->type == LIBFUNC){
				printf("\n ERROR in line %d. Shadowing of libfunc %s \n\n",yylineno,yytext);
			}else if(temp2!=NULL && temp2->type == USERFUNC){
				printf("\n ERROR in line %d. Function %s redefinition \n\n",yylineno,yytext);
			}else if((temp->scope == scope) && (temp->type != USERFUNC)){
				printf("\n ERROR in line %d. %s is already defined as var \n\n",yylineno,yytext);
			}else if((temp->scope<scope)){
				
				temp=insertNode(yytext,scope,yylineno,USERFUNC,currscopeoffset(),currscopespace());
				expr_e *exp = newexpr(programfunc_e);
				exp->symbol=temp;
				$<exprval>2=exp;
				emit(funcstart,exp,NULL,NULL,yylineno);
				temp->iadress=quad_count+1;
				inccurrscopeoffset();
			}
		push(&loopstack,loop);
		loop=0;
		funcDef++;
		
		
		if(funcDef>1){
			offsets_table[scopeSpaceCounter]= currscopeoffset();
			functionLocalOffset=0;
			formalArgOffset=0;
		}
		
		
     }
	  '('{enterscopespace();} idlist ')' block {if(funcDef>0){	$<exprval>1->symbol->locals_count=functionLocalOffset+1;
																		exitscopespace(); 
																		exitscopespace(); 
																		functionLocalOffset=offsets_table[scopeSpaceCounter];
																		
																	}  
																	emit(funcend,$<exprval>1,NULL,NULL,yylineno);
																	funcDef--;loop=pop(&loopstack);printf("function def \n");}
	|FUNCTION {node *temp= insertAnon(scope,yylineno,currscopeoffset(),currscopespace());
			expr_e *exp=newexpr(programfunc_e);
			exp->symbol=temp;
			$<exprval>1=exp;
			emit(funcstart,exp,NULL,NULL,yylineno);
			temp->iadress=quad_count+1;
			
			inccurrscopeoffset();
			push(&loopstack,loop);
		   loop=0;
			funcDef++;
			if(funcDef>1){
					offsets_table[scopeSpaceCounter]= currscopeoffset();
					functionLocalOffset=0;
					formalArgOffset=0;
			}
			printf("temp_id <- empty\n");}
	 '('{enterscopespace();} idlist ')' block { if(funcDef>0){$<exprval>1->symbol->locals_count=functionLocalOffset+1;
																		exitscopespace(); 
																		exitscopespace(); 
																		functionLocalOffset=offsets_table[scopeSpaceCounter];
																	} emit(funcend,$<exprval>1,NULL,NULL,yylineno);funcDef--;loop=pop(&loopstack);printf("function def \n");}
	
	;
const:	INTEGER	{
     $<exprval>$=newexpr(constnum_e);
	 $<exprval>$->numConst=yylval.intval;
	 printf("NUMBER %d\n",yylval.intval);
	 
	
	} 
	| REALNUMBER		{
	 $<exprval>$=newexpr(constnum_e);
	 $<exprval>$->numConst=yylval.realval;
		printf("REALNUMBER %s\n",yytext);}
	| STRING		{
		$<exprval>$=newexpr(conststring_e);
	 $<exprval>$->strConst=strdup(yylval.strval);
		printf("STRING to const\n");}
	| NIL			{
		$<exprval>$=newexpr(nil_e);
		$<exprval>$->strConst=strdup("NIL");
			printf("NIL to const \n");
				}
	| TRUE			{
				$<exprval>$=newexpr(constbool_e);
			$<exprval>$->boolConst=1;
			printf("TRUE to const\n");
			}
	| FALSE			{
			$<exprval>$=newexpr(constbool_e);
			$<exprval>$->boolConst=0;
		printf("FALSE to const\n");
	}
	;
idlist:ID {	node * temp = lookup_CertScope(yytext,0);
				if((temp != NULL) && (temp->type == LIBFUNC)){
					printf("\n ERROR in line %d. %s cannot be an argument \n\n",yylineno,yytext);
				}else{
					insertNode(yytext,scope+1,yylineno,FORMAL,currscopeoffset(),currscopespace());
					inccurrscopeoffset();
				}
			printf("ID to idlist\n");
			}
	|idlist ',' ID {node * temp = lookup_CertScope(yytext,scope + 1);
					  node * temp2 = lookup_CertScope(yytext,0);
						if((temp2 != NULL) && (temp2->type == LIBFUNC)){
							printf("\n ERROR in line %d. %s cannot be an argument \n\n",yylineno,yytext);
						}else if((temp != NULL) && (temp->type == FORMAL)){
							printf("\n ERROR in line %d. argument redefinition\n\n",yylineno);
						}else{
							
							insertNode(yytext,scope+1,yylineno,FORMAL,currscopeoffset(),currscopespace()); 
							inccurrscopeoffset();
						}
		printf("idlist comma to idlist\n");
		}
	|{;}
;
ifstmt: IF '(' expr ')' {
	
				expr_e *trueExp=newexpr(boolexpr_e);
				trueExp->boolConst=1;
				emit_Realop(if_eq, $<exprval>expr, trueExp,nextquad()+4);
			
				emit_Realop(jump,NULL,NULL,0);
					push(&ifstack,nextquad()); 
			}stmt{
				t=pop(&ifstack);
				patchlabel(t,nextquad()+2);
				printf("if()\n");
			}
	| {patchlabel(t,nextquad()+3);} ELSE {
			emit_Realop(jump,NULL,NULL,0);
					push(&ifstack,nextquad()); 
				}
				stmt {
					
					patchlabel(pop(&ifstack),nextquad()+2);
					printf("ifelse stmt \n");
					}
	;
whilestmt: WHILE	{push(&ifstack,nextquad()+2); } '('{ scope++;loop++; set_loop(loop);} expr ')'{
																	expr_e *tr=newexpr(constbool_e);
																	tr->boolConst=1;
																	emit_Realop(if_eq,$<exprval>expr,tr,nextquad()+4);
																	
																	emit_Realop(jump,NULL,NULL,0);
																	push(&ifstack,nextquad());
																	scope--;
																	} stmt {
																		
																				int temp1=pop(&ifstack);
																				int temp2=pop(&ifstack);
																				
																				printf("temp2 %d nex %d \n",temp2,nextquad()+2);
																				emit_Realop(jump,NULL,NULL,temp2);
																				patchlabel(temp1,nextquad()+2);
																				t = pop(&breakstack);
																				while(t != -1){
																				patchlabel(t,nextquad()+2);
																				t = pop(&breakstack);
																				}
																				t = pop(&continuestack);
																				while(t != -1){
																				patchlabel(t,temp2);
																				t = pop(&continuestack);
																				}
																				loop--; set_loop(loop);printf("while()stmt\n");
																				};
N: {
	emit_Realop(jump,NULL,NULL,0);
	$<intval>N=nextquad();

	}
	;
M:{$<intval>M=nextquad();};

forp: FOR '('{scope++;loop++;set_loop(loop); } elist ';' M expr ';'{} { 
															$<forprefix.test>$=$<intval>M;
															printf("for.test %d \n",$M);
															expr_e *tr=newexpr(constbool_e);
															tr->boolConst=1;
															
															emit_Realop(if_eq,$<exprval>expr,tr,0);
															
															$<forprefix.enter>$=nextquad();
															};
forstmt: forp N{} elist ')'{scope--;} N stmt N {
																
																	printf("n1=%d\n",$<intval>2);
																	patchlabel($<forprefix.enter>$,($<intval>7)+2);
																	printf("n2=%d\n",$<intval>7);
																	
																	patchlabel($<intval>2,nextquad()+2);
																	printf("n3=%d\n",$<intval>9);
																	patchlabel($<intval>7,$<forprefix.test>$+2);
																	
																	patchlabel($<intval>9,($<intval>2)+3);
																	t = pop(&breakstack);
																				while(t != -1){
																				patchlabel(t,nextquad()+2);
																				t = pop(&breakstack);
																				}
																				t = pop(&continuestack);
																				while(t != -1){
																				patchlabel(t,($<intval>2)+3);
																				t = pop(&continuestack);
																				}
																				loop--; set_loop(loop);
																	printf("FOR (ELIST;EXPR;ELIST)STMT\n");
															
																	};
					
returnstmt: RETURN ';' {printf("returnstmt\n");
								emit(ret,NULL,NULL,NULL,yylineno);
						}
	|RETURN expr ';' {printf("returnstmt with expr\n");
							emit(ret,$<exprval>expr,NULL,NULL,yylineno);
					};
%%
int yyerror (const char * YaccProvidedMessage)
{	
	fprintf(stderr,"%s: at line %d,before token: %s\n",YaccProvidedMessage,yylineno,yytext);
	fprintf(stderr,"INPUT NOT VALID \n");
}


int main(int argc,char **argv)
{
		
	init_stacks();
	init_offsets_table();
	insert_libfunc();
	
	flag=1;
	
	yyparse();
    print_quads();
	print();

	return 0;
}
