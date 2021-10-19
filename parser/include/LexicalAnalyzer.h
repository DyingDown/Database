//
// Created by o_oyao on 2021/9/23.
//

#ifndef DATABASE_LEXICALANALYZER_H
#define DATABASE_LEXICALANALYZER_H

#include <string>
#include <vector>
#include "Token.h"
#include "TokenType.h"

class LexicalAnalyzer {
private:
    Token getNumber();    /* get int or float numbers or dot */
    Token getWords();     /* get ID or */
    Token getString();    /* get string */
    Token getPunct();     /* get punctuation */
    int currentPosition;
    bool isSpace(char a);
    Token scanNextTokens();
    int currentTokenPos;
public:
    std::string sql_str;
    int sql_len;
    LexicalAnalyzer(std::string content);
    LexicalAnalyzer();
    void getAllTokens();
    Token getNextToken();
    Token getCurrentToken();
    std::vector<Token> Tokens;
};


#endif //DATABASE_LEXICALANALYZER_H
