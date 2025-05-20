#ifndef BSTTREE_H
#define BSTTREE_H
#include "NODEtree.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;




template <class Key, class Value>

class BSTtree {

public:

BSTtree();
BSTtree(const BSTtree<Key, Value>& orig);
virtual ~BSTtree();
bool empty() const;
int size() const;
int height() const;
NODEtree<Key,Value>* insert(const Key& k, const Value& value);
const vector<Value>& valuesOf(const Key& k) const;
void printPreorder(const NODEtree<Key,Value>* n = nullptr) const;
void printInorder(const NODEtree<Key,Value>* n = nullptr) const;
void printPostorder(const NODEtree<Key,Value>* n = nullptr) const;
void printSecondLargestKey() const;
void mirrorTree();
list<NODEtree<Key, Value>*> getLeafNodes() const;

protected:

NODEtree<Key,Value>* root;
NODEtree<Key,Value>* search(const Key& k) const;

private:

int _size;
NODEtree<Key,Value>* copia(const NODEtree<Key,Value>* orig);
NODEtree<Key,Value>* insertaNode(NODEtree<Key,Value>* orig,NODEtree<Key,Value>* node);
const vector<Value>& valuesOfRecursiu(const NODEtree<Key,Value> orig,const Key& k) const;
void deleteNode(NODEtree<Key,Value>* node);
void buscarElGros(const NODEtree<Key,Value>* node)const;
void mirallNode(NODEtree<Key,Value> * orig, NODEtree<Key,Value>* mirall);
NODEtree<Key,Value>* getRoot() const;
const string valuesAString(const NODEtree<Key,Value>* node) const;
void buscaFulles(NODEtree<Key,Value>*node,list<NODEtree<Key,Value>*> &llista) const;
};

template <class Key, class Value>
BSTtree<Key,Value>::BSTtree(){
    this->root = nullptr;
    this->_size= 0;

}
template <class Key, class Value>
NODEtree<Key,Value>* BSTtree<Key,Value>::copia(const NODEtree<Key,Value>* orig){

    NODEtree<Key,Value>* node = new NODEtree<Key,Value>(*orig);
    if(orig->hasLeft()){
        node->setLeft(copia(orig->getLeft()));
        node->getLeft()->setFather(node);
    }
    if(orig->hasRight()){
        node->setRight(copia(orig->getRight()));
        node->getRight()->setFather(node);

    }
    return node;
}
template <class Key, class Value>
NODEtree<Key,Value>* BSTtree<Key,Value>::getRoot() const{
    return this->root;
}

template <class Key, class Value>
BSTtree<Key,Value>::BSTtree(const BSTtree<Key,Value>& orig){
    
    this->root = copia(orig.getRoot());
    this->_size = orig.size();
}

template<class Key,class Value>
void BSTtree<Key,Value>::deleteNode(NODEtree<Key,Value>* node){
    if(node->getLeft()!=nullptr){
        deleteNode(node->getLeft());
    }
    if(node->getRight()!=nullptr){
        deleteNode(node->getRight());
    }
    delete node;
    this->_size = this->_size-1;
}


template <class Key, class Value>
BSTtree<Key,Value>::~BSTtree(){
    
}
template <class Key, class Value>

bool BSTtree<Key,Value>::empty() const{
    return this->root == nullptr;
}
template <class Key, class Value>
int BSTtree<Key,Value>::size() const{
    return this->_size;
}
template <class Key, class Value>
int BSTtree<Key,Value>::height()const{
    return this->root->height();
}
template <class Key, class Value>
NODEtree<Key,Value>* BSTtree<Key,Value>::insert(const Key& k, const Value& value){
    
    NODEtree<Key,Value>* node = new NODEtree<Key,Value>(k);
    
    node->insertValue(value);
    
    return insertaNode(this->root,node);
}
template <class Key, class Value>
NODEtree<Key,Value>* BSTtree<Key,Value>::insertaNode(NODEtree<Key,Value>* orig ,NODEtree<Key,Value>* node){
    
    if(orig == nullptr){
        orig = node;
        this->_size = this->_size +1;
        return node;
    }
    else if(orig->getKey() == node->getKey()){
        
        orig->insertValue(node->getValue()[0]);
        return orig;
    } else if(orig->getKey()<node->getKey()){
        return insertaNode(orig->getRight(),node);

    }else if(orig->getKey()>node->getKey()){
        return insertaNode(orig->getLeft(),node);
    }
}

