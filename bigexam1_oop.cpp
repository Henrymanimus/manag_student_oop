#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*------------------------------MANAGE STUDENT-------------------------------*/

// Create student class
class Student
{
public:
    int id;
    string name;
    vector<float> scoreList;

    Student(int id, string name, vector<float> scoreList)
    {
        this->id = id;
        this->name = name;
        this->scoreList = scoreList;
    }
};
/*------------------------------MANAGE STUDENT-------------------------------*/
// Create class of the school

class classRoom
{
private:
    int classID;
    string className;

public:
    classRoom(int id, string name) : classID(id), className(name) {}

    int getClassID() const
    {
        return classID;
    }

    void setClassID(int id)
    {
        classID = id;
    }

    string getClassName() const
    {
        return className;
    }

    void setClassName(const string &name)
    {
        className = name;
    }
};

// All fuctuon in the school

class School
{
public:
    // generic
    vector<Student *> studentList;
    vector<classRoom *> classList;

    School()
    {
    }

    // Add student
    void addStudent()
    {
        string name;
        vector<float> scores(3);

        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        // enter point
        cout << "Enter Math score: ";
        cin >> scores[0];
        cout << "Enter Literature score: ";
        cin >> scores[1];
        cout << "Enter English score: ";
        cin >> scores[2];

        if (studentList.empty())
        {
            int firstID = 0;
            studentList.push_back(new Student(firstID, name, scores));
        }
        else
        {
            Student *lastStudent = studentList.back();
            int lastStudentID = lastStudent->id;
            int newID = lastStudentID + 1;
            studentList.push_back(new Student(newID, name, scores));
        }

        cout << "input successfully" << endl;
    }

    // show student
    void showStudent()
    {
        if (studentList.empty())
        {
            cout << "List is empty. Please add student" << endl;
            return;
        }

        for (int i = 0; i < studentList.size(); ++i)
        {
            cout << "ID: " << studentList[i]->id << ", ";
            cout << "student name: " << studentList[i]->name << ", ";
            cout << "Math: " << studentList[i]->scoreList[0] << ", ";
            cout << "Literature: " << studentList[i]->scoreList[1] << ", ";
            cout << "English: " << studentList[i]->scoreList[2] << endl;
        }
    }

    // remove student
    void removeStudent()
    {
        int enterID;
        cout << "Enter ID student you want to erase: ";
        cin >> enterID;

        for (int i = 0; i < studentList.size(); ++i)
        {
            if (studentList[i]->id == enterID)
            {
                studentList.erase(studentList.begin() + i);
                cout << "Student has ID: " << enterID << " is erased success" << endl;
            }
            else
            {
                cout << "student not exist in the list";
            }
        }
    }

    // UpdateStudent
    void updateStudent()
    {
        int enterID;
        cout << "Enter student ID you want to update: ";
        cin >> enterID;

        for (int i = 0; i < studentList.size(); ++i)
        {
            if (studentList[i]->id == enterID)
            {
                string newName;
                int newScore;
                vector<float> newStudentScores(3);

                cout << "Enter new student name: " << endl;
                cin.ignore();
                getline(cin, newName);
                if (!newName.empty())
                {
                    studentList[i]->name = newName;
                }

                cout << "Enter new Math score: ";
                cin >> newScore;
                newStudentScores[0] = newScore;

                cout << "Enter new Literature score: ";
                cin >> newScore;
                newStudentScores[1] = newScore;

                cout << "Enter new English score: ";
                cin >> newScore;
                newStudentScores[2] = newScore;

                studentList[i]->scoreList = newStudentScores;

                cout << "Student information updated successfully.\n";
                return;
            }
        }

        cout << "Student not found in the list.\n";
    }

    // Search student
    void searchStudent()
    {
        string name;
        cout << "Enter student name you want to find: ";
        cin.ignore();
        getline(cin, name);

        for (int i = 0; i < studentList.size(); ++i)
        {
            int sum = 0;
            if (studentList[i]->name == name)
            {
                cout << "ID: " << studentList[i]->id << ", ";
                cout << "student name: " << studentList[i]->name << ", ";
                cout << "Math: " << studentList[i]->scoreList[0] << ", ";
                cout << "Literature: " << studentList[i]->scoreList[1] << ", ";
                cout << "English: " << studentList[i]->scoreList[2] << endl;
                // Average point
                double average = (studentList[i]->scoreList[0] + studentList[i]->scoreList[1] + studentList[i]->scoreList[2]) / 3.0;
                cout << "Average: " << average << endl;
                return;
            }
        }
        cout << "student not exist in the list" << endl;
    }

