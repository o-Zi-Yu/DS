#ifndef __decath_h_
#define __decath_h_

#include <iostream>
#include <string>
using namespace std;

class Decath{
public:
//There are 24 varibles in this class: 13 strings including name, country, and scores, 
// and 11 integars including points for each term.
//All the strings have the initial value "" while all the integars have the initial value 0
	Decath(const string& fst="", const string& lst="", const string& country ="", 
	const string& loo = "", const string& LJ = "", const string& SP = "", const string& HJ = "", const string& foo = "", 
	const string& lloH = "", const string& DT = "", const string& PV = "", const string& JT = "", const string& lfoo = "",
	const int loo_p = 0, const int LJ_p =0, const int SP_p =0, const int HJ_p =0, const int foo_p =0, 
	const int lloH_p =0, const int DT_p =0, const int PV_p =0, const int JT_p =0, const int lfoo_p =0,
	const int total_point = 0);

//get functions for each varible
	const string& getFst() const { return fstn; }
	const string& getLst() const { return lstn; }
	const string& getCoun() const { return coun; }

	const string& getloo() const { return loo_; }
	const string& L_J() const { return lj; }
	const string& S_P() const { return sp; }
	const string& H_J() const { return hj; }
	const string& getFoo() const { return foo_; }
	const string& getllo() const { return lloH_; }
	const string& D_T() const { return dt; }
	const string& P_V() const { return pv; }
	const string& J_T() const { return jt; }
	const string& getlfoo() const { return lfoo_; }

	const int getloo_p() const { return loo_po; }
	const int L_J_p() const { return lj_p; }
	const int S_P_p() const { return sp_p; }
	const int H_J_p() const { return hj_p; }
	const int getFoo_p() const { return foo_po; }
	const int getllo_p() const { return lloH_po; }
	const int D_T_p() const { return dt_p; }
	const int P_V_p() const { return pv_p; }
	const int J_T_p() const { return jt_p; }
	const int getlfoo_p() const { return lfoo_po; }
	const int getTotal_P() const { return p_total; }

//modifiers for each varible
	void setFstn(const string& fst) { fstn = fst; }
	void setLstn(const string& lst) { lstn = lst; }
	void setCoun(const string& country) { coun = country; }
	void setOneh(const string& loo) { loo_ = loo; }
	void setLJ(const string& LJ) { lj = LJ; }
	void setSP(const string& SP) { sp = SP; }
	void setHJ(const string& HJ) { hj = HJ; }
	void setFouh(const string& foo) { foo_ = foo; }
	void setOtenh(const string& lloH) { lloH_ = lloH; }
	void setDT(const string& DT) { dt = DT; }
	void setPV(const string& PV) { pv = PV; }
	void setJT(const string& JT) { jt = JT; }
	void setOfoo(const string& lfoo) { lfoo_ = lfoo; }

	void setOneh_p(const int loo_p) { loo_po = loo_p; }
	void setLJ_p(const int LJ_p) { lj_p = LJ_p; }
	void setSP_p(const int SP_p) { sp_p = SP_p; }
	void setHJ_p(const int HJ_p) { hj_p = HJ_p; }
	void setFouh_p(const int foo_p) { foo_po = foo_p; }
	void setOtenh_p(const int lloH_p) { lloH_po = lloH_p; }
	void setDT_p(const int DT_p) { dt_p = DT_p; }
	void setPV_p(const int PV_p) { pv_p = PV_p; }
	void setJT_p(const int JT_p) { jt_p = JT_p; }
	void setOfoo_p(const int lfoo_p) { lfoo_po = lfoo_p; }
	void setTotal_P(const int total_point) { p_total = total_point; }

//The function for computing total running point
	const int getRunning_point() const {return loo_po + foo_po + lloH_po + lfoo_po;}
	
private:
	string fstn, lstn, coun, loo_, foo_, lloH_, lfoo_, lj, sp, hj, dt, pv, jt;	
	int loo_po, lj_p, sp_p, hj_p, foo_po, lloH_po, dt_p, pv_p, jt_p, lfoo_po, p_total;

};

//Two functions for converting track scores and field scores to point
int track_point(float a, float b, float c, float s) ;

int field_point(float a, float b, float c, float s) ;

//The function for deciding if two decathletes are the same person
bool same_person(const Decath& exist, const Decath& newp);

//Three sorting functions for score, point, and custom
bool Sort_Score(const Decath& dec1, const Decath& dec2);

bool Sort_Point(const Decath& dec1, const Decath& dec2);

bool Sort_Custom(const Decath& dec1, const Decath& dec2);

#endif