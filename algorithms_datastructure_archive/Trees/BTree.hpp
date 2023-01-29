# ifndef BTREE_HPP
# define BTREE_HPP

# include "TreeBase.hpp"
# include "BNode.hpp"

# include <assert.h>
# include <iostream>
# include <utility>

template<typename K, typename V>
class BTree: Tree<K, V>{

private:
    BNode<K, V>* _split(BNode<K, V>* parent, BNode<K, V>* child) {
        int middleLoc = child -> middleLoc();

        // Constructs New Node
        BNode<K, V>* newNode = new BNode<K, V>(
            child -> _get_kList(middleLoc + 1, -1),
            child -> _get_vList(middleLoc + 1, -1),
            child -> _get_cList(middleLoc + 1, -1),
            child -> isLeaf
        );
        
        // Update Parent
        K upKey = (child -> key)[middleLoc];
        if (parent == nullptr) {
            parent = new BNode<K, V>(upKey, (*child)[upKey]);
            parent -> children = {child, newNode};
            child -> nthChild = 0;
            child -> parent = parent;
            newNode -> nthChild = 1;
            newNode -> parent = parent;
        } else {
            parent -> insert_(upKey, (*child)[upKey], newNode);
        }

        // Update Child
        child -> resize(middleLoc);
        
        return parent;
    }

    BNode<K, V>* _merge(BNode<K, V>* root, int loc) {
        BNode<K, V>* leftC = (root -> children)[loc];
        BNode<K, V>* rightC = (root -> children)[loc + 1];
        K pKey;
        BNode<K, V>* pPtr;
        // Copy the Node from parent -> leftC
        pKey = (root -> key)[loc];
        pPtr = (rightC -> children)[0];
        leftC -> push_back_(pKey, (*root)[pKey], pPtr);
        // Merge the Nodes
        for (int i = 0; i < rightC -> size(); ++i) {
            pKey = (rightC -> key)[i];
            pPtr = (rightC -> children)[i + 1];
            leftC -> push_back_(pKey, (*rightC)[pKey], pPtr);
        }
        // Pop Node From Parent
        root -> pop_(loc);

        // Delete Right Child
        delete rightC;

        return root;
    }


    BNode<K, V>* _find_helper(BNode<K, V>* root, K key) {
        if (root == nullptr) {
            return nullptr;
        }
        BNode<K, V>* p = root -> traverse_(key);
        return (p == root) ? root: _find_helper(p, key);
    }

    BNode<K, V>* _insertion_helper(BNode<K, V>* root, K key, V val){
        // Traversal
        if (root == nullptr) {
            ++nodeNum;
            return new BNode<K, V>(key, val, true);
        }
        
        BNode<K, V>* p = root -> traverse_(key);
        if (p == root) {
            return root;
        } else if (root -> isLeaf) {
            root -> insert_(key, val, nullptr);
            ++nodeNum;
        } else {
            p = _insertion_helper(p, key, val);
            if (p -> size() >= M) {
                root = _split(root, p);
            }
        }
        return root;
    }

    /*  
        B-Tree Removal is Rather Complicated
            -> Total Conditions 6
            -> Post-deletion Adjustment is left for "root's" Parent
    */
    BNode<K, V>* _removal_helper(BNode<K, V>* root, K key){
        if (root == nullptr) {
            return nullptr;
        }
        
        BNode<K, V>* p = root -> traverse_(key);
        // Found in the Current Node
        if (p == root) {
            int loc = root -> locate_(key);
            if (root -> isLeaf) {
                // Current Node is Leaf
                root -> pop_(loc);
                --nodeNum;
                return root;
            } else {
                // Current Node is Internal Node
                std::pair<BNode<K, V>*, int> succ = root -> get_successor(key);
                // Copy The Successor Into the Location
                K upKey = (succ.first -> key)[succ.second];
                (root -> mapping).erase(key);
                (root -> mapping)[upKey] = (*succ.first)[upKey];
                (root -> key)[loc] = upKey;
                // Go delete the successor
                p = _removal_helper((root -> children)[loc + 1], upKey);
            }
        } else {
            p = _removal_helper(p, key);
        }
        
        if (p == nullptr) {
            return root;
        }

        // Adjust 
        if (p -> size() >= minNodeSize) {
            return root;
        } else {
            int loc = p -> nthChild;
            BNode<K, V>* rightSib = (loc < root -> size()) ? (root -> children)[loc + 1]: nullptr;
            BNode<K, V>* leftSib = (loc > 0) ? (root -> children)[loc - 1]: nullptr;
            K pKey;
            // Since Insertion Prioritize Right Split
            // We Prioritize Right Merge Here
            if (rightSib != nullptr && rightSib -> size() > minNodeSize){
                // Target Child Modification
                pKey = (root -> key)[loc];
                p -> push_back_(pKey, (*root)[pKey], (rightSib -> children).front());
                // Root Modification
                (root -> mapping).erase(pKey);
                pKey = (rightSib -> key).front();
                (root -> key)[loc] = pKey;
                (root -> mapping)[pKey] = (*rightSib)[pKey];
                // Right Sibling Modification
                rightSib -> pop_front_(false);
            } else if (leftSib != nullptr && leftSib -> size() > minNodeSize){
                // Target Child Modification
                pKey = (root -> key)[loc - 1];
                p -> push_front_(pKey, (*root)[pKey], (leftSib -> children).back(), false);
                // Root Modification
                (root -> mapping).erase(pKey);
                pKey = (leftSib -> key).back();
                (root -> key)[loc - 1] = pKey;
                (root -> mapping)[pKey] = (*leftSib)[pKey];
                // Right Sibling Modification
                leftSib -> pop_back_();
            } else if (rightSib != nullptr) { 
                // Merge
                root = _merge(root, loc);
            } else {
                root = _merge(root, loc - 1);
            }
        }
        return root;
    }

