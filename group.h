#include "student.h"
#include <initializer_list>
#include <memory>
#include <algorithm>
//include "subject.h"

class Student;
class Group
: public std::enable_shared_from_this<Group>
{
    public:

    friend std::ostream& operator<<(std::ostream& os,const Group& group);

    Group(std::string groupName);

    void addStudent(std::shared_ptr<Student>& student);

    void deleteStudent(std::shared_ptr<Student>& student);
       
    private:
    std::vector<std::weak_ptr<Student>> students;

    std::string groupName;

    
    /*std::vector<Subject> subjects;*/
};