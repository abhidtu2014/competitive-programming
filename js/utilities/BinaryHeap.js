class BinaryHeap {
    constructor() {
        this.heap = [];
        this.size = 0;
    }
    getLeftChildIndex (parentIndex) {  return 2*parentIndex + 1;}
    getRightChildIndex (parentIndex) { return 2*parentIndex + 2;}
    getParentIndex (childIndex) { return (childIndex-1)/2; }
    hasLeftChild (parentIndex) { return this.getLeftChildIndex(parentIndex) < this.size; }
    hasRightChild (parentIndex) { return this.getRightChildIndex(parentIndex) < this.size; }
    hasParent (childIndex) { return this.getParentIndex(childIndex) < this.size; }
    leftChild (index) { return this.heap[this.getLeftChildIndex(index)]; }
    rightChild (index) { return this.heap[this.getRightChildIndex(index)]; }
    parent (index) { return this.heap[this.getParentIndex(index)]; }
    swap (index1, index2) { [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]]; }
    isEmpty () { return this.size === 0; }
    // Get top element of the heap
    peek () { return this.isEmpty() ? null: this.heap[0]; }
    // extracts the top element from the heap
    poll () {
        if (this.isEmpty()) { return null; }
        const topElement = this.peek();
        this.heap[0] = this.heap[this.size - 1];
        this.size--;
        this.__heapifyDown(0);
        return topElement;
    }

    insert (val) {
        this.heap[this.size] = val;
        this.size++;
        this.__heapifyUp();
    }

    buildHeap (arr) {
        this.heap = arr;
        this.size = arr.length;
        const startIndex = Math.floor((this.size - 1)/2);
        for (let i = startIndex; i >= 0; i--) {
            this.__heapifyDown(i);
        }
    }
    // Abstract methods, needs to be implemented in Extended classes (MinHeap/MaxHeap)
    __heapifyDown(index) {}
    __heapifyUp() {} 
}

class MinHeap extends Heap {
    constructor () {
        super();
    }

    __heapifyDown(index) {
        while (this.hasLeftChild(index)) {
            let smallestChildIndex = this.getLeftChildIndex(index);
            if (this.hasRightChild(index) && this.getRightChild(index) < this.getRightChild(index)) {
                smallestChildIndex = this.getRightChildIndex(index);
            }

            if (this.heap[index] < this.heap[smallestChildIndex]) {
                break;
            } else {
                this.swap(index, smallestChildIndex);
            }
            index = smallestChildIndex;
        }
    }

    __heapifyUp () {
        let index = this.size - 1;
        while (this.hasParent(index) && this.parent(index) > this.heap[index]) {
            this.swap(index, this.getParentIndex(index));
            index = this.getParentIndex(index);
        }
    }
}