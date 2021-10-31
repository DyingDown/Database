#include <iostream>
#include <utility>
#include "InputBuffer.h"
#include "Tokenizer.h"
#include "Parser.h"

using namespace std;

void testCreateTable(std::string sql);
void testDeleteStatement(std::string sql);
void testDropTable(std::string sql);
void testInsert(std::string sql);
void testSelect(std::string sql);
void testUpdate(std::string sql);
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
    std::string sql;
    sql = "Create table color(red int, green string, blue float);";
    sql = "delete from color where green >= '123' and blue != 12.5;";
    sql = "drop table color, canvas;";
    sql = "Insert into color VALUES (255, 45.5);";
    sql = "Select *, color.red as blue from color, canvas where green > 5 and blue < 6;";
    sql = "update student set number = 1.2, name = 'asd' where id = 123;";
    try {
        testUpdate(sql);
    } catch (const char* msg){
        std::cout << msg << std::endl;
    }
    return 0;
}
void testCreateTable(std::string sql) {
    Parser parser(std::move(sql));
    SQLCreateTableStatement stmt = parser.CreateTable();
    std::cout << stmt.TableName << std::endl;
    for(const auto& i: stmt.columns) {
        std::cout << i.columnName << " " << i.columnType << endl;
    }
}

void testDeleteStatement(std::string sql) {
    Parser parser(std::move(sql));
//        for (auto i : parser.Lex.Tokens) cout << i.value << " " << i.type << endl;
    SQLDeleteStatement stmt = parser.DeleteRow();
    std::cout << stmt.tableName << std::endl;
    for(int i = 0, j = 0; i < stmt.expr.exprs.size() or j < stmt.expr.ops.size(); i ++, j ++) {
        if(i < stmt.expr.exprs.size()){
            stmt.expr.exprs[i].leftVal.printValue();
            cout << (stmt.expr.exprs[i].compareOp == TokenType::GREATER_EQUAL_TO) << endl;
            stmt.expr.exprs[i].rightVal.printValue();
        }
        if(j < stmt.expr.ops.size())
            cout << (int)(stmt.expr.ops[j] == TokenType::AND) << endl;
    }
}

void testDropTable(std::string sql) {
    Parser parser(std::move(sql));
    SQLDropTableStatement stmt = parser.DropTable();
    for(const auto& i : stmt.tableNames) cout << i << endl;
}

void testInsert(std::string sql) {
    Parser parser(std::move(sql));
    SQLInsertStatement stmt = parser.InsertRow();
    cout << "table name:" << stmt.tableName << endl;
    for(const auto& i : stmt.columnNames) cout << i << " " ;
    cout << endl;
    for(auto i : stmt.values) i.printValue();
    cout << endl;
}

void testSelect(std::string sql) {
    Parser parser(std::move(sql));
    SQLSelectStatement stmt = parser.Select();
    cout << "Select List:" << endl;
    for(const auto& i : stmt.selectList) {
        cout << i.tableName << "." << i.columnName << " as " << i.newColumnName << endl;
    }
    cout << "Table Names:" << endl;
    for(const auto& i : stmt.tableLists) {
        cout << i << endl;
    }
    cout << "Expressions:" << endl;
    for(int i = 0, j = 0; i < stmt.expr.exprs.size() or j < stmt.expr.ops.size(); i ++, j ++) {
        if(i < stmt.expr.exprs.size()){
            stmt.expr.exprs[i].leftVal.printValue();
            cout << (stmt.expr.exprs[i].compareOp == TokenType::GREATER_THAN) << endl;
            stmt.expr.exprs[i].rightVal.printValue();
        }
        if(j < stmt.expr.ops.size())
            cout << (int)(stmt.expr.ops[j] == TokenType::AND) << endl;
    }
}

void testUpdate(std::string sql) {
    Parser parser(std::move(sql));
    SQLUpdateStatement stmt = parser.Update();
    cout << "Table name: " << stmt.tableName << endl;
    for(auto i : stmt.assigns) {
        cout << i.columnName << " = ";
        i.value.printValue();
    }
    cout << "Expressions:" << endl;
    for(int i = 0, j = 0; i < stmt.expr.exprs.size() or j < stmt.expr.ops.size(); i ++, j ++) {
        if(i < stmt.expr.exprs.size()){
            stmt.expr.exprs[i].leftVal.printValue();
            cout << (stmt.expr.exprs[i].compareOp == TokenType::EQUAL) << endl;
            stmt.expr.exprs[i].rightVal.printValue();
        }
        if(j < stmt.expr.ops.size())
            cout << (int)(stmt.expr.ops[j] == TokenType::AND) << endl;
    }
}