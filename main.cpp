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

void addStudent(){
    string firstname, surname, gender;
    int age, group;

    cout << "Enter Firstname: \t" << endl;
    cin >> firstname;
    cout << "Enter Surname: \t" << endl;
    cin >> surname;
    cout << "Enter Gender (Male/Female): \t" << endl;
    cin >> gender;
    cout << "Enter age: \t" << endl;
    cin >> age;
    cout << "Enter Group (1, 2 or 3): \t" << endl;
    cin >> group;

    Student newStudent(firstname, surname, gender, age, group);
    students.push_back(newStudent);

    cout << "Student added successfully!\n";
}

void viewStudents(){
    for (const auto& student : students) {
        cout << student.firstname << "  " << student.surname << "  " << student.gender << "  " << student.age << ", Group " << student.group << ")\n";
    }
}

void viewActivities(const vector<Activity>& activities) {
    for (const auto& activity : activities) {
       // cout << activity.name << " (Remaining capacity: " << activity.getRemainingCapacity() << ")\n";
    }
}

//void saveToFile(const string& filename) {
//    ofstream file(filename);
//    for (const auto& student : students) {
//        file << student.firstname << "," << student.surname << "," << student.gender << "," << student.age << "," << student.group << "\n";
//    }
//    file.close();
//    cout << "Data saved to " << filename << "\n";
//}

int main(){
    initializeActivities();
    int choice;

    while(true){
        cout <<"1. Add Student \n";
        cout <<"2. View Students \n";
        cout <<"3. View Clubs / Societies \n";
        cout <<"4. View Sports \n";
        cout <<"5. Save all Files \n";
        cout <<"6. Exit \n";
        cout <<"Enter choice: ";
        cin >> choice;

        switch (choice)
switch (choice){
            case 1:
                addStudent();
        break;

    case 2:
                viewStudents();
        break;

    case 3:
                viewActivities(clubs);
        break;

    case 4:
                viewActivities(sports);
        break;

//            case 5:
//                saveToFile("students.csv");
//        break;
            case 6:
                return 0;
    default:
        cout << "Invalid choice. Please try again. \n";

        }
    }
}






