#ifndef __VLCMODULE__
#define __VLCMODULE__

#include <ModulesHandler.h>
#include <Watson.h>

class VLC_Module : public ModulesHandler {

private:
    FILE* ControlPipe = nullptr;

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

    VLC_Module() : ModulesHandler(std::vector<std::string>{"playing", "play"}) {
        std::cout << "[ModulesHandler] VLC Module initialized" << std::endl;
        ActiveModules.push_back(this);
    }

};


#endif
