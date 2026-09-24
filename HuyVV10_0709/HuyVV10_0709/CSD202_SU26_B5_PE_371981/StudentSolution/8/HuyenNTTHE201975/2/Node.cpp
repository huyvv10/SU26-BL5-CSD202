#include "Node.h"

Node::Node()
    : info(), next(nullptr) {
}

Node::Node(const Student& x, Node* p)
    : info(x), next(p) {
}

Node::Node(const Student& x)
    : Node(x, nullptr) {
}
