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
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    STRING = 259,
    WHILE = 260,
    FOR = 261,
    IF = 262,
    ELSE = 263,
    FUNCTION = 264,
    RETURN = 265,
    BREAK = 266,
    CONTINUE = 267,
    AND = 268,
    OR = 269,
    NOT = 270,
    LOCAL = 271,
    TRUE = 272,
    FALSE = 273,
    NIL = 274,
    PLUS = 275,
    MINUS = 276,
    MUL = 277,
    MOD = 278,
    DIV = 279,
    EQUALS = 280,
    N_EQL = 281,
    PLUSPLUS = 282,
    MINUSMINUS = 283,
    ID = 284,
    ASSIGN = 285,
    REALNUMBER = 286,
    GRTR_EQL = 287,
    LESS_EQL = 288,
    GRTR = 289,
    LESS = 290,
    L_BRACKET = 291,
    R_BRACKET = 292,
    L_BRACE = 293,
    R_BRACE = 294,
    L_PAR = 295,
    R_PAR = 296,
    COMMA = 297,
    SEMCOL = 298,
    COLON = 299,
    DOT = 300,
    DBL_DOT = 301,
    WRONG_DEFINITION = 302,
    GLOB = 303
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define STRING 259
#define WHILE 260
#define FOR 261
#define IF 262
#define ELSE 263
#define FUNCTION 264
#define RETURN 265
#define BREAK 266
#define CONTINUE 267
#define AND 268
#define OR 269
#define NOT 270
#define LOCAL 271
#define TRUE 272
#define FALSE 273
#define NIL 274
#define PLUS 275
#define MINUS 276
#define MUL 277
#define MOD 278
#define DIV 279
#define EQUALS 280
#define N_EQL 281
#define PLUSPLUS 282
#define MINUSMINUS 283
#define ID 284
#define ASSIGN 285
#define REALNUMBER 286
#define GRTR_EQL 287
#define LESS_EQL 288
#define GRTR 289
#define LESS 290
#define L_BRACKET 291
#define R_BRACKET 292
#define L_BRACE 293
#define R_BRACE 294
#define L_PAR 295
#define R_PAR 296
#define COMMA 297
#define SEMCOL 298
#define COLON 299
#define DOT 300
#define DBL_DOT 301
#define WRONG_DEFINITION 302
#define GLOB 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:1909  */

	int intval;
	char* strval;
	float realval;

#line 156 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
