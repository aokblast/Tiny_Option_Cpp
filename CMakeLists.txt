cmake_minimum_required(VERSION 3.9)

project(libOption VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

add_library(libOption SHARED Optional.cpp)
target_include_directories(libOption PRIVATE .)

include(GNUInstallDirs)

install(TARGETS libOption
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
