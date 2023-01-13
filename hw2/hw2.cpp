#include "hw2.h"


//sort by the country in alphabetical order, then by last name
bool sorted1 (const Athlete& one, const Athlete& two) {
    return one.country()<two.country() ||
    (one.country()==two.country() && one.last_name()<two.last_name());
}

//sort by total points of athletes
bool sorted2 (Athlete& one, Athlete& two) {
    return one.get_sum_point()>two.get_sum_point();
}

/*sort by the average points of the athletes has valid points, 
    if same, then by total points of athletes*/
bool sorted3 (Athlete& one, Athlete& two) {
    int a = one.get_sum_point() / one.get_event_num() >
        two.get_sum_point() / two.get_event_num();
    return a || (a && one.get_sum_point()>two.get_sum_point());
}

/*create a vector that uses the Athlete class in the head file.
It stores the athlete's first name, last name, country, and every
event score and the number of events athlete has valid score(custom).
*/
std::vector <Athlete> a_vector(std::ifstream& in_str){
    std::vector <Athlete> ath;
    std::string first, last, country, time;
    std::string event;
    while (!in_str.eof()) {//read to end
        in_str >> first;
        if (first == "event"){
            in_str >> event;
        }
        else {
            in_str >> last >> country >> time;
            Athlete b = Athlete(first, last, country);
            //search if the athlete is in the vector
            bool exist = false;
            for (unsigned int i = 0; i < ath.size(); i++){
                if (ath[i].first_name() == first && 
                    ath[i].last_name() == last && ath[i].country() == country){
                    exist = true;
                    break;
                }
            }
            if (exist == false){
                b.set_first(first);
                b.set_last(last);
                b.set_length(first.size(), 0);
                b.set_length(last.size(), 1);
                ath.push_back(b);
            }
            
            //loop through the vector to find the althlete
            for (unsigned int i = 0; i < ath.size(); i++){
                if (ath[i].first_name() == first && ath[i].last_name() == last){
                    //store the score in the array
                    if (event == "100_METERS"){
                    ath[i].set_score(time, 0);
                    ath[i].set_event_num();
                    }
                    if (event == "LONG_JUMP"){
                    ath[i].set_score(time, 1);
                    ath[i].set_event_num();
                    }
                    if (event == "SHOT_PUT"){
                    ath[i].set_score(time, 2);
                    ath[i].set_event_num();
                    }
                    if (event == "HIGH_JUMP"){
                    ath[i].set_score(time, 3);
                    ath[i].set_event_num();
                    }
                    if (event == "400_METERS"){
                    ath[i].set_score(time, 4);
                    ath[i].set_event_num();
                    }
                    if (event == "110_METERS_HURDLES"){
                    ath[i].set_score(time, 5);
                    ath[i].set_event_num();
                    }
                    if (event == "DISCUS_THROW"){
                    ath[i].set_score(time, 6);
                    ath[i].set_event_num();
                    }
                    if (event == "POLE_VAULT"){
                    ath[i].set_score(time, 7);
                    ath[i].set_event_num();
                    }
                    if (event == "JAVELIN_THROW"){
                    ath[i].set_score(time, 8);
                    ath[i].set_event_num();
                    }
                    if (event == "1500_METERS"){
                    ath[i].set_score(time, 9);
                    ath[i].set_event_num();
                    }
                }
            }
        }
    }
    return ath;
}

/*inputs the score of 1500M 
    and output in a vector of float with minute and second*/
std::vector <float> min_sec(std::string time){
    int m;
    std::vector <float> m_s;
    //find ':'
    for (unsigned int i = 0; i < time.size(); i++){
        if (time[i] == ':'){
            m = i;
        }
    }
    float minute = std::stoi(time.substr(0, m));
    float second = std::stof(time.substr(m+1));
    m_s = {minute, second};
    return m_s;
}

