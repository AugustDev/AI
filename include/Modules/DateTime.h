#ifndef __DATETIME__
#define __DATETIME__

#include <iostream>
#include <vector>
#include <string>
#include <Modules/ModulesHandler.h>
#include <Database.h>
#include <Utilities.h>

class DateTime_Module : public ModulesHandler {

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

    DateTime_Module() : ModulesHandler(std::vector<std::string>{"date", "time"}) {
        std::cout << "[ModulesHandler] DateTime Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};

#endif
