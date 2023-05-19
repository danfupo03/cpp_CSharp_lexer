#include "highlighter.h"
class CommentsHighlighter : public Highlighter
{
public:
    CommentsHighlighter();
    ~CommentsHighlighter() = default;
};

CommentsHighlighter::CommentsHighlighter()
{
    className = "comments";
    std::string singleLineComment = operatorSafe("//") + "[^\n]*\\\n";
    std::string delimitedComment = operatorSafe("/\\*") + "(.*?)" + operatorSafe("\\*/");
    std::string regexString = "(" + singleLineComment + "|" + delimitedComment + ")";
    regexp = std::regex(regexString, std::regex::extended);
}
