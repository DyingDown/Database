//
// Created by o_oyao on 2021/10/5.
//

#ifndef DATABASE_TOKEN_H
#define DATABASE_TOKEN_H

#include <iostream>

class Token {
public:
    int type;
    std::string value;
    Token(int type, std::string value);
};


#endif //DATABASE_TOKEN_H
