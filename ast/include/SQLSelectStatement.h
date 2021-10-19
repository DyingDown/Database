//
// Created by o_oya on 2021/10/17.
//

#ifndef DATABASE_SQLSELECTSTATEMENT_H
#define DATABASE_SQLSELECTSTATEMENT_H

#include "SQLSelectListElement.h"
#include "SQLExpression.h"
#include <vector>
#include <iostream>

class SQLSelectStatement {
public:
    std::vector<SQLSelectListElement> selectList;
    std::vector<std::string> tableLists;
    SQLExpression expr;
};

#endif //DATABASE_SQLSELECTSTATEMENT_H
