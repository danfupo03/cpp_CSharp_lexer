#include "highlighter.h"

class OperatorsHighlighter : public Highlighter
{
public:
    OperatorsHighlighter();
    ~OperatorsHighlighter() = default;
};

OperatorsHighlighter::OperatorsHighlighter()
{
    className = "operators";

    std::vector<std::string> operators({"{",
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
                                        "=>"});
    std::string regexString = "(";
    for (auto it = operators.begin(); it != operators.end(); ++it)
    {
        std::regex specialChars{R"([-[\]{}()*+?.,\^$|#\s])"};
        std::string sanitized = std::regex_replace(*it, specialChars, R"(\$&)");
        regexString += sanitized;
        if (it != operators.end() - 1)
        {
            regexString += "|";
        }
    }
    regexString += ")+";

    regexp = std::regex(regexString);
}
