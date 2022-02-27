cmake_minimum_required(VERSION 3.17)
project(CPlusPlus)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPlusPlus main.cpp SvgTemplate.h Shape/Rectangle.cpp Shape/Rectangle.h IShape.h Shape/Circle.cpp Shape/Circle.h Shape/Segment.cpp Shape/Segment.h Color.h Point.h Shape/Polygon.cpp Shape/Polygon.h MyCLI.h MyLibrary.h)