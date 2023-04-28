#include <regex>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string regex_escape(const std::string& str) {
    static const std::regex re(R"([-[\]{}()*+?.,\^$|#\s])");
    return std::regex_replace(str, re, R"(\$&)");
}

int main() {
    std::vector<std::string> keywords = {"foo", "bar", "baz"};
    std::string pattern = "(?![^<]*>)\\b(";
    for (auto kw : keywords) {
        pattern += regex_escape(kw) + "|";
    }
    pattern.pop_back();
    pattern += ")\\b";
    std::regex keywordRegex(pattern);
    std::string testString = "This is a test string with foo, bar, and baz.";
    std::smatch match;
    std::ofstream outFile("output.html");
    outFile << "<html><head><title>Keyword Highlighter</title><style>.keyword{color:red;}</style></head><body><p>";
    while (std::regex_search(testString, match, keywordRegex)) {
        outFile << match.prefix();
        outFile << "<span class=\"keyword\">" << match[0] << "</span>";
        testString = match.suffix();
    }
    outFile << testString << "</p></body></html>";
    outFile.close();
    return 0;
}
