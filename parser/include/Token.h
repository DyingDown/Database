//
// Created by o_oyao on 2021/10/5.
//

#ifndef DATABASE_TOKEN_H
#define DATABASE_TOKEN_H

#include <iostream>
#include "TokenType.h"

class Token {
public:
    TokenType::TokenTypes type;
    std::string value;
    Token(TokenType::TokenTypes type, std::string value);
};


#endif //DATABASE_TOKEN_H
