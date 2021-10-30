#include <iostream>
#include "InputBuffer.h"
#include "Tokenizer.h"
#include "Parser.h"

using namespace std;
int main() {
    // input
    /* input test
    InputBuffer a = InputBuffer();
    a.read_input();
    Tokenizer b = Tokenizer(a.input_buffer);
    for(auto i : b.Tokens) {
        std::cout << i.value<< " " << i.type << std::endl;
    }
    Parser p = Parser(a.input_buffer);
    */
    // create table
    /*** create table test
    try {
        Parser parser("Create table color(red int, green string, blue float);");
        SQLCreateTableStatement stmt = parser.CreateTable();
        std::cout << stmt.TableName << std::endl;
        for(auto i: stmt.columns) {
            std::cout << i.columnName << " " << i.columnType << endl;
        }
    } catch (const char* msg){
        std::cout << msg << std::endl;
    }
    */

    // delete statement
    try {
        Parser parser("delete from color where green >= '123' and blue != 12.5;");
//        for (auto i : parser.Lex.Tokens) cout << i.value << endl;
        SQLDeleteStatement stmt = parser.DeleteRow();
        std::cout << stmt.tableName << std::endl;
        for(int i = 0, j = 0; i < stmt.expr.exprs.size() or j < stmt.expr.ops.size(); i ++, j ++) {
            if(i < stmt.expr.exprs.size())
                cout << stmt.expr.exprs[i].leftVal.getString() << " " << (stmt.expr.exprs[i].compareOp == TokenType::GREATER_EQUAL_TO) << " " << stmt.expr.exprs[i].rightVal.getInt() << std::endl;
            if(j < stmt.expr.ops.size())
                cout << (stmt.expr.ops[j] == TokenType::AND) << endl;
        }
    } catch (const char* msg){
        std::cout << msg << std::endl;
    }
    return 0;
}