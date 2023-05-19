#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <string>
#include <regex>

std::string operatorSafe(std::string s)
{
    return "(<[^/>]*>" + s + "</[^>]*>)";
}
class Highlighter
{
public:
    std::string highlight(std::string);

protected:
    Highlighter() = default;
    std::string className;
    std::regex regexp;
};

std::string Highlighter::highlight(std::string input)
{
    return std::regex_replace(input, regexp, "<span class=" + className + ">$&</span>");
}

#endif // !HIGHLIGHTER_H