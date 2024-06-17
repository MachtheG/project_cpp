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

//Activity Class
class Activity{
public:
    string name;
    int max_capacity;
    vector<Student> students;

    Activity(string n, int cap) : name(n), max_capacity(cap) {}

    bool addStudent(const Student& student){
        if (students.size() < max_capacity){
            students.push_back(student);
            return true;
        }
        return false;
    }

    int getRemainingCapacity() {
        return max_capacity - students.size();

    }
};

vector<Student> students;
vector<Activity> sports;
vector<Activity> clubs;

void initializeActivities() {
    //Initialize sports
    sports.emplace_back("Rugby", 20);
    sports.emplace_back("Athletics", 20);
    sports.emplace_back("Swimming", 20);
    sports.emplace_back("Football", 20);

    //Initialize clubs
    clubs.emplace_back("Journalism Club", 60);
    clubs.emplace_back("Red Cross Society", 60);
    clubs.emplace_back("AISEC", 60);
    clubs.emplace_back("Business Club", 60);
    clubs.emplace_back("Computer Science Club", 60);


}


