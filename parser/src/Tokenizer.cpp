//
// Created by o_oyao on 2021/9/23.
//

#include "../include/Tokenizer.h"

#include <utility>
#include <iostream>
#include <cctype>
#include <algorithm>

Tokenizer::Tokenizer(std::string content) {
    sql_str = std::move(content);
    currentPosition = 0;
    sql_len = sql_str.length();
    getAllTokens();
    currentTokenPos = 0;
}
Tokenizer::Tokenizer() {
    sql_str = "";
    currentPosition = 0;
    sql_len = 0;
    currentTokenPos = 0;
}

Token Tokenizer::scanNextTokens() {
    while(currentPosition < sql_len and isSpace(sql_str[currentPosition])) {
        currentPosition ++;
    }
    Token currentToken(TokenType::ILLEGAL, "");
    if(currentPosition >= sql_len) {
        currentToken = Token(TokenType::END, "");
    } else if(sql_str[currentPosition] == '\"' or sql_str[currentPosition] == '\'') {
        currentToken = getString(sql_str[currentPosition]);
    } else if(isdigit(sql_str[currentPosition])) {
        currentToken = getNumber();
    } else if(isalpha(sql_str[currentPosition])) {
        currentToken = getWords();
    } else {
        currentToken = getPunct();
    }
    return currentToken;
}

Token Tokenizer::getNumber() {
    std::string number;
    int dot = 0;
    char currentChar = sql_str[currentPosition];
    while((currentChar == '.' or isdigit(currentChar)) and currentPosition < sql_len) {
        if(currentChar == '.') {
            if(dot == 1) {
            }
            dot ++;
        }
        number += currentChar;
        currentPosition ++;
        currentChar = sql_str[currentPosition];
    }
    if(dot == 0) {
        return {TokenType::INT, number};
    } else if(dot == 1) {
        if(number == ".") {
            return {TokenType::DOT, number};
        }
        return {TokenType::FLOAT, number};
    } else {
        return {TokenType::ILLEGAL, number};
    }
}

Token Tokenizer::getWords() {
    std::string str;
    int illegalCharNum = 0;
    while((std::isalpha(sql_str[currentPosition]) or sql_str[currentPosition] == '_') and currentPosition < sql_len) {
        if(sql_str[currentPosition] != '_' and isalpha(sql_str[currentPosition]) and isdigit(sql_str[currentPosition])) {
            illegalCharNum ++;
            break;
        }
        str += sql_str[currentPosition];
        currentPosition ++;
    }
    if(illegalCharNum) {
        return {TokenType::ILLEGAL, str};
    }
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    TokenType::TokenTypes type;

    if(str == "add") {
        type = TokenType::ADD;
    } else if(str == "alter") {
        type = TokenType::ALTER;
    } else if(str == "all") {
        type = TokenType::ALL;
    } else if(str == "and") {
        type = TokenType::AND;
    } else if(str == "any") {
        type = TokenType::ANY;
    } else if(str == "as") {
        type = TokenType::AS;
    } else if(str == "asc") {
        type = TokenType::ASC;
    } else if(str == "avg") {
        type = TokenType::AVG;
    } else if(str == "by") {
        type = TokenType::BY;
    } else if(str == "check") {
        type = TokenType::CHECK;
    } else if(str == "column") {
        type = TokenType::COLUMN;
    } else if(str == "count") {
        type = TokenType::COUNT;
    } else if(str == "create") {
        type = TokenType::CREATE;
    } else if(str == "delete") {
        type = TokenType::DELETE;
    } else if(str == "desc") {
        type = TokenType::DESC;
    } else if(str == "drop") {
        type = TokenType::DROP;
    } else if(str == "distinct") {
        type = TokenType::DISTINCT;
    } else if(str == "except") {
        type = TokenType::EXCEPT;
    } else if(str == "foreign") {
        type = TokenType::FOREIGN;
    } else if(str == "from") {
        type = TokenType::FROM;
    } else if(str == "group") {
        type = TokenType::GROUP;
    } else if(str == "having") {
        type = TokenType::HAVING;
    } else if(str == "in") {
        type = TokenType::IN;
    } else if(str == "index") {
        type = TokenType::INDEX;
    } else if(str == "is") {
        type = TokenType::IS;
    }  else if(str == "insert") {
        type = TokenType::INSERT;
    }  else if(str == "into") {
        type = TokenType::INTO;
    } else if(str == "join") {
        type = TokenType::JOIN;
    } else if(str == "key") {
        type = TokenType::KEY;
    } else if(str == "like") {
        type = TokenType::LIKE;
    } else if(str == "min") {
        type = TokenType::MIN;
    } else if(str == "max") {
        type = TokenType::MAX;
    } else if(str == "not") {
        type = TokenType::NOT;
    } else if(str == "null") {
        type = TokenType::NUL;
    } else if(str == "or") {
        type = TokenType::OR;
    } else if(str == "order") {
        type = TokenType::ORDER;
    } else if(str == "primary") {
        type = TokenType::PRIMARY;
    } else if(str == "table") {
        type = TokenType::TABLE;
    } else if(str == "select") {
        type = TokenType::SELECT;
    } else if(str == "set") {
        type = TokenType::SET;
    } else if(str == "sum") {
        type = TokenType::SUM;
    } else if(str == "update") {
        type = TokenType::UPDATE;
    } else if(str == "union") {
        type = TokenType::UNION;
    } else if(str == "values") {
        type = TokenType::VALVUES;
    } else if(str == "where") {
        type = TokenType::WHERE;
    }
    else {
        type = TokenType::ID;
    }
    return {type, str};
}

