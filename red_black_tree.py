'''
    Red Black Tree
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
        self.c = c
        self.key = key
        self.value = value
        self.isLeaf = isLeaf

        # Elders
        self.parent = parent
        # Children
        self.left = left
        self.right = right

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



class RBTrees(object):

    def __init__(self):
        self.root = None
        self.nodeCnt = 0

    def __str__(self):
        path = []
        func = lambda x, y = path: path.append(str(x.key))
        self.inorder_traverse(self.root, func)
        return ','.join(path)

    # Left Rotation w.r.t x
    def _left_rotation(self, x: RB_Node):
        # Getting x's right child
        y = x.right
        assert(y != None), "Debug Port for y == None"
        
        # At this point, we assume that y is an valid node
        # 1. Detach the left child of y
        # if y.left:
        y.left.parent = x
        x.right = y.left

        # 2. Re-parent y
        y.parent = x.parent
        if y.parent == None:
            self.root = y
        else:
            # Originally x is the left child of its parents
            if x == x.parent.left:
                y.parent.left = y
            else:
                y.parent.right = y
        
        # 3. Fix relationship between x & y
        x.parent = y
        y.left = x

    # Right Rotation w.r.t x
    def _right_rotation(self, x: RB_Node):
        # Almost Mirror operations to left rotation
        y = x.left
        assert(y != None), "Debug Port for y == None"

        # 1. Detach the right child of x
        # if y.right:
        y.right.parent = x
        x.left = y.right
        # 2. Re-parent y
        y.parent = x.parent
        if y.parent == None:
            self.root = y
        else:
            if x == x.parent.left:
                y.parent.left = y
            else:
                y.parent.right = y
        # 3. Fix the relationship between x & y
        x.parent = y
        y.right = x

    # Returns the Closest Node Compared with Target
    def _bin_search_utils(self, root: RB_Node, target) -> RB_Node:
        if root.key == target or root.isLeaf:
            return root
        
        if root.key > target:
            return self._bin_search_utils(root.left, target)
        else:
            return self._bin_search_utils(root.right, target)

    # Traverse the RB Tree
    def inorder_traverse(self, root: RB_Node, func):
        if root.isLeaf:
            return
        self.inorder_traverse(root.left, func)
        func(root)
        self.inorder_traverse(root.right, func)
        return



    # Construct New Leaf
    def _get_new_leaf(self, key, value = None):
        newLeaf = RB_Node(key, value = value, c = 'Red', isLeaf = False)
        newLeaf.left = RB_Node(None, parent = newLeaf)
        newLeaf.right = RB_Node(None, parent = newLeaf)
        return newLeaf

    def _insert_node_tree(self, x: RB_Node) -> bool:
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

        # Now Try to Restore the properties

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
                    x.get_grandparent().c = 'Black'
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
                    x.get_grandparent().c = 'Black'
                    self._left_rotation(x.get_grandparent())
        self.root.c = 'Black'
        return True
        

    def insert(self, key, value = None) -> bool:
        newLeaf = self._get_new_leaf(key, value)
        if not self.root:
            self.root = newLeaf
            self.root.c = 'Black'
            return True
        
        if self._insert_node_tree(newLeaf):
            assert(self._insertion_restoreRB(newLeaf))
        
        return True








    def delete(self, key):
        pass






if __name__ == '__main__':
    
    testNode = RB_Node(1, 'Black')
    testTree = RBTrees()
    
    import random

    for _ in range(50):

        randomPool = [random.randint(0, 1000) for _ in range(10)]
        # print(randomPool)
        for i in randomPool:
            testTree.insert(i)
        print(testTree)
