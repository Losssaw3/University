cmake_minimum_required(VERSION 3.10)

project(University)

# List your source files excluding demo.cpp
set(SOURCE_FILES
Teacher.cpp
subject.cpp
student.cpp
group.cpp
)

# Add executable and include demo.cpp
add_executable(demo demo.cpp ${SOURCE_FILES})

# Include headers
target_include_directories(demo PUBLIC include)