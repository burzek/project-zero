#include "math.h"


std::random_device rd;
std::default_random_engine eng(rd());


/**
 * @brief returns rand float from-to (included)
 * 
 * @param from 
 * @param to 
 * @return float 
 */
float RandRangeFloat(int from, int to) {
    std::uniform_real_distribution<float> distr(from, to);
    return distr(eng);
}

/**
 * @brief returns rand integer from-to (included)
 * 
 * @param from 
 * @param to 
 * @return int 
 */
int RandRangeInt(int from, int to) {
    std::uniform_int_distribution<int> distr(from, to);
    return distr(eng);
}