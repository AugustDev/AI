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
    std::string SongPath = db.getEntry("playlist", "path", SongName);

    if (!SongPath.empty())
    {
        //Deprecated method, now using VLC API instead
        //API::NewProcess("cvlc --play-and-exit", SongPath + " vlc://quit");

        std::thread MusicThread (VLC_Module::StaticPlay, SongPath, 600);

        //! Problem: this is returned only after MusicThread finishes execution
        /* Generate speech output after excecution */
        setOutput(db.getRandomEntry("Choices.Approvals"));

        //Joining thread
        MusicThread.join();
    }
}

void VLC_Module::Stop() {
    std::cout << ControlPipe << std::endl;
    //if (ControlPipe != nullptr)
    //    pclose(ControlPipe);
}
