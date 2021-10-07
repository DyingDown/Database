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
    Token getNumber();
    Token getWords();
    Token getString();
    Token getPunct();
    int currentPosition;
    bool isSpace(char a);
public:
    std::string sql_str;
    int sql_len;
    std::vector<Token> tokens;
    Token scanNextTokens();
    LexicalAnalyzer(std::string content);

};


#endif //DATABASE_LEXICALANALYZER_H
