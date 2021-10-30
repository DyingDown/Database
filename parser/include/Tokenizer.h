//
// Created by o_oyao on 2021/9/23.
//

#ifndef DATABASE_TOKENIZER_H
#define DATABASE_TOKENIZER_H

#include <string>
#include <vector>
#include "Token.h"
#include "TokenType.h"

class Tokenizer {
private:
    Token getNumber();    /* get int or float numbers or dot */
    Token getWords();     /* get ID or */
    Token getString(char quotation);    /* get string */
    Token getPunct();     /* get punctuation */
    int currentPosition;
    bool isSpace(char a);
    Token scanNextTokens();
    int currentTokenPos;
public:
    std::string sql_str;
    int sql_len;
    Tokenizer(std::string content);
    Tokenizer();
    void getAllTokens();
    Token getNextToken();
    Token getCurrentToken();
    void traceBack();
    std::vector<Token> Tokens;
};


#endif //DATABASE_TOKENIZER_H
