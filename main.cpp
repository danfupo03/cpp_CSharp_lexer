#include <regex>
#include <iostream>
#include <fstream>
#include "lexer.h"
#include "keywords.h"

int main()
{
    //     (define input (file->string "input.txt"))

    // (define output3
    //   (highlightIntegerLiteral
    //    (highlightRealLiteral
    //     (highlightStringLiteral
    //      (highlightCharLiteral (highlightKeywords (highlightComments (highlightOperators input))))))))

    // (define finalOutput
    //   (string-append
    //    "<head> <link rel='stylesheet' href='styles.css'> <title>problemSituation</title> </head><style>span *{color:inherit !important}</style><pre>"
    //    output3
    //    "</pre>"))

    // (define output-port (open-output-file "main.html" #:exists 'replace))
    // (write-string finalOutput output-port)
    // (close-output-port output-port)

    std::ifstream input("input.txt");
    std::string inputString((std::istreambuf_iterator<char>(input)),
                            std::istreambuf_iterator<char>());

    std::string output = highlightKeywords(inputString, keywords);

    std::ofstream output_file("output.html");

    output_file << "<head> <link rel='stylesheet' href='styles.css'> <title>problemSituation</title> </head><style>span *{color:inherit !important}</style><pre>"
                << output
                << "</pre>";

    output_file.close();

    return 0;
}
