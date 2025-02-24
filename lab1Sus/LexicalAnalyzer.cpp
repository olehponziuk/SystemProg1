#include "LexicalAnalyzer.h"

 std::vector<std::string> Split(const std::string & str, char separator)
{
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> result;
    while(std::getline(ss, item, separator))
        result.push_back(item);

    return result;
}

LexicalAnalyzer::LexicalAnalyzer() {
    _metaSymbol = '*';
    _mask = "a*f*";
}

LexicalAnalyzer::LexicalAnalyzer(char metaSymbol, const std::string &mask)
{
    _metaSymbol = metaSymbol;
    _mask = mask;
}

bool LexicalAnalyzer::IsMatch(const std::string word)
{
    int wordLength = word.length();
    std::vector<std::string> maskItems = Split(_mask, _metaSymbol);

    int start = 0;
    for(std::string item : maskItems) {
        int itemLength = item.length();
        int last = start + itemLength - 1;
        int first = start;
        if (itemLength > wordLength)
            return false;
        bool hasItem = false;
        while(last != wordLength){
            bool isCorrect = true;
            for(int i = 0; i < itemLength; i++ ){
                if( item[i] != word[first + i]) {
                    isCorrect = false;
                    break;
                }
            }
            if (isCorrect) {
                hasItem = true;
                start = last + 1;
                break;
            }
            last++;
            first++;

        }
        if(!hasItem)
            return false;
    }

    return true;
}

std::vector<std::string> LexicalAnalyzer::CheckInRange(const std::vector<std::string> & words)
{
    int n = _mask.length();
    std::string tmpMask;
    int countMetaSymbols = 0;
    bool isFirstSymbol = true;
    for(int i = 0; i < n; i++){
        if (_mask[i] == _metaSymbol && isFirstSymbol){
            isFirstSymbol = false;
            tmpMask.push_back(_mask[i]);
            countMetaSymbols++;
            continue;
        }
        else if (_mask[i] == _metaSymbol && !isFirstSymbol){
            countMetaSymbols++;
            continue;
        }
        tmpMask.push_back(_mask[i]);
        isFirstSymbol = true;
    }
    _mask = tmpMask;

    std::vector<std::string> result;
    for(std::string word : words)
    {
        int len = word.length();
        if (len == 0){
            std::cout << "<notMatch, " << word << ">" << std::endl;
            continue;
        }
        else if(IsMatch(word)){
            std::cout << "<Match, " << word << ">" << std::endl;
            result.push_back(word);
        }
        else{
            std::cout << "<notMatch, " << word << ">" << std::endl;
        }

    }

    return result;
}
