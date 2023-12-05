#include "Teacher.h"

Teacher::Teacher(std::string name, std::string graduate)
:teacherName(name) , graduate(graduate), subject(nullptr)
{
}

std::shared_ptr<Subject> Teacher::getSubject()
{
    return this->subject;
}

void Teacher::setSubject(std::shared_ptr<Subject> subject)
{
    this->subject = subject;
}

void Teacher::setGroup(std::shared_ptr<Group> group)
{
    this->groups.emplace_back(group);
}

std::ostream& operator<<(std::ostream& os, const Teacher& teacher)
{
    return os << teacher.teacherName;
}

void Teacher::showGroup()
{
    for(auto it = groups.cbegin(); it < groups.cend(); it++)
    {
    }
}