#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Lexer
{
private:
    vector<string> keywords = {"abstract", "as", "base", "bool", "break", "byte", "case", "catch", "char", "checked", "class", "const", "continue", "decimal", "default", "delegate", "do", "double", "else", "enum", "event", "explicit", "extern", "false", "finally", "fixed", "float", "for", "foreach", "goto", "if", "implicit", "in", "int", "interface", "internal", "is", "lock", "long", "namespace", "new", "null", "object", "operator", "out", "override", "params", "private", "protected", "public", "readonly", "ref", "return", "sbyte", "sealed", "short", "sizeof", "stackalloc", "static", "string", "struct", "switch", "this", "throw", "true", "try", "typeof", "uint", "ulong", "unchecked", "unsafe", "ushort", "using", "virtual", "void", "volatile", "while"};
    vector<string> operators = {"+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", ">>>", "<<<", "=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", ">>>=", "<<<=", "&=", "|=", "^=", "=>", ".", "::", ":", "?", "??", "??=", "->", "=>", "=>>", "=>>>", "=>>>", "=>>=", "=>>>=", "=>>>=", "=>>>="};
    vector<string> punctuation = {",", ";", "(", ")", "{", "}", "[", "]", ":", "::", ".", "?", "??", "??=", "->", "=>", "=>>", "=>>>", "=>>>", "=>>=", "=>>>=", "=>>>=", "=>>>="};
    vector<pair<regex, string>> token_patterns = {
        {regex("\\b(if|else|while|for|switch|case|break|continue|return)\\b"), "keyword"},
        {regex("\\b(\\w+)\\b"), "identifier"},
        {regex("\\b(true|false|null)\\b"), "literal"},
        {regex("\\b(\\d+)\\b"), "literal"},
        {regex("\\b(0x[\\da-fA-F]+)\\b"), "literal"},
        {regex("\\b([\\d.]+f?)\\b"), "literal"},
        {regex("[+\\-*/%<>=!&|\\^~?]+"), "operator"},
        {regex("[;{}\\(\\)\\[\\],.]"), "punctuation"}
    };
public:
    Lexer();
    ~Lexer();
    vector<string> tokenize(string input);
};


