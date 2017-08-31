#ifndef _658_H
#define _658_H

struct solution_658 {
    int start;
    int end;
};

static int abs(int x)
{
	/* If x is a negative number, then x >> 31 is 11..11.
	 * x XOR 11..11 = NOT x, and 11..11 is -1 (2's complement).
	 * (NOT x) - (-1) = -x (2's complement).
	 *
	 * If x is a positive number, then x >> 31 is 00..00.
	 * x XOR 00..00 = x, and 00..00 is 0.
	 * x - 0 = x.
	 */
    return (x ^ (x >> 31)) - (x >> 31);
}

int findCloseElmentID(int *arr, int arrSize, int target)
{
    int start = 0, end = arrSize, mid;

	/* Use binary search to find the starting point of the solution. */
    while (start != end - 1) {
        mid = (start + end) >> 1;
        if (arr[mid] <= target)
            start = mid;
        else
            end = mid;
    }

	/* Boundary checking. */
    if (start + 1 == arrSize)   // At the end of the array
        return start;

	if (abs(arr[start] - target) <= abs(arr[start + 1] - target))
        return start;
    else
        return start + 1;
}

struct solution_658 findSolution(int *arr, int arrSize, int startPoint, int target, int solSize)
{
    struct solution_658 solution;
    int leftDiff, rightDiff, solNum = 1;    // It will be positive.

    solution.start = solution.end = startPoint;

	/* Find the solution from the starting point and extend to the left and right. */
    while (solution.start != 0 && solution.end != arrSize - 1 &&   // Check boundary
           solNum < solSize) {
        leftDiff = abs(arr[solution.start - 1] - target);   // Find the value 1 left
        rightDiff = abs(arr[solution.end + 1] - target);    // Find the value 1 right
        if (leftDiff <= rightDiff)
            --solution.start;
        else
            ++solution.end;
        ++solNum;
    }

    /* Check if the number of solution is enough. */
    if (solNum < solSize) {
        if (solution.start == 0)
            solution.end += solSize - solNum;
        else
            solution.start -= solSize - solNum;
    }

    return solution;
}

#endif
