#include <string>
#include <iostream>
#include <memory>
#include <vector>

class Subject;

class Group;

/**
 * @brief class Teacher
 * 
 */
class Teacher
{
    public:
        /**
         * @brief Construct a new Teacher object
         * 
         * @param name teacher's name 
         * @param graduate teacher's graduate
         */
        Teacher(std::string name, std::string graduate);

        /**
         * @brief Get the Subject object taught by the teacher
         * 
         * @return std::shared_ptr<Subject> a pointer to subject object 
         */
        std::shared_ptr<Subject> getSubject();

        /**
         * @brief Set the Subject object taught by the teacher
         * 
         * @param subject pointer to Subject object to teach
         */
        void setSubject(std::shared_ptr<Subject> subject);

        /**
         * @brief Set the Group object taught by the teacher
         * 
         * @param group pointer to group object to teach
         */
        void setGroup(std::shared_ptr<Group> group);

        /**
         * @brief overload << operator
         * 
         * @param os output stream
         * @param teacher teacher object to put into stream
         * @return std::ostream& stream which contains teacher object
         */
        friend std::ostream& operator<<(std::ostream& os, const Teacher& teacher);

        /**
         * @brief function which displays groups taught by Teacher
         * 
         */
        void showGroup();
    
    private:
        
        std::shared_ptr<Subject> subject;
    
        const std::string teacherName;

        std::string graduate;

        std::vector<std::shared_ptr<Group>> groups;
};