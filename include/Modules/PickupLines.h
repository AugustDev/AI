#ifndef __MODPICKUPL__
#define __MODPICKUPL__

#include <ModulesHandler.h>
#include <Utilities.h>
#include <Watson.h>

class PickupLines_Module : public ModulesHandler {

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

    PickupLines_Module(std::vector<std::string> Keywords) : ModulesHandler(Keywords) {
        std::cout << "[ModulesHandler] PickupLines Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

    PickupLines_Module(std::string Keyword) : ModulesHandler(Keyword) {
        std::cout << "[ModulesHandler] PickupLines Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};

#endif
