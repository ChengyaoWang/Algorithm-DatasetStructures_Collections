#ifndef TREEBASE_HPP
#define TREEBASE_HPP

/*
    Base Class for Trees
*/
template<typename K, typename V>
class Tree{
    private:

    public:
    Tree(){}
    ~Tree(){}

    virtual V operator[](K key) = 0;
    virtual bool insert(K key, V val) = 0;
    virtual bool remove(K key) = 0;
};

#endif