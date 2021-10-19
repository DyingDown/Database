//
// Created by o_oya on 2021/10/16.
//

#ifndef DATABASE_SQLCREATETABLESTATEMENT_H
#define DATABASE_SQLCREATETABLESTATEMENT_H

#include <iostream>
#include "SQLColumnDefine.h"
#include <vector>

class SQLCreateTableStatement {
public:
    std::string TableName;
    std::vector<SQLColumnDefine> columns;
};


#endif //DATABASE_SQLCREATETABLESTATEMENT_H
