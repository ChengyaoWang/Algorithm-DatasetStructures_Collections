'''
    Implementation of Red - Black Tree in Python
'''

'''
    Definition of RB_Node
'''
class RB_Node(object):
    def __init__(
        self,
        key,
        c: str = 'Black',
        value = None,
        parent = None,
        left = None,
        right = None,
        isLeaf: bool = True
    ):
        # Self - Information
        self.c: str = c
        self.key = key
        self.value = value
        self.isLeaf: bool = isLeaf

        # Elders
        self.parent: RB_Node = parent
        # Children
        self.left: RB_Node = left
        self.right: RB_Node = right

    def get_grandparent(self):
        return self.parent.parent if self.parent else None

    def get_sibling(self):
        if not self.parent:
            return None
        if self == self.parent.left:
            return self.parent.right
        return self.parent.left

    def get_uncle(self):
        if not self.parent:
            return None
        return self.parent.sibling
    
    def get_successor(self):
        retNode = self
        # If self has left child
        if not retNode.right.isLeaf:
            retNode = self.right
            while not retNode.left.isLeaf:
                retNode = retNode.left
        # Else, trace up
        else:
            p = retNode.parent
            while p is not None:
                if retNode != p.right:
                    break
                retNode = p
                p = p.parent
            retNode = p
        return retNode

    def get_predecessor(self):
        retNode = self
        # If self has right child
        if not retNode.left.isLeaf:
            retNode = self.left
            while not retNode.right.isLeaf:
                retNode = retNode.right
        # Else, trace up
        else:
            p = retNode.parent
            while p is not None:
                if retNode != p.left:
                    break
                retNode = p
                p = p.parent
            retNode = p
        return retNode

    def get_num_child(self) -> int:
        return 2 - self.left.isLeaf - self.right.isLeaf
    

