#ifndef __INTERPRETER__
#define __INTERPRETER__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string.h>

#include <API.h>
#include <Utilities.h>
#include <Modules/vlc.h>
#include <Modules/Skype.h>

static std::string const AI = "jarvis";

class Interpreter {

private:
   /*
        Contains information information about the speech input(sentence)
        in a form of an array of words.
    */
   std::vector<std::string> CallData;

   /*
        If Speech Synthesis is requested, the output string is contained here.
    */
   std::string SynthesizeSpeech;

   /*
        Checks if keyword is in the string (now rebuilt in API)
    */
   bool Keyword(std::string);

   /*
        Gives next keyword id in the CallData array (now rebuilt in API)
    */
   int NextKeywordId(std::string);

public:
   Interpreter(std::vector<std::string> CallData) {
     this->CallData = CallData;
   }

   /*
        Assigning input string captured by microphone
    */
   Interpreter setInput(std::vector<std::string> CallData);

   /*
        Returns string for speaker-output
    */
   std::string getSpeech();

   /*
        Cleans SynthesizeSpeech variable
    */
   void CleanSpeech();

   /*
        Central function assigning tasks
    */
   bool operate();

   Interpreter()
   {

   }

   ~Interpreter()
   {

   }

};

#endif
