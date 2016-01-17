#ifndef __MODULESHANDLER__
#define __MODULESHANDLER__

#include <iostream>
#include <string>
#include <vector>

class ModulesHandler;

/*
    Contains a list of active modules (childs of ModulesHandler)
*/
extern std::vector<ModulesHandler*> ActiveModules;

class ModulesHandler {
private:

    /*
        Keyword in a sentencd required to activate this module
    */
    std::vector<std::string> ActivationKeywords;

    /*
        String for speaker-output
    */
    std::string OutputString;

public:
    /*
        Main execution function for the module, performs the Action
    */
    virtual void Execute(std::vector<std::string>);

    /*
        Stop the action started with Execute
    */
    virtual void Stop();

    /*
        Just outputs test string
    */
    virtual void Test();

    /*
        Does this module requires speaker-output?
    */
    bool OutputRequest();

    /*
        Returns string for speaker-output
    */
    std::string getOutput();

    /*
        Sets string for speaker-output
    */
    void setOutput(std::string);

    /*
        Returns keywords required to activate this module
    */
    std::vector<std::string> getActivationKeywords();

    ModulesHandler(std::vector<std::string> ActivationKeywordVector);
};

#endif