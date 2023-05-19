#include <regex>
#include <iostream>
#include <fstream>
#include "src/lexer.h"

int main()
{
    std::ifstream input("input.txt");
    std::string inputString((std::istreambuf_iterator<char>(input)),
                            std::istreambuf_iterator<char>());

    Lexer lexer;

    inputString = lexer.lex(inputString);

    std::ofstream output_file("output.html");

    output_file << "<head> <link rel='stylesheet' href='styles.css'> <title>problemSituation</title> </head><style>span *{color:inherit !important}</style><pre>"
                << inputString
                << "</pre>";

    output_file.close();

    return 0;
}
