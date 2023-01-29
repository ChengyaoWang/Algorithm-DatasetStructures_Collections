# ifndef BNODE_HPP
# define BNODE_HPP

# include <vector>
# include <unordered_map>
# include <utility>


template<typename K, typename V>
class BNode{

private:

    int _find_loc(K key) {
        int c = 0;
        for (; c < (this -> key).size(); ++c) {
            if (key <= (this -> key)[c])
                break;
        }
        return c;
    }

    bool _push_node(int loc, K key, V val, BNode<K, V>* p, bool pAlignRight) {
        int dp = pAlignRight ? 1: 0;
        // Insert Key, Val & Chilren
        mapping[key] = val;
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

    bool _pop_node(int loc, bool pAlignRight) {
        int dp = pAlignRight ? 1: 0;
        // Remove Key, Val & Children
        mapping.erase(key[loc]);
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


public:
    bool isLeaf;
    std::vector<K> key;
    std::unordered_map<K, V> mapping;
    std::vector<BNode<K, V>*> children;
    // Association With the Parent
    BNode<K, V>* parent = nullptr;
    int nthChild = -1;


    // Constructors & Destructors
    BNode (std::vector<K> key, std::vector<V> val, std::vector<BNode<K, V>*> children, bool isLeaf = false) {
        this -> key = key;
        for (int i = 0; i < key.size(); ++i) {
            (this -> mapping)[key[i]] = val[i];
        }
        this -> isLeaf = isLeaf;
        this -> children = children;
        for (int i = 0; i < children.size(); ++i) {
            if (children[i] != nullptr) {
                children[i] -> parent = this;
                children[i] -> nthChild = i;
            }
        }
    }
    // For Getting a new root
    BNode (K key, V val, bool isLeaf = false) {
        this -> key = {key};
        (this -> mapping)[key] = val;
        this -> isLeaf = isLeaf;
        this -> children = {nullptr, nullptr};
    }
    ~BNode(){}

    V& operator[](K key) {
        return mapping[key];
    }
    
    // Helper Functions
    int size(void){return key.size();}
    int middleLoc(void){return int(key.size()) / 2;}

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
    std::vector<BNode<K, V>*> _get_cList(int start, int end) {
        end = (end == -1) ? size() + 1: end;
        return std::vector<BNode<K, V>*> (children.begin() + start, children.begin() + end);
    }

    bool resize(int end) {
        end = (end == -1) ? size(): end;
        for (auto it = key.begin() + end; it != key.end(); ++it) {
            mapping.erase(*it);
        }
        key.resize(end);
        children.resize(end + 1);
        return true;
    }

    // Used for Traversing
    BNode<K, V>* traverse_(K key){
        int loc = _find_loc(key);
        return (loc < size() && key == (this -> key)[loc]) ? this: children[loc];
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
    
    std::pair<BNode<K, V>*, int> get_successor(K key) {
        int loc = _find_loc(key);
        BNode<K, V>* p = this;

        if (!isLeaf) {
            p = (p -> children)[loc + 1];
            while (!p -> isLeaf) {
                p = (p -> children).front();
            }
            return std::make_pair(p, 0);
        } else if (loc < size() - 1) {
            return std::make_pair(this, loc + 1);
        } else {
            // While Has Parent
            while (p -> nthChild != -1) {
                if (p -> nthChild < p -> parent -> size()) {
                    loc = p -> nthChild;
                    break;
                }
                p = p -> parent;
            }
            p = p -> parent;
            return std::make_pair(p, loc);
        }
    }

    std::pair<BNode<K, V>*, int> get_predecessor(K key) {
        int loc = _find_loc(key);
        BNode<K, V>* p = this;
        if (!isLeaf) {
            p = (p -> children)[loc];
            while (!p -> isLeaf) {
                p = (p -> children).back();
            }
            return std::make_pair(p, p -> size() - 1);
        } else if (loc > 0) {
            return std::make_pair(this, loc - 1);
        } else {
            // While Has Parent
            while (p -> nthChild != -1) {
                if (p -> nthChild > 0) {
                    loc = p -> nthChild - 1;
                    break;
                }
                p = p -> parent;
            }
            p = p -> parent;
            return std::make_pair(p, loc);
        }
    }
    // Insertion
    bool insert_(K key, V val, BNode<K, V>* newK, bool pAlignRight = true) {
        int loc = _find_loc(key);
        return _push_node(loc, key, val, newK, pAlignRight);
    }

    // Removal
    bool remove_(K key, bool pAlignRight = true) {
        int loc = _find_loc(key);
        return _pop_node(loc, pAlignRight);
    }

    // Other Functions
    bool pop_back_(bool pAlignRight = true) {
        return _pop_node(size() - 1, pAlignRight);
    }
    bool pop_front_(bool pAlignRight = true) {
        return _pop_node(0, pAlignRight);
    }
    bool pop_(int loc, bool pAlignRight = true) {
        return _pop_node(loc, pAlignRight); 
    }
    bool push_back_(K key, V val, BNode<K, V>* newK, bool pAlignRight = true) {
        return _push_node(size(), key, val, newK, pAlignRight);
    }
    bool push_front_(K key, V val, BNode<K, V>* newK, bool pAlignRight = true) {
        return _push_node(0, key, val, newK, pAlignRight);
    }
    bool push_(int loc, K key, V val, BNode<K, V>* newK, bool pAlignRight = true) {
        return _push_node(loc, key, val, newK, pAlignRight);
    }


};
# endif