#include <Modules/vlc.h>

void VLC_Module::Test()
{
    std::cout << "[Test Call] from VLC Module" << std::endl;
}

void VLC_Module::Execute(std::vector<std::string> v)
{
    /* Identifying song name */
    int ElementId = API::NextKeywordId(v, getActivationKeywords());

    if (ElementId == -1) return;

    std::string SongName = v[ElementId];
    std::cout << SongName << std::endl;

    /* Connecting to database SongsList */
    Database SongsList = Database("localhost", "Jarvis", "root", "JarvisBase");
    std::cout << SongsList.getEntry("SongsListPC", SongName) << std::endl;

    if (SongsList.getEntry("SongsListPC", SongName) != "-1")
        API::NewProcess("cvlc --play-and-exit", SongsList.getEntry("SongsListPC", SongName) + " vlc://quit");

    setOutput("Excelent choice Sir.");
}

void VLC_Module::Stop() {
    std::cout << ControlPipe << std::endl;
    //if (ControlPipe != nullptr)
    //    pclose(ControlPipe);
}