Token Tokenizer::getString(char quotation) {
    std::string str;
    currentPosition ++;
    while(currentPosition < sql_len and sql_str[currentPosition] != quotation) {
        str += sql_str[currentPosition];
        currentPosition ++;
    }
    if(currentPosition < sql_len and sql_str[currentPosition] == quotation) {
        currentPosition ++;
        return {TokenType::STRING, str};
    }
    return {TokenType::ILLEGAL, str};
}

Token Tokenizer::getPunct()  {
    std::string str;
    TokenType::TokenTypes type;
    while(std::ispunct(sql_str[currentPosition]) and currentPosition < sql_len) {
        str += sql_str[currentPosition];
        currentPosition ++;
        if(str == "+" or str == "-" or str == "*" or
           str == "/" or str == "," or str == ";" or
           str == "(" or str == ")" ) break;
    }
    if(str == "+") {
        type = TokenType::PLUS;
    } else if (str == "-") {
        type = TokenType::MINUS;
    } else if (str == "*") {
        type = TokenType::ASTERISK;
    } else if (str == "/") {
        type = TokenType::DIVISION;
    } else if (str == ";") {
        type = TokenType::SEMICOLON;
    } else if (str == ",") {
        type = TokenType::COMMA;
    } else if (str == ">") {
        type = TokenType::GREATER_THAN;
    } else if (str == "<") {
        type = TokenType::LESS_THAN;
    } else if (str == "(") {
        type = TokenType::L_BRACKET;
    } else if (str == ")") {
        type = TokenType::R_BRACKET;
    } else if (str == "=") {
        type = TokenType::EQUAL;
    } else if (str == ">=") {
        type = TokenType::GREATER_EQUAL_TO;
    } else if (str == "<=") {
        type = TokenType::LESS_EQUAL_TO;
    } else if (str == "!=") {
        type = TokenType::NOT_EQUAL;
    } else if (str == "<>") {
        type = TokenType::NOT_EQUAL;
    } else {
        type = TokenType::ILLEGAL;
    }
    return {type, str};
}

bool Tokenizer::isSpace(char a) {
    return a == '\n' or a == '\t' or a == ' ';
}

void Tokenizer::getAllTokens() {
    while(true) {
        this->Tokens.push_back(scanNextTokens());
        if(Tokens.back().type == TokenType::END) {
            break;
        }
    }
}

Token Tokenizer::getNextToken() {
    if(currentTokenPos < Tokens.size()) {
        std::cout << Tokens[currentTokenPos].value << std::endl;
        return Tokens[currentTokenPos ++];
    } else {
        return {TokenType::END, ""};
    }
}

Token Tokenizer::getCurrentToken() {
    if(currentTokenPos < Tokens.size()) {
        return Tokens[currentTokenPos];
    } else {
        return {TokenType::END, ""};
    }
}

void Tokenizer::traceBack() {
    this->currentTokenPos --;
}




