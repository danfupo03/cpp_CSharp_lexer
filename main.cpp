#include <regex>
#include <iostream>
#include <fstream>
#include "lexer.h"
#include "rkts/keywords.h"
#include "rkts/operators.h"

int main()
{

    // (define output3
    //   (highlightIntegerLiteral
    //    (highlightRealLiteral
    //     (highlightStringLiteral
    //      (highlightCharLiteral (highlightKeywords (highlightComments (highlightOperators input))))))))

    std::ifstream input("input.txt");
    std::string inputString((std::istreambuf_iterator<char>(input)),
                            std::istreambuf_iterator<char>());

    std::string output = highlightKeywords(inputString, keywords), output2 = highlightOperators(output, operators);

    std::ofstream output_file("output.html");

    output_file << "<head> <link rel='stylesheet' href='styles.css'> <title>problemSituation</title> </head><style>span *{color:inherit !important}</style><pre>"
                << output << output2
                << "</pre>";

    output_file.close();

    return 0;
}
