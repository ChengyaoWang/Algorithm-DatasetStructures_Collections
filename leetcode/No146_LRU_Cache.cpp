/*
    Serialization & Deserialization of Binary Trees
        https://leetcode.com/problems/lru-cache/
*/

class DLL_Node{
public:
    int k, v;
    DLL_Node *next, *prev;
    DLL_Node(int k, int v){
        this -> k = k;
        this -> v = v;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkedList{
public:
    DLL_Node *head, *tail;
    DoubleLinkedList(){
        head = new DLL_Node(-1, -1);
        tail = new DLL_Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    void append(DLL_Node *node){
        node -> prev = tail -> prev;
        node -> next = tail;
        tail -> prev = node;
        node -> prev -> next = node;
    }
    void pop(DLL_Node *node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
};


class LRUCache {
private:
    DoubleLinkedList dll;
    unordered_map<int, DLL_Node*> dic;
    int maxCapacity;
    
public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        dll = DoubleLinkedList();
        dic = {};
    }
    
    int get(int key) {
        if(dic.find(key) == dic.end()){
            return -1;
        }
        DLL_Node *buf = dic[key];
        dll.pop(buf);
        dll.append(buf);
        return buf -> v;
    }
    
    void put(int key, int value) {
        DLL_Node *buf = nullptr;
        if(dic.find(key) != dic.end()){
            buf = dic[key];
            dll.pop(buf);
            dll.append(buf);
            buf -> v = value;
        }
        else{
            if(dic.size() == maxCapacity){
                buf = dll.head -> next;
                dic.erase(buf -> k);
                dll.pop(buf);
            }
            buf = new DLL_Node(key, value);
            dic[key] = buf;
            dll.append(buf);
        }
    }
};