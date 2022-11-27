#include "source/myAVL.h"


//createAVL is called only when there's no AVL available, so it returns a pointer to an new AVL;
node *createAVL(int key, int data){
    node *root = malloc(sizeof(node));

    root->father=NULL; //by definition, a root node have no father;
    root->data=data;
    root->depth=1;
    root->L_son=NULL;
    root->R_son=NULL;
    root->key=key;

    return root;
} 
//----------------------------------------------------------------
node *insert(node *n, int key, int data){//inserts a new node in the AVL.

    if(n==NULL)
        return createAVL(key, data);
    if(key < n->key){
        n->L_son = insert(n->L_son, key, data);
        n->R_son->father=n;
    }
    return n;
}
//----------------------------------------------------------------
node *rootInsert(node *n, int key, int data){
    if(n==NULL)
        return createAVL(key, data);
    if(key< n->key){
        n->L_son = rootInsert(n->L_son, key, data);
        n->L_son->father=n;
        n=R_rotate(n);
    }else{
        n->R_son = rootInsert(n->R_son, key, data);
        n->R_son->father = n;
        n = L_rotate(n);
    }
    return n;
}
//----------------------------------------------------------------
node *binarySearch(node *n, int key){
    if(n==NULL)
        return NULL;
    if(n->key==key)
        return n;
    if(key<n->key)
        return binarySearch(n->L_son, key);
    return binarySearch(n->R_son, key);
}
//----------------------------------------------------------------
node *delete(int key){

}
//----------------------------------------------------------------
node *L_rotate(node *n){
    node *aux = n->R_son;
    n->R_son=aux->L_son;
    aux->father=n->father;
    n->father=aux;
    if(aux->L_son!=NULL)
        aux->L_son->father=n;
    aux->L_son=n;
    return aux;
}
//----------------------------------------------------------------
node *R_rotate(node *n){
    node *aux = n->L_son;
    n->L_son=aux->R_son;
    aux->father=n->father;
    n->father=aux;
    if(aux->R_son!=NULL)
        aux->R_son->father=n;
    aux->R_son=n;
    return aux;
}
//----------------------------------------------------------------
node *successor(int key){

}
//----------------------------------------------------------------
node *predecessor(int key){

}