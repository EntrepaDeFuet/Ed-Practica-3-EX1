#include <stdio.h>
#include "BSTtree.h"
using namespace std;

int main(){
    BSTtree<int, int> tree1;
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};

    for (int i = 0; i < 8 ; i++) {
        cout << "Inserta a l'arbre la key " << testKeys[i] << " amb valor " << testValues[i] << endl;
        tree1.insert(testKeys[i], testValues[i]);
        cout << tree1.valuesOf(testKeys[i])[0] << endl;
        
    }
    cout << "Preorder = [";
    tree1.printPreorder();
    cout << "]" << endl;
    cout << "Inorder = [";
    tree1.printInorder();
    cout << "]" << endl;
    cout << "Postorder = [";
    tree1.printPostorder();
    cout << "]" << endl;
    tree1.printSecondLargestKey();
    cout << "FULLES De l'arbre = ";
    list<NODEtree<int,int> *> fulles = tree1.getLeafNodes();
    cout << "{ " ;
    for(NODEtree<int, int>* n: fulles){
        cout << n->getKey() << " ";
    }
    cout << "}" << endl<< endl;
    BSTtree<int, int> tree2(tree1);
    tree1.mirrorTree();
    cout << "Inorder = [";
    tree1.printInorder();
    cout << "]" << endl;
    return 0;
}