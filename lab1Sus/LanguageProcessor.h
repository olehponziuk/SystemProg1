#ifndef LAB1SUS_LANGUAGEPROCESSOR_H
#define LAB1SUS_LANGUAGEPROCESSOR_H
#include <string>
#include "LexicalAnalyzer.h"

class LanguageProcessor {
private:
    std::string _outFile;
    std::string _inFile;
    LexicalAnalyzer _analyzer;

    LanguageProcessor(const std::string & outFile, const std::string & inFile, char metaSymbol, const std::string & mask);
public:
    void Run();

    class LanguageProcessorBuilder{
    private:
        std::string _outFile;
        std::string _inFile;
        char _metaSymbol = '*';
        std::string _mask ="a*b*";
    public:
        LanguageProcessorBuilder & addOutFile(const std::string & outFile);
        LanguageProcessorBuilder & addInFile(const std::string & inFile);
        LanguageProcessorBuilder & addMetaSymbol(char metaSymbol);
        LanguageProcessorBuilder & addMask(const std::string & mask);

        LanguageProcessor build();
    };
};


#endif //LAB1SUS_LANGUAGEPROCESSOR_H
