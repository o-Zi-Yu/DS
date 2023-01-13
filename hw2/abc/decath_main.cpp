#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
#include "decath.h"
using namespace std;


//A function for setting all the points into the class
void set_Points(vector<Decath>& dec){
    string s;
    int point;
    float score;
    for(int i=0; i<int(dec.size()); i++){
//the int total point will add every calculated point and be added into the class at last
        int total_p = 0;   

        s = dec[i].getloo();    //extract the score
        if (s.size() !=0){
            score = atof(s.c_str());    // convert the score to a float type
            point = track_point(25.4347, 18, 1.81, score);    //calculate the point 
            dec[i].setOneh_p(point);    //set the point into the class
            total_p += point;
        }
        else {dec[i].setOneh_p(0);}

// The following are the similar steps for adding points
        s = dec[i].getFoo();
        if (s.size() !=0){
            score = atof(s.c_str());            
            point = track_point(1.53775, 82, 1.81, score);
            dec[i].setFouh_p(point);
            total_p += point;
        }
        else {dec[i].setFouh_p(0);}

        s = dec[i].getllo();
        if (s.size() !=0){
            score = stof(s.c_str());
            point = track_point(5.74352, 28.5, 1.92, score);
            dec[i].setOtenh_p(point);
            total_p += point;
        }
        else {dec[i].setOtenh_p(0);}

//The exception is 1500
        s = dec[i].getlfoo();
        if (s.size() !=0){
            float mi, sec;
            int loc, len;

            loc = s.find(':');     //looking for the index of ":"         
            sec = atof((s.substr(loc+1)).c_str());    //convert the seconds part to float
            len = s.size()-(s.substr(loc+1)).size();    //calculate the length of minute part
            mi = atof((s.substr(0,len-1)).c_str());    //convert the minute part to float 

            score = mi*60 + sec;    // calculate the score in unit of second 
            point = track_point(0.03768, 480, 1.85, score);    // finally calculate the point for 1500 
            dec[i].setOfoo_p(point);
            total_p += point;
        }
        else {dec[i].setOtenh_p( 0);}

//The following part will get points of field sports and set it into the class 
        s = dec[i].L_J();
        if (s.size() !=0){
            score = atof(s.c_str());
            point = field_point(0.14354, 220, 1.4, score*100);
            dec[i].setLJ_p(point);
            total_p += point;
        }
        else {dec[i].setLJ_p( 0);}
        
        s = dec[i].S_P();
        if (s.size() !=0){
            score = atof(s.c_str());
            point = field_point(51.39, 1.5, 1.05, score);
            dec[i].setSP_p(point);
            total_p += point;
        }
        else {dec[i].setSP_p( 0);}
        
        s = dec[i].H_J();
        if (s.size() !=0){
            score = atof(s.c_str());
            point = field_point(0.8465, 75, 1.42, score*100);
            dec[i].setHJ_p(point);
            total_p += point;
        }
        else {dec[i].setHJ_p( 0);}
        
        s = dec[i].D_T();
        if (s.size() !=0){
            score = atof(s.c_str());
            point = field_point(12.91, 4, 1.1, score);
            dec[i].setDT_p(point);
            total_p += point;
        }
        else {dec[i].setDT_p( 0);}
        
        s = dec[i].P_V();
        if (s.size() !=0){
            score = atof(s.c_str());
            point = field_point(0.2797, 100, 1.35, score*100);
            dec[i].setPV_p(point);
            total_p += point;
        }
        else {dec[i].setPV_p( 0);}
        
        s = dec[i].J_T();
        if (s.size() !=0){
            score = atof(s.c_str());
            point = field_point(10.14, 7, 1.08, score);
            dec[i].setJT_p(point);
            total_p += point;
        }
        else {dec[i].setJT_p(0);}

        dec[i].setTotal_P(total_p);
    }
}

