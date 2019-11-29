#include <Database.h>

Database Database::setDatabase(std::string Name) {
    DBName = Name;
}

/*
    Hardcoded for now
*/
std::string Database::getEntry(std::string Table, std::string Column, std::string Keyword) {
    std::cout << "http://localhost/ai/newquery.php?table=" + Table + "&req=" + Column + "&key=" + Keyword << std::endl;
    std::string out =  HTTPGET("http://localhost/ai/newquery.php?table=" + Table + "&req=" + Column + "&key=" + Keyword);
    std::cout << out << std::endl;
    return out;
}

std::string Database::getRandomEntry(std::string Table, std::string Column) {
    std::cout << "http://localhost/ai/newquery.php?table=" + Table + "&req=" + Column + "&randomentry=true" << std::endl;
    std::string out =  HTTPGET("http://localhost/ai/newquery.php?table=" + Table + "&req=" + Column + "&randomentry=true");
    std::cout << out << std::endl;
    return out;
}

std::string Database::getRandomEntry(std::string Table)
{
    if (Table == std::string("Choices.Approvals"))
    {
        std::vector<std::string> List
        {
            "Excelent choice sir.",
            "Fantastic choice.",
            "I love the way you think sir."
        };

        return List[API::RandomInt(0, List.size() - 1)];

    }

    return "";
}

std::string NewQuery(std::string query)
{
    return HTTPGET("http://localhost/ai/newquery.php?input=" + query);
}
