#include "highlighter.h"

class RealLiteralHighlighter : public Highlighter
{
public:
    RealLiteralHighlighter();
    ~RealLiteralHighlighter() = default;
};

RealLiteralHighlighter::RealLiteralHighlighter()
{
    className = "realLiterals";

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

    std::string decimalDigit = "[0-9]";
    std::string decoratedDecimalDigit = "(_*" + decimalDigit + ")";
    std::string realTypeSuffix = "[FfDdMm]";
    std::string sign = operatorSafe("(\\+|-)");
    std::string exponentPart = "([eE]" + sign + "?" + decimalDigit + decoratedDecimalDigit + "*)";
    std::string realLiteral = "\\s(" + decimalDigit + decoratedDecimalDigit + "*" + operatorSafe("\\.") + decimalDigit + decoratedDecimalDigit + "*" + exponentPart + "?" + realTypeSuffix + "?|" + operatorSafe("\\.") + decimalDigit + decoratedDecimalDigit + "*" + exponentPart + "?" + realTypeSuffix + "?|" + decimalDigit + decoratedDecimalDigit + "*" + exponentPart + realTypeSuffix + "?|" + decimalDigit + decoratedDecimalDigit + "*" + realTypeSuffix + ")\\b";

    regexp = std::regex(realLiteral);
}