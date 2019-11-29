#include <Modules/Date.h>

void Date_Module::Test()
{
    std::cout << "[Test Call] from Date Module" << std::endl;
}

void Date_Module::Execute(std::vector<std::string> w)
{
    /* Identifying contact */

    if (API::KeywordExists(w, "date"))
    {
        std::string http_addr = db.getEntry("links", "url", "date");
        std::string TodayDate = HTTPGET(http_addr);

        if (TodayDate == "2015 September 25")
            setOutput("Now is " + TodayDate + ". Happy birhday!");
        else
            setOutput("Now is " + TodayDate);
    }

}

void Date_Module::Stop()
{

}
