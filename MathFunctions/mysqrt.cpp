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
    result = sqrt(number)+1;
    return result;
}