    //
// Created by o_oya on 2021/10/16.
//

#ifndef DATABASE_SQLEXPRESSION_H
#define DATABASE_SQLEXPRESSION_H

#include <iostream>
#include <vector>
#include "SQLSingleExpression.h"
#include "TokenType.h"

class SQLExpression {
public:
    std::vector<SQLSingleExpression> exprs;
    std::vector<TokenType::TokenTypes> ops;
};


#endif //DATABASE_SQLEXPRESSION_H
