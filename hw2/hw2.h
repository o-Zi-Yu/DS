#ifndef __athlete_h_
#define __athlete_h_
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

//Class to store and return all scores.
class Athlete {
    public:
        /* CONSTRUCTOR  Athletes are identified from first name, 
            last name and nationality. Scores and points are stored in it. */
        Athlete();
        Athlete(const std::string& fst, const std::string& lst, const std::string cty){
            first_name_ = fst;
            last_name_ = lst;
            country_ = cty;
        }
        // ACCESSORS
        const std::string& first_name() const { return first_name_; }
        const std::string& last_name() const { return last_name_; }
        const std::string& country() const { return country_; }
        const std::string& get_score(int i) const { return score_a[i]; }
        int& get_point(int i) {return point_[i];}
        int& get_sum_point() {return point_sum;}
        int& get_length(int i) {return length[i];}
        int& get_event_num() {return event_num;}

        // MODIFIERS
        void set_first(const std::string & fst) {first_name_ = fst;}
        void set_last(const std::string & lst) {last_name_ = lst;}
        void set_length(const unsigned int & len, int i) {length[i] = len;}
        void set_country(const std::string & cty) { country_ = cty; }
        //save score in array
        void set_score(const std::string & score, int i) { score_a[i] = score;}
        //save point in array
        void set_point(int point, int i) {point_[i] = point;}
        void set_event_num() {event_num += 1;} //count event_number

        //loop through array to sum up points
        void add_point(){
            point_sum = 0;
            for (int i = 0; i < 10; i++){
                point_sum += point_[i];
            }
        }
        
    private:
        // REPRESENTATION
        std::string first_name_;
        std::string last_name_;
        std::string country_;
        std::string score_a[10];
        int point_[10];
        int point_sum = 0;
        int length[2];
        int event_num = 0;
};

//modified sort algorithms
bool sorted1 (const Athlete& one, const Athlete& two);
bool sorted2 (Athlete& one, Athlete& two);
bool sorted3 (Athlete& one, Athlete& two);
std::vector <Athlete> a_vector(std::ifstream& in_str);
std::vector <float> min_sec(std::string time);
int space(std::vector<Athlete>& ath, int j);
void out_score(std::ofstream& f_out, std::vector <Athlete> ath);
void cal_point(std::vector <Athlete> &ath);
void out_point(std::ofstream& f_out, std::vector<Athlete>& ath);
void out_custom(std::ofstream& f_out, std::vector<Athlete>& ath);

#endif