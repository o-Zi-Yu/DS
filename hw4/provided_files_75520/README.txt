HOMEWORK 4: DEBUGGING & GROCERY LISTS

NAME:  < ziyu zhu >


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT PART 1:  < 30 >
ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT PART 2:  < 25 >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(TAs, ALAC tutors, upperclassmen, students/instructor via LMS,
etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >
https://thispointer.com/c-how-to-copy-clone-a-stl-list-or-sub-list/
http://www.cplusplus.com/reference/list/list/list/
https://blog.csdn.net/liyuan_669/article/details/22100165
https://www.cnblogs.com/xudong-bupt/p/8420695.html
http://www.cplusplus.com/reference/list/list/sort/
https://stackoverflow.com/questions/29286863/invalid-use-of-non-static-member-function
https://blog.csdn.net/zhouzhenhe2008/article/details/77428743
Zhenming
Zixiang
Jenay
Eric 
Ben


PART 2 ORDER NOTATION:
For each request/command,

i = # of different ingredients in the kitchen
u = maximum units of a single ingredient in the kitchen
r = # of different recipes
k = maximum # of different ingredients in a single recipe
v = maximum units of single ingredient in a single recipe
a = maximum # of different ingredients added with a single ’a’ command 
w = maximum units of a single ingredient added with a single ’a’ command


command 'r' / add a recipe:
O(r)

command 'a' / add ingredients to the kitchen:
O(a)

command 'p' / print a recipe:
O(ulog(u))

command 'm' / make a recipe:
O(k*i)

command 'k' / print the contents of the kitchen:
O(k*u*log(k))


MISC. COMMENTS TO GRADER:
Optional, please be concise!
