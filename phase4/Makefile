all: phase1.l parser.y symtable.c temporaries.c quad.c inst.c
	clear
	flex phase1.l 
	yacc -d -t -v parser.y
	gcc lex.yy.c y.tab.c symtable.c temporaries.c quad.c inst.c -o lala
avm: avm.c inst.c quad.c temporaries.c symtable.c assign.c functions.c vmfuncs.c
	clear
	gcc avm.c inst.c quad.c temporaries.c symtable.c assign.c functions.c vmfuncs.c
