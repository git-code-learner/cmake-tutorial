/**
 * This is a basic cmake tutorial project.
 * It basically does nothing except for practice.
*/
#include <iostream>
#include "TutorialConfig.h"

/**
 * Main function.
 * Starting point of the program.
*/
int main(int argc, char const *argv[])
{
    std::cout << "Project Tutorial. Hello!" << std::endl;
    if (argc < 2)
    {
        //Report version.
        std::cout << argv[0] << " version " << Tutorial_VERSION_MAJOR <<
            "." << Tutorial_VERSION_MINOR << std::endl;
        
        //Help the user.
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    else
    {
        //Finish. OK.
        return 0;
    } 
}


