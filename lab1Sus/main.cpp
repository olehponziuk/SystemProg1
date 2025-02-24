#include <iostream>
#include "LanguageProcessor.h"

int main() {
    LanguageProcessor processor = LanguageProcessor::LanguageProcessorBuilder()
            .addInFile("in.txt")
            .addOutFile("out.txt")
            .addMetaSymbol('*')
            .addMask("a*f*")
            .build();

    processor.Run();
    return 0;
}
