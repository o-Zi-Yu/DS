HOMEWORK 1: MOIRE STRINGS


NAME:  < ziyu zhu >


COLLABORATORS AND OTHER RESOURCES:
did by my own

http://www.weixueyuan.net/view/5825.html
https://blog.csdn.net/kingstar158/article/details/6859379
https://blog.csdn.net/liuweiyuxiang/article/details/50838349
https://www.ojit.com/article/1723609
https://www.geeksforgeeks.org/isalpha-isdigit-functions-c-example/
https://blog.csdn.net/baiqishijkh/article/details/79236202


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 5 + 5 (extra) >


EXTRA CREDIT SHAPES:
Diamond.
The height needs to be odd to form the shape.
example cmd line:

./moire.exe abcde 11 diamond abcde_11_diamond.txt

output:
     *
    *a*
   *bcd*
  *eabcd*
 *eabcdea*
*bcdeabcde*
 *abcdeab*
  *cdeab*
   *cde*
    *a*
     *


the input of height(argv[2]) needs to be odd number.

example cmd line:
./moire.exe abcde 10 diamond abcde_10_diamond.txt

output:
Height needs to be odd.



MISC. COMMENTS TO GRADER:  

Basic comments are written in the cpp file.

My Thought:
I created a string to contain all the characters needed to output
1. Find out how many strings are looped in the shape.
2. Form the string to contain all of them.
3. Find out the algorithm of each shape of each line.
4. Cut the string and output.

Algorithm of number of looped string(expect for edge cases):
Because the division is to the floor, so the answer needs to +1 to have the final
loop that may be not complete

Square:
Height-2 is the actual height that we need to output.
The square is just (height-2) * (height-2) +1

Right triangle:
Height-3 is the actual height that we need to output.
The characters are increased by 1 and forms a arithmetic sequence.
So it is (1+height-3)*(height-3)/2 +1 

Isosceles triangle:
Height-2 is the actual height that we need to output.
The characters are increased by 2 and forms a arithmetic sequence.
So it is (1+(height-1)*2)*(height-1)/2 +1

Diamond:
It is two times of the isosceles triangle.
So it is (1+(height-1)*2)*(height-1) +1


Algorithm of cuting:
Square:
cut by height-2
beginning is the line number * (height-2), easily done by the for loop

Right triangle:
the cut is increased by 1, easily done by the for loop
needs to save the character number in the string, 
so use a variable for counting character number

Isosceles triangle:
the cut is increased by 2, easily done by the for loop
the character number of the each line's ending is a perfect number, 
so it is i * i and (i+1) * (i+1)
Spaces are reducing by 1, easily done by the for loop

Diamond:
Cut the diamond into upper and lower parts.
The upper parts is exactly same as the isoceles triangle, expect for the height 
becomes (height-2)/2+1.
So the lower part's height is (height-2)/2
Since this time is not perfect square, use the cut decrease by 2.
needs to save the character number in the string, 
so use a variable for counting character number
Spaces are increasing by 1, easily done by the for loop


Error cases:
1. argument is not 5
2. height is not a pure number    e.g. 12o
3. output is not ending with .txt, perhaps the user can not open it
4. height is not high enough to construct the shape   e.g. 0
*5. shape is diamond with even height which cannot form
6. the shape is not valid, only can support the above 4.

All errors are returning 1 as functions that can output normally returns 0.



