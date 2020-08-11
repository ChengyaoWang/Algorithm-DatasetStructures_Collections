'''
    This is the implementation of Quick Sort & Quick Select
'''

# Quick Sort Algorithm
# Time Complexity: O(nlogn)
# Space Complexity: O(1)
def quick_sort_(target: list, reverse = False) -> list:
    def quick_sort_utils(X: list, low: int, up: int):
        if low >= up:
            return
        l, r, pivot = low, up, X[(low + up) // 2]
        while l <= r:
            while X[l] < pivot:
                l += 1
            while X[r] > pivot:
                r -= 1
            if l >= r:
                break
            X[l], X[r] = X[r], X[l]
            l += 1
            r -= 1
        quick_sort_utils(X, low, l - 1)
        quick_sort_utils(X, r + 1, up)
    quick_sort_utils(target, 0, len(target) - 1)
    return target[::-1] if reverse else target

# Quick Select Algorithm
# Time Complexity: O(n)
# Space Complexity: O(1)
def quick_select_(target: list, idx: list, reverse = False) -> list:
    def quick_select_utils(X: list, k: int, low: int, up: int):
        if low >= up:
            return X[up]
        l, r, pivot = low, up, X[(low + up) // 2]
        while l <= r:
            while X[l] < pivot:
                l += 1
            while X[r] > pivot:
                r -= 1
            if l >= r:
                break
            X[l], X[r] = X[r], X[l]
            l += 1
            r -= 1
        if l - low + 1 > k:
            return quick_select_utils(X, k, low, l - 1)
        elif l - low + 1 == k and l == r:
            return X[l]
        else:
            return quick_select_utils(X, k - r + low - 1, r + 1, up)
    return quick_select_utils(target, idx, 0, len(target) - 1)


if __name__ == '__main__':
    import random
    dummyList = [random.randint(0, 100) for _ in range(50)]
    print(quick_select_(dummyList, 4))
    quick_sort_(dummyList)
    print(dummyList)