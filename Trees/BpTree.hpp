# ifndef BPTREE_HPP
# define BPTREE_HPP

# include "TreeBase.hpp"
# include "BpNode.hpp"

# include <assert.h>
# include <iostream>
# include <utility>

template<typename K, typename V>
class BpTree: Tree<K, V>{

private:
    BpNode<K, V>* _split(BpNode<K, V>* parent, BpNode<K, V>* child) {
        int middleLoc = child -> middleLoc();
        K upKey = (child -> key)[middleLoc];
        // Constructs New Node (See if Child is a Leaf)
        BpNode<K, V>* newNode = nullptr;
        if (child -> isLeaf) {
            newNode = new BpNode<K, V> (
                child -> _get_kList(middleLoc, -1),
                child -> _get_vList(middleLoc, -1),
                child, child -> next, child -> isLeaf
            );
        } else {
            newNode = new BpNode<K, V> (
                child -> _get_kList(middleLoc + 1, -1),
                child -> _get_cList(middleLoc + 1, -1),
                child -> isLeaf
            );
        }

        // Update Parent
        if (parent == nullptr) {
            parent = new BpNode<K, V>({upKey}, {child, newNode});
        } else {
            parent -> push_(upKey, newNode, true);
        }
        // Update Child
        child -> resize(middleLoc);
        
        return parent;
    }

    BpNode<K, V>* _merge(BpNode<K, V>* root, int loc) {
        BpNode<K, V>* leftC = (root -> children)[loc];
        BpNode<K, V>* rightC = (root -> children)[loc + 1];
        K pKey;
        BpNode<K, V>* pPtr;
        // We need the Node from parent if leftC / rightC is not child
        if (!leftC -> isLeaf) {
            pKey = (root -> key)[loc];
            pPtr = (rightC -> children)[0];
            leftC -> push_back_(pKey, pPtr, true);
        } else {
            leftC -> next = rightC -> next;
            if (rightC -> next)
                rightC -> next -> prev = leftC;
        }
        // Merge the Nodes
        for (int i = 0; i < rightC -> size(); ++i) {
            pKey = (rightC -> key)[i];
            if (leftC -> isLeaf) {
                leftC -> push_back_(pKey, (*rightC)[pKey]);
            } else {
                pPtr = (rightC -> children)[i + 1];
                leftC -> push_back_(pKey, pPtr, true);
            }
        }
        // Pop Node From Parent
        root -> pop_(loc, true);

        // Delete Right Child
        delete rightC;

        return root;
    }


    BpNode<K, V>* _find_helper(BpNode<K, V>* root, K key) {
        if (root -> isLeaf) {
            return (root -> kInNode(key)) ? root: nullptr;
        } else {
            BpNode<K, V>* p = root -> traverse_(key);
            return _find_helper(p, key);
        }
    }

    BpNode<K, V>* _insertion_helper(BpNode<K, V>* root, K key, V val){
        // Traversal
        if (root == nullptr) {
            ++nodeNum;
            return new BpNode<K, V>({key}, {val}, head, tail);
        } else if (root -> isLeaf) {
            if (!root -> kInNode(key)){
                root -> push_(key, val);
                ++nodeNum;
            }
        } else {
            BpNode<K, V>* p = root -> traverse_(key);
            p = _insertion_helper(p, key, val);
            if (p -> size() >= M) {
                root = _split(root, p);
            }
        }
        return root;
    }

