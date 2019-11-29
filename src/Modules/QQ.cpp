#include <Modules/QQ.h>

void QQ_Module::Test()
{
    std::cout << "[Test Call] from QQ Module" << std::endl;
}

void QQ_Module::Execute(std::vector<std::string> w)
{
    std::cout << "QQ BYE" << std::endl;
    setOutput("It was pleasure working with you sir. Good bye.");
    //API::NewProcess("dbus-send --system --print-reply --dest=org.freedesktop.ConsoleKit /org/freedesktop/ConsoleKit/Manager org.freedesktop.ConsoleKit.Manager.Stop");


}

void QQ_Module::Stop()
{

}
