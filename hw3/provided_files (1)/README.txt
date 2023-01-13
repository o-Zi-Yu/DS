HOMEWORK 3: CONNECT FOUR


NAME:  < ziyu zhu >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >
https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019
http://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/
https://blog.csdn.net/FX677588/article/details/69592329
https://www.geeksforgeeks.org/iterators-c-stl/
https://en.cppreference.com/w/cpp/language/for
https://blog.csdn.net/ungoneless/article/details/51276849
https://blog.csdn.net/xujing19920814/article/details/54882396
https://stackoverflow.com/questions/30720594/deleting-a-dynamically-allocated-2d-array
https://stackoverflow.com/questions/16541597/identifier-ostream-is-undefined-error
https://blog.csdn.net/hengbao4/article/details/53224107
https://docs.microsoft.com/en-us/cpp/cpp/destructors-cpp?view=vs-2019
https://www.geeksforgeeks.org/destructors-c
/http://www.cplusplus.com/forum/beginner/51161/
Zhenming
Zixiang
Guanghan
Eric 
Spencer



Remember: Your implementation for this assignment must be done on your
own, as described in the "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 30 >



ORDER NOTATION:
For each of the functions below, write the order notation O().
Write each answer in terms of m = the number of rows and n = the
number of columns.  You should assume that calling new [] or delete []
on an array will take time proportional to the number of elements in
the array.

insert (excluding checking for connected four)
O(n^2)

insert (including checking for connected four)
O(n)

numTokensInColum
O(1)

numTokensInRow
O(n)

numColumns
O(1)

numRows
O(1)

print
O(n*m || n^2)
in line 208 is n^2, other for loops are n*m
because it depends on the size of n and m, so I write ||

clear
O(n^2)

TESTING & DEBUGGING STRATEGY: 
Discuss your strategy for testing & debugging your program.  
What tools did you use (gdb/lldb/Visual Studio debugger,
Valgrind/Dr. Memory, std::cout & print, etc.)?  How did you test the
"corner cases" of your Matrix class design & implementation?


gdb with cmd as run, bt, f num and print
drmemory to check all leaks. -g is a good cmd to find the exact function line.
mostly use gdb to fix the error of array size.
In student cases, I tried many corner cases with operators, 
gdb is good for testing, because it can show what line has the errors.


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