template<class Key, class Value>
const vector<Value>& BSTtree<Key,Value>::valuesOf(const Key& k) const{
    return valuesOfRecursiu(this->root,k);
}
template<class Key, class Value>
const vector<Value>& BSTtree<Key,Value>::valuesOfRecursiu(const NODEtree<Key,Value> orig,const Key& k) const{
    if(orig == nullptr){

        throw string("No hi ha cap valor amb aquesta clau");

    }else if(orig.getKey()==k){

        return orig.getValue();

    } else {
        if(k>orig.getKey()){
            return valuesOfRecursiu(orig.getRight(),k);
        } else {
            return valuesOfRecursiu(orig.getLeft(),k);
        }
    }
}
template<class Key, class Value>
const string BSTtree<Key,Value>::valuesAString(const NODEtree<Key,Value>* node)const{
    vector<Value> llista = node->getValue();
    string cadena = "";
    for (int i = 0; i<llista.size();i++){
        cadena += llista[i];
    }
    return cadena;
}

template<class Key, class Value>
void BSTtree<Key,Value>::printPreorder(const NODEtree<Key,Value>* n) const{
    if(n == nullptr && this->root == nullptr){
        return;
    } else if(n==nullptr){
        printPreorder(this->root);
    } else {
        cout << valuesAString(n);
        if(n->getLeft()!=nullptr){
            printPreorder(n->getLeft());
        }
        if(n->getRight()!=nullptr){
            printPreorder(n->getRight());
        }
    }
}
template<class Key, class Value>
void BSTtree<Key,Value>::printInorder(const NODEtree<Key,Value>* n) const{
    if(n == nullptr && this->root == nullptr){
        return;
    } else if(n==nullptr){
        printInorder(this->root);
    } else {
        if(n->getLeft()!=nullptr){
            printInorder(n->getLeft());
        }
        cout << valuesAString(n);
        if(n->getRight()!=nullptr){
            printInorder(n->getRight());
        }
    }
}
template<class Key, class Value>
void BSTtree<Key,Value>::printPostorder(const NODEtree<Key,Value>* n) const{
    if(n == nullptr && this->root == nullptr){
        return;
    } else if(n==nullptr){
        printPostorder(this->root);
    } else {
        if(n->getLeft()!=nullptr){
            printPostorder(n->getLeft());
        }
        
        if(n->getRight()!=nullptr){
            printPostorder(n->getRight());
        }
        cout << valuesAString(n);
    }
}
template<class Key,class Value>
void BSTtree<Key,Value>::buscarElGros(const NODEtree<Key,Value>* node)const{
    if(node->getRight()==nullptr){
        cout << node->getFather()->getKey() << endl;
    } else {
        buscarElGros(node->getRight());
    }
}
template<class Key,class Value>
void BSTtree<Key,Value>::printSecondLargestKey() const{
    buscarElGros(this->root);
}

template <class Key,class Value>
void BSTtree<Key,Value>::mirallNode(NODEtree<Key,Value> * orig, NODEtree<Key,Value>* mirall){
    if (orig == nullptr){
        return;
    } else {
        NODEtree<Key,Value>* node = new NODEtree<Key,Value>(*orig);
        mirall = node;
        mirallNode(orig->getLeft(),mirall->getRight());
        mirallNode(orig->getRight(),mirall->getLeft());

    }

}

template <class Key,class Value>
void BSTtree<Key,Value>::mirrorTree(){
    BSTtree<Key,Value>* mirall = new BSTtree();

    mirallNode(this->root,mirall->root);
    BSTtree<Key,Value>* copia = this;
    NODEtree<Key,Value>* copiaRoot = mirall->getRoot();
    this->root = copiaRoot;
    delete copia;
}
template<class Key, class Value>
void BSTtree<Key,Value>::buscaFulles(NODEtree<Key,Value>*node,list<NODEtree<Key,Value>*> &llista) const{
    if(node == nullptr){
        return;
    } if(node->isExternal()){
        llista.push_back(node);
        return;
    } else {
        buscaFulles(node->getLeft(),llista);
        buscaFulles(node->getRight(),llista);
    }

}
template <class Key, class Value>
list<NODEtree<Key, Value>*> BSTtree<Key,Value>::getLeafNodes() const{
    list<NODEtree<Key,Value>*> llista;
    buscaFulles(this->root,llista);
    return llista;
}

#endif