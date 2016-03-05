#ifndef __MODULESHANDLER__
#define __MODULESHANDLER__

#include <iostream>
#include <string>
#include <vector>
#include <Database.h>

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

protected:
    /*
        Databse connection for all derived classes to use
    */
    Database db = Database("localhost", "Jarvis", "root", "JarvisBase");

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

    /*
        Constructors with input ActivationKeyword (vector)
    */
    ModulesHandler(std::vector<std::string> ActivationKeywordVector);

    ModulesHandler(std::string ActivationKeyword);
};

#endif
