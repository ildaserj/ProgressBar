cmake_minimum_required(VERSION 3.19)
project(esempio)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE-FILES main.cpp ResourceFile.cpp ResourceFile.h Observer.h Subject.h FileManager.cpp FileManager.h ControlProgressBar.cpp ControlProgressBar.h ProgressBar.cpp ProgressBar.h)
add_executable(esempio ${SOURCE-FILES})
add_library(core ${SOURCE-FILES})

include_directories(headers /usr/include c:/SFML/include)
add_subdirectory(GoogleTest)
#add_subdirectory(Doctest)

#target_link_libraries(esempio core)

set(SFML_ROOT c:/SFML) #add "SFML_ROOT" + path of the directory where you have the library, in my case in c:/SFML 
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(core ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build 
if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()
target_link_libraries(esempio core)
