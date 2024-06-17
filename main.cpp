#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


//Classes Implementation
// 1. Student Class -> To store details and selected activities.

class Student {

public:
    string firstname;
    string surname;
    string gender;

    int age;
    int group;

    vector<string> sports;
    vector<string> clubs;

    // Definition of the constructor
    Student(string fn, string sn, string g, int a, int grp)
        : firstname(fn), surname(sn), gender(g), age(a), group(grp) {}
};

//

int main() {


    return 0;
}
