#include "Teacher.h"
#include <memory>
#include <vector>
#pragma once

class Teacher;

/**
 * @brief class Subject
 * 
 */
class Subject:public std::enable_shared_from_this<Subject>
{
    public:

        /**
         * @brief Construct a new Subject object by its name
         * 
         * @param subjectName name of the subject
         */
        Subject(std::string subjectName);

        /**
         * @brief overload << operator
         * 
         * @param os output stream
         * @param subject subject object to put into stream
         * @return std::ostream& stream which contains subject object 
         */
        friend std::ostream& operator<<(std::ostream& os,const Subject& subject);

        /**
         * @brief Set teacher to subject
         * 
         * @param teacher teacher which teaches Subject
         */
        void setTeacher(std::shared_ptr<Teacher>& teacher);

        /**
         * @brief delete Teacher from Subject (Subject may cantains more than 1 teacher)
         * 
         * @param teacher a pointer to Teacher object to delete
         */
        void deleteTeacher(std::shared_ptr<Teacher>& teacher);

    private:

    std::vector<std::weak_ptr<Teacher>> subjectTeachers;

    const std::string subjectName;

};