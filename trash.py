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
        

    def _deletion_restoreRB_case6(self, x: RB_Node) -> bool:
        sibling = x.get_sibling()

        sibling.c = sibling.parent.c
        sibling.parent.c = 'Black'

        if sibling == sibling.parent.left:
            sibling.right.c = 'Black'
            self._left_rotation(x.parent)
        else:
            sibling.left.c = 'Black'
            self._right_rotation(x.parent)
        return True
