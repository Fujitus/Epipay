cmake_minimum_required(VERSION 3.6)
project(Epipay)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES
        "src/*.cpp"
        "include/*.hpp"
        "include/*.hh")
	
include_directories(include)
add_executable(Epipay ${SOURCE_FILES} src/Keyboard.cpp include/Keyboard.hh src/RegisterUi.cpp include/RegisterUi.hh src/NfcReader.cpp include/NfcReader.hh)
