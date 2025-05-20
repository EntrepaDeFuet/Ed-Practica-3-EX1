#ifndef NODETREE_H
#define NODETREE_H
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class Key, class Value>


class NODEtree {

public:

NODEtree(const Key& key);
NODEtree(const NODEtree<Key,Value>& orig);
virtual ~NODEtree();

/* Modificadors */
void setRight( NODEtree<Key,Value>* node);
void setLeft( NODEtree<Key,Value>* node);
void setKey( Key _key);


/* Consultors */
const Key& getKey() const;
const vector<Value>& getValue() const;
 NODEtree <Key,Value>* getLeft() const;
 NODEtree <Key, Value>* getRight() const;



bool isRoot() const;
bool hasLeft() const;
bool hasRight() const;
bool isExternal() const;
void insertValue(const Value& v);
int depth() const;
int height() const;
bool operator==(const NODEtree<Key,Value>& node) const;

// Mètodes pròpis per a encapsular codi:
NODEtree <Key,Value>* getFather() const;
bool mateixaLlista(vector<Value> llista) const;
void setFather( NODEtree<Key,Value>* node);

private:

Key key;
vector<Value> values;
NODEtree<Key, Value>* left;
NODEtree<Key,Value>* right;
//Sense l'atribut pare no he sapigut com veure si es root o calcular la depth.
NODEtree<Key, Value>* father;

};
//Constructors:

template <class Key, class Value>
NODEtree<Key,Value>::NODEtree(const Key& key){
    this->key = key;
    this->father = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <class Key, class Value>
NODEtree<Key,Value>::NODEtree(const NODEtree<Key,Value>& orig){
    this->key = orig.getKey();
    this->values = orig.getValue();
    this->father = orig.getFather();
}

template <class Key, class Value>
void NODEtree<Key,Value>::setRight(NODEtree<Key,Value>* node){
    this->right = node;
}

//Destructor:
template <class Key, class Value>
NODEtree<Key,Value>::~NODEtree(){}

//Modificadors:

template <class Key, class Value>
void NODEtree<Key,Value>::setLeft(NODEtree<Key,Value>* node){
    this->left = node;
}
template <class Key, class Value>
void NODEtree<Key,Value>::setKey(Key _key){
    this->key = _key;
}
//Consultors:
template <class Key, class Value>
const Key& NODEtree<Key,Value>::getKey() const{
    return this->key;
}
template <class Key, class Value>
const vector<Value>& NODEtree<Key,Value>::getValue() const{
    return this->values;
}

template <class Key, class Value>
 NODEtree<Key,Value>* NODEtree<Key,Value>::getRight() const{
    return this->right;
}
template <class Key, class Value>
 NODEtree<Key,Value>* NODEtree<Key, Value>::getLeft() const{
    return this->left;
}
template <class Key,class Value>
NODEtree <Key,Value>*  NODEtree<Key, Value>::getFather() const{
    return this->father;
}

//Altres mètodes.

template <class Key, class Value>
bool NODEtree<Key,Value>::isRoot()const{
    if(this->getFather()== nullptr){
        return true;
    } else {
        return false;
    }
}

template <class Key, class Value>
bool NODEtree <Key, Value>::hasLeft() const{
    return this->getLeft()!=nullptr;
}

template <class Key, class Value>
bool NODEtree <Key, Value>::hasRight() const{
    return this->getRight()!=nullptr;
}

template <class Key, class Value>
bool NODEtree <Key, Value>::isExternal() const{
    return !this->hasLeft() && !this->hasRight();
}

template <class Key, class Value>
void NODEtree <Key, Value>::insertValue(const Value& value){
    Value value1 = value;
    this->values.push_back(value1);
}

template <class Key, class Value>
int NODEtree <Key, Value>::depth()const{
    if(this->isRoot()){
        return 0;
    } else {
        return 1 + this->father->depth();
    }
}

template <class Key, class Value>
int NODEtree <Key, Value>::height() const{
    if(this->isExternal()){
        return 1;
    } else {
        return 1 + max(this->getLeft()->height(),this->getRight()->height());
    }
}
template <class Key, class Value>
bool NODEtree <Key, Value>::operator==(const NODEtree <Key,Value>& node) const{

    return this->getKey()==node.getKey() && this->mateixaLlista(node.getValue());

}

template <class Key, class Value>
bool NODEtree<Key,Value>::mateixaLlista(vector<Value> llista) const{
    bool b = true;
    int n;
    int i = 0;
    if(llista.size()==this->values.size()){
        n = llista.size();
    } else {
        b = false;
    }
    while(b && i < n){
        b = llista[i] == this->values[i];
        i++;
    }
    return b;
}
template <class Key, class Value>
void NODEtree<Key,Value>::setFather( NODEtree<Key,Value>* node){
    this->father = node;
}

#endif