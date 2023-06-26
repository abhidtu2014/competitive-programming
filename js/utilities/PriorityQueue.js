const top = 0;
const parent = i => (i - 1) >> 1;
const left = i => (i << 1) + 1;
const right = i => (i << 1) + 2;

class MyPriorityQueue {
  constructor(comparator = (a, b) => a < b) {
    this._comparator = comparator;
    this._heap = [];
  }
  size() {
    return this._heap.length;
  }
  isEmpty() {
    return this.size() == 0;
  }
  peek() {
    return this._heap[top];
  }
  push(...values) {
    values.forEach(val => {
      this._heap.push(val);
      this._heapifyUp();
    });
    return this.size();
  }
  pop() {
    const toRemove = this.peek();
    const bottom = this.size() - 1;
    this._swap(top, bottom);
    this._heap.pop();
    this._heapifyDown();
    return toRemove;
  }
  replace(value) {
    const replacedValue = this.peek();
    this._heap[top] = value;
    this._heapifyDown();
    return replacedValue;
  }
  _compare(i, j) {
    return this._comparator(this._heap[i], this._heap[j]);
  }
  _swap(i, j) {
    [this._heap[i], this._heap[j]] = [this._heap[j], this._heap[i]];
  }
  _heapifyUp() {
    let index = this.size() - 1;
    while (index > top && this._compare(parent(index), index) > 0) {
      this._swap(index, parent(index));
      index = parent(index);
    }
  }
  _heapifyDown() {
    let index = top;
    while (
      (left(index) < this.size() && this._compare(index, left(index)) > 0) ||
      (right(index) < this.size() && this._compare(index, right(index)) > 0)
    ) {
      const swapIndex =
        right(index) < this.size() && this._compare(left(index), right(index)) > 0
          ? right(index)
          : left(index);
      this._swap(index, swapIndex);
      index = swapIndex;
    }
  }
}