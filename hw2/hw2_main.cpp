
#include "hw2.h"

/*The main function takes 4 arguments. Except for the first compiled file,
they are the txt file to open, txt file to write, and the algorism chosen to
sort the athletes.If there are some error inputs, there will be some outputs 
to show that the input is invalid. 
See sort algorism in sort functions.
*/
int main(int argc, const char * argv[]){
    //error case
    if (argc < 4){
        std::cerr << "Missing or excessive arguments, need 4." << std::endl;
        exit(1);
    }
    //define arguments that inputs
    std::ifstream in_str2(argv[1]);
    std::ofstream f_out(argv[2]);
    std::string type(argv[3]);
    if (!in_str2.good()) {//test if the file is successfully opened
        std::cerr << "Can't open " << argv[1] << " to read.\n";
        exit(1);
    }
    if (!f_out.good()) {//test if the file is successfully opened
        std::cerr << "Can't open " << argv[2] << " to write.\n";
        exit(1);
    }
    //create a vector with athletes as classes in it.
    std::vector <Athlete> v_athlete = a_vector(in_str2);

    //algorism sort by scores
    if (type == "scores"){
        out_score(f_out, v_athlete);
        return 0;
    }
    //algorism sort by points
    else if (type == "points"){
        cal_point(v_athlete);
        out_point(f_out, v_athlete);
        return 0;
    }
    //algorism sort by average scores
    else if (type == "custom"){
        cal_point(v_athlete);
        out_custom(f_out, v_athlete);
        return 0;
    }
    //error case
    else{
        std::cerr << "Invalid sorting algorithms.\n";
        exit(1);
    }
}

