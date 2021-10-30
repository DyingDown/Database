//
// Created by o_oya on 2021/10/29.
//


#include <gtest/gtest.h>
#include "Parser.h"
#include "SQLCreateTableStatement.h"
//#include <iostream>



TEST(Parser, SQLCreateTableStatement) {
    Parser parser("Create table color(red int, green string, blue double);");
    SQLCreateTableStatement stmt = parser.CreateTable();
    EXPECT_EQ(stmt.TableName, "color");

}