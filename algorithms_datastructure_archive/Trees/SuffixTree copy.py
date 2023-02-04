'''
    Suffix Tree Structure
        -> Uses Ukkonen's Algorithm for construction
        -> Which luckily takes O(n)

    A Life-Saver Reference:
        https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english/9513423#9513423

    Cautions:
        1) This implementation mainly serves to handle `k-mismatch problem`, thus may not be general enough
        2) Implementation is not quite `Pythonic`, for a easier translation to cpp / go version
'''

from __future__ import annotations
from typing import List, Tuple, Dict

# class SuffixTreeEdge(object):
#     def __init__(self, n_idx_st: int, n_idx_en: int) -> SuffixTreeEdge:
#         self.n_idx_st: int = n_idx_st
#         self.n_idx_en: int = n_idx_en

# Node Class for SuffixTrees
class SuffixTreeNode(object):
    def __init__(self,
        n_idx: int, l_idx: int = 1000000
    ) -> SuffixTreeNode:
        
        self.n_idx: int = n_idx
        self.l_idx: int = l_idx

        self.suffix_link: SuffixTreeNode = None
        self.children: Dict[str, SuffixTreeNode] = {'\0': None}

    def split(self,
        act_i: int, act_l: int, 
        act_new_c: str, act_ori_c: str
    ) -> None:
        
        if self.l_idx < act_l:
            raise RuntimeError('Cannot Split At Index Beyond the Length of Current Edge')
        
        # new_l: int = 

        self.children[act_ori_c] = SuffixTreeNode(n_idx = self.n_idx + act_l, l_idx = self.l_idx)
        self.children[act_new_c] = SuffixTreeNode(n_idx = act_i)
        self.l_idx = act_l

        return 

    def __len__(self) -> int:
        return self.l_idx

    def __getitem__(self, c: str) -> SuffixTreeNode:
        return self.children.get(c, None)

    def __setitem__(self, c: str, child: SuffixTreeNode) -> None:
        self.children[c] = child
        return

class SuffixTree(object):

    def __init__(self) -> None:
        self.root: SuffixTreeNode = SuffixTreeNode(n_idx = -1)
        self.s: str = None

    def build_tree(self, s: str):
        # Insert Termination Char
        s += '$'
        self.s = s

        # Prepare to Build Tree
        n = len(s)
        self.act_e: str = '\0'
        self.act_n: SuffixTreeNode = self.root
        self.act_l: int = 0
        self.remainder: int = 0

        # Begins Iterative Insertion
        for i, c in enumerate(s):

            # If we can still be lazy, Update self.act_xxx
            if self.act_n[c] is None and self.act_e is None:
                self.act_n[c] = SuffixTreeNode(n_idx = i)
                continue

            # If we can still be lazy, Update self.act_xxx
            if self.act_e is None or s[self.act_n[self.act_e].n_idx + self.act_l] == c:
                if self.act_e is None:
                    self.act_e = c
                self.act_l += 1
                self.remainder += 1
                continue

            # Now we HAVE to split
            split_node_prev: SuffixTreeNode = None
            while self.remainder > 0:
                # split_node = self.act_n.split(
                #     act_i = i, act_l = 
                # )
                if split_node_prev is not None:
                    split_node_prev.suffix_link = split_node
                split_node_prev = split_node

                # Rule 1 
                if self.act_n == self.root:
                    self.act_e = s[self.act_n[self.act_e][0] + 1]
                    self.act_l -= 1
                    self.remainder -= 1
                elif self.act_n.suffix_link is not None:
                    self.act_n = self.act_n.suffix_link
                    self.act_l -= 1
                    self.remainder -= 1
                else:
                    self.act_n = self.root

            self.act_e = None

if __name__ == '__main__':
    
    tree: SuffixTree = SuffixTree()
    # tree.build_tree(s = 'abcabxabcd')
    tree.build_tree(s = 'abcab')
    print('Tree Build Done')
