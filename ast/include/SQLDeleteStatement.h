//
// Created by o_oya on 2021/10/16.
//

#ifndef DATABASE_SQLDELETESTATEMENT_H
#define DATABASE_SQLDELETESTATEMENT_H

#include "SQLExpression.h"
#include <iostream>

class SQLDeleteStatement {
public:
    std::string tableName;
    SQLExpression expr;
};


#endif //DATABASE_SQLDELETESTATEMENT_H
