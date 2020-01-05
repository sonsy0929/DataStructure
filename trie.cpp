#include <cstdio>
#include <cstring>
using namespace std;
const int nodeSize = 26;
int toNumber(char c) { return c - 'A';}
struct trieNode {
    trieNode *children[nodeSize];
    bool terminal;
    trieNode() : terminal(false){
        memset(children, 0, sizeof(children));
    }
    ~trieNode() {
        for (int i = 0; i < nodeSize; i++) {
            if (children[i]) delete children[i];
        }
    }
    void insert(const char *key){
        if (*key == 0) terminal = true;
        else {
            int next = toNumber(*key);
            if (children[next] == nullptr) children[next] = new trieNode();
            children[next]->insert(key + 1);
        }
    }
    trieNode* find(const char *key){
        if (*key == 0) return this;
        int next = toNumber(*key);
        if (children[next] == nullptr) return nullptr;
        return children[next]->find(key + 1);
    }
};