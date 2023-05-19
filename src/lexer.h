#include <iostream>
#include <vector>
#include "highlighter.h"
#include "keywords.h"
#include "charLiteral.h"
#include "stringLiteral.h"

using namespace std;

// string operatorSafe(string s)
// {
//     return "<[^/>]*>" + s + "</[^>]*>";
// }

class Lexer
{
public:
    Lexer();
    ~Lexer() = default;
    string lex(string);

private:
    vector<Highlighter *> highlighters;
};

Lexer::Lexer()
{
    highlighters.push_back(new KeywordsHighlighter());
    // highlighters.push_back(new OperatorsHighlighter());
    // highlighters.push_back(new CommentsHighlighter());
    highlighters.push_back(new CharLiteralHighlighter());
    highlighters.push_back(new StringLiteralHighlighter());
    // highlighters.push_back(new RealLiteralHighlighter());
    // highlighters.push_back(new IntegerLiteralHighlighter());
}

string Lexer::lex(string input)
{
    std::string output = input;
    for (auto highlighter : highlighters)
    {
        output = highlighter->highlight(output);
    }
    return output;
}
