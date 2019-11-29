#include <Watson.h>

namespace Watson
{

    void Text2Speech(std::string s)
    {
        API::NewProcess("curl -k -u '0f841b75-8a5d-4ad8-a45b-339b41c5c36e':'fIxBS2C24SSG' -X POST --header 'Content-Type: application/json' \
  --header 'Accept: audio/wav' --data '{\"text\":\""+s+"\"}' --output watout.wav 'https://stream.watsonplatform.net/text-to-speech/api/v1/synthesize?voice=en-US_AllisonVoice'", "");

    std::cout << "curl -k -u '0f841b75-8a5d-4ad8-a45b-339b41c5c36e':'fIxBS2C24SSG' -X POST --header 'Content-Type: application/json' \
--header 'Accept: audio/wav' --data '{\"text\":\""+s+"\"}' --output watout.wav 'https://stream.watsonplatform.net/text-to-speech/api/v1/synthesize?voice=en-US_AllisonVoice'" << std::endl;
    }

    void SequencialPlay(std::string s)
    {
        API::NewProcess("curl -k -u '0f841b75-8a5d-4ad8-a45b-339b41c5c36e':'fIxBS2C24SSG' -X POST --header 'Content-Type: application/json' \
  --header 'Accept: audio/wav' --data '{\"text\":\""+s+"\"}' --output watout.wav 'https://stream.watsonplatform.net/text-to-speech/api/v1/synthesize?voice=en-US_AllisonVoice'", " && sleep 2 && cvlc --play-and-exit watout.wav vlc://quit");

    }
}
