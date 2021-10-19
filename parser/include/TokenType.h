//
// Created by o_oyao on 2021/10/5.
//

#ifndef DATABASE_TOKENTYPE_H
#define DATABASE_TOKENTYPE_H


class TokenType {
public:
    enum TokenTypes{
        INT,                 // Integers
        STRING,
        FLOAT,
        ID,

        ADD,
        ALTER,
        ALL,
        AND,
        ANY,
        AS,
        ASC,                 // 升序
        AVG,
        BY,
        CHECK,
        COLUMN,
        COUNT,
        CREATE,
        DELETE,
        DESC,                // descending  降序
        DROP,              // keywords
        DISTINCT,
        EXCEPT,
        FOREIGN,
        FROM,
        GROUP,
        HAVING,
        IN,
        INDEX,
        INSERT,
        INTO,
        IS,
        JOIN,
        KEY,
        LIKE,
        MIN,
        MAX,
        NOT,
        NUL,
        OR,
        ORDER,
        PRIMARY,
        TABLE,
        SELECT,
        SET,
        SUM,
        UPDATE,
        UNION,
        VALVUES,
        WHERE,

        L_BRACKET,            // (
        R_BRACKET,            // )
        SEMICOLON,            // ;
        COMMA,                // ,
        DOT,                  // .
        ASTERISK,             // '*'
        PLUS,                 // +
        MINUS,                // -
        DIVISION,             // /
        GREATER_THAN,         // >
        LESS_THAN,            // <
        GREATER_EQUAL_TO,     // >=
        LESS_EQUAL_TO,        // <=
        EQUAL,                // =
        NOT_EQUAL,            // != <>
        ILLEGAL,
        END
    };
};


#endif //DATABASE_TOKENTYPE_H
