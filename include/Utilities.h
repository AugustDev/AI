#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

/*
    Splits a string into string array at char c
*/
std::vector<std::string> split(const char *str, char c);

/*
    Primitive testing skype call (temp)
*/
bool skype_call(std::string address);


void init_string(struct string *s);

/*
    Used for libcurl, mainly HTTPGET function
*/
size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s);

/*
 * Obtain website source code
 */
std::string HTTPGET(char* http_addr);

#endif
