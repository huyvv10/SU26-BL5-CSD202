#pragma once
#include <vector>
#include "Node.h"

// Hang doi luu tru con tro Node* (phu hop duyet BFS cay)
// Giu phong cach dat ten phuong thuc dang: isEmpty, clear, enqueue, dequeue, front
class Queue {
private:
    std::vector<Node*> a; // buffer vong
    int max;              // suc chua
    int first;            // vi tri phan tu dau
    int last;             // vi tri trong ke tiep (sau phan tu cuoi)
    int size_;            // so phan tu hien co

public:
    Queue();              // mac dinh capacity = 100
    explicit Queue(int m);

    bool isEmpty() const;
    bool isFull() const;
    void clear();

    // dua phan tu vao cuoi hang
    // tra ve true neu thanh cong, false neu day
    bool enqueue(Node* x);

    // lay va loai bo phan tu dau hang
    // tra ve nullptr neu rong
    Node* dequeue();

    // xem phan tu dau hang (khong loai bo)
    // tra ve nullptr neu rong
    Node* front() const;

    // kich thuoc hien tai
    int size() const { return size_; }

    // suc chua (capacity)
    int capacity() const { return max; }
};
