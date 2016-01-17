#ifndef __VLCMODULE__
#define __VLCMODULE__

#include <iostream> //
#include <vector>
#include <string>
#include "Modules/ModulesHandler.h"
#include <Database.h>

class Skype_Module : public ModulesHandler {

public:
    /*
        Output test string
    */
    virtual void Test();

    /*
        Action happens here
    */
    virtual void Execute(std::vector<std::string>);

    virtual void Stop();

    VLC_Module() : ModulesHandler("call") {
        std::cout << "[ModulesHandler] Skype Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};


#endif
