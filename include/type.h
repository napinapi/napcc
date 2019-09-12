#pragma once
#include "AST.h"

typedef struct AST AST;

// Type data
typedef enum {
	TY_INT,
	TY_PTR
} TypeKind;

typedef struct Type Type;
struct Type {
	TypeKind kind;
	Type *ptr;
};

// Make new type.
Type *newType(TypeKind kind);
