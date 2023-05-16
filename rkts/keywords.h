#include <iostream>
#include <regex>
#include <map>
#include <vector>

std::vector<std::string> keywords({
    "abstract",
    "as",
    "base",
    "bool",
    "break",
    "byte",
    "case",
    "catch",
    "char",
    "checked",
    "const",
    "continue",
    "decimal",
    "default",
    "delegate",
    "do",
    "double",
    "else",
    "enum",
    "event",
    "explicit",
    "extern",
    "false",
    "finally",
    "fixed",
    "float",
    "for",
    "foreach",
    "goto",
    "if",
    "implicit",
    "in",
    "int",
    "interface",
    "internal",
    "is",
    "lock",
    "long",
    "namespace",
    "new",
    "null",
    "object",
    "operator",
    "out",
    "override",
    "params",
    "private",
    "protected",
    "public",
    "readonly",
    "ref",
    "return",
    "sbyte",
    "sealed",
    "short",
    "sizeof",
    "stackalloc",
    "static",
    "string",
    "struct",
    "switch",
    "this",
    "throw",
    "true",
    "try",
    "typeof",
    "uint",
    "ulong",
    "unchecked",
    "unsafe",
    "ushort",
    "using",
    "virtual",
    "void",
    "volatile",
    "while",
    "class"});

std::string keywordRegEx(std::vector<std::string> keywords) {
    std::string result = "(?![^<]*>)\\b(";
    for (auto it = keywords.begin(); it != keywords.end(); ++it) {
        result += *it;
        if (it != keywords.end() - 1) {
        result += "|";
        }
    }
    result += ")\\b";
    return result;
}

std::string highlightKeywords(std::string s, const std::vector<std::string>& keywords) {
    std::string regexPattern = keywordRegEx(keywords);
    std::regex keywordRegex(regexPattern);
    return std::regex_replace(s, keywordRegex, "<span class=keywords>$&</span>");
}
