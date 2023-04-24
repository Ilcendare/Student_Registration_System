cmake_minimum_required(VERSION 3.25)
project(Student_Registration_System C)

set(CMAKE_C_STANDARD 11)

add_executable(Student_Registration_System main.c Linked_List.c Student_Registration.c)
