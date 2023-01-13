#include "Fighter.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
//You may add additional typedefs, includes, etc. up here

//This is the only array you are allowed to have in your program.
const std::string move_names[7] = {"jab", "forward-tilt", "up-tilt", 
  "down-tilt", "forward-smash", "up-smash", "down-smash"};

//Feel free to put forward declarations here

//input the set of name of fighters and names to check whether the name of fighter is in the set
bool invalid_character(const std::set<std::string>& name_fighter,
  const std::string& name) {
	if (name_fighter.find(name) == name_fighter.end()) {return true;}
	else{return false;}
}

//input the set of movement and move to check whether the name of fighter is in the set
bool invalid_move(const std::set<std::string>& movement,
  const std::string& move) {
	if (movement.find(move) == movement.end()) {
		return true;
	}
	else {return false;}
}

/*A simple query - given the name of the character, output the startup
frame data for one particular move or all moves of this character. 
If ‘all’ is specified, output should be in alphabetical order based on move name.*/
void q(const std::string& name, const std::string& move, 
  const std::map<std::string, Fighter>& map_fighter, std::ofstream& outfile) {
    Fighter a = map_fighter.find(name)->second;
	//find the correct movement and print the frame
	if (move == move_names[0]) {
		outfile << a.get_name() << " " << move_names[0] << ": " << a.get_jab()
		  << std::endl;
	}
	else if (move == move_names[1]) {
		outfile << a.get_name() << " " << move_names[1] << ": " << a.get_f_tilt()
		  << std::endl;
	}
	else if (move == move_names[2]) {
		outfile << a.get_name() << " " << move_names[2] << ": " << a.get_u_tilt()
		  << std::endl;
	}
	else if (move == move_names[3]) {
		outfile << a.get_name() << " " << move_names[3] << ": " << a.get_d_tilt()
		  << std::endl;
	}
	else if (move == move_names[4]) {
		outfile << a.get_name() << " " << move_names[4] << ": " << a.get_f_smash()
		  << std::endl;
	}
	else if (move == move_names[5]) {
		outfile << a.get_name() << " " << move_names[5] << ": " << a.get_u_smash()
		  << std::endl;
	}
	else if (move == move_names[6]) {
		outfile << a.get_name() << " " << move_names[6] << ": " << a.get_d_smash()
		  << std::endl;
	}
	else { //move is all
		outfile << a.get_name() << " " << move_names[6] << ": " << a.get_d_smash()
		  << std::endl;
		outfile << a.get_name() << " " << move_names[3] << ": " << a.get_d_tilt()
		  << std::endl;
		outfile << a.get_name() << " " << move_names[4] << ": " << a.get_f_smash()
		  << std::endl;
		outfile << a.get_name() << " " << move_names[1] << ": " << a.get_f_tilt()
		  << std::endl;
		outfile << a.get_name() << " " << move_names[0] << ": " << a.get_jab()
		  << std::endl;
		outfile << a.get_name() << " " << move_names[5] << ": " << a.get_u_smash()
		  << std::endl;
		outfile << a.get_name() << " " << move_names[2] << ": " << a.get_u_tilt() 
		 << std::endl;
	}
}

