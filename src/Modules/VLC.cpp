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
    std::string SongPath = db.getEntry("SongsListPC", SongName);

    if (!SongPath.empty())
    {
        API::NewProcess("cvlc --play-and-exit", SongPath + " vlc://quit");

        /* Generate speech output after excecution */
        setOutput(db.getRandomEntry("Choices.Approvals"));
    }
}

void VLC_Module::Stop() {
    std::cout << ControlPipe << std::endl;
    //if (ControlPipe != nullptr)
    //    pclose(ControlPipe);
}
