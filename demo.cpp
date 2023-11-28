#include "group.h"
#include <iostream>
#include <memory>

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
    std::cout << *gg;
    std::cout << sharedStudent2->getGroup();
    return 0;
}