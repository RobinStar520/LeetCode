// Design an iterator that supports the peek operation on an existing iterator in addition to the hasNext and the next operations.

// Implement the PeekingIterator class:

// PeekingIterator(Iterator<int> nums) Initializes the object with the given integer iterator iterator.
// int next() Returns the next element in the array and moves the pointer to the next element.
// boolean hasNext() Returns true if there are still elements in the array.
// int peek() Returns the next element in the array without moving the pointer.
// Note: Each language may have a different implementation of the constructor and Iterator, but they all support the int next() and boolean hasNext() functions.

 

// Example 1:

// Input
// ["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
// [[[1, 2, 3]], [], [], [], [], []]
// Output
// [null, 1, 2, 2, 3, false]

// Explanation
// PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
// peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
// peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
// peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
// peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
// peekingIterator.hasNext(); // return False
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// All the calls to next and peek are valid.
// At most 1000 calls will be made to next, hasNext, and peek.
 

// Follow up: How would you extend your design to be generic and work with all types, not just integer?

/*
Approach:
    For this question, we need to use the API provided by the question, and can't copy the sequence and manipulate it directly. So we need to save the next value
to get it in O(1) time. The API "Iterator::next()" can help us achieve the goal. In addition, set a class member denoting whether we can access the following
value.
*/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator 
{
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		this->has_next = Iterator::hasNext();
		if (this->has_next)
		{
			this->nextVal = Iterator::next();
		}
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() 
    {
        return this->nextVal;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
    {
        // Be aware of the order: We must judge whether we can accsee the next element first.
        // Otherwise, if the iterator points to the last element, the "has_next" doesn't update in time, the iterator probably moves out of range.
		int temp = this->nextVal;
		this->has_next = Iterator::hasNext();
	    if (this->has_next)
		{
			nextVal = Iterator::next();
		}
		
		return temp;
	}
	
	bool hasNext() const 
	{
	    return this->has_next;
	}

private:
	int nextVal;

	bool has_next;
	
};