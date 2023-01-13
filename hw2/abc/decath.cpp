#include <iostream>
#include <math.h>
#include "decath.h"

using namespace std;

Decath::Decath(const string& fst, const string& lst, const string& country, const string& loo, 
const string& LJ, const string& SP, const string& HJ, const string& foo, const string& lloH, 
const string& DT, const string& PV, const string& JT, const string& lfoo, const int loo_p, 
const int LJ_p, const int SP_p, const int HJ_p, const int foo_p, const int lloH_p, 
const int DT_p, const int PV_p, const int JT_p, const int lfoo_p, const int total_point)
	: fstn(fst), lstn(lst), coun(country), 
	loo_(loo), lj(LJ), sp (SP), hj(HJ), foo_ (foo), lloH_ (lloH), dt (DT), pv (PV),	jt(JT),	lfoo_(lfoo), 
	loo_po(loo_p), lj_p(LJ_p), sp_p(SP_p), hj_p(HJ_p), foo_po(foo_p), 
	lloH_po(lloH_p), dt_p(DT_p), pv_p(PV_p), jt_p(JT_p), lfoo_po(lfoo_p), p_total(total_point)
{}

int track_point(float a, float b, float c, float s){
	return int(a*pow((b - s), c));
}

int field_point(float a, float b, float c, float s){
	return int(a*pow((s - b), c));
}

//Comparing first name, last name, and country to decide if two object are the same one
bool same_person(const Decath& exist, const Decath& newp){
	return (exist.getFst() == newp.getFst()) && (exist.getLst() == newp.getLst()) && (exist.getCoun() == newp.getCoun());
}

//Sort Decath type objects by country first and then by last name
bool Sort_Score(const Decath& dec1, const Decath& dec2){
	if( dec1.getCoun() == dec2.getCoun() ) { return dec1.getLst() < dec2.getLst(); }
	else { return dec1.getCoun() < dec2.getCoun(); }  
}

//Sort function by total point
bool Sort_Point(const Decath& dec1, const Decath& dec2){
	return dec1.getTotal_P() > dec2.getTotal_P();
}

//Sort function by sum of all track terms 
bool Sort_Custom(const Decath& dec1, const Decath& dec2){
	return dec1.getRunning_point() > dec2.getRunning_point() ;
}