#include "highlighter.h"

std::string operatorSafe(std::string s)
{
    return "(<[^/>]*>" + s + "</[^>]*>)";
}


class RealLiteralHighlighter : public Highlighter
{
public:
    RealLiteralHighlighter();
    ~RealLiteralHighlighter() = default;
};

RealLiteralHighlighter::RealLiteralHighlighter()
{
    className = "realLiteral";

    // (define operatorSafe (lambda (s) (string-append "(<[^/>]*>" s "</[^>]*>)")))

    // (define decimalDigit "[0-9]")

    // (define decoratedDecimalDigit (string-append "(_*" decimalDigit ")"))

    // (define realTypeSuffix "[FfDdMm]")

    // (define sign (operatorSafe "(\\+|-)"))

    // (define exponentPart (string-append "([eE]" sign "?" decimalDigit decoratedDecimalDigit "*)"))

    // (define realLiteral
    //   (string-append
    //    "\\s(" decimalDigit decoratedDecimalDigit "*" (operatorSafe "\\.") decimalDigit decoratedDecimalDigit "*" exponentPart "?" realTypeSuffix "?|"
    //    (operatorSafe "\\.") decimalDigit decoratedDecimalDigit "*" exponentPart "?" realTypeSuffix "?|"
    //    decimalDigit decoratedDecimalDigit "*" exponentPart realTypeSuffix "?|"
    //    decimalDigit decoratedDecimalDigit "*" realTypeSuffix ")\\b" ))

    std::string operatorSafe = "(<[^/>]*>" + className + "</[^>]*>)";

    regexp = std::regex(floatingLiteral);
}