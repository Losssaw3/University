#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>


class Group;

/**
 * @brief class Student
 * 
 */
class Student
{
    public:

        /**
         * @brief Construct a new Student object
         * 
         * @param studentName student's name
         * @param studentAge student's age
         * @param recordBookNumber students's recordBookNumber
         */
        Student(std::string studentName,size_t studentAge, size_t recordBookNumber);

        /**
         * @brief Set the Group object to student
         * 
         * @param group pointer to the group to which the student belongs
         */
        void setGroup(std::shared_ptr<Group> group);

        /**
         * @brief Get the Group object
         * 
         * @return std::shared_ptr<Group> a pointer to the group to which the student belongs
         */
        std::shared_ptr<Group> getGroup();

        /**
         * @brief overload << operator
         * 
         * @param os output stream
         * @param student student object to put into stream
         * @return std::ostream& stream which contains student object
         */
        friend std::ostream& operator<<(std::ostream& os, const Student& student);
        
    private:
        std::shared_ptr<Group> group;

        std::string studentName;

        size_t age;
    
        size_t recordBookNumber;

};