cmake_minimum_required(VERSION 3.0.0)
project(LarkPlot VERSION 0.1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# set(Qt5_DIR C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Core Gui OpenGL PrintSupport REQUIRED)

add_definitions(-DQCUSTOMPLOT_USE_OPENGL)
add_definitions(-w)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)


# add_executable(${PROJECT_NAME} 
#                 qcustomplot.h
#                 qcustomplot.cpp
#                 mainwindow.ui
#                 mainwindow.cpp
#                 main.cpp
#                 )

add_library(QCustomPlotLib
    qcp/qcustomplot.h
    qcp/qcustomplot.cpp
)

include_directories(qcp)
include_directories(.)
target_link_libraries(QCustomPlotLib
                        ${MOC_Files}
                        Qt5::Core
                        Qt5::Gui
                        Qt5::Widgets
                        Qt5::OpenGL
                        Qt5::PrintSupport
                        ${OPENGL_LIBRARIES}
                        )

aux_source_directory(. SRCS)
add_library(${PROJECT_NAME}
    ${SRCS}
)



target_link_libraries(${PROJECT_NAME}
                        ${MOC_Files}
                        QCustomPlotLib
                        Qt5::Core
                        Qt5::Gui
                        Qt5::Widgets
                        Qt5::OpenGL
                        Qt5::PrintSupport
                        ${OPENGL_LIBRARIES}
                        )

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
