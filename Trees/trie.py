'''
    This is an implementation of Trie
'''

class TrieNode(object):
    def __init__(self):
        self.children = [None for _ in range(52)]
        self.children_name = []
        self.EndOfStr = False


class Trie(object):

    char2idx = lambda self, x: ord(x) - 65 - 6 * (ord(x) >= 97)
    idx2char = lambda self, x: chr(65 + x + 6 * (x >= 26))

    def __init__(self):
        self.root = TrieNode()

    def insert(self, target: str):
        p = self.root
        for char in target:
            idx = self.char2idx(char)
            if p.children[idx] is None:
                p.children[idx] = TrieNode()
            p.children_name.append(target)
            p = p.children[idx]
        p.EndOfStr = True

    def word_in_tree(self, target: str) -> bool:
        p = self.root
        for char in target:
            idx = self.char2idx(char)
            if p.children[idx] is None:
                return False
            p = p.children[idx]
        return p != None and p.EndOfStr

    def search_prefix(self, target: str):
        p = self.root
        for char in target:
            idx = self.char2idx(char)
            if p.children[idx] is None:
                return None
            p = p.children[idx]
        return p

    def search_words_with_prefix(self, target: str):
        prefix_p = self.search_prefix(target)
        if prefix_p == None:
            return []
        return prefix_p.children_name

    def traverse(self):
        func = lambda x: print(''.join(x))
        self._dfs_helper(self.root, [], func)

    def _dfs_helper(self, p, path, function):
        if p is None:
            return
        if p.EndOfStr:
            function(path)
            return
        for idx in range(52):
            path.append(self.idx2char(idx))
            self._dfs_helper(p.children[idx], path, function)
            path.pop()
        return

if __name__ == '__main__':

    words = ["area","lead","wall","lady","ball"]
    trie = Trie()
    for word in words:
        trie.insert(word)

    # trie.printAll()
    print(trie.search_words_with_prefix('l'))