#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

using namespace std;

struct TNode {
    int data;
    TNode* next;
    TNode* prev;
};

typedef TNode* head;

void insertDepan(head& L, int databaru);
void insertBelakang(head& L, int databaru);
void hapusDepan(head& L);
void hapusBelakang(head& L);
void clear(head& L);
void tampil(head& L);
void tampilBelakang(head& L);
int hitungNode(head& L);
void printHeader(const string& title);

