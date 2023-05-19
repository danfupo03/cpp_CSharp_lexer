#include "highlighter.h"

class StringLiteralHighlighter : public Highlighter
{
public:
    StringLiteralHighlighter();
    ~StringLiteralHighlighter() = default;
};

StringLiteralHighlighter::StringLiteralHighlighter()
{
    className = "stringLiteral";

    std::string hexDigit = "[0-9A-Fa-f]";
    std::string unicodeEscapeSequence = "(\\\\u" + hexDigit + hexDigit + hexDigit + hexDigit + "|\\\\U" + hexDigit + hexDigit + hexDigit + hexDigit + hexDigit + hexDigit + hexDigit + hexDigit + ")";
    std::string hexEscapeSequence = "\\\\x" + hexDigit + hexDigit + "?" + hexDigit + "?" + hexDigit + "?";
    std::string simpleEscapeSequence = "\\\\['\"\\\\abfnrtv0]";
    std::string singleRegularStringLiteralCharacter = "[^\"\\\\]";
    std::string regularStringLiteralCharacter = "(" + singleRegularStringLiteralCharacter + "|" + simpleEscapeSequence + "|" + hexEscapeSequence + "|" + unicodeEscapeSequence + ")";
    std::string regularStringLiteral = "\"(" + regularStringLiteralCharacter + "*)\"";
    std::string quoteEscapeSequence = "\"\"";
    std::string singleVerbatimStringLiteralCharacter = "[^\"]";
    std::string verbatimStringLiteralCharacter = "(" + singleVerbatimStringLiteralCharacter + "|" + quoteEscapeSequence + ")";
    std::string verbatimStringLiteral = "@\"" + verbatimStringLiteralCharacter + "*\"";
    std::string stringLiteral = "(" + regularStringLiteral + "|" + verbatimStringLiteral + ")";

    regexp = std::regex(stringLiteral);

}