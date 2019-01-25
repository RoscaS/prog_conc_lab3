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
        helpers.h

        sem.h
        sem.cpp
        workerbase.h
        workerbase.cpp
        master.h
        master.cpp
        workerthread.h
        workerthread.cpp
        displaymandel.h
        displaymandel.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)


