#include <cstdio>
using namespace std;
const int SIZE = 100'0001;
template <typename T>
void swap(T &u, T &v){
    T tmp = u;
    u = v;
    v = tmp;
}
template <typename T>
struct Heap{
    static const int TOP = 1;
    int size;
    T heap[SIZE];
    Heap() : size(0) {}
    bool empty(){
        return !size;
    }
    T top(){
        return heap[TOP];
    }
    void push(T n){
        heap[++size] = n;
        int i = size;
        while (i/2){
            if (heap[i/2] < heap[i]) swap(heap[i/2], heap[i]);
            i/=2;
        }
    }
    void pop(){
        if (!size) return;
        heap[TOP] = heap[size--];
        int i = TOP;
        while (1){
            int left, right, child;
            left = (i*2 <= size ? i*2 : -1);
            right = (i*2+1 <= size ? i*2+1 : -1);
            
            if (left == -1 && right == -1) break;
            else if (right == -1) child = left;
            else child = heap[left] > heap[right] ? left : right;

            if (heap[child] > heap[i]) swap(heap[child], heap[i]);
            i = child;
        }
    }
};