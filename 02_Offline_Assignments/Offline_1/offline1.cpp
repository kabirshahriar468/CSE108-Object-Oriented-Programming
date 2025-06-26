#include<iostream>
#include<cstdlib>
#include<cstring>
#define N 1200

using namespace std;

class Student
{
private:

    char *studentName;
    int id=0;
    float credit=0.0,cgpa=0.0;

public:

    Student(const char *name,int ID,float CREDIT,float CGPA)
    {
        int length=strlen(name);
        studentName=(char*) malloc(sizeof(char)*(length+1));
        strcpy(studentName,name);
        id=ID;
        credit=CREDIT;
        cgpa=CGPA;
    }

    ~Student()
    {
        free(studentName);
    }

    void showInfo()
    {
        cout<<"Name: "<<studentName<<','<<" Id: "<<id<<','<<" Credit Completed: "<<credit<<','<<" Cgpa: "<<cgpa<<endl;
    }

    void change(const char *name)
    {
        free(studentName);
        int length=strlen(name);
        studentName=(char*)malloc(sizeof(char)*(length+1));
        strcpy(studentName,name);
    }

    void change(int ID)
    {
        id=ID;
    }


    void addTermResult(float CREDIT,float CGPA)
    {
        float temp=credit;
        credit+=CREDIT;
        cgpa=((cgpa*temp)/credit+(CREDIT*CGPA)/credit);
    }



};

class Batch
{
private:
    int index=0;
    Student *student;
public:
    Batch()
    {
        student=(Student*)malloc(sizeof(Student)*N);
    }
    ~Batch()
    {
        free(student);
    }

    void addStudent(Student &STUDENT)
    {
        student[index]=STUDENT;
        index++;
    }

    void showAllStudents()
    {
        for(int i=0;i<index;i++)
        {
            student[i].showInfo();
        }
    }
};











int main()
{
// Part 1
    /*A student class holds the information of the
    student name, id, credit earned so far, and
    cumulative gpa (cgpa)*/
    /*The name of a student is stored using malloc,
    which will be freed during destruction*/
    Student s1("Tamim Iqbal", 1905131, 39, 3.56);
    Student s2("Liton Das", 1905150, 39, 3.52);
    s1.showInfo();
    cout<<"Changing the name of s1"<<endl;
    /*During changing the name, you should reallocate
    memory of the new name and free the previously
    allocated memory*/
    s1.change("Tamim Iqbal Khan");
    s1.showInfo();
    cout<<"Changing the id of s2"<<endl;
    s2.change(1905149);
    s2.showInfo();
    cout<<"Adding a term result of s1"<<endl;
    /*The first argument of addTermResult is the credit
    earned in a term and second one is the gpa obtained
    in that term*/
    s1.addTermResult(19, 3.85);
    s1.showInfo();
// Part 2
    /*Batch contains a list of students*/
    /*During construction, a Batch object allocates dynamic
    memory for 1200 students using malloc. The memory will
    be freed during destruction*/
    Batch b;
    b.addStudent(s1);
    b.addStudent(s2);
    cout<<"Printing the list of students of the batch b"<<endl;
    b.showAllStudents();
}









