//
// Created by o_oya on 2021/10/16.
//

#ifndef DATABASE_SQLINSERTSTATEMENT_H
#define DATABASE_SQLINSERTSTATEMENT_H

#include "SQLValue.h"
#include <vector>
#include <iostream>

class SQLInsertStatement {
public:
    std::string tableName;
    std::vector<std::string> columnNames;
    std::vector<SQLValue> values;
};


#endif //DATABASE_SQLINSERTSTATEMENT_H
