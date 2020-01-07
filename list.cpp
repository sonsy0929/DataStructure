#include <cstdio>
using namespace std;
const int MAXIN = 100'001;
const int MAXLIST = 600'001;
struct Node {
    char c;
    Node *next, *prev;
    Node() : c(0), prev(0), next(0) {}
};

struct List {
    Node *head, *tail;
    Node nodeList[MAXLIST];
    int size, allocIDX;
    List() : head(&nodeList[allocIDX++]), tail(&nodeList[allocIDX++]){
        tail->prev = head;
        head->next = tail;
    }
    void push_back(char c){
        Node* node = &nodeList[allocIDX++];
        node->c = c;
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }
    void pop_back(){
        if (tail->prev == head) return;
        Node* dNode = tail->prev;
        dNode->prev->next = dNode->next;
        dNode->next->prev = dNode->prev;
    }
    void insert(int n, char c){
        Node* newNode = &nodeList[allocIDX++];
        Node* node = head;
        for (int i = 0; i < n; i++) node = node->next;
        newNode->c = c;
        newNode->prev = node;
        newNode->next = node->next;

        node->next->prev = newNode;
        node->next = newNode;
    }
    void erase(int n){
        Node* node = head;
        for (int i = 0; i < n; i++) node = node->next;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

