//
// Created by o_oyao on 2021/10/5.
//

#include "../include/Token.h"

Token::Token(TokenType::TokenTypes type, std::string value) {
    this->type = type;
    this->value = std::move(value);
}
