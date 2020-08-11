'''
    This is the implementation of Binary Search
    reference: https://leetcode.com/discuss/general-discussion/786126/python-powerful-ultimate-binary-search-template-solved-many-problems
'''
# Binary Search Algorithm (with User Defined Condition)
# Time Complexity: O(logn)
# Space Complexity: O(1) - Inplace Search
def binary_search_(array: list, target: int) -> int:
    def condition(value) -> bool:
        return target <= array[mid]
    low, up = 0, len(array)
    while low < up:
        mid = low + (up - low) // 2
        if condition(mid):
            up = mid
        else:
            low = mid + 1
    return low

if __name__ == '__main__':
    import random
    dummyList = sorted([random.randint(0, 100) for _ in range(20)])
    print(dummyList)
    print(dummyList[binary_search_(dummyList, 40)])