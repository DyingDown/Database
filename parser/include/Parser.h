//
// Created by o_oya on 2021/10/11.
//

#ifndef DATABASE_PARSER_H
#define DATABASE_PARSER_H

#include "Tokenizer.h"
#include "SQLCreateTableStatement.h"
#include "SQLDeleteStatement.h"
#include "SQLDropTableStatement.h"
#include "SQLInsertStatement.h"
#include "SQLSelectStatement.h"
#include "SQLUpdateStatement.h"
#include "SQLAssignStatement.h"

class Parser {
private:
    bool Match(int targetType);
    SQLColumnDefine getColumnDefine();
    SQLExpression getExpressions();
    SQLSingleExpression getSingleExpression();
    SQLValue getValue();
    TokenType::TokenTypes getCompare();
    TokenType::TokenTypes getLogicOp();
    SQLSelectListElement getSelectElement();
    SQLAssignStatement getAssigns();
public:
    Tokenizer Lex;
    Parser(std::string sql_statement);
    SQLCreateTableStatement CreateTable();
    SQLDeleteStatement DeleteRow();
    SQLDropTableStatement DropTable();
    SQLInsertStatement InsertRow();
    SQLSelectStatement Select();
    SQLUpdateStatement Update();

};


#endif //DATABASE_PARSER_H