    BpNode<K, V>* _removal_helper(BpNode<K, V>* root, K key){
        if (root == nullptr) {
            return nullptr;
        } else if (root -> isLeaf) {
            if (root -> kInNode(key)) {
                int _loc = root -> locate_(key);
                root -> pop_(_loc);
                --nodeNum;
            }
        } else {
            BpNode<K, V>* p = root -> traverse_(key);
            p = _removal_helper(p, key);
            if (p -> size() < minNodeSize) {
                int loc = p -> nthChild;
                BpNode<K, V>* rightSib = (loc < root -> size()) ? (root -> children)[loc + 1]: nullptr;
                BpNode<K, V>* leftSib = (loc > 0) ? (root -> children)[loc - 1]: nullptr;
                K pKey;
                if (rightSib != nullptr && rightSib -> size() > minNodeSize){
                    // Target Child Modification
                    pKey = (rightSib -> key).front();
                    if (p -> isLeaf) {
                        p -> push_back_(pKey, (*rightSib)[pKey]);
                        rightSib -> pop_front_();
                    } else {
                        p -> push_back_(pKey, (rightSib -> children).front(), true);

                        auto q = p -> get_successor((p -> key).back());
                        (p -> key).back() = (q.first -> key)[q.second];
                        
                        rightSib -> pop_front_(false);
                    }
                    // Root Modification
                    auto pair = root -> get_successor((root -> key)[loc]);
                    (root -> key)[loc] = (pair.first -> key)[pair.second];

                } else if (leftSib != nullptr && leftSib -> size() > minNodeSize){
                    // Target Child Modification
                    pKey = (leftSib -> key).back();
                    if (p -> isLeaf) {
                        p -> push_front_(pKey, (*leftSib)[pKey]);
                        leftSib -> pop_back_();
                    } else {
                        p -> push_front_(pKey, (leftSib -> children).back(), false);
                        
                        auto q = p -> get_successor((p -> key).front());
                        (p -> key).front() = (q.first -> key)[q.second];
                        
                        leftSib -> pop_back_(true);
                    }
                    // Root Modification
                    auto pair = root -> get_successor((root -> key)[loc - 1]);
                    (root -> key)[loc - 1] = (pair.first -> key)[pair.second];
                } else if (rightSib != nullptr) { 
                    // Merge
                    root = _merge(root, loc);
                } else {
                    root = _merge(root, loc - 1);
                }
            }
        }
        return root;
    }

    /*
        Utility Functions
    */
    template<typename Lambda>
    void _inorder_traverse(BpNode<K, V>* root, Lambda&& func){
        if (root == nullptr) {
            return ;
        } else if (root -> isLeaf) {
            for (auto& k: root -> key) {
                func(k);
                assert(previous <= k);
                previous = k;
                
            }
        } else {
            // for (auto& c: root -> children) {
                // _inorder_traverse(c, func);
            // }
            _inorder_traverse((root -> children).front(), func);
            for (int i = 0; i < root -> size(); ++i) {
                func((root -> key)[i]);
                
                assert(previous <= (root -> key)[i]);
                previous = (root -> key)[i];
                
                _inorder_traverse((root -> children)[i + 1], func);
            }
        }     
        return;
    }

    void _check_validity_helper(BpNode<K, V>* root, int depth){
        /*
            Check for all nodes
                1. All node should have size " (M - 1) / 2 <= <= M - 1" (except root)
        */
        if ((this -> root != root && root -> size() < minNodeSize) || M - 1 < root -> size()){
            std::cout << "Node Size Is Out of Range" << std::endl;
        }
        /*
            Leaf Check
                2. Total Number
                3. All leaves on same height
                4. Size of Vec_Key / Mapping Size
        */
        if (root -> isLeaf) {
            if (height == -1) {
                height = depth;
            } else if (height != depth) {
                std::cout << "Uneven Depth" << std::endl;
            }
            if (root -> size() != root -> mapping.size()) {
                std::cout << "Size of Key & Mapping Doesn't Match" << std::endl;
            }
            nodeCount += root -> size();
        } else {
            /*
                Internal Node Check
                    2. Mapping Value & Vec_children Should Match
                    3. Parent Pointer
                    4. nthChild Attribute
                    5. Key Index should be equal to the first key of the right child
            */
            if (root -> children.size() != root -> size() + 1){
                std::cout << "Size of Key & Children Doesn't Match" << std::endl;
            }
            BpNode<K, V>* c = nullptr;
            for (int i = 0; i < (root -> children).size(); ++i) {
                c = (root -> children)[i];
                _check_validity_helper(c, depth + 1);
                if (c != nullptr && c -> parent != root) {std::cout << "Parent Pointer Invalid" << std::endl;}
                if (c != nullptr && c -> nthChild != i) {std::cout << "Child nthChild Num Invalid" << std::endl;}
            }
        }
        return;
    }

public:
    // Operational Variables 
    BpNode<K, V>* root = nullptr;
    BpNode<K, V>* head = new BpNode<K, V>();
    BpNode<K, V>* tail = new BpNode<K, V>();
    int nodeNum = 0, M, minNodeSize;

    int previous = -1;

    // Variables for Validity Check
    bool FLAG_valid;
    int nodeCount, height = -1;

    BpTree(int M){
        this -> M = M;
        minNodeSize = (M - 1) / 2;
        head -> next = tail;
        tail -> prev = head;
    }
    ~BpTree(void){}

    template<typename Lambda>
    void InorderTraverse(Lambda&& func){
        _inorder_traverse(root, func);
    }

    V operator[](K key){
        BpNode<K, V>* foundNode = _find_helper(root, key);
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
            root = nullptr;
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