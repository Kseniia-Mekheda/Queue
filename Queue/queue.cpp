#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    size = 5; 
    queue = new int[size];
    start = 0;
    end = -1;
    filled = 0;
}

Queue::Queue(int cap) 
{
    size = cap;
    queue = new int[size]; 
    start = 0;
    end = -1;
    filled = 0;
}

Queue::~Queue() 
{
    delete[] queue;
}

bool Queue::isEmpty() const
{
    return filled == 0;
}

bool Queue::isFull() const
{
    return filled == size;
}

bool Queue::isAny() const
{
    return filled >= 0;
}

void Queue::addToQueue(int value)
{
    if (isFull())
    {
        cout << "Your array for queue was full. Capacity increased;" << endl;
        size *= 2;
        int* newQueue = new int[size]; 

        for (int i = 0; i < size; ++i)
        {
            newQueue[i] = queue[i]; 
        }

        delete[] queue;
        queue = newQueue;
        start = 0;
        end = filled - 1;
    }

    end = (end + 1) % size;
    queue[end] = value;
    ++filled;
}

int Queue::removeFromQueue()
{
    if (isEmpty())
    {
        cout << "Your queue is empty" << endl;
        return -100;
    }

    int victim = queue[start];
    start = (start + 1) % size;
    --size;
    return victim;
}

int Queue::peek() const
{
    return queue[start];
}

void Queue::display() const 
{
    if (isEmpty())
    {
        cout << "Your queue is empty" << endl;
        return;
    }

    for (int i = 0; i < filled; ++i) {
        cout << queue[i] << ' ';
    }
    cout << endl;
}

int Queue::checkSize() const
{
    return size;
}


PriorityQueue::PriorityQueue() 
    : head(nullptr), 
      tail(nullptr) 
{}

PriorityQueue::~PriorityQueue()
{
    while (!noItems()) 
    {
        removeItem();
    }
}

void PriorityQueue::fillQueue(int value, int priority)
{
    Node* newNode = new Node(value, priority);
    if (noItems())
    {
        head = tail = newNode;
    }
    else
    {
        if (priority > head->priority) 
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr && current->next->priority >= priority)
            {
                current = current->next;
            }

            if (current == tail)
            {
                tail->next = newNode;
                newNode->previous = tail;
                tail = newNode;
            }
            else
            {
                newNode->next = current->next;
                newNode->previous = current;
                current->next->previous = newNode;
                current->next = newNode;
            }
        }
    }
}

int PriorityQueue::removeItem()
{
    if (noItems())
    {
        cout << "Your queue is empty" << endl;
        return -100;
    }

    int data;
    Node* temporary = head;

    if (head == tail) {
        data = head->value;
        delete head;
        head = tail = nullptr;
    }
    else 
    {
        data = head->value;
        head = head->next;
        head->previous = nullptr;
        delete temporary;
    }

    return data;
}

bool PriorityQueue::noItems() const
{
    return head == nullptr;
}

bool PriorityQueue::atLeastOne() const
{
    return head != nullptr;
}

void PriorityQueue::printOut() const
{
    if (noItems())
    {
        cout << "Your queue is empty" << endl;
        return;
    }

    Node* current = head; 
    while (current != nullptr)
    {
        cout << "Value: " << current->value << ". Priority: " << current->priority << ";  ";
        current = current->next;
    }

    cout << endl;
}

int PriorityQueue::peekItem() const
{
    return head->value;
}