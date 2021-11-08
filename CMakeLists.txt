# Add .cpp files in the project root directory as source files
set(SOURCE_FILES src/main.cpp src/Card.cpp src/Deck.cpp src/Player.cpp src/GameManager.cpp)

# Add project name
set(PROJECT_NAME Lab11)

###########################################
# Do not change anything below this line
###########################################

cmake_minimum_required(VERSION 3.16)  # CMake version check
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard
project(${PROJECT_NAME}) 

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})