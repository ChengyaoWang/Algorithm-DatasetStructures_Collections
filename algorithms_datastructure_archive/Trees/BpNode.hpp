# ifndef BPNODE_HPP
# define BPNODE_HPP

# include <vector>
# include <unordered_map>
# include <utility>

# include <assert.h>


template<typename K, typename V>
class BpNode{

private:
    // InNode Traverse Method
    int _find_loc(K key) {
        int c = 0;
        for (; c < size(); ++c) {
            if (key <= (this -> key)[c])
                break;
        }
        return c;
    }
    // Push Node for Internal Node
    bool _push_node(int loc, K key, BpNode<K, V>* p, bool pAlignRight) {
        int dp = pAlignRight ? 1: 0;
        // Insert Key, Children
        (this -> key).insert((this -> key).begin() + loc, key);
        children.insert(children.begin() + loc + dp, p);
        // Update Information About Child (If Not Nullptr)
        if (p != nullptr) {
            p -> parent = this;
            p -> nthChild = loc + dp;
            for (int i = loc + 1 + dp; i < children.size(); ++i) {
                ++(children[i] -> nthChild);
            }
        }
        // Return on Success
        return true;
    }
    // Push Node for Leaf Node
    bool _push_node(int loc, K key, V val) {
        // Insert Key, Val & Chilren
        (this -> key).insert((this -> key).begin() + loc, key);
        mapping[key] = val;
        // Return on Success
        return true;
    }
    // Pop Node for Internal Node  
    bool _pop_node(int loc, bool pAlignRight) {
        int dp = pAlignRight ? 1: 0;
        // Remove Key, Children
        key.erase(key.begin() + loc);
        children.erase(children.begin() + loc + dp);
        // Update Information About Child
        for (int i = loc + dp; i < children.size(); ++i) {
            if (children[i] != nullptr) {
                --(children[i] -> nthChild);
            }
        }
        // Return On Success
        return true;
    }
    // Pop Node for Leaf Node
    bool _pop_node(int loc) {
        // Remove Key, Val & Children
        mapping.erase(key[loc]);
        key.erase(key.begin() + loc);
        // Return On Success
        return true;
    }



public:
    bool isLeaf;
    std::vector<K> key;
    BpNode<K, V>* parent = nullptr;
    int nthChild = -1;
    // Field For Internal / Leaf Nodes
    BpNode<K, V>* prev = nullptr, *next = nullptr;
        
    std::vector<BpNode<K, V>*> children;
    std::unordered_map<K, V> mapping;
    
    // Constructors & Destructors
    // For Internal Nodes
    BpNode (std::vector<K> key, std::vector<BpNode<K, V>*> children, bool isLeaf = false) {
        this -> key = key;
        this -> children = children;
        for (int i = 0; i < children.size(); ++i) {
            if (children[i] != nullptr) {
                children[i] -> parent = this;
                children[i] -> nthChild = i;
            }
        }
        this -> isLeaf = isLeaf;
    }
    // For Leaf Nodes
    BpNode (std::vector<K> key, std::vector<V> val, BpNode<K, V>* prev, BpNode<K, V>* next, bool isLeaf = true) {
        this -> key = key;
        for (int i = 0; i < key.size(); ++i) {
            (this -> mapping)[key[i]] = val[i];
        }
        this -> isLeaf = isLeaf;
        this -> prev = prev;
        this -> next = next;
        prev -> next = this;
        next -> prev = this;
    }
    // For Empty Nodes
    BpNode (bool isLeaf = true) {}
    ~BpNode(){}


    V& operator[](K key) {
        assert(isLeaf);
        return mapping[key];
    }
    

    // Helper Functions
    int size(void){return key.size();}
    int middleLoc(void){return int(key.size() - 1) / 2;}
    bool kInNode(K key){return mapping.find(key) != mapping.end();}


