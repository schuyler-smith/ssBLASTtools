/*
 *
 * Author:  Schuyler D. Smith
 * Function:  askforhelp
 * Purpose:  Function to check if comman-line help argument
 * is called and return the usage statement.
 *
 */

#ifndef HELPCALL_SDS
#define HELPCALL_SDS

#include <iostream>
#include <cstring>
#include <string>

bool askforhelp(int argc, char * argv[], std::string statement)
{
    bool usage;
    for(int i=1;i < argc;i++){
        usage = (!strcmp(argv[i], "-h") | !strcmp(argv[i], "--help"));
    }
    if(usage){
        std::cout << "\nUsage: " << statement << "\n" << std::endl;
    }
    return usage;
}

#endif