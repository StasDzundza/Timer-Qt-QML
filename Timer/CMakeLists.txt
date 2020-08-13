cmake_minimum_required(VERSION 3.10)

cmake_minimum_required(VERSION 3.10)

project(timer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.14.2\\msvc2017_64\\")

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the Qt libraries for Qt Quick/QML
find_package(Qt5 REQUIRED Qml Quick Multimedia)

# add the qml.qrc file
qt5_add_resources(qml_QRC qml.qrc)

# add source files
set(SOURCE 
	${SOURCE}
	src/main.cpp
	src/timer.cpp
	src/timer_logger.cpp
)

# Tell CMake to create the helloworld executable
add_executable(timer ${SOURCE} ${qml_QRC})

target_include_directories(timer PRIVATE include/)


# Use the Qml/Quick modules from Qt 5.
target_link_libraries(timer Qt5::Qml Qt5::Quick Qt5::Multimedia)