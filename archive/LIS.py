'''
    This is the Implementation for finding the Longest Increasing Subsequence
'''

from typing import List

# LIS using naive DP
# Time Complexity: O(n^2)
# Space Complexity: O(n)
def LIS_normal_dp_(nums: list) -> int:
    dp, maxLen = [1 for _ in range(len(nums))], 0
    for i, val in enumerate(nums):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)
        maxLen = max(maxLen, dp[i])
    return maxLen

# LIS using Binary Search + DP
# Time Complexity: O(nlogn)
# Space Complexity: O(n)
def LIS_binary_search_(nums: List[int]) -> int:

    from bisect import bisect_right
    maxLen = len(nums)
    d = [float('inf') for _ in range(maxLen + 1)]
    d[0] = float('-inf')

    for i in range(maxLen):
        idx = bisect_right(a = d, x = nums[i])
        if d[idx - 1] < nums[i] < d[idx]:
            d[idx] = nums[i]

    ret = 0
    for i in range(maxLen + 1):
        if d[i] != float('inf'):
            ret = i

    return ret

# LIS using Binary Search + DP, Returns the Optimal Array
# Time Complexity: O(nlogn)
# Space Complexity: O(n)
def LIS_binary_search_array_(nums: List[int]) -> List[int]:

    from bisect import bisect_right
    maxLen = len(nums)
    # DP Array
    d = [float('inf') for _ in range(maxLen + 1)]
    d[0] = float('-inf')
    # Index of DP Array
    di = [-1 for _ in range(maxLen + 1)]
    # Ancestor Position
    pos = [-1 for _ in range(maxLen)]

    for i in range(maxLen):
        idx = bisect_right(a = d, x = nums[i])
        if d[idx - 1] < nums[i] < d[idx]:
            d[idx], di[idx] = nums[i], i
            pos[i] = di[idx - 1]

    ret = 0
    for i in range(maxLen + 1):
        if d[i] != float('inf'):
            ret = i

    ret = di[ret]
    retList = []
    while ret != -1:
        retList.append(nums[ret])
        ret = pos[ret]

    return retList[::-1]

if __name__ == '__main__':
    
    import tqdm
    import random

    for _ in tqdm.tqdm(range(1000)):

        dummyList = [random.randint(0, 100) for _ in range(200)]
        a = LIS_binary_search_array_(dummyList)

        x = LIS_normal_dp_(nums = dummyList)
        y = LIS_binary_search_(nums = dummyList)
        z = LIS_normal_dp_(nums = a)

        assert x == y and x == z, "Error"