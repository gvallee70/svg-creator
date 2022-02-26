cmake_minimum_required(VERSION 3.17)
project(CPlusPlus)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPlusPlus main.cpp SvgTemplate.cpp SvgTemplate.h Shape/Rectangle.cpp Shape/Rectangle.h IShape.cpp IShape.h Shape/Circle.cpp Shape/Circle.h Shape/Segment.cpp Shape/Segment.h Color.cpp Color.h Point.cpp Point.h Shape/Polygon.cpp Shape/Polygon.h MyCLI.cpp MyCLI.h MyLibrary.cpp MyLibrary.h)