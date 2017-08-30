/* 477. Total hamming distance
 */

/* Testing data */
int nums[4] = { 4, 14, 4, 14 }; // 6

int hammingDistance(int a, int b)
{
    if (a == b) return 0;

    int i = a ^ b;
    // Popcount algorithm
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
    i = (i & 0x00FF00FF) + ((i >> 8) & 0x00FF00FF);
    return (i & 0x0000FFFF) + ((i >> 16) & 0x0000FFFF);
}
/**
 * @brief Get the total hammimg distance of each pair in the _nums_
 *
 * Directly calculate the hamming distance of all pairs of the input numbers.
 * O(n^2) time -> TLE
 *
 * @param nums The pointer to the array of integers
 * @param numSize The number of elements in the _nums_
 * @return The total hamming distance of each pair in the _nums_
 */
int totalHammingDistance_sol1(int *nums, int numSize)
{
    int sum = 0;

    for (int i = 0; i < numSize - 1; ++i)
        for (int j = i + 1; j < numSize; ++j)
            sum += hammingDistance(nums[i], nums[j]);

    return sum;
}

/**
 * There are k numbers of all n numbers in bit x which are set.
 * The total hamming distance of each bit is k * (n-k).
 */
int totalHammingDistance_sol2(int *nums, int numSize)
{
    int sum = 0, k = 0;

    for (int i = 0; i < 32; ++i) {
        k = 0;
        for (int j = 0; j < numSize; ++j)
            k += (nums[j] >> i) & 1;
        sum += k * (numSize - k);
    }

    return sum;
}