    // Resize Function
    std::vector<K> _get_kList(int start, int end) {
        end = (end == -1) ? size(): end;
        return std::vector<K> (key.begin() + start, key.begin() + end);
    }
    std::vector<V> _get_vList(int start, int end) {
        end = (end == -1) ? size(): end;
        std::vector<V> retList = {};
        for(auto it = key.begin() + start; it != (key.begin() + end); ++it) {
            retList.push_back(mapping[*it]);
        }
        return retList;
    }
    std::vector<BpNode<K, V>*> _get_cList(int start, int end) {
        end = (end == -1) ? size() + 1: end;
        return std::vector<BpNode<K, V>*> (children.begin() + start, children.begin() + end);
    }
    bool resize(int end) {
        end = (end == -1) ? size(): end;
        if (isLeaf) {
            for (auto it = key.begin() + end; it != key.end(); ++it) {
                mapping.erase(*it);
            }
        } else {
            children.resize(end + 1);
        }
        key.resize(end);
        return true;
    }


    // Used for Traversing
    BpNode<K, V>* traverse_(K key){
        int _loc = _find_loc(key);
        if (_loc < size() && (this -> key)[_loc] == key) {
            ++_loc;
        }
        return children[_loc];
    }
    // Used for Query
    int locate_(K key) {
        int _loc = _find_loc(key);
        return (_loc == (this -> key).size()) ? -1: _loc;
    }

    /*
        For the Following Functions, We Always Assume "key" is present in "root"
            -> Validity Check Should be done by the caller
    */
    std::pair<BpNode<K, V>*, int> get_successor(K key) {
        int _loc = _find_loc(key);
        if (isLeaf) {
            if (_loc < size() - 1) {
                return std::make_pair(this, _loc + 1);
            } else {
                return std::make_pair(next, 0);
            }
        } else {
            BpNode<K, V>* p = children[_loc + 1];
            while (!p -> isLeaf) {
                p = (p -> children).front();
            }
            return std::make_pair(p, 0);
        }
    }
    std::pair<BpNode<K, V>*, int> get_predecessor(K key) {
        int _loc = _find_loc(key);
        if (isLeaf) {
            if (_loc > 0) {
                return std::make_pair(this, _loc - 1);
            } else {
                return std::make_pair(prev, prev ? prev -> size() - 1: 0);
            }
        } else {
            BpNode<K, V>* p = children[_loc];
            while (!p -> isLeaf) {
                p = (p -> children).back();
            }
            return std::make_pair(p, (p -> key).size() - 1);
        }
    }
    
    /*
        Modifiers Functions
    */
    // For Leaf Nodes
    bool pop_back_(void) {return _pop_node(size() - 1);}
    bool pop_front_(void) {return _pop_node(0);}
    bool pop_(int loc) {return _pop_node(loc); }
    bool push_back_(K key, V val) {return _push_node(size(), key, val);}
    bool push_front_(K key, V val) {return _push_node(0, key, val);}
    bool push_(int loc, K key, V val) {return _push_node(loc, key, val);}
    bool push_(K key, V val) {
        int loc = _find_loc(key);
        return _push_node(loc, key, val);
    }
    // For Internal Nodes
    bool pop_back_(bool pAlignRight) {return _pop_node(size() - 1, pAlignRight);}
    bool pop_front_(bool pAlignRight) {return _pop_node(0, pAlignRight);}
    bool pop_(int loc, bool pAlignRight) {return _pop_node(loc, pAlignRight); }
    bool push_back_(K key, BpNode<K, V>* newK, bool pAlignRight) {return _push_node(size(), key, newK, pAlignRight);}
    bool push_front_(K key, BpNode<K, V>* newK, bool pAlignRight) {return _push_node(0, key, newK, pAlignRight);}
    bool push_(int loc, K key, BpNode<K, V>* newK, bool pAlignRight) {return _push_node(loc, key, newK, pAlignRight);}
    bool push_(K key, BpNode<K, V>* newK, bool pAlignRight) {
        int loc = _find_loc(key);
        return _push_node(loc, key, newK, pAlignRight);
    }
};
# endif