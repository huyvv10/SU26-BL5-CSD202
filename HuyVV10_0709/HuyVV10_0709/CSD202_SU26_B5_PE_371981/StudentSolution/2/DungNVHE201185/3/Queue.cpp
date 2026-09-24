#include "Queue.h"

Queue::Queue()
    : a(100, nullptr), max(100), first(0), last(0), size_(0) {}

Queue::Queue(int m)
    : a(m > 0 ? m : 1, nullptr),
      max(m > 0 ? m : 1),
      first(0), last(0), size_(0) {}

bool Queue::isEmpty() const {
    return size_ == 0;
}

bool Queue::isFull() const {
    return size_ == max;
}

void Queue::clear() {
    // khong can xoa Node*, chi reset trang thai hang doi
    first = 0;
    last  = 0;
    size_ = 0;
}

bool Queue::enqueue(Node* x) {
    if (isFull()) return false;
    a[last] = x;
    last = (last + 1) % max;
    ++size_;
    return true;
}

Node* Queue::dequeue() {
    if (isEmpty()) return nullptr;
    Node* res = a[first];
    a[first] = nullptr; // tuy chon, giup tranh treo con tro cu
    first = (first + 1) % max;
    --size_;
    return res;
}

Node* Queue::front() const {
    if (isEmpty()) return nullptr;
    return a[first];
}
