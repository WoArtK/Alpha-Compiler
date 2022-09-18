all: phase1.l parser.y symtable.c temporaries.c quad.c
	clear
	flex phase1.l 
	yacc -d -t -v parser.y
	gcc lex.yy.c y.tab.c symtable.c temporaries.c quad.c -o lala

