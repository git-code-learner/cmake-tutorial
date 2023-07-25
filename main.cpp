#include <iostream>
#include "TutorialConfig.h"
#include <stdlib.h>

//Optional library MathFunctions.
#ifdef USE_MYMATH
#   include "MathFunctions.h"
#else
#    include <cmath>
#endif
// Step 6. Adding a custom Command and Generated File.
// Important note:
// this step is unclear. It tells sth about "valid C code in
// precomputed table", but nowhere is the information how the 
// file should look like. Plus, there is some algorithm given for 
// calculations, that also is unclear.
// Therefore the entire step was ommited, as kinda stupid - 
// the tutorial is to master cmake not, some unclear
// mathematical visions.


/**
 * Main function.
 * Starting point of the program.
*/
int main(int argc, char const *argv[])
{
    Header info to the user.
    std::cout << "Project Tutorial. Hello!" << std::endl;

    Usage analysis.
    if (argc < 2)
    {
        Report version.
        std::cout << argv[0] << " version " << Tutorial_VERSION_MAJOR <<
            "." << Tutorial_VERSION_MINOR << std::endl;
        
        Help the user.
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    else
    {
        Sqare root calculation.
        float inputValue{};
        inputValue = strtof(argv[1],NULL); Type casting.
        
        #ifdef USE_MYMATH
        const float outputValue = mysqrt(inputValue);
        #else
        const float outputValue = sqrt(inputValue);
        #endif
        
        std::cout << "The square root of " << inputValue << " is: " << outputValue << std::endl;
    
        Finish. OK.
        return 0;
    } 
}