class RBTrees(object):

    def __init__(self):
        self.root: RB_Node = RB_Node(key = None)
        self.nodeCnt: int = 0

    def __str__(self) -> str:
        if self.nodeCnt == 0:
            return 'Empty Tree'
        path = []
        def func(x: RB_Node):
            if not x.isLeaf:
                path.append(str(x.key))
        self.inorder_traverse(self.root, func, 0)
        return 'Inorder Traversal:\n\t' + '-'.join(path)

    def __getitem__(self, key):
        loc = self._bin_search_utils(self.root, key)
        if loc.key == key:
            return loc.value
        return None

    def __len__(self):
        return self.nodeCnt

    # Left Rotation w.r.t x
    def _left_rotation(self, x: RB_Node) -> None:
        # Getting x's right child
        y = x.right
        assert(y != None), "Debug Port for y == None"
        
        # At this point, we assume that y is an valid node
        # 1. Detach the left child of y
        x.right = y.left
        if y.left:
            y.left.parent = x
        
        # 2. Re-parent y
        y.parent = x.parent
        if x.parent == None:
            self.root = y
        else:
            # Originally x is the left child of its parents
            if x == x.parent.left:
                x.parent.left = y
            else:
                x.parent.right = y
        
        # 3. Fix relationship between x & y
        y.left = x
        x.parent = y

    # Right Rotation w.r.t x
    def _right_rotation(self, x: RB_Node) -> None:
        # Almost Mirror operations to left rotation
        y = x.left
        assert(y != None), "Debug Port for y == None"

        # 1. Detach the right child of x
        # if y.right:
        x.left = y.right
        if y.right:
            y.right.parent = x
        
        # 2. Re-parent y
        y.parent = x.parent
        if x.parent == None:
            self.root = y
        else:
            if x == x.parent.left:
                x.parent.left = y
            else:
                x.parent.right = y
        # 3. Fix the relationship between x & y
        y.right = x
        x.parent = y

    # Returns the Closest Node Compared with Target
    def _bin_search_utils(self, root: RB_Node, target) -> RB_Node:
        if root.key == target or root.isLeaf:
            return root
        
        if root.key > target:
            return self._bin_search_utils(root.left, target)
        else:
            return self._bin_search_utils(root.right, target)

    # Construct New Leaf
    def _get_new_leaf(self, key, value = None):
        newLeaf = RB_Node(key, value = value, c = 'Red', isLeaf = False)
        newLeaf.left = RB_Node(None, parent = newLeaf)
        newLeaf.right = RB_Node(None, parent = newLeaf)
        return newLeaf

    # Traverse Methods
    def _inorder_traverse(self, root: RB_Node, func, depth: int) -> None:
        if not root:
            return None
        self._inorder_traverse(root.left, func, depth + 1)
        func(root)
        self._inorder_traverse(root.right, func, depth + 1)
    def _preorder_traverse(self, root: RB_Node, func, depth: int) -> None:
        if not root:
            return None
        func(root)
        self._preorder_traverse(root.left, func, depth + 1)
        self._preorder_traverse(root.left, func, depth + 1)
    def _postorder_traverse(self, root: RB_Node, func, depth: int) -> None:
        if not root:
            return None
        self._postorder_traverse(root.left, func, depth + 1)
        self._postorder_traverse(root.left, func, depth + 1)
        func(root)
    def _depthwise_traverse(self, root: RB_Node, func) -> None:
        import collections
        q = collections.deque([root])
        while q:
            curNode = q.popleft()
            func(curNode)
            if not curNode.isLeaf:
                q.append(curNode.right)
                q.append(curNode.right)

    # Traverse the RB Tree
    def traverse(self, root: RB_Node, func, order: str = 'preorder', depth: int = None) -> None:
        if order == 'preorder':
            self._preorder_traverse(root = root, func = func, depth = 0)
        elif order == 'inorder':
            self._inorder_traverse(root = root, func = func, depth = 0)
        elif order == 'postorder':
            self._postorder_traverse(root = root, func = func, depth = 0)
        elif order == 'depthwise':
            self._depthwise_traverse(root = root, func = func)
        else:
            raise ValueError('order Type not Supported')
        return None

    # Standard Insertion Process for BSTs
    def _insert_node_tree(self, x: RB_Node) -> bool:
        if self.root.isLeaf:
            self.root = x
            return True
        insertLoc = self._bin_search_utils(self.root, x.key)
        # If Key already existed in the tree
        if insertLoc.key == x.key:
            return False
        
        x.parent = insertLoc.parent
        if insertLoc == insertLoc.parent.left:
            x.parent.left = x
        else:
            x.parent.right = x
        self.nodeCnt += 1
        return True

    # Standard Deletion Process for BSTs
    def _delete_node_tree(self, xKey) -> RB_Node:
        if not self.root:
            return None
        deleteLoc = self._bin_search_utils(self.root, xKey)
        
        # If Key not Found
        if deleteLoc.key != xKey:
            return None
        
        self.nodeCnt -= 1

        if deleteLoc.get_num_child() == 2:
            # Prioritize Successor for no reason
            copiedNode = deleteLoc.get_successor()
            if copiedNode is None:
                copiedNode = deleteLoc.get_predecessor()
        else:
            copiedNode = deleteLoc

        # Swap the 2 nodes
        deleteLoc.key = copiedNode.key
        deleteLoc.value = copiedNode.value
        # deleteLoc.c = copiedNode.c

        # Delete copiedNode, guaranteed to be single childed
        if not copiedNode.right.isLeaf:
            copiedNode_child = copiedNode.right
        else:
            copiedNode_child = copiedNode.left
        
        copiedNode_child.parent = copiedNode.parent
        
        if copiedNode.parent:
            if copiedNode == copiedNode.parent.left:
                copiedNode_child.parent.left = copiedNode_child
            else:
                copiedNode_child.parent.right = copiedNode_child

        # Handles the simpliest case here
        if copiedNode.c == 'Black':
            if copiedNode_child.c == 'Red':
                copiedNode_child.c = 'Black'
            else:
                return copiedNode_child 
        return None

    # Restore Tree after insertion
    # 4 Cases in total
    def _insertion_restoreRB(self, x: RB_Node) -> bool:
        # y will be the uncle for x
        while x != self.root and x.parent.c == 'Red':
            if x.parent == x.get_grandparent().left:
                y = x.get_grandparent().right
                if y.c == 'Red':
                    x.parent.c = 'Black'
                    y.c = 'Black'
                    x.get_grandparent().c = 'Red'
                    x = x.get_grandparent()
                else:
                    if x == x.parent.right:
                        x = x.parent
                        self._left_rotation(x)
                    x.parent.c = 'Black'
                    x.get_grandparent().c = 'Red'
                    self._right_rotation(x.get_grandparent())
            else:
                y = x.get_grandparent().left
                if y.c == 'Red':
                    x.parent.c = 'Black'
                    y.c = 'Black'
                    x.get_grandparent().c = 'Red'
                    x = x.get_grandparent()
                else:
                    if x == x.parent.left:
                        x = x.parent
                        self._right_rotation(x)
                    x.parent.c = 'Black'
                    x.get_grandparent().c = 'Red'
                    self._left_rotation(x.get_grandparent())
        self.root.c = 'Black'
        return True

    # Restore Tree after deletion
    # 6 Cases in total
    #   Credit: https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
    '''Case 1 - x is the root'''
    def _deletion_restoreRB_case1(self, x: RB_Node) -> bool:
        if x.parent is None:
            self.root = x
            return True
        return self._deletion_restoreRB_case2(x)
    '''Case 2 - x's sibling is red'''
    def _deletion_restoreRB_case2(self, x: RB_Node) -> bool:
        sibling = x.get_sibling()
        if sibling.c == 'Red':
            x.parent.c = 'Red'
            sibling.c = 'Black'
            if x == x.parent.left:
                self._left_rotation(x.parent)
            else:
                self._right_rotation(x.parent)
        return self._deletion_restoreRB_case3(x)   
    '''Case 3 - Black Sibling'''
    def _deletion_restoreRB_case3(self, x: RB_Node) -> bool:
        sibling = x.get_sibling()
        if sibling.parent.c == sibling.c == sibling.left.c == sibling.right.c == 'Black':
           sibling.c = 'Red'
           return self._deletion_restoreRB_case1(x.parent)
        return self._deletion_restoreRB_case4(x)
    '''Case 4 - Red Parent & Black Sibling'''
    def _deletion_restoreRB_case4(self, x: RB_Node) -> bool:
        sibling = x.get_sibling()
        if sibling.parent.c == 'Red' and sibling.c == sibling.left.c == sibling.right.c == 'Black':
            sibling.parent.c = 'Black'
            sibling.c = 'Red'
            return True
        return self._deletion_restoreRB_case5(x)
    '''Case 5 - Fix Subtree of Siblings'''        
    def _deletion_restoreRB_case5(self, x: RB_Node) -> bool:
        sibling = x.get_sibling()
        if sibling.c == 'Black':
            if x == x.parent.left and sibling.left.c == 'Red' and sibling.right.c == 'Black':
                sibling.c = 'Red'
                sibling.left.c = 'Black'
                self._right_rotation(sibling)
            elif x == x.parent.right and sibling.right.c == 'Red' and sibling.left.c == 'Black':
                sibling.c = 'Red'
                sibling.right.c = 'Black'
                self._left_rotation(sibling)
        return self._deletion_restoreRB_case6(x)
    '''Case 6 - Restore the entire family'''
    def _deletion_restoreRB_case6(self, x: RB_Node) -> bool:
        sibling = x.get_sibling()

        sibling.c = sibling.parent.c
        sibling.parent.c = 'Black'

        if x == x.parent.left:
            sibling.right.c = 'Black'
            self._left_rotation(x.parent)
        else:
            sibling.left.c = 'Black'
            self._right_rotation(x.parent)
        return True
    def _deletion_restoreRB(self, x: RB_Node) -> bool:
        return self._deletion_restoreRB_case1(x)


    '''
        Public APIs
    '''
    # Insertion Operation -> Takes O(logn)
    def insert(self, key, value = None) -> bool:
        newLeaf = self._get_new_leaf(key, value = value)
        if self._insert_node_tree(newLeaf):
            assert(self._insertion_restoreRB(newLeaf))
        return True
    # Deletion Operation -> Takes O(logn)
    def delete(self, key) -> bool:
        delLeaf = self._delete_node_tree(key)
        if delLeaf is not None:
            assert(self._deletion_restoreRB(delLeaf))
        return True
    # Check Validity of RB-Tree
    #   -> Only Property 4 & 5 is needed
    def check(self) -> bool:
        pathLen, adjacentRed = [None, True], [True]
        def _util_check(x: RB_Node, depth: int):
            if not x:
                if pathLen[0] is None:
                    pathLen[0] = depth
                pathLen[1] |= (pathLen[0] == depth)
                return
            _util_check(x.left, depth + (x.c == 'Black'))
            adjacentRed[0] |= (x.c == 'Black' or (x.left.c == 'Black' and x.right.c == 'Black'))
            _util_check(x.left, depth + (x.c == 'Black'))
        _util_check(self.root, 0)
        return (pathLen[1] and adjacentRed[0])




if __name__ == '__main__':
    
    testNode = RB_Node(1, 'Black')
    testTree = RBTrees()
    
    import random
    for _ in range(50000):
        print(f'Test {_}')
        # Insertion
        randomPool = [random.randint(0, 1000) for _ in range(100)]
        for i in randomPool:
            testTree.insert(i, i + 1)
        # Value Retrival
        for i in randomPool:
            assert(testTree[i] == i + 1), '(key, value) pair not correct'
        print('Validity of Tree After Insertion', testTree.check())

        # Deletion
        randomPool = [random.randint(0, 1000) for _ in range(100)]
        for i in randomPool:
            testTree.delete(i)
        for i in randomPool:
            assert(testTree[i] == None), '(key, value) not deleted'
        print('Validity of Tree After Deletion ', testTree.check())