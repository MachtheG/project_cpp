#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Classes Implementation
// 1. Student Class -> To store details and selected activities.

class Student {
public:
    // Variable declaration
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

// Activity Implementation
// 2. Activity Class -> To store details for students
class Activity {
public:
    string name;
    int max_capacity;
    vector<Student> students;

    Activity(string n, int cap) : name(std::move(n)), max_capacity(cap) {}

    bool addStudent(const Student& student) {
        if (students.size() < max_capacity) {
            students.push_back(student);
            return true;
        }
        return false;
    }

    int getRemainingCapacity() const {
        return max_capacity - students.size();
    }
};

// Global list
vector<Student> students;
vector<Activity> sports;
vector<Activity> clubs;

void initializeActivities() {
    // Initialize sports
    sports.emplace_back("Rugby", 20);
    sports.emplace_back("Athletics", 20);
    sports.emplace_back("Swimming", 20);
    sports.emplace_back("Soccer", 20); // Corrected "Football" to "Soccer" for consistency

    // Initialize clubs
    clubs.emplace_back("Journalism Club", 60);
    clubs.emplace_back("Red Cross Society", 60);
    clubs.emplace_back("AISEC", 60);
    clubs.emplace_back("Business Club", 60);
    clubs.emplace_back("Computer Science Club", 60);
}

// Function to add a student and their activities
void addStudent() {
    string firstname, surname, gender;
    int age, group;
    vector<string> selectedSports;
    vector<string> selectedClubs;

    cout << "Enter Firstname: ";
    cin >> firstname;
    cout << "Enter Surname: ";
    cin >> surname;
    cout << "Enter Gender (Male/Female): ";
    cin >> gender;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter Group (1, 2 or 3): ";
    cin >> group;

    // Ask if the student wants to participate in sports
    cout << "Do you want to participate in sports? (yes/no): ";
    string participateInSports;
    cin >> participateInSports;

    if (participateInSports == "yes") {
        // Allow selection of one sport
        while (selectedSports.size() < 1) {
            cout << "Select a sport (Rugby, Athletics, Swimming, Soccer): ";
            string sport;
            cin >> sport;
            bool found = false;
            for (auto& s : sports) {
                if (s.name == sport && s.getRemainingCapacity() > 0) {
                    s.addStudent({firstname, surname, gender, age, group});
                    selectedSports.push_back(sport);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Sport not found or full. Please try again.\n";
            }
        }

        // Allow selection of up to two clubs
        while (selectedClubs.size() < 2) {
            cout << "Select a club (Journalism Club, Red Cross Society, AISEC, Business Club, Computer Science Club): ";
            string club;
            cin >> club;
            bool found = false;
            for (auto& c : clubs) {
                if (c.name == club && c.getRemainingCapacity() > 0) {
                    c.addStudent({firstname, surname, gender, age, group});
                    selectedClubs.push_back(club);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Club not found or full. Please try again.\n";
            }
        }
    } else {
        // Allow selection of up to three clubs if no sport is selected
        while (selectedClubs.size() < 1 || selectedClubs.size() > 3) {
            cout << "Select up to 3 clubs (Journalism Club, Red Cross Society, AISEC, Business Club, Computer Science Club): ";
            string club;
            cin >> club;
            bool found = false;
            for (auto& c : clubs) {
                if (c.name == club && c.getRemainingCapacity() > 0) {
                    c.addStudent({firstname, surname, gender, age, group});
                    selectedClubs.push_back(club);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Club not found or full. Please try again.\n";
            }
            if (selectedClubs.size() >= 1 && selectedClubs.size() <= 3) {
                break;
            }
        }
    }

    // Create a new student object and add it to the global students vector
    Student newStudent(firstname, surname, gender, age, group);
    newStudent.sports = selectedSports;
    newStudent.clubs = selectedClubs;
    students.push_back(newStudent);

    cout << "Student added successfully!\n";
}

// Function to view all students and their activities
void viewStudents() {
    for (const auto& student : students) {
        cout << student.firstname << " " << student.surname << " (" << student.gender << ", " << student.age << ", Group " << student.group << ")";
        if (!student.sports.empty()) {
            cout << " - Sports: ";
            for (const auto& sport : student.sports) {
                cout << sport << " ";
            }
        }
        if (!student.clubs.empty()) {
            cout << " - Clubs: ";
            for (const auto& club : student.clubs) {
                cout << club << " ";
            }
        }
        cout << endl;
    }
}

// Function to view activities
void viewActivities(const vector<Activity>& activities) {
    for (const auto& activity : activities) {
        cout << activity.name << " (Remaining capacity: " << activity.getRemainingCapacity() << ")\n";
    }
}

// Function to save students' data to a file
void saveToFile(const string& filename) {
    ofstream file(filename);
    for (const auto& student : students) {
        file << student.firstname << "," << student.surname << "," << student.gender << "," << student.age << "," << student.group;
        for (const auto& sport : student.sports) {
            file << "," << sport;
        }
        for (const auto& club : student.clubs) {
            file << "," << club;
        }
        file << "\n";
    }
    file.close();
    cout << "Data saved to " << filename << "\n";
}

int main() {
    initializeActivities(); // Initialize the activities
    int choice;

    // Main menu loop
    while (true) {
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. View Clubs / Societies\n";
        cout << "4. View Sports\n";
        cout << "5. Save all Files\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(); // Add a new student
                break;
            case 2:
                viewStudents(); // View all students
                break;
            case 3:
                viewActivities(clubs); // View clubs/societies
                break;
            case 4:
                viewActivities(sports); // View sports
                break;
            case 5:
                saveToFile("students.csv"); // Save data to file
                break;
            case 6:
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
