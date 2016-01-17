#ifndef __API__
#define __API__

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <random>

/*
    String functions and the their structure specific to the way
    Jarvis interprets input.
*/

namespace API {

    /*
        Checks if specific keyword exists in the Input(vector of words)
    */
    extern bool KeywordExists(std::vector<std::string> CallData, std::string Keyword);

    /*
        Same as above, just accepts multiple keywords in a form of string vector
    */
    extern bool KeywordExists(std::vector<std::string> CallData, std::vector<std::string> KeywordsVector);

    /*
        Gets the Id of the next word after keyword s
    */
    extern int NextKeywordId(std::vector<std::string> CallData, std::string s);

    /*
        Same as above, just accepts multiple keywords in a form of string vector
    */
    extern int NextKeywordId(std::vector<std::string> CallData, std::vector<std::string> KeywordsVector);

    /*
        Create new pipe and open a process.
    */
    extern FILE* NewProcess(std::string app, std::string input);

    /*
        Generates random number in range [min, max]
    */
    extern int RandomInt(int min, int max);

    /*
        Fancy /|\ print, requires figlet
    */
    extern void PrettyPrint(std::string);

}

#endif
