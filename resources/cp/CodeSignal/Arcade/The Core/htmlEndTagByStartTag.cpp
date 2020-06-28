std::string htmlEndTagByStartTag(std::string startTag) 
{
    int pos = startTag.find(' ');
    std::string tag = startTag.substr(1, pos - 1);
    return "</" + tag + (pos == std::string::npos ? "" : ">");
}
