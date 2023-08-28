// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

// Example 1:

// Input
// ["MyStack", "push", "push", "top", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 2, 2, false]

// Explanation
// MyStack myStack = new MyStack();
// myStack.push(1);
// myStack.push(2);
// myStack.top(); // return 2
// myStack.pop(); // return 2
// myStack.empty(); // return False
 

// Constraints:

// 1 <= x <= 9
// At most 100 calls will be made to push, pop, top, and empty.
// All the calls to pop and top are valid.

/*
Approach:
    This question needs to implement a stack-like data structure using some queues. You should know a crucial property of a stack: FILO(first in, last out).
So, we can use two queues to simulate this process.
*/

#include <queue>

using namespace std;

class MyStack 
{
public:
    MyStack() 
    {

    }
    
    void push(int x) 
    {
        mainQueue.push(x);
        return;
    }
    
    int pop() 
    {
        if (0 == mainQueue.size())
        {
            return -1;
        }
        // Transform the value from the main queue to the auxiliary queue.
        while (mainQueue.size() > 1)
        {
            auxQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        // first step: pop the top element;
        // second step: swap two queues
        auto curTop = mainQueue.front();
        mainQueue.pop();
        mainQueue.swap(auxQueue);
        return curTop;
    }
    
    int top() 
    {
        return mainQueue.back();
    }
    
    bool empty() 
    {
        return mainQueue.empty();
    }

private:
    // The main queue, when push or pop values, use this queue.
    queue<int> mainQueue;
    
    queue<int> auxQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
