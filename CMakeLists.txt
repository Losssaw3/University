cmake_minimum_required(VERSION 3.10)

project(University)

# List your source files excluding demo.cpp
set(SOURCE_FILES
/home/losaw3/Desktop/programming/University/Teacher.cpp
/home/losaw3/Desktop/programming/University/subject.cpp
/home/losaw3/Desktop/programming/University/student.cpp
/home/losaw3/Desktop/programming/University/group.cpp
)

# Add executable and include demo.cpp
add_executable(demo demo.cpp ${SOURCE_FILES})

# Include headers
target_include_directories(demo PUBLIC include)