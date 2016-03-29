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
   * Handling modules system
   * Example: jarvis play
   * Will call module which has associated keyword "play", which in this case is VLC module.
   */
  std::string CompleteOutput = "";
  for(int i = 0; i < ActiveModules.size(); i++)
  {
      if(API::KeywordExists(CallData, ActiveModules[i]->getActivationKeywords()))
      {
          ActiveModules[i]->Execute(CallData);

	  /*
	    Handling speech syntesis for multiple modules
	  */
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
