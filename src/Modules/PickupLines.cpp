#include <Modules/PickupLines.h>

void PickupLines_Module::Test()
{
    std::cout << "[Test Call] from PickupLines Module" << std::endl;
}

void PickupLines_Module::Execute(std::vector<std::string> w)
{
    /* Identifying contact */

    if(API::KeywordExists(w, "opener"))
    {
        std::string outStr = db.getRandomEntry("PickupLines", "text");

        Watson::SequencialPlay(outStr);
    }

}

void PickupLines_Module::Stop()
{

}
