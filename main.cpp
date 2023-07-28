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
    //Report info about project and its version.
    std::cout << PROJECT_NAME << " (" 
        << PROJECT_VERSION << ")";
    std::cout << ", hello!" << std::endl;

    //Usage analysis.
    if (argc < 2)
    {
        
        //Help the user.
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    else
    {
        //Sqare root calculation.
        float inputValue{};
        inputValue = strtof(argv[1],NULL); //Type casting.
        
        #ifdef USE_MYMATH
        const float outputValue = mysqrt(inputValue);
        #else
        const float outputValue = sqrt(inputValue);
        #endif
        
        std::cout << "The square root of " << inputValue << " is: " << outputValue << std::endl;
    
        //Finish. OK.
        return 0;
    } 
}


