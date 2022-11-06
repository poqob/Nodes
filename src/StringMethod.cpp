#include "../include/other/StringMethod.hpp"
#include <string.h>

string StringMethod::trim(std::string clause)
{
    // satirin basinda bosluk karakteri varsa siler.
    if (clause[0] == ' ')
    {
        clause = clause.substr(1, clause.length() - 1);
    }
    // satirin sonunda bosluk karakteri varsa siler.
    if (clause[clause.length() - 1] == ' ')
    {
        clause.pop_back();
    }
    return clause;
}