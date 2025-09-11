#include <iostream>

class Rama{
    private:
    int id;
    string name;
    int maxC;
    string career;
    string jefe;
    
    public:
    Rama(int id, string name, int maxC, string career, string jefe);
    int getId();
    string getName();
    int getMaxC();
    string getCareer();
}