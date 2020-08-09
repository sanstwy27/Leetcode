//============================================================================
// Name        : Leetcode.622. Design Circular Queue
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description :
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : head(0), tail(0) {
    	myQueue_ = vector<int>(k + 1, 0);
    	lenQ = myQueue_.size();
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
    	if(isFull())
    		return false;

    	myQueue_[head] = value;
    	head = (head + 1) % lenQ;
    	return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
    	if(isEmpty())
    		return false;

		tail = (tail + 1) % lenQ;
		return true;
    }

    /** Get the front item from the queue. */
    int Front() {
    	if(isEmpty())
    		return -1;

    	return myQueue_[tail];
    }

    /** Get the last item from the queue. */
    int Rear() {
    	if(isEmpty())
    		return -1;

    	int i = (head - 1) < 0 ? (head - 1 + lenQ) : head - 1;
    	return myQueue_[i];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
    	return (head == tail);
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
    	return ((head + 1) % lenQ == tail);
    }

private:
    vector<int> myQueue_;
    int head = 0, tail = 0, lenQ;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
	// Test Case
//	MyCircularQueue circularQueue(3); // set the size to be 3
//	cout << circularQueue.enQueue(1) << endl;  // return true
//	cout << circularQueue.enQueue(2) << endl;  // return true
//	cout << circularQueue.enQueue(3) << endl;  // return true
//	cout << circularQueue.enQueue(4) << endl;  // return false, the queue is full
//	cout << circularQueue.Rear() << endl;  // return 3
//	cout << circularQueue.isFull() << endl;  // return true
//	cout << circularQueue.deQueue() << endl;  // return true
//	cout << circularQueue.enQueue(4) << endl;  // return true
//	cout << circularQueue.Rear() << endl;  // return 4

	MyCircularQueue circularQueue(4); // set the size to be 3
	cout << circularQueue.enQueue(3) << endl;
	cout << circularQueue.Front() << endl;
	cout << circularQueue.isFull() << endl;
	cout << circularQueue.enQueue(7) << endl;
	cout << circularQueue.enQueue(2) << endl;
	cout << circularQueue.enQueue(5) << endl;
	cout << circularQueue.deQueue() << endl;
	cout << circularQueue.enQueue(4) << endl;
	cout << circularQueue.enQueue(2) << endl;
	cout << circularQueue.isEmpty() << endl;
	cout << circularQueue.Rear() << endl;

	return 0;
}