/* Output [limit] number of fighters that have the fastest [move], 
along with the corresponding frame data. The function iterate through the map
then increase the frame by one. 
*/
void f(const std::string& move, const std::string& limit, 
  std::map<std::string, Fighter>& map_fighter, std::ofstream& outfile) {
	std::map<std::string, Fighter>::iterator a;
	uint int_limit = std::stoi(limit);
	uint counter = 0;
	int frame = 1; //minimum frame
	bool full = false;
	outfile << "-f " << move << " " << limit << std::endl;
	//check if number is at limit or the fighter is at maximum
	while (!full && (counter < map_fighter.size())) {
		for (a = map_fighter.begin(); a != map_fighter.end(); a++) {
			//fighter number is at the limit
			if (counter == int_limit) {
				full = true;
				break;
			}
			if (move == move_names[0]) {
				if(a->second.get_jab() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_jab()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[1]) {
				if(a->second.get_f_tilt() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_f_tilt()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[2]) {
				if(a->second.get_u_tilt() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_u_tilt()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[3]) {
				if(a->second.get_d_tilt() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_d_tilt()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[4]) {
				if(a->second.get_f_smash() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_f_smash()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[5]) {
				if(a->second.get_u_smash() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_u_smash()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[6]) {
				if(a->second.get_d_smash() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_d_smash()
					  << std::endl;
					counter++;
				}
			}
		}
		frame++;
	}
}

/*Output [limit] number of fighters that have the slowest [move], along with the corresponding
frame data.*/
void s(const std::string& move, const std::string& limit, 
  std::map<std::string, Fighter>& map_fighter, std::ofstream& outfile) {
	std::map<std::string, Fighter>::iterator a;
	uint int_limit = std::stoi(limit);
	uint counter = 0;
	int frame = 60; //maximum frame
	bool full = false;
	outfile << "-s " << move << " " << limit << std::endl;
	//check if number is at limit or the fighter is at maximum
	while (!full && (counter < map_fighter.size())) {
		for (a = map_fighter.begin(); a != map_fighter.end(); a++) {
			//fighter number is at the limit
			if (counter == int_limit) {
				full = true;
				break;
			}
			if (move == move_names[0]) {
				if(a->second.get_jab() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_jab()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[1]) {
				if(a->second.get_f_tilt() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_f_tilt()
					  << std::endl;
					counter++;
				}
				
			}
			if (move == move_names[2]) {
				if(a->second.get_u_tilt() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_u_tilt()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[3]) {
				if(a->second.get_d_tilt() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_d_tilt()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[4]) {
				if(a->second.get_f_smash() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_f_smash()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[5]) {
				if(a->second.get_u_smash() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_u_smash()
					  << std::endl;
					counter++;
				}
			}
			if (move == move_names[6]) {
				if(a->second.get_d_smash() == frame) {
					outfile << a->second.get_name() << " " << a->second.get_d_smash()
					  << std::endl;
					counter++;
				}
			}
		}
		frame--;
	}
}

/*Output fighters that have a startup frame of [startup frame] for [move]
The function iterate through the map and print the name if the frame is correct*/
void d(const std::string& move, const std::string& startup_frame, 
  std::map<std::string, Fighter>& map_fighter, std::ofstream& outfile) {
	std::map<std::string, Fighter>::iterator a;
	int int_startup_frame = std::stoi(startup_frame);
	outfile << "-d " << move << " " << startup_frame << std::endl;
	for (a = map_fighter.begin(); a != map_fighter.end(); a++) {
		if (move == move_names[0]) {
			if(a->second.get_jab() == int_startup_frame) {
				outfile << a->second.get_name() << std::endl;
			}
		}
		if (move == move_names[1]) {
			if(a->second.get_f_tilt() == int_startup_frame) {
				outfile << a->second.get_name() << std::endl;
			}
			
		}
		if (move == move_names[2]) {
			if(a->second.get_u_tilt() == int_startup_frame) {
				outfile << a->second.get_name() << std::endl;
			}
		}
		if (move == move_names[3]) {
			if(a->second.get_d_tilt() == int_startup_frame) {
				outfile << a->second.get_name() << std::endl;
			}
		}
		if (move == move_names[4]) {
			if(a->second.get_f_smash() == int_startup_frame) {
				outfile << a->second.get_name() << std::endl;
			}
		}
		if (move == move_names[5]) {
			if(a->second.get_u_smash() == int_startup_frame) {
				outfile << a->second.get_name() << std::endl;
			}
		}
		if (move == move_names[6]) {
			if(a->second.get_d_smash() == int_startup_frame) {
				outfile << a->second.get_name() << std::endl;
			}
		}
	}
}


int main(int argc, char** argv){
	// Argument parsing
	if(argc != 4){
		std::cerr << "Proper usage is " << argv[0] 
		 << " [database file] [input file] [output file]" << std::endl;
		return -1;
	}

	std::ifstream dbfile(argv[1]);
	if(!dbfile){
		std::cerr << "Failed to open database " << argv[1] << " for reading."
		  << std::endl;
	}

	std::ifstream infile(argv[2]);
	if(!infile){
		std::cerr << "Failed to open input " << argv[2] << " for reading."
		  << std::endl;
	}

	std::ofstream outfile(argv[3]);
	if(!outfile){
		std::cerr << "Failed to open output " << argv[3] << " for writing."
		  << std::endl;
	}

	///////Fill in the rest of main below:

	//variables
	std::map<std::string, Fighter> map_fighter;
	std::set<std::string> name_fighter, movement;
	std::string name, jab, f_tilt, u_tilt, d_tilt, f_smash, u_smash, d_smash;

	//create set for movements
	for (int i = 0; i < 7; i++) {
		movement.insert(move_names[i]);
	}

	//read fighter datas (ignore first line of names)
	dbfile >> name >> jab >> f_tilt >> u_tilt >> d_tilt >> f_smash
	  >> u_smash >> d_smash;
	while (!dbfile.eof()) {//read to end
		dbfile >> name >> jab >> f_tilt >> u_tilt >> d_tilt >> f_smash 
		  >> u_smash >> d_smash;

		//create Fighter class for each fighters by name
		Fighter f = Fighter(name);
		name_fighter.insert(name);

		//set movements
		f.set_jab(std::stoi(jab));
		f.set_f_tilt(std::stoi(f_tilt));
		f.set_u_tilt(std::stoi(u_tilt));
		f.set_d_tilt(std::stoi(d_tilt));
		f.set_f_smash(std::stoi(f_smash));
		f.set_u_smash(std::stoi(u_smash));
		f.set_d_smash(std::stoi(d_smash));

		/*create pairs of names and fighter class into a pair and then
		put it into the map*/
		map_fighter.insert(std::make_pair(name, f));
	}
	//end of reading data

	//read queries by three string and operate the function
	std::string query, a, b;
	while (infile >> query >> a >> b) {//read to end, each read has 3 string
		if (query == "-q") {
			//check if name and movement are valid
			if (invalid_character(name_fighter, a)) {
				outfile << "Invalid character name: " << a << std::endl;
				outfile << std::endl;
				continue;
			}
			if (invalid_move(movement, b) && b != "all") {
				outfile << "Invalid move name: " << b << std::endl;
				outfile << std::endl;
				continue;
			}
			q(a, b, map_fighter, outfile);
			outfile << std::endl;
		}

		if (query == "-f") {
			if (invalid_move(movement, a)) {
				outfile << "Invalid move name: " << a << std::endl;
				outfile << std::endl;
				continue;
			}
			f(a, b, map_fighter, outfile);
			outfile << std::endl;
		}

		if (query == "-s") {
			if (invalid_move(movement, a)) {
				outfile << "Invalid move name: " << a << std::endl;
				outfile << std::endl;
				continue;
			}
			s(a, b, map_fighter, outfile);
			outfile << std::endl;
		}

		if (query == "-d") {
			if (invalid_move(movement, a)) {
				outfile << "Invalid move name: " << a << std::endl;
				outfile << std::endl;
				continue;
			}
			d(a, b, map_fighter, outfile);
			outfile << std::endl;
		}
	}

	return 0;
}

