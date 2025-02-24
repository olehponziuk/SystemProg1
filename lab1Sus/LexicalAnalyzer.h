#ifndef LAB1SUS_LEXICALANALYZER_H
#define LAB1SUS_LEXICALANALYZER_H
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


class LexicalAnalyzer {
private:
    char _metaSymbol;
    std::string _mask;

    bool IsMatch(const std::string word);
public:
    LexicalAnalyzer();
    LexicalAnalyzer(char metaSymbol, const std::string & mask);
    std::vector<std::string> CheckInRange(const std::vector<std::string> & words);
};


#endif
