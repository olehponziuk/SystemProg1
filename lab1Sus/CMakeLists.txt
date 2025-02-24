cmake_minimum_required(VERSION 3.25)
project(lab1Sus)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1Sus main.cpp LexicalAnalyzer.cpp LexicalAnalyzer.h LanguageProcessor.cpp LanguageProcessor.h)
