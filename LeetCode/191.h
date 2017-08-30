/* 191. Number of 1 bits
 */
#include <stdint.h>

///<summary>Get number of 1 bits of input _n_.</summary>
int hammingWeight(uint32_t n)
{
    // Popcount algorithm
    n = n - ((n >> 1) & 0x55555555);    // Group 2
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333); // Group 4
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F); // Group 8
    n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF); // Group 16
    return (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF); // Group 32
}