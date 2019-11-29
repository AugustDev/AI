#include <Modules/News.h>

void News_Module::Test()
{
    std::cout << "[Test Call] from News Module" << std::endl;
}

void News_Module::Execute(std::vector<std::string> w)
{
    /* Identifying contact */

    if(API::KeywordExists(w, "news"))
    {
        int ElementId = API::NextKeywordId(w, "news");
        if (ElementId == -1) return;

        std::string Topic = w[ElementId];

        std::string http_addr = db.getEntry("links", "url", "news") + Topic;
        std::string FetchedData = "Today in " + Topic  + ". " + HTTPGET(http_addr);

        std::cout << FetchedData << std::endl;
        setOutput(FetchedData);
    }

}

void News_Module::Stop()
{

}
