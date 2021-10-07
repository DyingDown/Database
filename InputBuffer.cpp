//
// Created by o_oyao on 2021/9/11.
//

#include "InputBuffer.h"
#include <iostream>

void InputBuffer::print_prompt () {
    printf("sql > ");
}

void InputBuffer::read_input() {
    std::string line;
    while(true) {
        this->print_prompt();
        getline(std::cin, line);
        this->input_buffer += line;
        int i = line.length() - 1;
        while((line[i] == '\n' or line[i] == ' ' or line[i] == '\t') and i >= 0) {
            i --;
        }
        if(line[i] == ';') break;
    }
}
