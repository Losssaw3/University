#include <iostream>
#include <memory>
#include <string>
#include <vector>


class Group;

class Student
{
    public:
        Student(std::string studentName,size_t studentAge, size_t recordBookNumber);
    
        void setGroup(std::shared_ptr<Group> group);

        std::shared_ptr<Group> getGroup();

        friend std::ostream& operator<<(std::ostream& os, const Student& student);
    private:
        std::shared_ptr<Group> group;

        std::string studentName;

        size_t age;
    
        size_t recordBookNumber;

};