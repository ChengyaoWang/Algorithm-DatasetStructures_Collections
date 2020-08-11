'''
    This is the Implementation for finding the Longest Increasing Subsequence
'''

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
def LIS_binary_search_(nums: list) -> int:
    dp, maxLen = [1 for _ in range(len(nums) + 1)], 0
    for i, val in enumerate(nums):
        low, up = 0, maxLen
        while low < up:
            mid = (low + up) // 2
            if nums[mid] < val:
                low = mid + 1
            else:
                up = mid
        dp[low] = val
        maxLen = max(maxLen, low + 1)
    return maxLen


if __name__ == '__main__':
    import random
    dummyList = [random.randint(0, 100) for _ in range(20)]
    print(dummyList)
    print(LIS_binary_search_(dummyList))