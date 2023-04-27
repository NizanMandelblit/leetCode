/**
 *
 * https://leetcode.com/problems/two-sum/
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i = 0;
    int j = 0;
    int *arraIndices = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;


    for (i = 0; i < numsSize; i++)
    {
        for (j = (i + 1); j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                arraIndices[0] = i;
                arraIndices[1] = j;
            }
        }
    }
    return arraIndices;
}