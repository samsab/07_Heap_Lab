07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. 'add', when using 'grow', is O(n) as it must take time to grow the heap. Otherwise, 'add' and 'remove' are O(log n) as they only have to iterate through one branch of the tree all the way down to find/add an element.
2. All memory is taken care of and none is leaked.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
Exercise 10.1: Illustrate the addition of the values 7 and then 3 to the BinaryHeap shown at the end of Figure 10.2.
7 starts at the left node of the '16' node. 16 is larger, so '7' and '16' swap. 7 is greater than 6, so it rests with '7' at index 6 and 16 at index 13.
Now our heap reads: [4, 9, 6, 17, 26, 8, 7, 19, 69, 32, 93, 55, 50, 16]
			  4
	   9			  6
  17	  26	  8		  7
19	69	32	93	55	50	16

3 starts at the right node of the new '7' node. 3 is smaller, so it traverses upward, switching with '7', then '6', then '4', finally resting at the root node.
Now our heap reads: [3, 9, 4, 17, 26, 8, 6, 19, 69, 32, 93, 55, 50, 16, 7]
			  4
	   9			  6
  17	  26	  8		  7
19	69	32	93	55	50	16

Exercise 10.2: Illustrate the removal of the next two values (6 and 8) on the BinaryHeap shown at the end of Figure 10.3.
First, we replace '6' with '55'. Then, we trickle down the heap, swapping any mismatched values ('55' and '8', '55' and '16').
Now our heap reads: [8, 9, 16, 17, 26, 50, 55, 19, 69, 32, 93]
			  8
	   9			  16
  17	  26	  50	  55
19	69	32	93

First, we replace '8' with '93'. Then, we trickle down the heap, swapping any mismatched values ('93' and '9', '17', '19')
Now our heap reads: [9, 17, 16, 19, 26, 50, 55, 93, 69, 32]
			  9
	   17			  16
  19	  26	  50	  55
93	69	32

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
Exercise 10.4: A d-ary tree is a generalization of a binary tree in which each internal node has d children. Using Eytzinger's method it is also possible to represent complete d-ary trees using arrays. Work out the equations that, given an index i, determine the index of i's parent and each of i's d children in this representation.


#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
10.4 was difficult. The concepts were foreign and caused confusion.