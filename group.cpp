#include "group.h"
#include <cinttypes>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

Group::Group(std::string groupName)
:groupName(groupName)
{
}

void Group::addStudent(std::shared_ptr<Student>& student)
{
    students.emplace_back(student);
    student->setGroup(shared_from_this());
}

void Group::setSubject(std::shared_ptr<Subject> subject, std::shared_ptr<Teacher> teacher)
{
    subjects.emplace_back(subject);
    teacher->setGroup(shared_from_this());
}

std::ostream& operator<<(std::ostream& os,const Group& group)
{
    os << group.groupName << "\n";
    for(auto it = group.students.cbegin(); it < group.students.cend(); it++)
    {
        if(auto student = it->lock())
        {
            os << *it->lock() << "\n";
        }
    }
    return os;
}


void Group::deleteStudent(std::shared_ptr<Student>& student)
{
    for (auto it = students.cbegin();it < students.cend(); it++)
    {
        if (it->lock() == student)
        {
            students.erase(it);
        }
    }
    student->setGroup(nullptr);
}

std::string Group::toString()
{
    return groupName;
}