#include "Interpreter.h"
#include "Utilities.h"

   Interpreter Interpreter::setInput(std::vector<std::string> CallData)
   {
     this->CallData = CallData;
     return *this;
   }

   bool Interpreter::operate() {
      int Action = 1;

     /*
      * Check if calling AI, do not parse otherwise
      */
     if (!API::KeywordExists(CallData, AI)) {
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
  for(int i = 0; i < ActiveModules.size(); i++)
  {
      if(API::KeywordExists(CallData, ActiveModules[i]->getActivationKeywords()))
      {
          ActiveModules[i]->Execute(CallData);
      }
  }

  /*
    Handling speech syntesis for multiple modules
  */
  std::string CompleteOutput = "";
  for(int i = 0; i < ActiveModules.size(); i++)
  {
      if(API::KeywordExists(CallData, ActiveModules[i]->getActivationKeywords()))
      {
          if (ActiveModules[i]->OutputRequest())
            SynthesizeSpeech += ActiveModules[i]->getOutput();
      }
  }

  /*
   * Stops all currently functioning modules
   */
  if (API::KeywordExists(CallData, "stop"))
  {
      for(int i = 0; i < ActiveModules.size(); i++)
      {
          ActiveModules[i]->Stop();
      }
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
