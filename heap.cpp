#include <iostream>
using namespace std;

class heap {

    public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int value) {

        // increment size
        size++;

        // initiate index to last position
        int idx = size;

        // put value at last index
        arr[idx] = value;

        // loop
        while (idx > 1) {

            int parent = idx / 2;

            // compare with parent
            if (arr[idx] > arr[parent]) {
                swap(arr[idx], arr[parent]);
                // update index
                idx = parent;
            }
            else {
                return;
            }

        }

    }

    void printHeap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        } cout << endl;
    }

    void deleteHeap() {

        if (size == 0) {
            cout << "nothing to delete" << endl;
            return;
        }

        swap(arr[1], arr[size]);
        size--;

        int index = 1;
        int leftchild = 2*index;
        int rightchild = 2*index + 1;

        while (index < size) {

            if (leftchild < size && arr[index] < arr[leftchild]) {
                swap(arr[index], arr[leftchild]);
                index = leftchild;
            }
            else if (rightchild < size && arr[index] < arr[rightchild]) {
                swap(arr[index], arr[rightchild]);
                index = rightchild;
            }
            else {
                return;
            }

        }

    }

};


void heapify(int arr[], int size, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);

        heapify(arr, size, largest);
    }

}

void heapsort(int arr[], int n) {

    int size = n;
    while(size > 1) {

        swap(arr[size], arr[1]);

        size--;

        heapify(arr, size, 1);

    }

}

int main() {

    // heap h;
    // h.insert(51);
    // h.insert(53);
    // h.insert(54);
    // h.insert(52);
    // h.insert(51);

    // h.printHeap();

    // h.deleteHeap();

    // h.printHeap();

    int array[6] = {-1, 54, 53, 55, 52, 51};
    int n = 5;
    // for (int i = n/2; i > 0; i--) {
    //     heapify(array, n, i);
    // }
    heapsort(array, 6);
    for (int i = 1; i < n; i++) {
        cout << array[i] << " ";
    } cout << endl;
}
