#include <iostream>
#include <vector>
#include <cmath>


void myswap(int heap [], int i, int j){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;

}


bool checkIsHeap(int heap [], int heapSize){
    int largest = heap[0];
    for(int i = 0; i < heapSize; i++){
        int leftChildIndex = (2 * i) + 1;
        int rightChildIndex  = (2 * i) + 2;
        bool hasChildLeft = !(leftChildIndex >= heapSize);
        bool hasChildRight = !(rightChildIndex >= heapSize);
    

   //     std::cout << "Current:" << heap[i] << " Left: " << heap[leftChildIndex] << " Right: " << heap[rightChildIndex] << std::endl;
        if(((heap[i] > largest && i !=0)) || hasChildLeft && heap[i] < heap[leftChildIndex] || hasChildRight && heap[i] < heap[rightChildIndex] ){
             std::cout << "Not a heap" << std::endl;
                return false;
        }
    }
    return true;

}
// MAX HEAP
void heapify(int heap [], int lastHeapIndex){
    for(int i = 0; i <= lastHeapIndex; i++){
        int parentIndex = std::floor(((i - 1) / 2));
        int tempIndex = i;

        while(heap[tempIndex] > heap[parentIndex]){
            myswap(heap, tempIndex, parentIndex);
            tempIndex = parentIndex;
            parentIndex = std::floor((tempIndex - 1) / 2);
        }

    }

}

void myheapsort(int heap [], int lastHeapIndex){
    heapify(heap,lastHeapIndex);
    for(int i = 0; i < 8; i++){
        std::cout << heap[i] << " ";
    }
    while(lastHeapIndex > 0){
        myswap(heap, 0, lastHeapIndex);
        lastHeapIndex -= 1;
        std::cout << "Last Heap Index: " << lastHeapIndex << std::endl;
        heapify(heap,lastHeapIndex);
        for(int i = 0; i < 8; i++){
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }


}


