#include <iostream>
#include <string>

class Teacher
{
public:
    Teacher( std::string Name, std::string Expert )
    {
        name = Name;
        expert = Expert;
    }
    void introduce(){
        std::cout << name << "会" << expert << "\n";
    }

private:
    std::string name;
    std::string expert;
};

class Student
{
public:
    Student( std::string Name, std::string Study )
    {
        name = Name;
        study = Study;
    }

private:
    std::string name;
    std::string study;
};

class TchStud : public Teacher, public Student
{
public:
    TchStud(std::string Name, std::string Study, std::string Expert) : Teacher(Name, Expert), Student(Name, Study)
    {
    }

    void introduce()
    {
        std::cout << name << "在学" << study << ", 也会" << expert << "\n";
    }
};

int main()
{
    Teacher teacher("HTY", "python");
    TchStud genius("ZXA", "C", "python");
    teacher.introduce();
    genius.introduce();
}
