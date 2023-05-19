#include "highlighter.h"

class CharLiteralHighlighter : public Highlighter
{
public:
    CharLiteralHighlighter();
    ~CharLiteralHighlighter() = default;
};

CharLiteralHighlighter::CharLiteralHighlighter()
{
    className = "charLiteral";

    std::string hexDigit = "[0-9A-Fa-f]";
    std::string unicodeEscapeSequence = "(\\\\u" + hexDigit + hexDigit + hexDigit + hexDigit + "|\\\\U" + hexDigit + hexDigit + hexDigit + hexDigit + hexDigit + hexDigit + hexDigit + hexDigit + ")";
    std::string hexEscapeSequence = "\\\\x" + hexDigit + hexDigit + "?" + hexDigit + "?" + hexDigit + "?";
    std::string singleCharacter = "[^'\\\\(\\\n)]";
    std::string simpleEscapeSequence = "\\\\['\"\\\\abfnrtv0]";
    std::string character = "(" + singleCharacter + "|" + simpleEscapeSequence + "|" + hexEscapeSequence + "|" + unicodeEscapeSequence + ")";

    std::string charLiteral = "'(" + character + ")'";

    regexp = std::regex(charLiteral);
}