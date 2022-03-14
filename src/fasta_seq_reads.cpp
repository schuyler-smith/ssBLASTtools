/*
 *
 *	Author: Schuyler D. Smith
 *
 */

#include <iostream>
#include <string>
#include <regex>
#include "helpcheck.hpp"
#include "get_fa_line.hpp"

int main(int argc, char * argv[])
{
    int eval = EXIT_SUCCESS;
    try{
        if(!askforhelp(argv))
        {
            for(int i=1;i < argc;i++){
                get_fa_line(argv[i], false);
            }
        }
    } catch(std::exception const &err) {
         /* update eval on throwed exceptions */
         eval = EXIT_FAILURE;
         std::cerr << "error: " << err.what() << std::endl;
    }
    return eval;
}