

cmake_minimum_required(VERSION 3.19)
project(tsu_old_lab_1)

set(CMAKE_CXX_STANDARD 14)
add_compile_options("-fPIC")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS
        # список необходимых библиотек
        Core
        # и т.д., например Widgets, Charts
        )

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.hpp")
#qt_wrap_cpp(SOURCE_FILES ${HEADER_FILES})

add_executable(
        # имя исполняемого файла
        MyAwesomeQtProject
        # список файлов с исходным кодом
        src/main.cpp
        src/IObserver.h src/ISubject.h
        src/Publisher.h src/Publisher.cpp
        src/File.h src/File.cpp

        ${SOURCE_FILES} # TODO эта ссылка не работает
)

target_link_libraries(
        # имя исполняемого файла
        MyAwesomeQtProject
        # список библиотек
        Qt5::Core

        # и т.д., например Qt5::Widgets, Qt5::Charts
)
