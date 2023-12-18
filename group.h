#include "student.h"
#include <initializer_list>
#include <memory>
#include <string>
#include <algorithm>
#include "subject.h"
#pragma once

class Subject;

class Student;

/**
 * @brief class Group
 * 
 */
class Group

: public std::enable_shared_from_this<Group>
{
    public:

    /**
     * @brief Construct a new Group object
     * 
     * @param groupName group's name 
     */
    Group(std::string groupName);

    /**
     * @brief function which adds student to the group 
     * 
     * @param student pointer to student object to add
     */
    void addStudent(std::shared_ptr<Student>& student);

    /**
     * @brief function which deletes student from group
     * 
     * @param student pointer to student object to delete
     */
    void deleteStudent(std::shared_ptr<Student>& student);

    /**
     * @brief Set the Subject object to the group
     * 
     * @param subject pointer to subject object which to set
     * @param teacher pointer to teacher object whict to set
     */
    void setSubject(std::shared_ptr<Subject> subject, std::shared_ptr<Teacher> teacher);

    /**
     * @brief function which convert group object to std::string
     * 
     * @return std::string group object
     */
    std::string toString();

    /**
     * @brief overload << operator
     * 
     * @param os output stream
     * @param group group object to put into stream
     * @return std::ostream& stream which contains group object
     */
    friend std::ostream& operator<<(std::ostream& os,const Group& group);
       
    private:
    std::vector<std::weak_ptr<Student>> students;

    std::string groupName;
    
    std::vector<std::weak_ptr<Subject>> subjects;
};