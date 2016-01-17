#include <API.h>

namespace API {

    bool KeywordExists(std::vector<std::string> CallData, std::string s) {
       if(std::find(CallData.begin(), CallData.end(), s) != CallData.end())
         return true;
       else
         return false;
    }

    bool KeywordExists(std::vector<std::string> CallData, std::vector<std::string> KeywordList) {
        for (auto elem : KeywordList) {
            if(std::find(CallData.begin(), CallData.end(), elem) != CallData.end())
              return true;
        }
       return false;
    }

    int NextKeywordId(std::vector<std::string> CallData, std::string s) {
        if (KeywordExists(CallData, s)) {
          int id = std::find(CallData.begin(), CallData.end(), s) - CallData.begin() + 1;

          /* Keyword may be the last word in a sentence in that case, no NextKeyword exists */
          if (id < CallData.size())
            return id;

        }
      return -1;
    }

    int NextKeywordId(std::vector<std::string> CallData, std::vector<std::string> KeywordList) {
        for(auto elem : KeywordList) {
            if (KeywordExists(CallData, elem)) {
              int id = std::find(CallData.begin(), CallData.end(), elem) - CallData.begin() + 1;

              /* Keyword may be the last word in a sentence in that case, no NextKeyword exists */
              if (id < CallData.size())
                return id;
            }
        }
      return -1;
    }

    FILE* NewProcess(std::string app, std::string input) {
        FILE* p = popen((app + " " + input).c_str(), "r");
        return p;
    }

    void PrettyPrint(std::string s) {
        system(("figlet " + s).c_str());
    }


}
