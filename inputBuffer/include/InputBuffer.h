//
// Created by o_oyao on 2021/9/11.
//

#include <string>

#ifndef DATABASE_INPUTBUFFER_H
#define DATABASE_INPUTBUFFER_H


class InputBuffer {
public:
    std::string input_buffer;
    InputBuffer() {
        input_buffer = "";
    }
    void print_prompt();
    void read_input();
};


#endif //DATABASE_INPUTBUFFER_H
