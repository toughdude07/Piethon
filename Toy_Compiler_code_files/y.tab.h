/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    INTNUM = 258,
    FLOATNUM = 259,
    IDENT = 260,
    DATA = 261,
    PLUSEQ = 262,
    MINUSEQ = 263,
    MULTEQ = 264,
    DIVEQ = 265,
    MODEQ = 266,
    POWEQ = 267,
    INC = 268,
    DEC = 269,
    LE = 270,
    GE = 271,
    EQ = 272,
    NE = 273,
    IF = 274,
    ELSE = 275,
    WHILE = 276,
    DEF = 277,
    PRINT = 278,
    RETURN = 279,
    END = 280,
    LOWER_THAN_ELSE = 281,
    UMINUS = 290
  };
#endif
/* Tokens.  */
#define INTNUM 258
#define FLOATNUM 259
#define IDENT 260
#define DATA 261
#define PLUSEQ 262
#define MINUSEQ 263
#define MULTEQ 264
#define DIVEQ 265
#define MODEQ 266
#define POWEQ 267
#define INC 268
#define DEC 269
#define LE 270
#define GE 271
#define EQ 272
#define NE 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define DEF 277
#define PRINT 278
#define RETURN 279
#define END 280
#define LOWER_THAN_ELSE 281
#define UMINUS 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "parse_.y" /* yacc.c:1909  */

    int                             intVal;
    double                          floatVal;
    char*                           ident;
    string*                         op;
    Operation*                      atm;
    string*                         data;
    vector<Operation*>*             stmt;
    vector<vector<Operation*>*>*     pr;

#line 119 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
