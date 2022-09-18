/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHILE = 258,
    FOR = 259,
    BREAK = 260,
    CONTINUE = 261,
    IF = 262,
    ELSE = 263,
    FUNCTION = 264,
    RETURN = 265,
    AND = 266,
    OR = 267,
    NOT = 268,
    LOCAL = 269,
    TRUE = 270,
    FALSE = 271,
    NIL = 272,
    EQUALS = 273,
    NOT_EQUALS = 274,
    PLUS_PLUS = 275,
    MINUS_MINUS = 276,
    ID = 277,
    INTEGER = 278,
    STRING = 279,
    REALNUMBER = 280,
    GREATER_EQUAL = 281,
    LESS_EQUAL = 282,
    DOUBLE_DOT = 283,
    GLOB = 284
  };
#endif
/* Tokens.  */
#define WHILE 258
#define FOR 259
#define BREAK 260
#define CONTINUE 261
#define IF 262
#define ELSE 263
#define FUNCTION 264
#define RETURN 265
#define AND 266
#define OR 267
#define NOT 268
#define LOCAL 269
#define TRUE 270
#define FALSE 271
#define NIL 272
#define EQUALS 273
#define NOT_EQUALS 274
#define PLUS_PLUS 275
#define MINUS_MINUS 276
#define ID 277
#define INTEGER 278
#define STRING 279
#define REALNUMBER 280
#define GREATER_EQUAL 281
#define LESS_EQUAL 282
#define DOUBLE_DOT 283
#define GLOB 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "parser.y" /* yacc.c:1909  */

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
	

#line 128 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
