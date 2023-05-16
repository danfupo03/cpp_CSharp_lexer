#include <iostream>
#include <regex>
#include <map>
#include <vector>

std::vector<std::string> operators({
    "{",
    "}",
    "[",
    "]",
    "(",
    ")",
    ".",
    ",",
    ":",
    ";",
    "+",
    "-",
    "*",
    "/",
    "%",
    "&",
    "|",
    "^",
    "!",
    "~",
    "=",
    "<",
    ">",
    "?",
    "??",
    "::",
    "++",
    "--",
    "&&",
    "||",
    "->",
    "==",
    "!=",
    "<=",
    ">=",
    "+=",
    "-=",
    "*=",
    "/=",
    "%=",
    "&=",
    "|=",
    "^=",
    "<<",
    "<<=",
    "=>"
});

std::regex operatorRegEx(std::vector<std::string> operators) {
    std::string pattern = "(";
    for (auto it = operators.begin(); it != operators.end(); ++it) {
        pattern += *it;
        if (it != operators.end() - 1) {
            pattern += "|";
        }
    }
    pattern += ")+";
    return std::regex(pattern);
};

std::string highlightOperators(std::string s, std::vector<std::string> operators) {
    std::regex operatorRegex = operatorRegEx(operators);
    return std::regex_replace(s, operatorRegex, "<span class=operators>$&</span>");
}