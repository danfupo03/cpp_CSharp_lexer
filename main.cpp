#include <regex>
#include <iostream>
#include <fstream>
#include "lexer.h"

int main()
{
    Lexer lexer;
    ifstream file("input.cs");
    ofstream output("output.html");
    string input((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    string outputText = lexer.lex(input);

    output << outputText;

    file.close();
    output.close();

    return 0;
}
