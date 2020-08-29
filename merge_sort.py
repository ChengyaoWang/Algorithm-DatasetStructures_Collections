'''
    This is the implementation of Merge Sort 
'''
# Merge Sort Algorithm
# Time Complexity: O(nlogn)
# Space Complexity: O(n)

from utils import timer

@timer
def merge_sort(target: list, reverse: bool = False):
    _merge_sort_cur(0, len(target), target)
    return target[::-1] if reverse else target

def _merge_sort_cur(low: int, up: int, target: list):
    if low + 1 >= up:
        return
    mid = (low + up) // 2
    _merge_sort_cur(low, mid, target)
    _merge_sort_cur(mid, up, target)
    p1, p2, newList = low, mid, []
    while p1 < mid and p2 < up:
        if target[p1] < target[p2]:
            newList.append(target[p1])
            p1 += 1
        else:
            newList.append(target[p2])
            p2 += 1
    newList = newList + target[p1: mid] + target[p2: up]
    target[low: up] = newList[:]
    return


if __name__ == '__main__':

    import random

    test_case_num = 100
    test_case_size = sorted([random.randint(0, 100000) for _ in range(test_case_num)])

    for i in test_case_size:
        print(f'Array Size {i}........')
        dummyList = [random.randint(-100000, 100000) for _ in range(i)]
        merge_sort(dummyList)
        if dummyList != sorted(dummyList):
            raise ValueError("\nWrong answer, Aborting....")
        print('Passed\n')