#ifndef __EMAILMODULE__
#define __EMAILMODULE__

#include <iostream> //
#include <vector>
#include <string>
#include <Modules/ModulesHandler.h>
#include <Database.h>

class Email_Module : public ModulesHandler {

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

    Email_Module() : ModulesHandler(std::vector<std::string>{"email", "mail"}) {
        std::cout << "[ModulesHandler] Email Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};


#endif
