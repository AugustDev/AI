#include <Modules/Time.h>

void Time_Module::Test()
{
    std::cout << "[Test Call] from Time Module" << std::endl;
}

void Time_Module::Execute(std::vector<std::string> w)
{
    /* Identifying contact */

    if (API::KeywordExists(w, "time"))
    {
        std::string http_addr = "http://localhost/ai/datetime.php?opt=time";
        std::string Time = HTTPGET(http_addr);
        setOutput("Now is " + Time);
    }

}

void Time_Module::Stop()
{

}
