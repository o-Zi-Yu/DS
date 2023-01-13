/*
These two functions are not required for your program, but may be helpful!
The recursive function will generate every combination of 0/1 for 6 positions
in a vector. Whenever pos == 6, the vector is complete.

Hint: There are 6 different "fields" in a query, this may be useful in constructing
your hash table.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <vector>
#include "actor.h"

void read_movies(const std::string movies, std::list<Actor> MOVIE_DATA);
void read_actor(const std::string actors, std::map <std::string, std::string> ACTOR_DATA);
unsigned int hash_str(const std::string s);

int main(){
	// std::ofstream outfile(argv[1]);
	// if(!outfile){
	// 	std::cerr << "Failed to open output " << argv[1] << " for writing."
	// 	  << std::endl;
	// }
	std::list<Actor> MOVIE_DATA;	
	std::vector<std::pair<int, std::list<Actor> > > imdb;
	std::map <std::string, std::string> ACTOR_DATA;
	int table_size = 100;
	int occupancy = 0.5;
	std::string text, str_table_size, str_occupancy, movies, actors;
	std::cin >> text;
	if (text == "table_size") {
		std::cin >> str_table_size;
		table_size = std::stoi(str_table_size);
		std::cin >> text;
	}
	if (text == "occupancy") {
		std::cin >> str_occupancy;
		occupancy = std::stoi(str_occupancy);
		std::cin >> text;
	}
	if (text == "movies") {
		std::cin >> movies;
		std::cin >> text;
		read_movies(text, MOVIE_DATA);
	}
	if (text == "actors") {
		std::cin >> actors;
		std::cin >> text;
		read_actor(text, ACTOR_DATA);
	}

	std::list<Actor>::iterator itr;
	for (itr = MOVIE_DATA.begin(); itr != MOVIE_DATA.end(); itr++) {
		int hash = 0;
		hash += hash_str(itr->get_title());
		hash += hash_str(itr->get_year());
		hash += hash_str(itr->get_min());
		for (uint i = 0; i < itr->get_genre().size(); i++) {
			hash += hash_str(itr->get_genre()[i]);
		}
		for (uint i = 0; i < itr->get_actor().size(); i++) {
			hash += hash_str(itr->get_actor()[i]);
		}
		for (uint i = 0; i < itr->get_row().size(); i++) {
			hash += hash_str(itr->get_row()[i]);
		}
		std::pair<int, std::list<Actor> > p;
		p.first = hash;
		imdb.push_back(p);
	}

}
	
void read_movies(const std::string movies, std::list<Actor> MOVIE_DATA){
	std::ifstream f_movie(movies);
	std::string text;
	int number;
	while (f_movie >> text) {
		Actor a = Actor(text);
		f_movie >> text;
		a.set_year(text);
		f_movie >> text;
		a.set_min(text);
		f_movie >> text;
		number = std::stoi(text);
		for (int i = 0; i < number; i++) {
			std::vector<std::string> genre;
			f_movie >> text;
			genre.push_back(text);
			if (i == number) 
				a.set_genre(genre);
		}
		f_movie >> text;
		number = std::stoi(text);
		for (int i = 0; i < number; i++) {
			std::vector<std::string> actor;
			f_movie >> text;
			actor.push_back(text);
			if (i == number) 
				a.set_actor(actor);
		}
		f_movie >> text;
		number = std::stoi(text);
		for (int i = 0; i < number; i++) {
			std::vector<std::string> row;
			f_movie >> text;
			row.push_back(text);
			if (i == number) 
				a.set_row(row);
		}
		MOVIE_DATA.push_back(a);
	}
}

void read_actor(const std::string actors, std::map <std::string, std::string> ACTOR_DATA){
	std::ifstream f_actor(actors);
	std::string number, name;
	while (f_actor >> number) {
		f_actor >> name;
		ACTOR_DATA[number] = name;
	}
}

unsigned int hash_str(const std::string s){
   unsigned int h = 29;
   for(uint i = 0; i < s.size(); i++) {
     h = (h * 37) ^ (s[i] * 97);
   }
   return h % 59;
}

void permute_filters(int pos, std::vector<int> filter){
	if(pos == 6){
		//Add other code here if you want to use the completed vectors
		return;
	}

	filter.push_back(0);
	std::vector<int> filter_new = filter;
	filter_new.back() = 1;
	permute_filters(pos+1, filter_new);
	permute_filters(pos+1, filter);
}

//Driver function, feel free to modify to pass more arguments
void permute_filters(){
		permute_filters(0, std::vector<int>());
}
