#include <cstdio>
using namespace std;
const int STRINGSIZE = 10'000;
const int NODESIZE = 10'000;
const int HASHSIZE = 100'019;
void _strcpy(char* dst, const char* src){
    int i = 0;
    for (; src[i]; i++) dst[i] = src[i];
    dst[i] = src[i];
}
bool _strcmp(const char* u, const char* v){
    for (int i = 0; ; i++){
        if (!u[i] && !v[i]) return true;
        if (u[i] != v[i]) return false;
    }
}
struct Node{
    char key[STRINGSIZE];
    int value;
    Node* next;
};
struct Hash{
    Node hash[HASHSIZE];
    Node nodeList[NODESIZE];
    int allocIDX;
    Hash(){
        allocIDX = 0;
    }
    unsigned long getHashVal(const char* key){
        unsigned long value = 5381;
        int c;
        while (c = *key++) value = (((value << 5) + value) + c) % HASHSIZE;
        return value % HASHSIZE;
    }
    void insert(char* key, int value){
        int hashValue = getHashVal(key);
        Node* newNode = &nodeList[allocIDX++];
        _strcpy(newNode->key, key);
        newNode->value = value;
        newNode->next = hash[hashValue].next;
        hash[hashValue].next = newNode;
    }
    int operator[](const char* key){
        return getValue(key);
    }
    int getValue(const char* key){
        int hashValue = getHashVal(key);
        Node* curr = hash[hashValue].next;
        while (curr != nullptr && !_strcmp(curr->key, key)) curr = curr->next;
        if (!curr) return -1;
        return curr->value;
    }
};