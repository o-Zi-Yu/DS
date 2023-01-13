#include <iostream>
#include <string>

class Animal{
    public:
        Animal();
        Animal(std::string name);
        
        // float setweight() const;
        // monkey.setweight() = 10.0;
        std::string getname() const;
        void setname();

        void setWeight(float weight);
        bool onland() const;
        bool inwater() const;
        bool eatmeat() const;
        bool eatplant() const;
        bool omnivore() const;
        bool amphibious() const;

    private:
        float weight;

    

};   