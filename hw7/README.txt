HOMEWORK 7: SUPER SMASH BROS. FRAMES


NAME:  < ziyu zhu >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.
https://zh.cppreference.com/w/cpp/header/set
https://blog.csdn.net/zy20150613/article/details/78693579


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 6 >



ORDER NOTATION ANALYSIS:
Consider the following variables and give the complexity for both running
time AND space along with a short justification for each of the queries below.
For the commands, do not count the space occupied by the database in the space
complexity analysis.

f: The total number of fighters
m: The number of different moves
t: The highest number of moves that have the same starting frame
*n: The number of fighters need to find



reading the database/populating your initial data structure:
Complexity: O(f*m) Space: f*m
I did not create other sets or maps in query so all the space in operation
is f. The space of the map is always the number of the fighters * moves.

-q (specific move):
Complexity: O(log(f))  Space: f*m
search for specific fighter is log(f), specific move is O(1).

-q (all):
Complexity: O(m*log(f)) Space: f*m
search for specific fighter is log(f), all moves is m.

-f:
Complexity: O(n*f) Space: f*m
For worst case, I need to go through the map for n times, so it is n*f.

-s:
Complexity: O(n*f) Space: f*m
For worst case, I need to go through the map for n times, so it is n*f.

-d:
Complexity: O(f) Space: f*m
Go though the map to check the frame so it is f.

MISC. COMMENTS TO GRADER:  
(optional, please be concise!)






