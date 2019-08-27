#pragma once
#include <stdlib.h>

// AST type.
typedef enum {
	AST_ADD,		// a + b
	AST_SUB,		// a - b
	AST_MUL,		// a * b
	AST_DIV,		// a / b
	AST_LESS,		// a < b
	AST_LESSEQ,		// a <= b
	AST_EQ,			// a == b
	AST_ASSIGN,		// a = b
	AST_RETURN,		// return a
	AST_LVAR,		// a
	AST_NUM,		// [0-9]+
} ASTType;

// AST sets.
typedef struct AST AST;
struct AST {
	ASTType type;
	AST *lhs, *rhs;
	int val;			// The value (AST_NUM).	
	int offset;			// Local variable offset (AST_LVAR).
};

AST *newAST(ASTType type, AST *lhs, AST *rhs);
AST *newNumAST(int val);