    /*
        Utility Functions
    */
    template<typename Lambda>
    void _inorder_traverse(BNode<K, V>* root, Lambda&& func){
        if (root == nullptr) {
            return;
        }
        for (int i = 0; i <= root -> size(); ++i) {
            _inorder_traverse((root -> children)[i], func);
            if (i == root -> size())
                break;
            
            auto p = root -> get_successor((root -> key)[i]);
            auto q = root -> get_predecessor((root -> key)[i]);
                        
            if (q.first != nullptr) {
                func((q.first -> key)[q.second]);
            }
            func((root -> key)[i]);
            if (p.first != nullptr) {
                func((p.first -> key)[p.second]);
            }
            std::cout << std::endl;
        }
        return;
    }

    void _check_validity_helper(BNode<K, V>* root, int depth){
        /*
            Depth Check
                5. All leaves on same height
        */
        if (root == nullptr) {
            if (height == -1) {
                height = depth;
            } else if (height != depth) {
                std::cout << "Uneven Depth" << std::endl;
            }
            return;
        }
        /*
            Node Check:
                1. All node should have size " (M - 1) / 2 <= <= M - 1"
                2. Size of Vec_Key / Mapping Size & Mapping Value / Vec_children
                3. Parent Pointer
        */
        if (root -> size() < minNodeSize || M - 1 < root -> size()){
            std::cout << "Node Size Is Out of Range" << std::endl;
        } else if (root -> children.size() != root -> size() + 1){
            std::cout << "Size of Key & Children Doesn't Match" << std::endl;
        } else if (root -> size() != root -> mapping.size()) {
            std::cout << "Size of Key & Mapping Doesn't Match" << std::endl;
        }
        for (int i = 0; i <= root -> size(); ++i) {
            BNode<K, V>* p = (root -> children)[i];
            _check_validity_helper(p, depth + 1);
            if (i == root -> size())
                break;
            /*
                Items To Check:
                    4. "nthChild" attribute
                    6. Total Number
            */
            ++nodeCount;
            if (p != nullptr && p -> parent != root) {
                std::cout << "Parent Pointer Invalid" << std::endl;
            } else if (p != nullptr && p -> nthChild != i) {
                std::cout << "Child nthChild Num Invalid" << std::endl;
            }
        }
        return;
    }

public:
    // Operational Variables 
    BNode<K, V>* root = nullptr;
    int nodeNum = 0, M, minNodeSize;
    
    // Variables for Validity Check
    bool FLAG_valid;
    int nodeCount, height = -1;

    BTree(int M){
        this -> M = M;
        minNodeSize = (M - 1) / 2;
    }
    ~BTree(void){}

    template<typename Lambda>
    void InorderTraverse(Lambda&& func){
        _inorder_traverse(root, func);
    }

    V operator[](K key){
        BNode<K, V>* foundNode = _find_helper(root, key);
        if (foundNode == nullptr) {
            return -1;
        } else {
            return (*foundNode)[key];
        }
    }

    bool insert(K key, V val){
        root = _insertion_helper(root, key, val);
        // If We Need Another Level
        if (root -> size() >= M) {
            root = _split(nullptr, root);
        }
        return true;
    }

    bool remove(K key){
        root = _removal_helper(root, key);
        if (root && root -> size() == 0) {
            root = root -> children[0];
        }
        return true;
    }

    bool check_validity(void) {
        FLAG_valid = true;
        nodeCount = 0;
        height = -1;
        _check_validity_helper(root, 0);
        return FLAG_valid & (nodeCount == nodeNum);
    }
};



# endif