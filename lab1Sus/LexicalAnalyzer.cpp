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
    std::vector<std::string> maskItems = Split(_mask, _metaSymbol);
    int wordLength = word.length();
    int maskItemsSize = maskItems.size();

    if (wordLength < maskItems[0].size() || wordLength < maskItems[maskItemsSize - 1].size())
        return false;
    if (_mask[0] != _metaSymbol)
        for(int i = 0; i < maskItems[0].size(); i++)
            if (word[i] != maskItems[0][i]) return false;

    /*if (word[wordLength - 1] != _metaSymbol){
        int j = wordLength - 1;
        for(int i = maskItems[maskItemsSize - 1].size() - 1; i >= 0 ; i--) {
            if (word[j] != maskItems[maskItemsSize - 1][i])
                return false;
            j--;
        }
    }*/
    bool backIsMetaSymbol = false;
    if (_mask[_mask.size() - 1] == _metaSymbol)
        backIsMetaSymbol = true;

    int start = 0;
    for(int k = 0; k < maskItemsSize; k++) {
        int itemLength = maskItems[k].length();
        int last = start + itemLength - 1;
        int first = start;
        if (itemLength > wordLength)
            return false;
        bool hasItem = false;
        while(last != wordLength){
            bool isCorrect = true;
            for(int i = 0; i < itemLength; i++ ){
                if( maskItems[k][i] != word[first + i]) {
                    isCorrect = false;
                    break;
                }
            }
            if (isCorrect) {
                if (k == maskItemsSize - 1 && !backIsMetaSymbol && last != wordLength - 1)
                    return false;
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
