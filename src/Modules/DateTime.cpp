#include <Modules/DateTime.h>

void DateTime_Module::Test()
{
    std::cout << "[Test Call] from DateTime Module" << std::endl;
}

void DateTime_Module::Execute(std::vector<std::string> w)
{
    /* Identifying contact */

    if (API::KeywordExists(w, "time"))
    {
        std::string http_addr = "http://localhost/ai/datetime.php?opt=time";
        std::string Time = HTTPGET(http_addr);
        setOutput("Now is " + Time);
    }

    if (API::KeywordExists(w, "date"))
    {
        std::string http_addr = "http://localhost/ai/datetime.php?opt=date";
        std::string TodayDate = HTTPGET(http_addr);

        if (TodayDate == "2015 September 25")
            setOutput("Now is " + TodayDate + ". Happy birhday!");
        else
            setOutput("Now is " + TodayDate);
    }

}

void DateTime_Module::Stop()
{

}
