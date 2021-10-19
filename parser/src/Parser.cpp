//
// Created by o_oya on 2021/10/11.
//

#include "../include/Parser.h"

#include <utility>
#include "../include/Token.h"
#include "../include/LexicalAnalyzer.h"
#include "../include/TokenType.h"

Parser::Parser(std::string sql_stm) {
    Lex = LexicalAnalyzer(std::move(sql_stm));
}

bool Parser::Match(int targetType) {
    if(Lex.getNextToken().type == targetType) return true;
    return false;
}

SQLCreateTableStatement Parser::CreateTable() {
    SQLCreateTableStatement stmt;
    if(Match(TokenType::CREATE) and Match(TokenType::TABLE)) {
        if(Lex.getCurrentToken().type != TokenType::ID) {
            throw "Doesn't declare the table name";
        }
        stmt.TableName = Lex.getNextToken().value;
        if(Match(TokenType::L_BRACKET)) {
            do {
                stmt.columns.push_back(getColumnDefine());
            } while(Match(TokenType::COMMA));
            if(Match(TokenType::R_BRACKET) and Match(TokenType::SEMICOLON)) {
                return stmt;
            } else {
                throw "No matching ')' or no ending ';'";
            }
        } else {
            return stmt;
        }
    } else {
        throw "Not a Create Table Statement!";
    }
}

SQLDeleteStatement Parser::DeleteRow() {
//    SQLDeleteStatement stmt;
    if(Match(TokenType::DELETE) and Match(TokenType::FROM)) {
        if(Lex.getCurrentToken().type != TokenType::ID) {
            throw "Doesn't declare the table name";
        }
        std::string tableName = Lex.getNextToken().value;
        if(Match(TokenType::WHERE)) {
            SQLExpression expr = getExpressions();
            if(Match(TokenType::SEMICOLON))
                return {tableName, expr};
            else
                throw "Missing ';'";
        } else {
            throw "Not a complete delete statement";
        }
    } else {
        throw "Not a Delete Statement";
    }
    return SQLDeleteStatement();
}

SQLDropTableStatement Parser::DropTable() {
    std::vector<std::string> tablenames;
    if(Match(TokenType::DROP) and Match(TokenType::TABLE)) {
        do {
            if(Lex.getCurrentToken().type == TokenType::ID) {
                tablenames.push_back(Lex.getNextToken().value);
            } else {
                throw "Missing table name";
            }
        } while(Match(TokenType::COMMA));
        if(Match(TokenType::SEMICOLON))
            return {tablenames};
        else
            throw "Missing ';'";
    } else {
        throw "Not a Drop Table Statement";
    }
}

SQLInsertStatement Parser::InsertRow() {
    SQLInsertStatement stmt;
    if(Match(TokenType::INSERT) and Match(TokenType::INTO)) {
        if(Lex.getCurrentToken().type == TokenType::ID) {
            stmt.tableName = Lex.getNextToken().value;
            if(!Match(TokenType::L_BRACKET)) {
                throw "missing '('";
            }
            do {
                if(Lex.getCurrentToken().type == TokenType::ID) {
                    stmt.columnNames.push_back(Lex.getNextToken().value);
                } else {
                    throw "expeted a column name";
                }
            } while(Match(TokenType::COMMA));
            if(!Match(TokenType::R_BRACKET)) {
                throw "missing ')'";
            }
            if(!Match(TokenType::VALVUES)) {
                throw "missing 'values'";
            }
            if(!Match(TokenType::L_BRACKET)) {
                throw "missing '('";
            }
            do {
                stmt.values.push_back(getValue());
            } while(Match(TokenType::COMMA));
            if(!Match(TokenType::R_BRACKET)) {
                throw "missing ')'";
            }
            if(!Match(TokenType::SEMICOLON)) throw "missing ';'";
            return stmt;
        } else {
            throw "Doesn't specify the table";
        }
    } else {
        throw "Not a insert statement";
    }
    return stmt;
}

