#ifndef __SKYPEMODULE__
#define __SKYPEMODULE__

#include <ModulesHandler.h>

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

    Skype_Module() : ModulesHandler(std::vector<std::string>{"call", "calling"}) {
        std::cout << "[ModulesHandler] Skype Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};


#endif
