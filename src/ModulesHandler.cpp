#include <Modules/ModulesHandler.h>

std::vector<ModulesHandler*> ActiveModules = {};

std::vector<std::string> ModulesHandler::getActivationKeywords() {
    return ActivationKeywords;
}

ModulesHandler::ModulesHandler(std::vector<std::string> ActivationKeywordVector) {
    ActivationKeywords = ActivationKeywordVector;
}

ModulesHandler::ModulesHandler(std::string ActivationKeyword) {
    ActivationKeywords = {ActivationKeyword};
}

bool ModulesHandler::OutputRequest() {
    if (OutputString.length() > 0)
        return true;
    return false;
}

void ModulesHandler::setOutput(std::string s) {
    OutputString = s;
}

std::string ModulesHandler::getOutput() {
    return OutputString;
}

void ModulesHandler::Test() {
    std::cout << "[Test Call] from ModulesHandler" << std::endl;
}

void ModulesHandler::Execute(std::vector<std::string>) {

}

void ModulesHandler::Stop() {

}
