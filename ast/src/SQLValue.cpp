//
// Created by o_oya on 2021/10/17.
//

#include "SQLValue.h"
#include "Token.h"
#include "TokenType.h"

SQLValue::SQLValue(Token val, types type) {
    if(val.type == TokenType::INT) {
        value = stoi(val.value);
        valueType = types::INT;
    } else if(val.type == TokenType::FLOAT) {
        value = stof(val.value);
        valueType = types::FLOAT;
    } else if(val.type == TokenType::STRING){
        value = val.value;
        valueType = types::STRING;
    } else if(val.type == TokenType::ID){
        value = val.value;
        valueType = types::COLUMN;
    }
}

int SQLValue::getInt() {
    return std::get<int>(value);
}

double SQLValue::getFloat() {
    return std::get<double>(value);
}

std::string SQLValue::getString() {
    return std::get<std::string>(value);
}

void SQLValue::printValue() {
    if(valueType == types::INT) {
        std::cout << getInt() << std::endl;
    } else if(valueType == types::COLUMN) {
        std::cout << getString() << std::endl;
    } else if(valueType == types::FLOAT) {
        std::cout << getFloat() << std::endl;
    } else if(valueType == types::STRING) {
        std::cout << getString() << std::endl;
    }
}

