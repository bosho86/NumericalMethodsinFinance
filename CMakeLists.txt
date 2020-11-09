cmake_minimum_required(VERSION 3.15)
project(Volatility)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS"-g")

include_directories(EuroCall)

add_executable(Volatility src/Volatility)
add_library(EuroCall EuroCall/EuroCall.cpp)


include_directories(include)
include_directories(src)

find_library(EuroCall EuroCall EuroCall)
target_link_libraries(Volatility EuroCall)
