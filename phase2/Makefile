all: phase1.l parser.y symtable.c
	clear
	flex phase1.l 
	yacc -d parser.y
	gcc lex.yy.c y.tab.c symtable.c -o lala

