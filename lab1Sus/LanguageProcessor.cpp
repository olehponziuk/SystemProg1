#include "LanguageProcessor.h"

std::vector<std::string> Split(const std::string & str, char separator)
{
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> result;
    while(std::getline(ss, item, separator))
        result.push_back(item);

    return result;
}

LanguageProcessor::LanguageProcessor(const std::string & outFile, const std::string & inFile, char metaSymbol, const std::string & mask)
{
    _outFile = outFile;
    _inFile = inFile;
    _analyzer = LexicalAnalyzer(metaSymbol, mask);
}

LanguageProcessor::LanguageProcessorBuilder & LanguageProcessor::LanguageProcessorBuilder::addOutFile(const std::string & outFile)
{
    _outFile = outFile;
    return *this;
}
LanguageProcessor::LanguageProcessorBuilder & LanguageProcessor::LanguageProcessorBuilder::addInFile(const std::string & inFile)
{
    _inFile = inFile;
    return *this;
}
LanguageProcessor::LanguageProcessorBuilder & LanguageProcessor::LanguageProcessorBuilder::addMetaSymbol(char metaSymbol)
{
    _metaSymbol = metaSymbol;
    return *this;
}
LanguageProcessor::LanguageProcessorBuilder & LanguageProcessor::LanguageProcessorBuilder::addMask(const std::string & mask)
{
    _mask = mask;
    return *this;
}
LanguageProcessor LanguageProcessor::LanguageProcessorBuilder::build()
{
    return LanguageProcessor(_outFile, _inFile, _metaSymbol, _mask);
}

void LanguageProcessor::Run()
{
    std::string str;
    std::ifstream in;
    in.open(_inFile);
    if(in.is_open()){
        while (std::getline(in, str)){}
    }
    in.close();


    std::vector<std::string> words = _analyzer.CheckInRange(Split(str, ' '));

    std::ofstream out;
    out.open(_outFile);
    if (out.is_open())
    {
        for(auto word : words)
            out << word << std::endl;
    }
    out.close();
}
