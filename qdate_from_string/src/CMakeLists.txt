
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

add_executable(qdate_from_string
  main.cpp
  )
target_link_libraries(qdate_from_string Qt5::Core)
