#include "subject.h"

Subject::Subject(std::string subjectName)
:subjectName(subjectName)
{
}



void Subject::setTeacher(std::shared_ptr<Teacher>& teacher)
{
    subjectTeachers.emplace_back(teacher);
    teacher->setSubject(shared_from_this());
}

void Subject::deleteTeacher(std::shared_ptr<Teacher>& teacher)
{
   for (auto it = subjectTeachers.cbegin();it < subjectTeachers.cend(); it++)
    {
        if (it->lock() == teacher)
        {
            subjectTeachers.erase(it);
        }
    }
    teacher->setSubject(nullptr);
}

std::ostream& operator<<(std::ostream& os,const Subject& subject)
{
    os << subject.subjectName << "\n";
    for(auto it = subject.subjectTeachers.cbegin(); it < subject.subjectTeachers.cend(); it++)
    {
        if(auto teacher = it->lock())
        {
            os << *it->lock() << "\n";
        }
    }
    return os;
}