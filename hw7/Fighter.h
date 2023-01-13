#ifndef __fighter_h_
#define __fighter_h_
#include <string>

class Fighter {
    public:
        //constructor
        Fighter();
        Fighter(const std::string fighter_name){name = fighter_name;}
        //accessor
        std::string get_name() {return name;}
        int get_jab() {return jab;}
        int get_f_tilt() {return f_tilt;}
        int get_u_tilt() {return u_tilt;}
        int get_d_tilt() {return d_tilt;}
        int get_f_smash() {return f_smash;}
        int get_u_smash() {return u_smash;}
        int get_d_smash() {return d_smash;}

         //member function
        void set_jab(int fighter_jab) {jab = fighter_jab;}
        void set_f_tilt(int fighter_f_tilt) {f_tilt = fighter_f_tilt;}
        void set_u_tilt(int fighter_u_tilt) {u_tilt = fighter_u_tilt;}
        void set_d_tilt(int fighter_d_tilt) {d_tilt = fighter_d_tilt;}
        void set_f_smash(int fighter_f_smash) {f_smash = fighter_f_smash;}
        void set_u_smash(int fighter_u_smash) {u_smash = fighter_u_smash;}
        void set_d_smash(int fighter_d_smash) {d_smash = fighter_d_smash;}
        

    private:
        std::string name;
        int jab, f_tilt, d_tilt, u_tilt, f_smash, d_smash, u_smash;
};

#endif