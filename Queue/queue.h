#pragma once 

class Queue 
{
private:
    int* queue;
    int size;
    int start;
    int end;
    int filled;

public:
    Queue();
    Queue(int cap);
    ~Queue();

    bool isEmpty() const;
    bool isFull() const;
    bool isAny() const;

    void addToQueue(int value);

    int removeFromQueue();
    int peek() const; 
    int checkSize() const;

    void display() const;
};


class PriorityQueue 
{
private: 
    struct Node 
    {
        int value;
        int priority;
        Node* next;
        Node* previous;
        Node(int val, int p, Node* nxt = nullptr, Node* prv = nullptr) 
            :value(val), priority(p), next(nxt), previous(prv) {}
    };

    Node* head;
    Node* tail; 

public:
    PriorityQueue();
    ~PriorityQueue();

    void fillQueue(int value, int priority);
    int removeItem();

    bool noItems() const;
    bool atLeastOne() const;

    int peekItem() const;
    void printOut() const;
};