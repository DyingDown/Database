//
// Created by o_oya on 2021/10/16.
//

#include "SQLColumnDefine.h"

#include <utility>


SQLColumnDefine::SQLColumnDefine(std::string columnName, SQLColumnDefine::Types columnType) {
    this->columnName = std::move(columnName);
    this->columnType = columnType;
}

std::map<std::string, SQLColumnDefine::Types> SQLColumnDefine::stringToType  =
        {{"int", Types::INT}, {"float", Types::FLOAT}, {"string", Types::STRING}};
