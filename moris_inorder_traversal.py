'''
    Implementation Moris - Inorder Traversal
        -> O(n) Space for BST traversal
'''
from red_black_tree import RBTrees




def MorisInorderTraversal(root, func) -> bool:

    pred = None

    while root:
        if root.left:
            pred = root.left
            while pred.right and pred.right != root:
                pred = pred.right            
            if pred.right is None:
                pred.right = root
                root = root.left
            else:
                func(root)
                pred.right = None
                root = root.right
        else:
            func(root)
            root = root.right

    return True


if __name__ == '__main__':

    rbtree = RBTrees()

    import random
    randomPool = [random.randint(0, 1000) for _ in range(5)]
    for num in randomPool:
        rbtree.insert(num)
    
    func = lambda x: print(x.key)
    MorisInorderTraversal(root = rbtree.root, func = func)
    







