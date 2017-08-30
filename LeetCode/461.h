/* 461. Hamming distance
 */

/**
 * @brief Get the hamming distance between bit string of two integers.
 * @param x A 32-bit signed integer.
 * @param y A 32-bit signed integer.
 * @return The hamming distance between bit string of _x_ and _y_.
 */
int hammingDistance(int x, int y)
{
    int w = x ^ y;

    // Popcount algorithm of calculating number of set bits
    w = w - ((w >> 1) & 0x55555555);    // Group 2
    w = (w & 0x33333333) + ((w >> 2) & 0x33333333); // Group 4
    w = (w & 0x0F0F0F0F) + ((w >> 4) & 0x0F0F0F0F); // Group 8
    w = (w & 0x00FF00FF) + ((w >> 8) & 0x00FF00FF); // Group 16
    return (w & 0x0000FFFF) + ((w >> 16) & 0x0000FFFF);
}

int hammingDistance2(int x, int y)
{
    int w = x ^ y;
    w = w - ((w >> 1) & 0x55555555);
    w = (w & 0x33333333) + ((w >> 2) & 0x33333333);
    return (((w + (w >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
