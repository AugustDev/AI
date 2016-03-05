#ifndef __DATEM__
#define __DATEM__

#include <ModulesHandler.h>
#include <Utilities.h>

class Date_Module : public ModulesHandler {

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

    Date_Module(std::vector<std::string> Keywords) : ModulesHandler(Keywords) {
        std::cout << "[ModulesHandler] Date Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

    Date_Module(std::string Keyword) : ModulesHandler(Keyword) {
        std::cout << "[ModulesHandler] Date Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};

#endif