int main(int argc, char* argv[]) {

//error checking for number of arguments 
	if (argc != 4){
    	cerr<<"Error: number of arguments is wrong"<<endl;  
    	return 1;
    }
//error checking for types
	string type=argv[3];
    if (type!="scores" && type!="points" && type!="custom"){
        cerr<<"Error: please enter an output type from: scores, points, or custom"<<endl;
        return 1;
    }

//error checking for reading files
	ifstream in_str(argv[1]);
	if (!in_str) {
	    cerr << "Could not open " << argv[1] << " to read." << endl;
	    return 1;
    }
//error checking for writing files
    ofstream out_str(argv[2]);
    if (!out_str){
    	cerr << "Could not open" << argv[2] << "to write." << endl;
    	return 1;
    }
    
    string line, event_, fst_n, lst_n, country, score;
    Decath player;
    vector<Decath> decathlete;    //construct the vector to save

// The huge while loop for reading files 
    while (in_str >> line) {
    	if (line == "event"){     //if the word "event" is read, read one more word for event name 
    		in_str >> event_;
    	}
    	else{             //otherwise, read three more words for first name, last name, country, and score
    		fst_n = line;
    		in_str >> lst_n >> country;
    		player = Decath(fst_n, lst_n, country);
            int if_new = 1;

//when the length of the vector is not zero, compare the new object with exeisted objects in the vector
//and then either change the score of an exeisting object or add the new object with the score into the vector 
            if (decathlete.size() !=0){
                for (int i=0; i< int(decathlete.size()); i++){
                    if ( same_person(decathlete[i], player) == true){
                        if_new = 0;
                        in_str >> score;

// the following code will add zeros for decimal part so that there are two bits of decimal
                        if (score.find(".")== -1){score = score+".00";}
                        else{
                            int digi = score.find(".");
                            if (score.substr(digi).size()!=3){ score = score+"0";}
                        }

                        if (score[0]=='0' && score[1]!='.'){score = score.substr(1);}

                        //decide which score to modify
                        if (event_ == "1500_METERS") { decathlete[i].setOfoo(score);}
                        if (event_ == "400_METERS") { decathlete[i].setFouh(score);}
                        if (event_ == "110_METERS_HURDLES") { decathlete[i].setOtenh(score);}
                        if (event_ == "100_METERS") { decathlete[i].setOneh(score);}
                        if (event_ == "POLE_VAULT") { decathlete[i].setPV(score);}
                        if (event_ == "JAVELIN_THROW") { decathlete[i].setJT(score);}
                        if (event_ == "SHOT_PUT") { decathlete[i].setSP(score);}
                        if (event_ == "HIGH_JUMP") { decathlete[i].setHJ(score);}
                        if (event_ == "DISCUS_THROW") { decathlete[i].setDT(score);}
                        if (event_ == "LONG_JUMP") { decathlete[i].setLJ(score);}
                        break;
                    }
                    
                }
            }
// if there is no exeisted object, 
            if(decathlete.size() ==0 || (decathlete.size() !=0 && if_new == 1) ){
        		in_str >> score;

                if (score.find(".")== -1){score = score+".00";}
                else{
                    int digi = score.find(".");
                    if (score.substr(digi).size()!=3){ score = score+"0";}
                }

                if (score[0]=='0' && score[1]!='.'){score = score.substr(1);}

        		if (event_ == "1500_METERS") { player.setOfoo(score);}
        		if (event_ == "400_METERS") { player.setFouh(score);}
        		if (event_ == "110_METERS_HURDLES") { player.setOtenh(score);}
    			if (event_ == "100_METERS") { player.setOneh(score);}
         		if (event_ == "POLE_VAULT") { player.setPV(score);}
        		if (event_ == "JAVELIN_THROW") { player.setJT(score);}
        		if (event_ == "SHOT_PUT") { player.setSP(score);}
    			if (event_ == "HIGH_JUMP") { player.setHJ(score);}
    			if (event_ == "DISCUS_THROW") { player.setDT(score);}        			
                if (event_ == "LONG_JUMP") { player.setLJ(score);}
        		
                decathlete.push_back(player); 
            }
    	}
    }
      
    if (type == "scores") {
        sort(decathlete.begin(), decathlete.end(), Sort_Score);
    	out_str << "DECATHLETE SCORES                             100     LJ     SP     HJ    400   110H     DT     PV     JT     1500" << endl;
    	for (int i=0; i<int(decathlete.size()); i++){
    		out_str << fixed << setprecision(2) << left << setw(20) << decathlete[i].getFst() << setw(19) << decathlete[i].getLst() 
            << setw(5) << decathlete[i].getCoun() << setw(8) << decathlete[i].getloo() << setw(6) << decathlete[i].L_J()
            << setw(8) << decathlete[i].S_P() << setw(6) << decathlete[i].H_J() << setw(7) << decathlete[i].getFoo()
            << setw(7) << decathlete[i].getllo() << setw(8) << decathlete[i].D_T() << setw(6) << decathlete[i].P_V()
            << setw(7) << decathlete[i].J_T() << setw(7) << decathlete[i].getlfoo() << endl;
    	}
    }

    if (type == "points") {

        set_Points(decathlete);
        sort(decathlete.begin(), decathlete.end(), Sort_Point);

        out_str << "DECATHLETE POINTS                             100     LJ     SP     HJ    400   110H     DT     PV     JT   1500    TOTAL" << endl;
        for (int i=0; i<int(decathlete.size()); i++){
            out_str << left << setw(20) << decathlete[i].getFst() << setw(19) << decathlete[i].getLst() 
            << setw(3) << decathlete[i].getCoun();
            out_str << right << setw(7) << decathlete[i].getloo_p() 
            << setw(7) << decathlete[i].L_J_p() << setw(7) << decathlete[i].S_P_p() 
            << setw(7) << decathlete[i].H_J_p() << setw(7) << decathlete[i].getFoo_p() 
            << setw(7) << decathlete[i].getllo_p() << setw(7) << decathlete[i].D_T_p() 
            << setw(7) << decathlete[i].P_V_p() << setw(7) << decathlete[i].J_T_p() 
            << setw(7) << decathlete[i].getlfoo_p() << setw(9) << decathlete[i].getTotal_P() << endl;
        }

    }

    if (type == "custom"){

        set_Points(decathlete);
        sort(decathlete.begin(), decathlete.end(), Sort_Custom);

        out_str<< "DECATHLETE POINTS                             100   110H    400   1500    Total Running Point     LJ     SP     HJ     DT     PV     JT    TOTAL" << endl;
        for (int i=0; i<int(decathlete.size()); i++){
            out_str << left << setw(20) << decathlete[i].getFst() << setw(19) << decathlete[i].getLst() 
            << setw(3) << decathlete[i].getCoun();
            out_str << right << setw(7) << decathlete[i].getloo_p() << setw(7) << decathlete[i].getllo_p() 
            << setw(7) << decathlete[i].getFoo_p() << setw(7) << decathlete[i].getlfoo_p() 
            << setw(23) << decathlete[i].getRunning_point() << setw(7) << decathlete[i].L_J_p()
            << setw(7) << decathlete[i].S_P_p() << setw(7) << decathlete[i].H_J_p() 
            << setw(7) << decathlete[i].D_T_p() << setw(7) << decathlete[i].P_V_p() 
            << setw(7) << decathlete[i].J_T_p() << setw(9) << decathlete[i].getTotal_P() << endl;
        }
    }

	return 0;
}