//calculate how long the spacing should have to output
//all spacing logic is in README
int space(std::vector<Athlete>& ath, int j){
    int space_length[2] = {0,0};
    for(unsigned int i = 0; i < ath.size(); i++){
        if (space_length[0] < ath[i].get_length(0)){
            space_length[0] = ath[i].get_length(0);
        }
        if (space_length[1] < ath[i].get_length(1)){
            space_length[1] = ath[i].get_length(1);
        }
    }
    return space_length[j];
}

/*takes in the file name to write, and the vector of athletes. 
    has no returns but write the file.*/
void out_score(std::ofstream& f_out, std::vector <Athlete> ath){
    //sort the vector in country by alphabetical order, then by last name
    sort(ath.begin(), ath.end(), sorted1);
    int first_space = space(ath, 0);
    int last_space = space(ath, 1);
    //output first line
    f_out << "DECATHLETE SCORES" << std::string(first_space+last_space-2, ' ')
        << "100     LJ     SP     HJ    400   110H     "
        << "DT     PV     JT     1500" << std::endl;
    //set all outputs has 2 decimals
    f_out << std::setprecision(2) << std::fixed;
    //loop throught the vector to print names, nationality and scores
    for(unsigned int i = 0; i < ath.size(); i++){
        f_out << std::left <<std::setw(first_space + 4) << ath[i].first_name()
            << std::left << std::setw(last_space + 4) << ath[i].last_name();
        f_out << std::left << std::setw(5) << ath[i].country();
        //if the score is invalid, just print nothing, else, print the float
        //separate events
        if (ath[i].get_score(0) == ""){
            f_out << ath[i].get_score(0);
        }
        else{
            f_out << std::stof(ath[i].get_score(0));
        }
        for (int j = 1; j < 9; j++){
            if (ath[i].get_score(j) == ""){
                f_out << std::right << std::setw(7)<< ath[i].get_score(j);
            }
            else{
                f_out << std::right << std::setw(7) 
                << std::stof(ath[i].get_score(j));
            }
        }
        if (ath[i].get_score(9) == ""){
            f_out << std::right << std::setw(8)<< ath[i].get_score(9);
        }
        //the minute should not be in 2 decimals, so turn it to one place
        //then turn back to 2 decimals.
        else{
            //if second less than 10, it should be 0x.xx but bot x.xx
            if (min_sec(ath[i].get_score(9))[1] < 10){
                f_out << std::right << std::setw(3)<<std::setprecision(0)
                << min_sec(ath[i].get_score(9))[0]<< ":0" <<std::setprecision(2)
                << min_sec(ath[i].get_score(9))[1];
            }
            else{
                f_out << std::right << std::setw(3)<<std::setprecision(0) 
                << min_sec(ath[i].get_score(9))[0] << ':' <<std::setprecision(2)
                << min_sec(ath[i].get_score(9))[1];
            }

        }
        f_out << std::endl;
    }
}

/*takes in the vector of athletes. 
    has no returns but set points and sum up them.*/
