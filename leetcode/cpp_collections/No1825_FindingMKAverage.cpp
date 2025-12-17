# include <iostream>
# include <queue>

using namespace std;

struct bstNode {
    int n, val;
    bstNode *l, *r;
    bstNode(int val): val(val), n(1), l(nullptr), r(nullptr) {}
};

class BST {
public:
    int size = 0;
    bstNode *root = nullptr;
    void insNode(int num) {
        if (root == nullptr)
            root = new bstNode(num);
        else {
            bstNode *p = root;
            for (;;) {
                if (p -> val == num) {
                    ++p -> n;
                    break;
                }
                else if (p -> val < num) {
                    if (p -> r == nullptr) {
                        p -> r = new bstNode(num);
                        break;
                    }
                    p = p -> r;
                }
                else {
                    if (p -> l == nullptr) {
                        p -> l = new bstNode(num);
                        break;
                    }
                    p = p -> l;
                }
            }
        }

        ++size;
        return;
    }
    void delNode(int num) {
        if (!contains(num))
            return ;

        bstNode *p = root, *p_parent = root;
        bstNode *tmp = nullptr;
        bool isLeftChild = true;
        for (;;) {
            if (p -> val == num) {
                if (--p -> n > 0) {
                    break;
                }
                // We're looking for the left subtree
                // if it doesn't exists
                if (p -> l == nullptr) {
                    // If it's a leaf node
                    tmp = (p -> r == nullptr) ? nullptr: p -> r;
                    if (p == root) {
                        root = p -> r;
                    }
                    else {
                        if (isLeftChild)
                            p_parent -> l = tmp;
                        else
                            p_parent -> r = tmp;
                    }
                    delete p;
                }
                // if it exists
                else {
                    // We have to find the largest number smaller than `num`
                    bstNode *pp = p -> l;
                    p_parent = p;
                    isLeftChild = true;
                    while (pp -> r != nullptr) {
                        p_parent = pp;
                        pp = pp -> r;
                        isLeftChild = false;
                    }

                    // Care if pp have a left subtree
                    tmp = (pp -> l != nullptr) ? pp -> l: nullptr;
                    if (isLeftChild)
                        p_parent -> l = tmp;
                    else
                        p_parent -> r = tmp;

                    // Swap the nodes
                    p -> n = pp -> n;
                    p -> val = pp -> val;
                    delete pp;
                }
                break;
            }
            else if (p -> val < num) {
                p_parent = p;
                p = p -> r;
                isLeftChild = false;
            }
            else {
                p_parent = p;
                p = p -> l;
                isLeftChild = true;
            }
        }
        
        --size;
        return ;
    }
    int max() {
        bstNode *p = root;
        while (p -> r != nullptr)
            p = p -> r;
        return p -> val;
    }
    int min() {
        bstNode *p = root;
        while (p -> l != nullptr)
            p = p -> l;
        return p -> val;
    }
    bool contains(int num) {
        bstNode *p = root;
        for (;;) {
            if (p == nullptr)
                return false;
            else if (p -> val == num)
                return true;
            else if (p -> val > num)
                p = p -> l;
            else
                p = p -> r;
        }
    }
    void printInOrder(bstNode *p) {
        if (p == nullptr)
            return ;
        printInOrder(p -> l);
        cout << p -> val << "/" << p -> n << "|";
        printInOrder(p -> r);
        return ;
    }
};



class MKAverage {
private:
    int m = 0, k = 0;
    long long rolling_sum = 0LL;
    int left_n = 0, mid_n = 0, right_n = 0;
    BST *left = nullptr, *mid = nullptr, *right = nullptr;
    queue<int> q = {};
public:
    MKAverage(int m, int k) {
        this -> m = m;
        this -> k = k;
        left = new BST();
        mid = new BST();
        right = new BST();
    }
    
    void addElement(int num) {
        if (q.size() == m) {
            int frontElem = q.front();
            q.pop();
            if (left -> contains(frontElem))
                left -> delNode(frontElem);
            else if (mid -> contains(frontElem)) {
                mid -> delNode(frontElem);
                rolling_sum -= frontElem;
            }
            else
                right -> delNode(frontElem);
        }

        q.push(num);
        if (left -> size == k || q.size() < m) {
            left -> insNode(num);
            if (left -> size > k) {
                num = left -> max();
                left -> delNode(num);
                mid -> insNode(num);
                rolling_sum += num;
            }
            if (mid -> size > (m - 2 * k)) {
                num = mid -> max();
                mid -> delNode(num);
                right -> insNode(num);
                rolling_sum -= num;
            }
        }
        else {
            right -> insNode(num);
            if (right -> size > k) {
                num = right -> min();
                right -> delNode(num);
                mid -> insNode(num);
                rolling_sum += num;
            }
            if (mid -> size > (m - 2 * k)) {
                num = mid -> min();
                mid -> delNode(num);
                left -> insNode(num);
                rolling_sum -= num;
            }
        }

    }

    int calculateMKAverage() {
        return (q.size() != m) ? -1: int(rolling_sum / (m - 2 * k));
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */