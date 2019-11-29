#ifndef __QQ__
#define __QQ__

#include <ModulesHandler.h>
#include <Utilities.h>

class QQ_Module : public ModulesHandler {

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

    QQ_Module(std::vector<std::string> Keywords) : ModulesHandler(Keywords) {
        std::cout << "[ModulesHandler] QQ Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

    QQ_Module(std::string Keyword) : ModulesHandler(Keyword) {
        std::cout << "[ModulesHandler] QQ Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};

#endif