void cal_point(std::vector <Athlete> &ath){
    //certain variables to calculate
    const std::vector <float> hun = {25.4347, 18, 1.81};
    const std::vector <float> lj = {0.14354, 220, 1.4};
    const std::vector <float> sp = {51.39, 1.5, 1.05};
    const std::vector <float> hj = {0.8465, 75, 1.42};
    const std::vector <float> fou = {1.53775, 82, 1.81};
    const std::vector <float> ele = {5.74352, 28.5 , 1.92};
    const std::vector <float> dt = {12.91, 4, 1.1};
    const std::vector <float> pv = {0.2797, 100, 1.35};
    const std::vector <float> jt = {10.14, 7, 1.08};
    const std::vector <float> fif = {0.03768, 480, 1.85};
    //2d vector
    const std::vector <std::vector<float>> cal =
         {hun, lj, sp, hj, fou, ele, dt, pv, jt, fif};
    //loop through the vector to calculate points
    for (unsigned int i = 0; i < ath.size(); i++){
        for (int j = 0; j < 10; j++){
            int p;
            //if the score is empty, point is 0, else is calculated
            if (!ath[i].get_score(j).empty()){
                //differs by track events and field events
                double s = std::stod(ath[i].get_score(j));
                if (j == 0 || j == 4 || j == 5 ){//track
                    p = int(cal[j][0] * pow((cal[j][1] - s), cal[j][2]));
                }
                else if (j == 9){//track but has minute, has extra calculation
                    std::string st = ath[i].get_score(9);
                    int minute = int(min_sec(st)[0]);
                    float second = min_sec(st)[1];
                    float s = minute*60 + second;
                    p = int(fif[0] * pow((fif[1] - s), fif[2]));
                }
                else if (j == 1 || j == 3 || j == 7){//field unit in centimeter
                    p = int(cal[j][0] * pow((s * 100 - cal[j][1]), cal[j][2]));
                }
                else{//field unit in meter
                    p = int(cal[j][0] * pow((s - cal[j][1]), cal[j][2]));
                }
            }
            else{
                p = 0;
            }
            //set points and sum up them
            ath[i].set_point(p, j);
            ath[i].add_point();
        }
    }
}

/*takes in the file name to write, and the vector of athletes. 
    has no returns but write the file.*/
void out_point(std::ofstream& f_out, std::vector <Athlete>& ath){
    //sort the vector by points
    sort(ath.begin(), ath.end(), sorted2);
    int first_space = space(ath, 0);
    int last_space = space(ath, 1);
    //output first line
    f_out << "DECATHLETE POINTS" << std::string(first_space+last_space-2,' ')
        << "100     LJ     SP     HJ    400   110H     "
        << "DT     PV     JT   1500    TOTAL" << std::endl;
    //loop throught the vector to print names, nationality and scores
    for(unsigned int i = 0; i < ath.size(); i++){
        f_out << std::left <<std::setw(first_space + 4)<< ath[i].first_name() 
            << std::left << std::setw(last_space + 4) << ath[i].last_name();
        f_out << std::left << std::setw(7) << ath[i].country();
        //separate events
        f_out << ath[i].get_point(0);
        for (int j = 1; j < 10; j++){
            f_out << std::right << std::setw(7) << ath[i].get_point(j);
        }
        //total points
        f_out << std::right << std::setw(9) << ath[i].get_sum_point();
        f_out << std::endl;
    }
}

/*takes in the vector of athletes. 
    has no returns but write the file.*/
void out_custom(std::ofstream& f_out, std::vector<Athlete>& ath){
    /*sort the vector by the average points of the athletes has valid points, 
    if same, then by total points of athletes*/
    sort(ath.begin(), ath.end(), sorted3);
    int first_space = space(ath, 0);
    int last_space = space(ath, 1);
    //output first line
    f_out << "DECATHLETE POINTS" << std::string(first_space+last_space - 2,' ')
        << "100     LJ     SP     HJ    400   110H     "
        << "DT     PV     JT   1500    TOTAL    AVG" << std::endl;
    //loop throught the vector to print names, nationality and scores
    for(unsigned int i = 0; i < ath.size(); i++){
        f_out << std::left <<std::setw(first_space + 4)<< ath[i].first_name() 
            << std::left << std::setw(last_space + 4) << ath[i].last_name();
        f_out << std::left << std::setw(7) << ath[i].country();
        //separate events
        f_out << ath[i].get_point(0);
        for (int j = 1; j < 10; j++){
            f_out << std::right << std::setw(7) << ath[i].get_point(j);
        }
        //total points
        f_out << std::right << std::setw(9) << ath[i].get_sum_point();
        //avg points
        f_out << std::right << std::setw(7) 
            << ath[i].get_sum_point() / ath[i].get_event_num();
        f_out << std::endl;
    }
}

