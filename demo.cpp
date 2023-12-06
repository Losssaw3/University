#include "group.h"
#include <iostream>
#include <memory>
#include "subject.h"

int main()
{
    Student s1("Bailo Andrei",20,3214324);
    Student s2("Ba Aei",21,3214342);
    std::shared_ptr<Student> sharedStudent1 = std::make_shared<Student>(s1);
    std::shared_ptr<Student> sharedStudent2 = std::make_shared<Student>(s2);
    Group g1("TKI");
    std::shared_ptr<Group> gg = std::make_shared<Group>(g1);
    gg->addStudent(sharedStudent2);
    gg->addStudent(sharedStudent1);
    std::cout << *gg;
    gg->deleteStudent(sharedStudent2);
    

    Teacher t1("Riadnov Aleksand Vasilievich" , "Doctor");
    Teacher t2("Platonova ov" , "Doctor");
    std::shared_ptr<Teacher> sharedTeacher1 = std::make_shared<Teacher>(t1);
    std::shared_ptr<Teacher> sharedTeacher2 = std::make_shared<Teacher>(t2);
    Subject subj1("Math");
    std::shared_ptr<Subject> sharedSubject = std::make_shared<Subject>(subj1);
    sharedSubject->setTeacher(sharedTeacher1);
    sharedSubject->setTeacher(sharedTeacher2);
    std::cout <<"\n" << *sharedSubject;

    gg->setSubject(sharedSubject, sharedTeacher2);
    sharedTeacher2->showGroup();
    std::cout << gg << "\n";
    sharedTeacher2->showGroup();
    return 0;
}