SQLSelectStatement Parser::Select() {
    SQLSelectStatement stmt;
    if(Match(TokenType::SELECT)) {
        do {
            stmt.selectList.push_back(getSelectElement());
        } while(Match(TokenType::COMMA));
        if(!Match(TokenType::FROM)) throw "Not a valid select";
        do {
            if(Lex.getCurrentToken().type == TokenType::ID) {
                stmt.tableLists.push_back(Lex.getNextToken().value);
            }
        } while(Match(TokenType::COMMA));
        if(Lex.getCurrentToken().type == TokenType::WHERE) {
            stmt.expr = getExpressions();
        }
    } else {
        throw "Not a select statement";
    }
    return stmt;
}

SQLUpdateStatement Parser::Update() {
    SQLUpdateStatement stmt;
    if(Match(TokenType::UPDATE)) {
        if(Lex.getCurrentToken().type == TokenType::ID) {
            stmt.tableName = Lex.getNextToken().value;
        }
        if(!Match(TokenType::SET)) throw "not valid";
        do {
            stmt.assigns.push_back(getAssigns());
        } while(Match(TokenType::COMMA));
        if(Match(TokenType::WHERE)) {
            stmt.expr = getExpressions();
        }
    }
    return stmt;
}

SQLColumnDefine Parser::getColumnDefine() {
    if(Lex.getCurrentToken().type != TokenType::ID) {
        throw "No column name";
    }
    std::string columnName = Lex.getNextToken().value;
    Token nextToken = Lex.getNextToken();
    if(nextToken.value == "int" or nextToken.value == "float" or nextToken.value == "string") {
        return {columnName, SQLColumnDefine::stringToType[nextToken.value]};
    } else {
        throw "Missing column Type";
    }
}

SQLExpression Parser::getExpressions() {
    SQLExpression expression;
    SQLSingleExpression exp = getSingleExpression();
    expression.exprs.push_back(exp);
    while(true) {
        TokenType::TokenTypes type = getLogicOp();
        if(type == TokenType::ILLEGAL) break;
        expression.ops.push_back(type);
        exp = getSingleExpression();
        expression.exprs.push_back(exp);
    }
    return expression;
}

SQLSingleExpression Parser::getSingleExpression() {
    SQLSingleExpression expr;
    expr.leftVal = getValue();
    expr.compareOp =  getCompare();
    expr.rightVal = getValue();
    return expr;
}

SQLValue Parser::getValue() {
    Token currentToken = Lex.getNextToken();
    if(currentToken.type == TokenType::ID or
       currentToken.type == TokenType::STRING or
       currentToken.type == TokenType::INT or
       currentToken.type == TokenType::FLOAT) {
        return {currentToken};
    } else {
        throw "Not a valid parameter";
    }
}

TokenType::TokenTypes Parser::getCompare() {
    Token token = Lex.getNextToken();
    if(token.type >= TokenType::ASTERISK and token.type <= TokenType::NOT_EQUAL) {
        return token.type;
    } else {
        return TokenType::ILLEGAL;
        throw "Not a valid comparison operator";
    }
    return TokenType::ILLEGAL;
}

TokenType::TokenTypes Parser::getLogicOp() {
    Token token = Lex.getNextToken();
    if(token.type == TokenType::AND or token.type == TokenType::OR) {
        return token.type;
    } else {
        return TokenType::ILLEGAL;
        throw "Not a valid Logic operator";
    }
    return TokenType::ILLEGAL;
}

SQLSelectListElement Parser::getSelectElement() {
    SQLSelectListElement ele;
    Token token = Lex.getNextToken();
    if(token.type == TokenType::ASTERISK) {
        ele.columnName = '*';
    } else if(token.type == TokenType::ID){
        ele.columnName = token.value;
    } else {
        throw "expected a table name or '*'";
    }
    return ele;
}

SQLAssignStatement Parser::getAssigns() {
    SQLAssignStatement stmt;
    if(Lex.getCurrentToken().type == TokenType::ID) {
        stmt.columnName = Lex.getNextToken().value;
        if(!Match(TokenType::EQUAL)) throw "not a valid assign statement";
        stmt.value = getValue();
    }
    return stmt;
}



