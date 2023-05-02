#include <iostream>
#include <vector>
#include <regex>
#include <map>

using namespace std;

string operatorSafe(string s)
{
    return "<[^/>]*>" + s + "</[^>]*>";
}

enum TokenType
{
    KEYWORD,
    OPERATOR_OR_PUNCTUATOR,
    INTEGER_LITERAL,
    REAL_LITERAL,
    STRING_LITERAL,
    CHARACTER_LITERAL,
    COMMENT
};

map<TokenType, string> token_class_name = {
    {OPERATOR_OR_PUNCTUATOR, "operatorOrPunctuator"},
    {KEYWORD, "keyword"},
    {INTEGER_LITERAL, "integerLiteral"},
    {REAL_LITERAL, "realLiteral"},
    {STRING_LITERAL, "stringLiteral"},
    {CHARACTER_LITERAL, "characterLiteral"},
    {COMMENT, "comment"}};

class Lexer
{
private:
    vector<pair<TokenType, regex>> token_regexes = {

        {COMMENT,
         regex("(" + operatorSafe("//") + ".* | " + operatorSafe("/\\*") + ".*" + operatorSafe("\\*/") + ")")},
        {KEYWORD,
         regex("\\b(abstract|as|base|bool|break|byte|case|catch|char|checked|const|continue|decimal|default|delegate|do|double|else|enum|event|explicit|extern|false|finally|fixed|float|for|foreach|goto|if|implicit|in|int|interface|internal|is|lock|long|namespace|new|null|object|operator|out|override|params|private|protected|public|readonly|ref|return|sbyte|sealed|short|sizeof|stackalloc|static|string|struct|switch|this|throw|true|try|typeof|uint|ulong|unchecked|unsafe|ushort|using|virtual|void|volatile|while)\\b")},
        {REAL_LITERAL,
         regex("[0-9]+\\" + operatorSafe(".") + "[0-9]+")},
        {INTEGER_LITERAL,
         regex("[0-9]+")},
        {STRING_LITERAL,
         regex("\"[^\"]*\"")},
        {CHARACTER_LITERAL,
         regex("'[^']*'")}};

public:
    Lexer() = default;
    ~Lexer() = default;
    string lex(string);
    string wrap(string, string);
};

string Lexer::lex(string input)
{
    for (auto token_regex : token_regexes)
    {
        cout << token_class_name[token_regex.first] << endl;
        input = regex_replace(input, token_regex.second, wrap("$&", token_class_name[token_regex.first]));
    }

    return "<head> <link rel='stylesheet' href='styles.css'> <title>problemSituation</title> </head><style>span *{color:inherit !important}</style><pre>" + input +
           "</pre>";
}

string Lexer::wrap(string input, string class_name)
{
    return "<span class=" + class_name + ">" + input + "</span>";
}
