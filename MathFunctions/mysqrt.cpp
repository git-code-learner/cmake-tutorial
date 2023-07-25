/**
 * Calculates the sqaure root of the number.
 * This library is intentionally working
 * non properly! To the proper result it adds
 * 1 in order for testing purposes to recognize 
 * what library was deployed.
*/

#include <cmath>

float mysqrt(const float &number)
{
    float result{};
    
    #if defined(HAVE_LOG) && defined(HAVE_EXP)
        result = exp(log(number) * 0.5);
    #else
        result = sqrt(number)+1;
    #endif

    return result;
}