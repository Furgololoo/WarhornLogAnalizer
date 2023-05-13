cmake_minimum_required(VERSION 3.16)

project(LogAnalizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 6.2 COMPONENTS Widgets REQUIRED)

qt_add_executable(appLogAnalizer

    src/cpp_code/main.cpp

    src/cpp_code/objectmanager.h    src/cpp_code/objectmanager.cpp

    # LOG
    src/cpp_code/log/loganalizer.h  src/cpp_code/log/loganalizer.cpp
    src/cpp_code/log/logentry.h     src/cpp_code/log/logentry.cpp
    src/cpp_code/log/logmanager.h   src/cpp_code/log/logmanager.cpp
    src/cpp_code/log/logtype.h      src/cpp_code/log/logtype.cpp

    # LOG GROUPS
    src/cpp_code/log/log_groups/gameplaylogs.h  src/cpp_code/log/log_groups/gameplaylogs.cpp

    # File
    src/cpp_code/files/filemanager.h    src/cpp_code/files/filemanager.cpp

    # QRC
    src/view/qml.qrc
    src/resources/resources.qrc
)

set_target_properties(appLogAnalizer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appLogAnalizer
    PRIVATE Qt6::Quick)

target_link_libraries(appLogAnalizer PRIVATE Qt6::Widgets)

install(TARGETS appLogAnalizer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
