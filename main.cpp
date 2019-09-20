#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

void addStudent();
void updateStudent();
void deleteStudent();
void displayAllStudents();
void main_menu();

void addStudent()
{

    char studentID[5];
    char studentName[25];
    char studentContactNo[10];
    char studentAddress[100];

    fstream studentDataFile;
    studentDataFile.open("studentData.txt", ios::app);
    cin.ignore();
    cout << " \n Please enter Student ID: ";
    cin.getline(studentID, 5);
    cout << " \n Please enter Student Name: ";
    cin.getline(studentName, 25);
    cout << " \n Please enter Student Contact No: ";
    cin.getline(studentContactNo, 10);
    cout << " \n Please enter Student Address: ";
    cin.getline(studentAddress, 100);
    studentDataFile << studentID << ',' << studentName << ',' << studentContactNo << ',' << studentAddress << '\n';
    cout << "Inserted new record!";
    studentDataFile.close();
    main_menu();
}

void updateStudent()
{
    fstream studentDataFile;
    fstream temp;

    studentDataFile.open("studentData.txt", ios::in);
    temp.open("temp.txt", ios::out);
    char studentID[5];
    char studentName[25];
    char studentContactNo[10];
    char studentAddress[100];
    char updateID[5];
    cin.ignore();
    cout << " \n\t Please Enter the Student ID which you need to update : ";
    cin.getline(updateID, 5);
    while (!studentDataFile.eof())
    {
        studentDataFile.getline(studentID, 5, ',');
        studentDataFile.getline(studentName, 25, ',');
        studentDataFile.getline(studentContactNo, 10, ',');
        studentDataFile.getline(studentAddress, 100);
        if (strcmp(studentID, updateID) == 0)
        {

            cout << " \n\t Please Enter new values for the specific Ice Cream Flavour : \n ";
            cout << " \n Please Enter a value for new Student ID: ";
            cin.getline(studentID, 5);
            cout << " \n Please Enter a value for new Student Name: ";
            cin.getline(studentName, 25);
            cout << " \n Please Enter a value for new Student Contact No: ";
            cin.getline(studentContactNo, 10);
            cout << " \n Please Enter a value for new Student Address: ";
            cin.getline(studentAddress, 100);
            temp << studentID << ',' << studentName << ',' << studentContactNo << ',' << studentAddress << '\n';
        }
        else
        {
            temp << studentID << ',' << studentName << ',' << studentContactNo << ',' << studentAddress << '\n';
        }
    }
    temp.close();
    studentDataFile.close();

    studentDataFile.open("studentData.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {
        temp.getline(studentID, 5, ',');
        temp.getline(studentName, 25, ',');
        temp.getline(studentContactNo, 10, ',');
        temp.getline(studentAddress, 100);
        studentDataFile << studentID << ',' << studentName << ',' << studentContactNo << ',' << studentAddress << '\n';
    }
    temp.close();
    studentDataFile.close();
    cout << "\n Updated Student Record!!! \n";
    main_menu();
}
void deleteStudent()
{

    fstream studentDataFile;
    fstream temp;

    studentDataFile.open("studentData.txt", ios::in);
    temp.open("temp.txt", ios::out);
    char studentID[5];
    char studentName[25];
    char studentContactNo[10];
    char studentAddress[100];

    char deleteID[5];
    cin.ignore();
    cout << " \n\t Please Enter the Student ID which you need to delete : ";
    cin.getline(deleteID, 5);
    while (!studentDataFile.eof())
    {
        studentDataFile.getline(studentID, 5, ',');
        studentDataFile.getline(studentName, 25, ',');
        studentDataFile.getline(studentContactNo, 10, ',');
        studentDataFile.getline(studentAddress, 100);
        if (strcmp(studentID, deleteID) == 0)
        {
            continue;
        }
        else
        {
            temp << studentID << ',' << studentName << ',' << studentContactNo << ',' << studentAddress << '\n';
        }
    }
    temp.close();
    studentDataFile.close();

    studentDataFile.open("studentData.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {
        temp.getline(studentID, 5, ',');
        temp.getline(studentName, 25, ',');
        temp.getline(studentContactNo, 10, ',');
        temp.getline(studentAddress, 100);
        studentDataFile << studentID << ',' << studentName << ',' << studentContactNo << ',' << studentAddress << '\n';
    }
    temp.close();
    studentDataFile.close();
    cout << "\n Deleted Student Record !!! \n";
    main_menu();
}
void displayAllStudents()
{
    ifstream studentDataFile;
    studentDataFile.open("studentData.txt");
    char studentID[5];
    char studentName[25];
    char studentContactNo[10];
    char studentAddress[100];

    if (studentDataFile.fail())
    {
        cout << "Error with your file";
    }
    else
    {
        string data;
        cout << " \n\t Student ID \t Student Name \t Student Phone No. \t Student Address \n";
        while (!studentDataFile.eof())
        {
            studentDataFile.getline(studentID, 5, ',');
            studentDataFile.getline(studentName, 25, ',');
            studentDataFile.getline(studentContactNo, 10, ',');
            studentDataFile.getline(studentAddress, 100);
            cout << "\n \t " << studentID << "\t" << studentName << "\t" << studentAddress << endl;
        }
        studentDataFile.close();
    }
    main_menu();
}

void main_menu()
{
    int option;
    cout << "\n WELCOME TO STUDENT DATA MANAGEMENT \n";
    cout << "\nSelect one of the following:\n\n";
    cout << "    1: Add New Student" << endl;
    cout << "    2: Update Existing Student Details" << endl;
    cout << "    3: Delete Student Record" << endl;
    cout << "    4. View All Student Details" << endl;
    cout << "    5: Logout" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        system("CLS");
        addStudent();
        break;
    case 2:
        system("CLS");
        updateStudent();
        break;

    case 3:
        system("CLS");
        deleteStudent();
        break;

    case 4:
        system("CLS");
        displayAllStudents();
        break;

    default:
        cout << " \n Choose right number \n";
    }
}

int main()
{
    char authenticationDetails[100];
    ifstream loginFile("login.txt");
    string line;
    int number;
    while (number < 3)
    {
        cout << "\n WELCOME TO STUDENT DATA MANAGEMENT \n";
        cout << "\nSelect one of the following:\n\n";
        cout << "    1: Login" << endl;
        cout << "    2: Register" << endl;
        cin >> number;
        if (number == 1)
        {
            bool found;
            string UserName, Password, uname, pword;
            string line = " ";

            cout << "Please enter your username to continue: ";
            cin >> UserName;
            cout << "Please enter your password to continue: ";
            cin >> Password;

            while (getline(loginFile, line))
            {
                stringstream iss(line);
                iss >> uname >> pword;

                if (UserName == uname && Password == pword)
                {
                    found = true;
                    system("CLS");
                    main_menu();
                }
                else
                {
                    cout << "User Name or Password is incorrect. Please check and type again";
                }
            }
        }

        else if (number == 2)
        {
            ofstream file;
            file.open("login.txt", ios::app);
            cout << "Enter the User Name: ";
            cin >> authenticationDetails;
            file << authenticationDetails << "\t";

            cout << "Enter your password: ";
            cin >> authenticationDetails;
            int len = strlen(authenticationDetails);

            while (len < 15)
            {
                authenticationDetails[len] = ',';
                len = len + 1;
            }
            file << authenticationDetails << endl;
            cout << "\n User registration success. Please Login to continue... \n";
        }
    }
}
