//
// Created by o_oya on 2021/10/16.
//

#ifndef DATABASE_SQLCOLUMNDEFINE_H
#define DATABASE_SQLCOLUMNDEFINE_H

#include <iostream>
#include <map>

class SQLColumnDefine {
public:
    enum Types {
        INT, FLOAT, STRING
    };
    static std::map<std::string, Types> stringToType;
    std::string columnName;
    Types columnType;
    int len = 500;
    SQLColumnDefine() = default;
    SQLColumnDefine(std::string columnName, Types columnType);
};


#endif //DATABASE_SQLCOLUMNDEFINE_H
