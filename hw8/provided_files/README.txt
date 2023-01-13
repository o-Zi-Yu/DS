HOMEWORK 8: ROPES


NAME:  < ziyu zhu >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.
https://stackoverflow.com/questions/49582390/binary-search-tree-copy-constructor-in-c
https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter14_023.html
https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
http://www.cplusplus.com/forum/beginner/136516/
https://stackoverflow.com/questions/49835157/c-copy-constructor-for-binary-tree-with-parent-nodes
https://codereview.stackexchange.com/questions/91132/a-binary-tree-its-copy-constructor-and-assignment-operator
http://www.cplusplus.com/forum/windows/59865/
https://blog.csdn.net/qq_34761108/article/details/52973436
https://blog.csdn.net/zxnsirius/article/details/52131984
https://www.jianshu.com/p/9fafb0205cd2
https://www.cnblogs.com/dishengAndziyu/p/10925465.html
https://blog.csdn.net/bohu83/article/details/79964660
david zhang lee
submitty

ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 25 >

BALANCED/WORST CASE RUNNIG TIME ANALYSIS:
n = characters in the string of the current Rope (*this)
m = characters in the string of the Rope passed in (for functions that take
    a second rope)
v = longest "value" of a leaf
p = longest path from root to a leaf
Using these variables, state and explain the big-O running time of each 
of the following operations two ways: 1) with a balanced Rope, 2) with an 
extremely unbalanced Rope. Explain what you considered an extremely 
unbalanced rope for the string "Hello my name is Simon".

extremely: all nodes are in the left, just like a stright line,
right nodes holes values, with one character in each, left nodes are connection

Copy Constructor:
balance: O(nlog(n)) //log(n) is the path of the node and there are n nodes
extremely: O(p) //goes through all the path to bottom

Construct from Node*:
both: O(1) //initialization is 1

Index:
balance: O(log(n)) //log(n) is the path of the node, it is a binary tree
extremely: O(p) //goes through all the path to bottom

Report:
balance: O(log(n) + v) //log(n) is the path of the node, v is the length it need to get
extremely: O(p + v) //goes through all the path to bottom, v is the length it need to get

iterator operator++:
balance: O(log(n)) //log(n) is the path of the node, it goes from bottom to top then to bottom
extremely: O(p)    //if it has the only node in left and others are in right it has to go through
		     all the way to right

Split:
balance: O(p+log(n)) //find the node is log(n), split the node is p, 
			because the right node can have p in length
extremely: O(p) //find and split the node is both p

Concat:
balance: O(nlog(n)+p) //copy the node is nlog(n), and adjust weight is p
extremely: O(p)	//both copy and adjust is p

TESTING & DEBUGGING STRATEGY: 
Briefly describe the tests in your StudentTests() function.
How did you test the "corner cases" of your implementation?

I tested edge cases of index and split out of range. Also test for the split the node to two.


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

