#include <Watson.h>

namespace Watson
{

    void Text2Speech(std::string s)
    {
        API::NewProcess("nodejs /home/amiras/Downloads/node-sdk-master/examples/text_to_speech.v1.js", "\""+s+"\"");
    }

}
