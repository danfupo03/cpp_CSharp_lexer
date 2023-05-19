#include "highlighter.h"

class KeywordsHighlighter : public Highlighter
{
public:
    KeywordsHighlighter();
    ~KeywordsHighlighter() = default;
};

KeywordsHighlighter::KeywordsHighlighter()
{
    className = "keywords";

    std::vector<std::string> keywords({"abstract",
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

    std::string regexString = "(?![^<]*>)\\b(";
    for (auto it = keywords.begin(); it != keywords.end(); ++it)
    {
        regexString += *it;
        if (it != keywords.end() - 1)
        {
            regexString += "|";
        }
    }
    regexString += ")\\b";

    regexp = std::regex(regexString);
}
