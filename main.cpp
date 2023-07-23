#include <iostream>
#include "TutorialConfig.h"

//Optional library MathFunctions.
#ifdef USE_MYMATH
#   include "MathFunctions.h"
#else
#    include <cmath>
#endif

/**
 * Main function.
 * Starting point of the program.
*/
int main(int argc, char const *argv[])
{
    //Header info to the user.
    std::cout << "Project Tutorial. Hello!" << std::endl;
    
    //Sqare root calculation.
    #ifdef USE_MYMATH
    const float outputValue = mysqrt(36);
    #else
    const float outputValue = sqrt(36);
    #endif
    std::cout << "The square root of 36 is: " << outputValue << std::endl;

    //Usage analysis.
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


