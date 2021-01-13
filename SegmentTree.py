'''
    This is the implementation of Segment Tree Using
        1. 1D - Arrays
        2. Binary Trees

    Public APIs are:
        1. Constructors
        2. Query - O(logn)
        3. Update - O(logn)
'''
import math
from typing import List, Tuple

# Implementation Using Binary Trees
class SegNode(object):
    def __init__(self, low: int = -1, up: int = -1, val: int = -1, left = None, right = None):
        self.low = low
        self.up = up
        self.val = val
        
        self.left = left
        self.right = right
        
class SegmentTree_TreeImple(object):
    
    def __init__(self, arr: List[int]):
        self.arr = arr.copy()
        self.root = self._init_util(low = 0, up = len(arr) - 1)

    def _init_util(self, low: int, up: int):
        if low == up:
            return SegNode(low = low, up = up, val = self.arr[low])
        
        curNode = SegNode(low = low, up = up)
        curNode.left = self._init_util(low, (low + up) // 2)
        curNode.right = self._init_util((low + up) // 2 + 1, up)
        curNode.val = curNode.left.val + curNode.right.val

        return curNode

    def _query_util(self, root: SegNode, low: int, up: int):
        # Query Range is within Node's Rage
        if low <= root.low and up >= root.up:
            return root.val
        elif root.up < low or root.low > up:
            return 0
        else:
            return self._query_util(root.left, low, up) + \
                   self._query_util(root.right, low, up)
    
    def _update_util(self, root: SegNode, idx: int, dVal: int):
        # Child Node Found
        if root is None:
            return 
        root.val += dVal
        mid = (self.root.low + self.root.up) // 2
        if idx <= mid:
            self._update_util(root.left, idx, dVal)
        else:
            self._update_util(root.right, idx, dVal)
        return 

    '''
        Public APIs
    '''
    def query(self, low: int, up: int) -> int:
        # Validate Invalid Input
        low = max(0, low)
        up = min(len(self.arr) - 1, up)
        # Query
        return self._query_util(root = self.root, low = low, up = up)

    def update(self, idx: int, val: int) -> None:
        assert(0 <= idx < len(self.arr)), 'Index Out of Range'
        dVal, self.arr[idx] = val - self.arr[idx], val
        self._update_util(root = self.root, idx = idx, dVal = dVal)


# Implementation Using Arrays
class SegmentTree_ArrImple(object):

    def __init__(self, arr: List[int]):
        self.arr = arr.copy()
        self.segArr = [None for _ in range(2 ** (math.ceil(math.log2(len(self.arr))) + 1) - 1)]
        self._init_util(idx = 0, low = 0, up = len(self.arr) - 1)

    def _init_util(self, idx: int, low: int, up: int):
        if low == up:
            self.segArr[idx] = self.arr[low]
        else:
            self.segArr[idx] =  self._init_util(2 * idx + 1, low, (low + up) // 2) + \
                                self._init_util(2 * idx + 2, (low + up) // 2 + 1, up)

        return self.segArr[idx]

    def _query_util(self, idx: int, curRange: Tuple[int], targetRange: Tuple[int]):
        curLow, curUp = curRange
        tarLow, tarUp = targetRange
        if tarLow <= curLow and curUp <= tarUp:
            return self.segArr[idx]
        elif tarUp < curLow or tarLow > curUp:
            return 0
        else:
            return self._query_util(2 * idx + 1, (curLow, (curLow + curUp) // 2), targetRange) + \
                   self._query_util(2 * idx + 2, ((curLow + curUp) // 2 + 1, curUp), targetRange)

    def _update_util(self, idx: int, tarIdx: int, dVal: int, curRange: Tuple[int]):
        
        if idx >= len(self.segArr) or self.segArr[idx] is None:
            return
        
        self.segArr[idx] += dVal
        curLow, curUp = curRange
        mid = (curLow + curUp) // 2

        if tarIdx <= mid:
            self._update_util(2 * idx + 1, tarIdx, dVal, curRange = (curLow, mid))
        else:
            self._update_util(2 * idx + 2, tarIdx, dVal, curRange = (mid + 1, curUp))
        
        return

    '''
        Public APIs
    '''
    
    def query(self, low: int, up: int) -> int:
        # Validate Invalid ranges
        low = max(0, low)
        up = min(len(self.arr) - 1, up)
        # Query
        return self._query_util(idx = 0, curRange = (0, len(self.arr) - 1), targetRange = (low, up))

    def update(self, idx: int, val: int):
        assert(0 <= idx < len(self.arr)), 'Index Out of Range'
        dVal, self.arr[idx] = val - self.arr[idx], val
        self._update_util(idx = 0, tarIdx = idx, dVal = dVal, curRange = (0, len(self.arr) - 1))


if __name__ == '__main__':

    testArr = [1, 3, 5, 7, 9, 11]

    treeA = SegmentTree_TreeImple(testArr)
    treeB = SegmentTree_ArrImple(testArr)


    print(treeA.query(0, 3))
    print(treeB.query(0, 3))

    treeA.update(5, 10)
    treeB.update(5, 10)

    print(treeA.query(0, 3))
    print(treeB.query(0, 3))

    treeA.update(0, 10)
    treeB.update(0, 10)

    print(treeA.query(0, 3))
    print(treeB.query(0, 3))

    print(treeA.query(0, 10))
    print(treeB.query(0, 10))

    print(treeB.arr)
    print(treeB.segArr)