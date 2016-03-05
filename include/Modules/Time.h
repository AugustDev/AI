#ifndef __TIMEM__
#define __TIMEM__

#include <ModulesHandler.h>
#include <Utilities.h>

class Time_Module : public ModulesHandler {

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

    Time_Module(std::vector<std::string> Keywords) : ModulesHandler(Keywords) {
        std::cout << "[ModulesHandler] Time Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

    Time_Module(std::string Keyword) : ModulesHandler(Keyword) {
        std::cout << "[ModulesHandler] Time Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};

#endif
