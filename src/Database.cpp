#include <Database.h>

Database Database::setDatabase(std::string Name) {
    DBName = Name;
}

/*
    Hardcoded for now
*/
std::string Database::getEntry(std::string Table, std::string Keyword) {
    if (Table == std::string("SongsListPC"))
    {
        std::map< std::string, std::string > Songs =
        {
            { "sun", "/home/amiras/Music/Mudvayne\\ -\\ Forget\\ To\\ Remember\\ \\(OST\\ Пила\\ 2\\ Saw\\ II\\).mp3" },
            { "young", "/home/amiras/Music/Young.mp3" },
            { "bridget", "/home/amiras/Music/Huriccane.mp3" },
            { "hurricane", "/home/amiras/Music/Huriccane.mp3"},
            { "selena", "/home/amiras/Music/Selena.mp3" },
            { "salsa", "/home/amiras/Music/salsa.mp3" },
            { "dance", "/home/amiras/Music/salsa.mp3" },
            { "iron", "/home/amiras/Music/ironman.mp3" },
            { "magic", "/home/amiras/Music/magic.mp3" },
    	    { "gyro", "/home/amiras/Music/gyroscope.mp3" },
    	    { "wildest", "/home/amiras/Music/wildestdreams.mp3" },
    	    { "something", "/home/amiras/Music/wildestdreams.mp3" },
            { "spectrum", "/home/amiras/Music/spectrum.mp3" },
            { "whatever", "/home/amiras/Music/whatever.mp3" }
        };

        return Songs[Keyword];
    }

    if (Table == std::string("ContactListSkype"))
    {
        std::map< std::string, std::string > Contacts =
        {
            { "matas", "desperado557" },
            { "mom", "raimundas35" },
            { "martin", "martinloan" }
        };

        return Contacts[Keyword];
    }

  return "";
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
