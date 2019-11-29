#include <Modules/Skype.h>

void Skype_Module::Test()
{
    std::cout << "[Test Call] from Skype Module" << std::endl;
}

void Skype_Module::Execute(std::vector<std::string> w)
{
    /* Identifying contact */
    int ElementId = API::NextKeywordId(w, getActivationKeywords());
    if (ElementId == -1) return;

    std::string ContactName = w[ElementId];

    /* Connecting to database Skype Contact List */
    //std::string ContactNumber = db.getEntry("ContactListSkype", ContactName);
    std::string ContactNumber = db.getEntry("ContactListSkype", "number", ContactName);

    /* If associated contact exists call */
    if (!ContactNumber.empty())
    {
        API::NewProcess("skype --callto", ContactNumber);
    }
}

void Skype_Module::Stop()
{

}
