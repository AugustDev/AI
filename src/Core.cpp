#include <voce.h>
#include <Utilities.h>
#include <Interpreter.h>

#include <Watson.h>

#include <Modules/vlc.h>
#include <Modules/Skype.h>
#include <Modules/EMail.h>
//#include <Modules/DateTime.h>
#include <Modules/Time.h>
#include <Modules/Date.h>
#include <Modules/News.h>
#include <Modules/QQ.h>
#include <Modules/PickupLines.h>

#include <API.h>
#include <thread> //to play in a new thread

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

struct config{
	const std::string libs = "/home/amiras/Documents/Dev/AIF/libs";
	const std::string grammar = "/home/amiras/Documents/Dev/AIF/application/grammar/";
} conf;

int main(int argc, char **argv)
{
	/* Initializing Modules */
	VLC_Module VLCModule;
	Skype_Module SkypeModule;
	Email_Module EmailModule;
	//DateTime_Module DateTimeModule;
	Time_Module TimeModule("time");
	Date_Module DateModule("date");
	News_Module NewsModule("news");
	PickupLines_Module PickupLinesModule("opener");
	QQ_Module QQ("bye");

	//std::thread MusicThread (VLC_Module::StaticPlay, "/home/amiras/Music/Young.mp3", 0);
	Interpreter interpreter;

	/* Initializing Voce */
	voce::init(conf.libs, true, true, conf.grammar, "digits");
	API::PrettyPrint("Jarvis");

	/* Begins */

	bool quit = false;
	while (!quit)
	{

#ifdef WIN32
		::Sleep(200);
#else
		usleep(200);
#endif

		while (voce::getRecognizerQueueSize() > 0)
		{
			std::string s = voce::popRecognizedString();

			std::cout << "(Input) " << s << std::endl;

			std::vector<std::string> data = split(s.c_str(), ' ');
			interpreter.setInput(data);

			if (interpreter.operate()) {
				// Two sound synthesis packages are available, Voce & IBM Watson.
				//Watson::SequencialPlay(interpreter.getSpeech());
				voce::synthesize(interpreter.getSpeech());
				interpreter.CleanSpeech();
			}

			/* Check if the string contains 'quit'.
			if (std::string::npos != s.rfind("quit"))
			{
				quit = true;
			}
			*/

			//voce::synthesize(s);
		}
	}

	voce::destroy();
	return 0;
}
