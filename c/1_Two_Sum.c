#include <stdio.h>
#include <stdlib.h>
#define SIZE 50000

/**
 * 
 * C does not have all the niceities of c++ and other language, so we have to do it the hard way.
 * Obvious brute force approach. O(n^2) time, O(1) space
 * 
 */
int *twoSum_1(int *nums, int numsSize, int target, int *returnSize)
{
    int *ret = (int *)malloc(2 * sizeof(int));
    for (ret[0] = 0; ret[0] < numsSize; ++ret[0])
    {
        for (ret[1] = ret[0] + 1; ret[1] < numsSize; ++ret[1])
        {
            if (nums[ret[0]] + nums[ret[1]] == target)
            {
                return ret;
            }
        }
    }
    *returnSize = 2;
    return NULL;
}
// https://leetcode.com/problems/two-sum/discuss/351702/C-4ms-99-using-hashtable
/**
 * Sorting approach. O(nlogn) time, O(n) space
 * The brute force is obviously expensive. If we were able to instead have the numbers in sorted order, 
 * we can find a solution in O(n) time. The reasoning behind this is as follows;
 * 1).Start with the two indexes, pointing to the lowest (lo) and highest (hi) values.
 * 2).If current values are less than our target, then increase lo and hence increase the sum. 
 *  If the sum is greater than our target, then decrease hi and hence reduce the sum.
 * 3). Continue from 2. so long as the sum doesn't equal the target.
 * The problem is of course that c makes us do it the hard way. 
 * In particular we don't want to rearrange the nums array as we need to return the indexes. 
 * We have to provide our own functions. 
 * partition_indexes that reorders an array of indexes based on the value of nums that the indexes 
 * address and sort_indexes that uses quicksort to reorder the index mappings.
 * Even though finding the answer if the numbers are sorted is O(n), 
 * we have to pay O(nlogn) time for the sort, so the solution is O(nlogn) time.
 */
void swap(int *const a, int *const b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Partition indexes that map to nums, without changing nums values or ordering
int partition_indexes(const int *const nums, int *const indexes, int lo, int hi)
{
    int pivot = lo++;
    int pivot_val = nums[indexes[pivot]];
    int idx = pivot;
    int tmp;
    for (; lo < hi; ++lo)
    {
        if (nums[indexes[lo]] <= pivot_val)
        {
            swap(indexes + lo, indexes + ++idx);
        }
    }

    // Swapt the pivot (which is at the front) with the last value less or equal to the pivot
    swap(indexes + pivot, indexes + idx);

    return idx;
}

// Sort indexes that map to nums, without changing nums values or ordering
void sort_indexes(const int *const nums, int *const indexes, int lo, int hi)
{
    if (lo < hi)
    {
        int pivot = partition_indexes(nums, indexes, lo, hi);
        sort_indexes(nums, indexes, lo, pivot);
        sort_indexes(nums, indexes, pivot + 1, hi);
    }
}

int *twoSum_2(int *nums, int numsSize, int target, int *returnSize)
{
    int *ret = (int *)malloc(2 * sizeof(int));

    // Build index mapping to nums that is sorted assendingly
    int *indexes = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i)
    {
        indexes[i] = i;
    }
    sort_indexes(nums, indexes, 0, numsSize);

    // Move in from either side, if the pair is below target, then left index must increase
    // to increase the sum, while right must decrease if the sum is over
    int lo = 0;
    int hi = numsSize - 1;
    while (nums[indexes[lo]] + nums[indexes[hi]] != target)
    {
        if (nums[indexes[lo]] + nums[indexes[hi]] < target)
        {
            ++lo;
        }
        else
        {
            --hi;
        }
    }

    ret[0] = indexes[lo];
    ret[1] = indexes[hi];

    free(indexes);

    *returnSize = 2;
    return ret;
}
// other ways
int *data = NULL;
int cmp(const void *a, const void *b)
{
    return data[*(int *)a] - data[*(int *)b];
}

int *twoSum_3(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int l, r, vl, vr;
    int *ix = (int *)malloc(numsSize * sizeof(int));
    int *res = (int *)malloc(2 * sizeof(int));
    for (r = 0; r < numsSize; r++){
        ix[r] = r;
    }

    data = nums;
    qsort(ix, numsSize, sizeof(int), cmp); // sort indexes by value
    vl = nums[ix[0]], vr = nums[ix[numsSize - 1]];

    for (l = 0, r = numsSize - 1; l < r && vl + vr != target;)
    {
        if (vl + vr > target)
        {
            r--;
            vr = nums[ix[r]];
        }
        else
        {
            l++;
            vl = nums[ix[l]];
        }
    }
    res[0] = ix[l];
    res[1] = ix[r];
    free(ix);
    return res;
}
/**
 * Hashmap. O(n) time, O(n) space
 * The hashmap solution for c++ is nice and simple
 * the c takes a bit more work and uses the external uthash (which is automatically included for c solutions).
 */
/**
 * 自定义hash 函数
 */
int hash(int key)
{
    int r = key % SIZE;
    return r < 0 ? r + SIZE : r;
}

void insert(int *keys, int *values, int key, int value)
{
    int index = hash(key);
    while (values[index])
    {
        index = (index + 1) % SIZE;
    }
    keys[index] = key;
    values[index] = value;
}

int search(int *keys, int *values, int key)
{
    int index = hash(key);
    while (values[index])
    {
        if (keys[index] == key)
        {
            return values[index];
        }
        index = (index + 1) % SIZE;
    }
    return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int keys[SIZE];
    int values[SIZE] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        int complements = target - nums[i];
        int value = search(keys, values, complements);
        if (value)
        {
            int *indices = (int *)malloc(sizeof(int) * 2);
            indices[0] = value - 1;
            indices[1] = i;
            return indices;
        }
        insert(keys, values, nums[i], i + 1);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    int nums[] = {3, 2, 3, 11, 15, 1}, target = 6;
    int count = sizeof(nums) / sizeof(nums[0]);
    int *p;
    int *result = twoSum_3(nums, count, target, p);
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", *(result + i));
    }
    // int *sortNums = sortArray(nums, count);
    // for (int i = 0; i < count; i++)
    // {
    //     printf("%d ", *(sortNums + i));
    // }
    // printf("\n");
    // int result[2] = {0, 0};
    // for (int i = 0; *(sortNums + i) < target && i < count; i++)
    // {
    //     //printf("%d ", *(sortNums + i)); 1 2 7
    //     result[0] = *(sortNums + i);
    //     while (*(sortNums + i + 1) != target - result[0])
    //     {
    //         i = i + 1;
    //     }
    //     result[1] = *(sortNums + i + 1);
    // }
    // for (int i = 0; i < 2; i++)
    // {
    //     printf("%d ", result[i]);
    // }

    return 0;
}