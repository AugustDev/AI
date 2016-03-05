#include <Modules/EMail.h>

void Email_Module::Test()
{
    std::cout << "[Test Call] from EMail Module" << std::endl;
}

void Email_Module::Execute(std::vector<std::string> w)
{
    /* Identifying contact */
    int ElementId = API::NextKeywordId(w, getActivationKeywords());
    if (ElementId == -1) return;

    std::string ContactName = w[ElementId];

    /* Specific keyword indicating to check email */
    if (ContactName == "check")
    {
        API::NewProcess("chromium-browser", "https://mail.google.com/mail/u/0/#inbox");
        return;
    }

    /* Connecting to database Email Contact List */
    Database db = Database("localhost", "Jarvis", "root", "JarvisBase");
    std::string ContactEmail = db.getEntry("ContactListEmail", ContactName);

    /* If associated contact exists compose message */
    if (!ContactEmail.empty())
    {
        API::NewProcess("chromium-browser", "\"https://mail.google.com/mail/?view=cm&fs=1&to="+ContactEmail+"\"");
    }
}

void Email_Module::Stop()
{

}
