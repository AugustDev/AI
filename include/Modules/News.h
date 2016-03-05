#ifndef __NEWSM__
#define __NEWSM__

#include <ModulesHandler.h>
#include <Utilities.h>

class News_Module : public ModulesHandler {

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

    News_Module(std::vector<std::string> Keywords) : ModulesHandler(Keywords) {
        std::cout << "[ModulesHandler] News Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

    News_Module(std::string Keyword) : ModulesHandler(Keyword) {
        std::cout << "[ModulesHandler] News Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};

#endif
