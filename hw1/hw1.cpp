
#include <string>
#include <fstream>
#include <iostream>

/*Function to print square. Passing in height, pattern and file name.
It writes the file and returns.
The following 3 functions's logic are mostly same with different shapes. 
Most comments in square can also be used in 2 others.
Special functions are commented separately.
See all algorithms in README
*/
int square(int height, std::string pattern, std::string f_name){

    std::ofstream f_out; //create output file variable
    f_out.open(f_name); //open with file name that passes in this function
    if (f_out.is_open()) { //test if the file is successfully opened
        const std::string star(height, '*'); //create the first line and the ending line that is  *

        int num = (height-2) * (height-2) / pattern.size(); //Create a string with all the characters needed.

        std::string loop;
        //create a string that contains all characters needed
        for(int i = 0; i <= num; i++){
            loop += pattern;
        }
        
        //output
        f_out << star << std::endl; //output first line with *

        //cut the string and print. See all algorithms in README
        for (int i = 0; i < height-2; i++){
            f_out << '*' << loop.substr(i * (height- 2), height-2) << '*'
             << std::endl;
        }

        f_out << star << std::endl; //output last line with *
    }
    f_out.close(); //close the file
    return 0; //the function ends in normal
}


int right_triangle(int height, std::string pattern, std::string f_name){

    std::ofstream f_out;
    f_out.open(f_name);
    if (f_out.is_open()) {
        //edge cases when height is 2
        if (height == 2){
            f_out << "*\n**" << std::endl;
        }
        else{
            const std::string star(height, '*');

            //cut square into half
            int num = (height-2) * (height-3) / 2 / pattern.size();

            std::string loop;
            for(int i = 0; i <= num; i++){
                loop += pattern;
            }
            
            f_out << "*\n**" << std::endl; //output the first 2 lines

            /*the increased num is increasing by 1 in the sequence, 
            then cut the string by the increased num
            */
            int j = 0;
            for (int i = 0; i < height-3; i++){
                j = i + j;
                f_out << '*' << loop.substr(j, i + 1) << '*' << std::endl;
            }
            f_out << star << std::endl; //output last line with *
        }
    }
    f_out.close();
    return 0;
}


int isosceles_triangle(int height, std::string pattern, std::string f_name){

    std::ofstream f_out;
    f_out.open(f_name);
    if (f_out.is_open()) {
        const std::string star(height * 2 - 1, '*');

        //arithmetic sequence increased by 2
        int num = (1 + (1 + 2 * (height-1)) * (height-1) / 2)
                  / pattern.size();

        std::string loop;
        for(int i = 0; i <= num; i++){
            loop += pattern;
        }

        //create the first line with (height-1) spaces and *
        f_out << std::string(height-1, ' ') << '*' << std ::endl; 

        /*the final number of the lines is a perfect square, 
        cut the string with them
        */
        for (int i = 0; i < height-2; i++){
            f_out << std::string(height - 2 - i, ' ') << "*" 
            << loop.substr(i * i, i * 2 + 1) << '*' << std::endl;
        }
        f_out << star << std::endl; //output last line with *
    }
    f_out.close();
    return 0;
}

/*for extra
the arguments passes in are same as above, but the height has to be odd 
to form a diamond. 
*/
int diamond(int height, std::string pattern, std::string f_name){

    std::ofstream f_out;
    f_out.open(f_name);
    if (f_out.is_open()) {
        /*arithmetic sequence increased by 2 as like the isosceles_triangle,
        but the number should be 2 times than the triangle.
        */
        int num = (1 + (1 + 2 * (height-1)) * (height-1))
                  / pattern.size();

        std::string loop;
        for(int i = 0; i <= num; i++){
            loop += pattern;
        }
        
        //create the first line with ((height-2) / 2 + 1) spaces and *
        f_out << std::string((height-2) / 2 + 1, ' ') << '*' << std::endl;


        /*create the isosceles_triangle on the above
        with height (height-2) / 2 + 1
        */
        for (int i = 0; i < (height-2) / 2 + 1; i++){
            f_out << std::string((height-2) / 2 - i, ' ') << "*" 
            << loop.substr(i * i, i * 2 + 1) << '*' << std::endl;
        }


        //get the line number the isosceles_triangle ends(last i of above loop)
        int end_line = ((height-1) / 2) * ((height-1) / 2);

        /*create the reversed isosceles_triangle under the above triangle
        with height (height-2) / 2 (minus one height of above)
        */
        for (int i = 0; i < (height-2) / 2; i++){
            f_out << std::string(i + 1, ' ') << "*" 
            << loop.substr(end_line, height - 2 * (i + 2)) << '*' << std::endl;
            end_line += height - 2 * (i + 2);
        }

        //create the last line with ((height-2) / 2 + 1) spaces and *
        f_out << std::string((height-2) / 2 + 1, ' ') << '*' << std::endl;
    }
    f_out.close();
    return 0;
}

/*The main function takes 5 arguments, except for the first compiled file,
they are the pattern to loop through to display, the height of the shape,
the shape of the texts, and the file name that outputs to the directory.
If there are some error inputs, there will be some outputs to show that the
input is invalid.
*/
int main(int argc, const char * argv[]){

    //define arguments that inputs
    std::string pattern = argv[1];
    std::string s_height = argv[2];
    std::string shape = argv[3];
    std::string f_name = argv[4];
    
    //edge cases
    //if argument number is not 5
    if (argc != 5){
        std::cerr << "Missing or excessive arguments, need 5." << std::endl;
        return 0;
    }

    //height is not pure number
    unsigned int int_count = 0;
    for (unsigned int i = 0; i <= s_height.size(); i++){
        if (isdigit(s_height[i])){
            int_count += 1;
        }
    }
    if (s_height.size() != int_count){
        std::cerr << "Height is not valid." << std::endl;
        return 1; //function ends with problem(s)
    }
    
    //file output is not ending with .txt, perhaps the user can not open it
    if (f_name.substr(f_name.size()-4) != ".txt"){
        std::cerr << "Output file name is not valid,"
        " need to use .txt as ending." << std::endl;
        return 1; //function ends with problem(s)
    }

    //transfer input height from string to int
    int height = std::stoi(s_height); 

    //height is not high enough to construct the shape
    if (height <= 1){
        std::cerr << "Height is not valid." << std::endl;
        return 1; //function ends with problem(s)
    }

    //main output
    //shape is square
    if (shape == "square"){ 
        square(height, pattern, f_name);
        return 0;
    }
    //shape is right_triangle
    else if (shape == "right_triangle"){ 
        right_triangle(height, pattern, f_name);
        return 0;
    }
    //shape is isosceles_triangle
    else if (shape ==  "isosceles_triangle"){ 
        isosceles_triangle(height, pattern, f_name);
        return 0;
    }
    //shape is diamond with odd height
    else if (shape ==  "diamond" && height % 2 == 1){ 
        diamond(height, pattern, f_name);
        return 0;
    }
    //shape is diamond with even height which cannot form
    else if (shape ==  "diamond" && height % 2 == 0){ 
        std::cerr << "Height needs to be odd." << std::endl;
        return 1; //function ends with problem(s)
    }
    //the shape is not valid
    else{
        std::cerr << "Shape not valid, only support square, right_triangle"
        " isosceles_triangle and diamond. Case sensitive." << std::endl;
        return 1; //function ends with problem(s)
    }
}
