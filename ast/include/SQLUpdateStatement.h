//
// Created by o_oya on 2021/10/17.
//

#ifndef DATABASE_SQLUPDATESTATEMENT_H
#define DATABASE_SQLUPDATESTATEMENT_H

#include "SQLAssignStatement.h"
#include "SQLExpression.h"
#include <vector>

class SQLUpdateStatement {
public:
    std::string tableName;
    std::vector<SQLAssignStatement> assigns;
    SQLExpression expr;
};


#endif //DATABASE_SQLUPDATESTATEMENT_H
