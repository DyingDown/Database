//
// Created by o_oya on 2021/10/17.
//

#ifndef DATABASE_SQLVALUE_H
#define DATABASE_SQLVALUE_H

#include <string>
#include <variant>
#include "Token.h"


class SQLValue {
public:
    enum types{
        INT, FLOAT, STRING, COLUMN
    };
    std::variant<int, double, std::string> value;
    types valueType;
    SQLValue() = default;
    SQLValue(Token val, types type = types::STRING);
    int getInt();
    double getFloat();
    std::string getString();
};


#endif //DATABASE_SQLVALUE_H
