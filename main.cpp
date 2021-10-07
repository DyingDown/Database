#include <iostream>
#include "InputBuffer.h"
#include "LexicalAnalyzer.h"

using namespace std;
int main() {
    InputBuffer a = InputBuffer();
    a.read_input();
    LexicalAnalyzer b = LexicalAnalyzer(a.input_buffer);
    Token t = b.scanNextTokens();
    while(t.type != TokenType::END) {
        std::cout << t.value<< " " << t.type << std::endl;
        t = b.scanNextTokens();
    }
    std::cout << t.value << std::endl;
    return 0;
}