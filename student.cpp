#include "student.h"
#include <exception>


Student::Student(std::string studentName,size_t studentAge, size_t recordBookNumber)
:studentName(studentName) , age(studentAge) , recordBookNumber(recordBookNumber) , group(nullptr)
{
}

void Student::setGroup(std::shared_ptr<Group> group)
{
    this->group = group;
}

std::ostream& operator<<(std::ostream& os, const Student& Student)
{
    os << Student.studentName << "\t" << Student.age << "\t" << Student.recordBookNumber;
    return os;
}

std::shared_ptr<Group> Student::getGroup()
{
    return group;
}