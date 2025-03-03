#include <iostream>
#include "LanguageProcessor.h"

const std::string BaseInPath = "C:\\Users\\kuzni\\CLionProjects\\lab1Sus\\InFiles";
const std::string BaseOutPath = "C:\\Users\\kuzni\\CLionProjects\\lab1Sus\\OutFiles";

int main() {
    std::cout << " Test 0; Mask a*f*\n" << std::endl;

    LanguageProcessor processorTest0 = LanguageProcessor::LanguageProcessorBuilder()
            .addInFile(BaseInPath + "\\in.txt")
            .addOutFile(BaseOutPath + "\\out.txt")
            .addMetaSymbol('*')
            .addMask("a*f*")
            .build();

    processorTest0.Run();

    std::cout << "\nTest 1; Mask Q*p\n" << std::endl;

    LanguageProcessor processorTest1 = LanguageProcessor::LanguageProcessorBuilder()
            .addInFile(BaseInPath + "\\in1.txt")
            .addOutFile(BaseOutPath + "\\out1.txt")
            .addMetaSymbol('*')
            .addMask("Q*p")
            .build();

    processorTest1.Run();

    std::cout << "\nTest 2; Mask **5*\n" << std::endl;

    LanguageProcessor processorTest2 = LanguageProcessor::LanguageProcessorBuilder()
            .addInFile(BaseInPath + "\\in2.txt")
            .addOutFile(BaseOutPath + "\\out2.txt")
            .addMetaSymbol('*')
            .addMask("**5*")
            .build();

    processorTest2.Run();

    std::cout << "\nTest 3; Mask  Ma*ska*\n" << std::endl;

    LanguageProcessor processorTest3 = LanguageProcessor::LanguageProcessorBuilder()
            .addInFile(BaseInPath + "\\in3.txt")
            .addOutFile(BaseOutPath + "\\out3.txt")
            .addMetaSymbol('*')
            .addMask("Ma*ska*")
            .build();

    processorTest3.Run();

    std::cout << "\nTest 4; Mask *11\n" << std::endl;

    LanguageProcessor processorTest4 = LanguageProcessor::LanguageProcessorBuilder()
            .addInFile(BaseInPath + "\\in4.txt")
            .addOutFile(BaseOutPath + "\\out4.txt")
            .addMetaSymbol('*')
            .addMask("*11")
            .build();

    processorTest4.Run();

    return 0;
}
