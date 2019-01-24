cmake_minimum_required(VERSION 3.13)
project(P_CONC_Labo3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -pthread -lm")

find_package(Threads)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)


set (
        SOURCE_FILES

        main.cpp

        sem.h
        sem.cpp
        displaymandel.h
        displaymandel.cpp
        workerthread.h
        workerthread.cpp
        workerbase.h
        workerbase.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)


