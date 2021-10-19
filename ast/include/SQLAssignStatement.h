//
// Created by o_oya on 2021/10/17.
//

#ifndef DATABASE_SQLASSIGNSTATEMENT_H
#define DATABASE_SQLASSIGNSTATEMENT_H

#include "SQLValue.h"
#include <iostream>

class SQLAssignStatement {
public:
    std::string columnName;
    SQLValue value;
};


#endif //DATABASE_SQLASSIGNSTATEMENT_H
