#pragma once
#include <stdlib.h>
#include "lexer.h"
#include "type.h"

typedef struct Type Type;
typedef struct Token Token;

// AST type.
typedef enum {
	AST_ADD,		// a + b
	AST_SUB,		// a - b
	AST_MUL,		// a * b
	AST_DIV,		// a / b
	AST_LESS,		// a < b
	AST_LESSEQ,		// a <= b
	AST_EQ,			// a == b
	AST_ADDR,		// *a
	AST_DEREF,		// &a
	AST_ASSIGN,		// a = b
	AST_ARGS,		// foo(1, 3*2, variable)
	AST_BLOCK,		// { stmt1 stmt2 } statement list (AST_BLOCK). 
	AST_IF,			// if(a)
	AsT_IF_ELSE,	// if(a) b else c
	AST_WHILE,		// while(a) b
	AST_RETURN,		// return a
	AST_LVAR,		// a
	AST_CALL,		// func()
	AST_NUM,		// [0-9]+
	AST_ARGDECS		// func(a, b, c)
} ASTType;

// AST sets.
typedef struct AST AST;
struct AST {
	ASTType type;
	AST *lhs, *rhs;
	int val;			// The value (AST_NUM).	
	int offset;			// Local variable offset (AST_LVAR).
	AST *cond;			// Condinate expression (AST_IF, AST_WHILE).
	Token *calledFunc;	// Called function token (AST_CALL).
};


AST *newAST(ASTType type, AST *lhs, AST *rhs);
AST *newNumAST(int val);