    //----------------------Create class-----------------------//
    // Add class
    void addClass()
    {
        string className;
        int newID = classList.empty() ? 0 : classList.back()->getClassID() + 1;

        cout << "Enter class name: ";
        cin.ignore();
        getline(cin, className);

        classList.push_back(new classRoom(newID, className));
        cout << "Class added successfully." << endl;
    }

    // Show class
    void showClass()
    {
        if (classList.empty())
        {
            cout << "No classes available." << endl;
            return;
        }
        for (int i = 0; i < classList.size(); ++i)
        {
            cout << "Class ID: " << classList[i]->getClassID() << ", ";
            cout << "Class Name: " << classList[i]->getClassName() << endl;
        }
    }
};

int main()
{
    School *school = new School();
    // Menu program
    char option;
    cout << "------School Program------" << endl;
    cout << "1. Manage student" << endl;
    cout << "2. Manage classes" << endl;
    cout << "q. Quit" << endl;

    while (true)
    {
        cout << "Enter your option: ";
        cin >> option;
        option = tolower(option);
        bool isQuitProgram = false;
        switch (option)
        {
        case '1':
            char optionManageStudent;
            cout << "Manage student" << endl;
            cout << "1. Show student" << endl;
            cout << "2. Add student" << endl;
            cout << "3. Remove student" << endl;
            cout << "4. Update student" << endl;
            cout << "5. Search student by name" << endl;
            cout << "6. View top students" << endl;
            cout << "7. View failed students" << endl;
            cout << "q. Quit" << endl;
            while (true)
            {
                cout << "Enter you option: ";
                cin >> optionManageStudent;
                optionManageStudent = tolower(optionManageStudent);
                bool isQuitManageStudentProgram = false;
                switch (optionManageStudent)
                {
                case '1':
                    school->showStudent();
                    break;
                case '2':
                    school->addStudent();
                    break;
                case '3':
                    school->removeStudent();
                    break;
                case '4':
                    school->updateStudent();
                    break;
                case '5':
                    school->showStudent();
                    break;
                case '6':
                    int enterTopStudent;
                    cout << "Enter number of top you want to show: ";
                    cin >> enterTopStudent;
                    int enterSubject;
                    cout << "Enter which subject you want to show (0: Math, 1: Literature, 2: English, 3: Average): ";
                    cin >> enterSubject;
                    // showTopStudent(studentName, studentScores, enterTopStudent, enterSubject);
                    break;
                case '7':
                    // showStudentsBelowAverage(studentName, studentScores);
                    break;
                case 'q':
                    cout << "Existing manage student program. Turn back to homepage" << endl;
                    isQuitManageStudentProgram = true;
                    break;

                default:
                    cout << "Invalid option" << endl;
                    break;
                }
                if (isQuitManageStudentProgram)
                {
                    cout << "------School Program------" << endl;
                    cout << "1. Manage student" << endl;
                    cout << "2. Manage classes" << endl;
                    cout << "q. Quit" << endl;
                    break;
                }
            }

            break;

        case '2':
            char optionManageClass;
            cout << "Manage Class" << endl;
            cout << "1. Show Class" << endl;
            cout << "2. Add Class" << endl;
            cout << "3. Remove Class" << endl;
            cout << "4. Update Class" << endl;
            cout << "5. Search Class by name" << endl;
            cout << "5. View student list of a class" << endl;
            cout << "5. View Top Class" << endl;
            cout << "q. Quit" << endl;
            while (true)
            {
                cout << "Enter you option: ";
                cin >> optionManageClass;
                optionManageClass = tolower(optionManageClass);
                bool isQuitManageClassProgram = false;
                switch (optionManageClass)
                {
                case '1':
                    school->showClass();
                    break;
                case '2':
                    school->addClass();
                    break;
                case '3':
                    // removeClass(className);
                    break;
                case '4':
                    // updateClass(className);
                    break;
                case '5':
                    // searchClass(className);
                    break;
                case '6':
                    // show top student
                    break;
                case 'q':
                    cout << "Existing manage class program. Turn back to homepage" << endl;
                    isQuitManageClassProgram = true;
                    break;

                default:
                    cout << "Invalid option" << endl;
                    break;
                }
                if (isQuitManageClassProgram)
                {
                    cout << "------School Program------" << endl;
                    cout << "1. Manage student" << endl;
                    cout << "2. Manage classes" << endl;
                    cout << "q. Quit" << endl;
                    break;
                }
            }
            break;

        case 'q':
            cout << "Existing...";
            isQuitProgram = true;
            // write in DB
            // ouputStudentList(studentName, studentScores);
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }
        if (isQuitProgram)
        {
            break;
        }
    }

    return 0;
}