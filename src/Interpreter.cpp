#include "Interpreter.h"
#include "Utilities.h"

   Interpreter Interpreter::setInput(std::vector<std::string> CallData)
   {
     this->CallData = CallData;
     return *this;
   }

   bool Interpreter::Keyword(std::string s) {
      if(std::find(CallData.begin(), CallData.end(), s) != CallData.end())
        return true;
      else
        return false;
   }

   int Interpreter::NextKeywordId(std::string s) {
      if (Keyword(s))
        return std::find(CallData.begin(), CallData.end(), s) - CallData.begin() + 1;
      else
        return -1;
   }

   bool Interpreter::operate() {
      int Action = 1;

     /*
      * Check if calling AI, do not parse otherwise
      */
     if (!Keyword(AI)) {
       return 0;
     }

   /*
    * YOUTUBE MODULE REBUILD
    * Play song operation
    * Example: Jarvis play *song*

   if(Keyword("play")) {

     int address_pos = NextKeywordId("play");

     // Number is not provided, exiting
     if (CallData.size() <= address_pos || address_pos == -1) {
      return 0;
     }

     FILE *lsofFile_p = popen((std::string("firefox ") + Songs[CallData[address_pos]] + std::string(" &")).c_str(), "r");
  }
  */

  /*
   * Handling modules system
   * Example: jarvis play
   * Will call module which has associated keyword "play", which in this case is VLC module.
   */
  for(int i = 0; i < ActiveModules.size(); i++)  {
      if(API::KeywordExists(CallData, ActiveModules[i]->getActivationKeywords())) {
          ActiveModules[i]->Execute(CallData);
      }
  }


  /*
    Handling speech syntesis for multiple modules
  */
  std::string CompleteOutput = "";
  for(int i = 0; i < ActiveModules.size(); i++) {
      if(API::KeywordExists(CallData, ActiveModules[i]->getActivationKeywords())) {
          if (ActiveModules[i]->OutputRequest())
            SynthesizeSpeech += ActiveModules[i]->getOutput();
      }
  }


  /*
   * Stops all currently functioning modules
   */
  if (API::KeywordExists(CallData, "stop")) {
      for(int i = 0; i < ActiveModules.size(); i++)  {
          ActiveModules[i]->Stop();
      }
  }

  /*
   * Give newsfeed from PHP
   * Example: Jarvis news technology
   */
  if(API::KeywordExists(CallData, "news")) {

     int address_pos = NextKeywordId("news");
     std::cout << "pos: " << address_pos  << ", Data size: "<< CallData.size() << std::endl;

     /* Number is not provided, exiting*/
     if (CallData.size() <= address_pos) {
      return NULL;
     }

     char* str1 = "http://localhost/ai/getnews.php?t=";
     const char* str2 = CallData[address_pos].c_str();
     char * http_addr ;
    if((http_addr = static_cast<char*>(malloc(strlen(str1)+strlen(str2)+1))) != NULL){
       http_addr[0] = '\0';   // ensures the memory is an empty string
       strcat(http_addr,str1);
       strcat(http_addr,str2);
    } else {
       //fprintf(STDERR,"malloc failed!\n");
       // exit?

    }
     SynthesizeSpeech = "Today in " + CallData[address_pos]  + ". " + HTTPGET(http_addr);
     return 1;
  }



     //Request Speech Synthesis
     if (SynthesizeSpeech.length() > 0)
       return true;


     return 0;
}

std::string Interpreter::getSpeech()
{
  return SynthesizeSpeech;
}

void Interpreter::CleanSpeech() {
  SynthesizeSpeech = "";
}
