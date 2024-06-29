#pragma once
#include <iostream>

template <class type>
struct Node {
    int n = 0;
    type value;
    Node<type>* prevNode = nullptr;
    Node<type>* nextNode = nullptr;
    //Node<type>* pointers = nullptr;
};

template <class type>
class Graph {
    /*Instance variable to track how many nodes are within a degenerated
    * binary tree.
    */
    int n = 0;

    /*Instance variables that point to the beginningand end of a degenerated
    * binary tree.
    */
    Node<type>* first = nullptr;
    Node<type>* root = nullptr;
    Node<type>* last = nullptr;

public:

    //Graph() {}

    /*Pushes a node onto a link / chain without regard for order.Instantiates a
    * new structure if necessary.
    */
    void push(type value) {
        Node<type>* newNode = new Node<type>;
        newNode->value = value;
        if (!first)
            last = first = newNode;
        else if (last) {
            newNode->prevNode = last;
            last = last->nextNode = newNode;
        }
        else {
            Node<type>* ptr = first;
            while (ptr->nextNode)
                ptr = ptr->nextNode;
            ptr->nextNode = newNode;
            newNode->prevNode = ptr;
            last = newNode;
        }
        n++;
    }

    //Inserts a node into a link/chain in ascending order.
    void insert(type value) {
        if (first) {
            Node<type>* newNode = new Node<type>;
            newNode->value = value;
            if (newNode->value < first->value) {
                first->prevNode = newNode;
                newNode->nextNode = first;
                first = first->prevNode;
            }
            else {

                Node<type>* ptr = first;
                /*Knowing that there's at least one node, this block loops through
                * the chain until ptr points to the last node in the tree or ptr
                * points to a node with a value greater than than node being inserted
                */
                while (ptr->nextNode && ptr->value <= newNode->value)
                    ptr = ptr->nextNode;

                /*It will either insert when ptr points to the last nodeand to a node
                * that stores a greater value or when it points to a node storing a
                * greater value deeper within the structure
                */
                if (ptr->nextNode || newNode->value < ptr->value) {
                    newNode->prevNode = ptr->prevNode;
                    ptr->prevNode->nextNode = newNode;
                    newNode->nextNode = ptr;
                    ptr->prevNode = newNode;
                } //Append a node to the end of the structure
                else {
                    last->nextNode = newNode;
                    newNode->prevNode = last;
                    last = newNode;
                }
            }
            n++;
        }
        else {
            push(value);
        }
    }

    //Appends a node to the end of a linked list.
    void emplace(type value) {
        Node<type>* newNode = new Node<type>;
        newNode->value = value;
        last = last->nextNode = newNode;
        n++;
    }

    //Removes a node from the front of a queue, or in FIFO fashion.
    type dequeue() {
        Node<type>* ptr = first;
        first = ptr->nextNode;
        type value = ptr->value;
        delete ptr;
        n--;
        return value;
    }

    //Removes a node from the end/top of a stack. 
    type pop() {
        Node<type>* ptr = last;
        last = ptr->prevNode;
        type value = ptr->value;
        delete ptr;
        n--;
        ptr = nullptr;
        return value;
    }

    //Swaps the values of two degenerated binary trees.
    void swap(Graph<type>& list) {
        type temp;
        Node<type>* ptr0 = first, * ptr1 = list->top();
        while (ptr0->prevNode && ptr1->prevNode) {
            temp = ptr0->value;
            ptr0->value = ptr1->value;
            ptr1->value = temp;
            ptr0 = ptr0->prevNode;
            ptr1 = ptr1->prevtNode;
        }
    }

    //Swaps two items within a list
    void swap(Node<type>* ptr, Node<type>* ptr1) {
        type value = ptr->value;
        ptr->value = ptr1->value;
        ptr1->value = value;
    }

    //Returns the maximum within a given range
    Node<type>* max(Node<type>* start) const {
        int max = INT_MIN;
        Node<type>* ptr = nullptr, * trv = start;
        while (trv) {
            if (max < trv->value) {
                max = trv->value;
                ptr = trv;
            }
            trv = trv->nextNode;
        }
        return ptr;
    }

    //Returns the minimum within a given range
    Node<type>* min(Node<type>* start) const {
        int min = INT_MAX;
        Node<type>* ptr = nullptr, * trv = start;
        while (trv) {
            if (trv->value < min) {
                min = trv->value;
                ptr = trv;
            }
            trv = trv->nextNode;
        }
        return ptr;
    }

    //Selection sort
    void selSort(bool findMin = true) {
        Node<type>* ptr = first;
        while (ptr) {
            if (findMin)
                swap(ptr, min(ptr));
            else
                swap(ptr, max(ptr));
            ptr = ptr->nextNode;
        }
    }

    void print(Node<type>* ptr) {
        while (ptr)
        {
            std::cout << ptr->value;
            ptr = ptr->nextNode;
        }
    }

    //Divide
    Node<type>** divide(Node<type>* list)
    {
    }


    // Merge
    Node<type>* merge(Node<type>* list0, Node<type>* list1)
    {
    }


    //Merge sort
    Node<type>* mergeSort(Node<type>* list)
    {
    }


    //Returns a pointer to the last node within a degenerated tree.
    Node<type>* top() {
        return last;
    }

    //Returns a boolean indicating if the tree is empty.
    bool empty() {
        return (last) ? false : true;
    }

    // Returns a pointer to the root of the tree
    Node<type>* getRoot() {
        return root;
    }

    //Returns a pointer to the first node within a tree.
    Node<type>* begin() {
        return first;
    }

    //Reurns a nullptr
    Node<type>* end() {
        return last->nextNode;
    }

    //Returns the last value within a degenerated tree.
    type back() {
        return last->value;
    }

    //Returns the current size of (or nodes within) the data structure.
    int size() {
        return n;
    }
    ~Graph() {}
};
