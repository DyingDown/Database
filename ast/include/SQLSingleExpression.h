//
// Created by o_oya on 2021/10/19.
//

#ifndef DATABASE_SQLSINGLEEXPRESSION_H
#define DATABASE_SQLSINGLEEXPRESSION_H

#include "SQLValue.h"
#include "TokenType.h"

class SQLSingleExpression {
public:
    SQLValue leftVal;
    TokenType::TokenTypes compareOp;
    SQLValue rightVal;
};


#endif //DATABASE_SQLSINGLEEXPRESSION_H
