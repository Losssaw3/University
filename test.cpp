#include <cstddef>
#include <iostream>
#include "group.h"
#include "group.cpp"
#include "student.h"
#include "student.cpp"
#include "subject.h"
#include "subject.cpp"
#include "Teacher.h"
#include "Teacher.cpp"
#include <gtest/gtest.h>
#include <memory>

class Student;

class Teacher;

class Subject;

class Group;

/**
 * Tests consist of 3 parts
 1) create a object and use some method
 2) create actual and expected values
 3) ASSERT
 * 
 */
 
TEST(GroupMetodsTest, addStudentTets)
{
    Group defaultGroup ("TKI");
    Student defaultStudent("Ivan" , 20 , 1234);
    std::shared_ptr<Student> defaultSharedStudent = std::make_shared<Student>(defaultStudent);
    std::shared_ptr<Group> defaultSharedGroup = std::make_shared<Group>(defaultGroup);

    defaultSharedGroup->addStudent(defaultSharedStudent);

    std::shared_ptr<Group> actual = defaultSharedGroup;

    std::shared_ptr<Group> expected = defaultSharedStudent->getGroup();

    ASSERT_EQ(actual, expected);
}

TEST(GroupMetodsTest, deleteStudentTest)
{
     Group defaultGroup ("TKI");
    Student defaultStudent("Ivan" , 20 , 1234);
    std::shared_ptr<Student> defaultSharedStudent = std::make_shared<Student>(defaultStudent);
    std::shared_ptr<Group> defaultSharedGroup = std::make_shared<Group>(defaultGroup);

    defaultSharedGroup->addStudent(defaultSharedStudent);
    defaultSharedGroup->deleteStudent(defaultSharedStudent);

    std::shared_ptr<Group> actual = defaultSharedStudent->getGroup();

    std::shared_ptr<Group> expected = nullptr;

    std::string actualStr = defaultSharedGroup->toString();
    std::string expectedStr = "TKI";

    ASSERT_EQ(actual, expected);
    ASSERT_EQ(actualStr, expectedStr);
}

TEST(GroupMetodsTest, setSubjectTest)
{
    Teacher defaultTeacher("IvanIvanovich", "Doctor");
    Group defaultGroup ("TKI");
    Subject defaultSubject("Math");
    std::shared_ptr<Teacher> defaultSharedTeacher = std::make_shared<Teacher>(defaultTeacher);
    std::shared_ptr<Subject> defaultSharedSubject = std::make_shared<Subject>(defaultSubject);
    std::shared_ptr<Group> defaultSharedGroup = std::make_shared<Group>(defaultGroup);

    defaultSharedSubject->setTeacher(defaultSharedTeacher);

    defaultSharedGroup->setSubject(defaultSharedSubject, defaultSharedTeacher);

    std::shared_ptr<Group> actual = defaultSharedGroup;

    std::shared_ptr<Group> expected = defaultSharedGroup;

    ASSERT_EQ(actual, expected);

}

TEST(SubjectMetodsTest, setTeacherTest)
{
    Teacher defaultTeacher("IvanIvanovich", "Doctor");
    Subject defaultSubject("Math");
    std::shared_ptr<Teacher> defaultSharedTeacher = std::make_shared<Teacher>(defaultTeacher);
    std::shared_ptr<Subject> defaultSharedSubject = std::make_shared<Subject>(defaultSubject);

    defaultSharedSubject->setTeacher(defaultSharedTeacher);

    std::shared_ptr<Subject> actual = defaultSharedTeacher->getSubject();

    std::shared_ptr<Subject> expected = defaultSharedSubject;

    ASSERT_EQ(actual, expected);
}

TEST(SubjectMetodsTest, deleteTeacherTest)
{
    Teacher defaultTeacher("IvanIvanovich", "Doctor");
    Subject defaultSubject("Math");
    std::shared_ptr<Teacher> defaultSharedTeacher = std::make_shared<Teacher>(defaultTeacher);
    std::shared_ptr<Subject> defaultSharedSubject = std::make_shared<Subject>(defaultSubject);

    defaultSharedSubject->setTeacher(defaultSharedTeacher);

    defaultSharedSubject->deleteTeacher(defaultSharedTeacher);

    std::shared_ptr<Subject> actual = defaultSharedTeacher->getSubject();

    std::shared_ptr<Subject> expected = nullptr;

    ASSERT_EQ(actual, expected);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}