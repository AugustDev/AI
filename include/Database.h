#ifndef __DATABASE__
#define __DATABASE__

#include <string>
#include <vector>
#include <map> //temp
#include <API.h>

/*
    This class would manage sets of data, such as music libraries, files,
    contacts... For now it will be hardcoded, but will use SQL in the future.
*/
class Database {

private:
    std::string DBHost;
    std::string DBName;
    std::string DBUser;
    std::string DBPass;

public:

    Database() {

    }

    Database(std::string DBHost, std::string DBUser, std::string DBPass, std::string DBName) {

    }

    /*
        Set Database Name
    */
    Database setDatabase(std::string Name);

    /*
        Get entry with associated keyword
        Map: Keyword -> entry
    */
    std::string getEntry(std::string Table, std::string Keyword);

    /*
        Get a random entry from Table
    */
    std::string getRandomEntry(std::string Table);

    /*
        Get Full Column of a specific Table.
        (Not sure about the format yet)
    */
    std::string getColumn(std::string Table, std::string Column);

    /*
        Get full Table.
        (Not sure about the format yet)
    */
    std::string getTable(std::string TableName);

};

#endif
