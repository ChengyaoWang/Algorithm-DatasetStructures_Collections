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


# Node Class for SuffixTrees
class SuffixTreeNode:

    def __init__(self) -> SuffixTreeNode:
        
        self.suffix_link: SuffixTreeNode = None
        self.children: Dict[List[int, int, SuffixTreeNode]] = {}

    def __getitem__(self, c: str) -> List[int, int, SuffixTreeNode]:
        return self.children.get(c, None)
    
    def __setitem__(self, c: str, n: List[int, int, SuffixTreeNode]) -> None:
        self.children[c] = n
        return
    
    def contains(self, c: str) -> bool:
        return c in self.children
    
    def split(self, e: str, c: str, dl: int) -> SuffixTreeNode:

        end: int = self.children[e][0] + dl
        newChild: SuffixTreeNode = SuffixTreeNode()
        newChild[c] = [end, -1, SuffixTreeNode()]

        self.children[e][1] = end
        self.children[e][2] = newChild

        return newChild

class SuffixTreeEdge(object):

    def __init__(self) -> None:
        pass
    
    



class SuffixTree(object):

    def __init__(self) -> None:
        self.root: SuffixTreeNode = SuffixTreeNode()
        self.inv_ptr: List[SuffixTreeNode] = None

    def build_tree(self, s: str):
        # Insert Termination Char
        s += '$'
        self.inv_ptr = []

        # Prepare to Build Tree
        n = len(s)
        self.act_e: str = '\0'
        self.act_n: SuffixTreeNode = self.root
        self.act_l: int = 0
        self.remainder: int = 1

        # Begins Iterative Insertion
        for i, c in enumerate(s):

            if not self.act_n.contains(c = c) and self.act_e is None:
                self.act_n[c] = [i, -1, SuffixTreeNode()]
                continue

            # If We Can Still be Lazy

            if self.act_e is None or s[self.act_n[self.act_e][0] + self.act_l] == c:
                if self.act_e is None:
                    self.act_e = c
                self.act_l += 1
                self.remainder += 1
                continue
            # Now we have to split
            split_node_prev: SuffixTreeNode = None
            
            
            
            while self.remainder > 0:
                split_node = self.act_n.split(e = self.act_e, c = c, dl = self.act_l)
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
