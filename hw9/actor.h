#include <string>

class Actor{
    public:
        Actor();
        Actor(const std::string str_title) {title = str_title;}

        std::string get_title() {return title;}
        std::string get_year() {return year;}
        std::string get_min() {return min;}
        std::vector<std::string> get_genre() {return genre;}
        std::vector<std::string> get_actor() {return actor;}
        std::vector<std::string> get_row() {return row;}

        void set_year(std::string str_year) {year = str_year;}
        void set_min(std::string str_min) {min = str_min;}
        void set_genre(std::vector<std::string> vec_genre) {genre = vec_genre;}
        void set_actor(std::vector<std::string> vec_actor) {actor = vec_actor;}
        void set_row(std::vector<std::string> vec_row) {row = vec_row;}

    private:
        std::string title, year, min;
        std::vector<std::string> genre, actor, row;
};