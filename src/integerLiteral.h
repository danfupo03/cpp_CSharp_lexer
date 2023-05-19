#include "highlighter.h"

class IntegerLiteralHighlighter : public Highlighter
{
public:
    IntegerLiteralHighlighter();
    ~IntegerLiteralHighlighter() = default;
};

IntegerLiteralHighlighter::IntegerLiteralHighlighter()
{
    className = "integerLiterals";
    std::string intTypeSuffix = "([uU][lL]?|[lL][uU]?)";
    std::string decoratedDecimalDigit = "(_*[0-9])";
    std::string decimalIntegerLiteral = "([0-9]" + decoratedDecimalDigit + "*" + intTypeSuffix + "?)";
    std::string hexDigit = "[0-9|A-F|a-f]";
    std::string decoratedHexDigit = "(_*" + hexDigit + ")";
    std::string hexIntegerLiteral = "(0x|0X)" + decoratedHexDigit + "+" + intTypeSuffix + "?";
    std::string binaryDigit = "(0|1)";
    std::string decoratedBinaryDigit = "(_*" + binaryDigit + ")";
    std::string binaryIntegerLiteral = "(0b|0B)" + decoratedBinaryDigit + "+" + intTypeSuffix + "?";
    std::string integerLiteral = "\\b(" + decimalIntegerLiteral + "|" + hexIntegerLiteral + "|" + binaryIntegerLiteral + ")\\b";
    regexp = std::regex(integerLiteral);
}
