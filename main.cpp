#include <iostream>
#include "InputBuffer.h"
#include "Tokenizer.h"
#include "Parser.h"

using namespace std;
int main() {
    InputBuffer a = InputBuffer();
    a.read_input();
    Tokenizer b = Tokenizer(a.input_buffer);
//    Token t = b.scanNextTokens();
    for(auto i : b.Tokens) {
        std::cout << i.value<< " " << i.type << std::endl;
    }
    Parser p = Parser(a.input_buffer);
//    std::cout << t.value << std::endl;
    return 0;
}