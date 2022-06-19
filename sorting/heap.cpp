#include <bits/stdc++.h>
#define MAX_SIZE 1000;
using namespace std;

// FLAWED (MAX HEAP)

class Heap{
    private:
        int size;
        string mode;
        int data[1000];
        string MIN_HEAP = "min";
        string MAX_HEAP = "max";
    public:
        Heap(string _mode){
            memset(this->data, 0, sizeof(this->data));
            this->size = 0;
            this->mode = _mode;
        }
        void insert(int _value){  
            this->data[this->size] = _value;
            this->heapify(this->size);
            this->size++;
        }
        void swap(int *a, int *b){
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        void heapify(int _idx){
            if(_idx == 0){
                // if only one element, there is no need to heapify
                return;
            }
            int parent = -1;
            if(_idx % 2 == 0){
                parent = (_idx - 2)/2;
            } else if(_idx % 2 != 0) {
                parent = (_idx - 1)/2;
            }
            // handle min and max heap accordingly
            if(this->mode == MIN_HEAP){
                if(this->data[parent] > this->data[_idx]){
                    this->swap(&this->data[parent], &this->data[_idx]);
                }
            } else if(this->mode == MAX_HEAP){
                 if(this->data[parent] < this->data[_idx]){
                    this->swap(&this->data[parent], &this->data[_idx]);
                }
            }
            this->heapify(parent);
        }
        int extract(){
            // delete the min/max from the heap and re-heapify
            int topofHeap;
            topofHeap = this->data[0];
            this->swap(&this->data[0], &this->data[this->size-1]);
            this->size--;
            // reheapify
            heapify(this->size-1);

            return topofHeap;
        }
        void print(){
           for(int i=0; i<this->size; i++){
                cout << this->data[i] << " "; 
            }
            cout << endl;
        }
        int peek(){
            return this->data[this->size];
        }
};

int main() {
    // use the default parameterized constructor
    Heap h ("min");
    for(int i=6; i>=0; i--){
        h.insert(i);
    }
    h.print();
    cout << h.extract() << endl;
    h.print();

}