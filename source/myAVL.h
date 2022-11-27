#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//AVL struct instance;
typedef struct node{

    int key;
    int data;
    int depth;
    node *father;
    node *L_son;
    node *R_son;
    
}node;


//AVL's functions and procedures;
node *createAVL(int key, int data);
node *insert(node *n, int key, int data);
node *rootInsert(node *n, int key, int data);
node *delete(int key);
node *L_rotate(node *n);
node *R_rotate(node *n);
node *successor(int key);
node *predecessor(int key);
node *binarySearch(node *n, int key);