cmake_minimum_required(VERSION 3.0.0)
project(picture_extract VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
add_executable(picture_extract main.cpp)
target_link_libraries(picture_extract ${OpenCV_LIBS})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
