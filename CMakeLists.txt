cmake_minimum_required(VERSION 3.16)
project(QtJsCommunication LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/QtJsCommunication")

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS WebEngineWidgets)
find_package(Qt6 COMPONENTS WebEngineCore)
find_package(Qt6 COMPONENTS WebChannel)
file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/*.cpp
        ${PROJECT_SOURCE_DIR}/*.h
        ${PROJECT_SOURCE_DIR}/*.ui
        ${PROJECT_SOURCE_DIR}/*.qrc
        )

qt_add_executable(QtJsCommunication ${SOURCE_FILES}
)
set_target_properties(QtJsCommunication PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
target_link_libraries(QtJsCommunication PUBLIC
    Qt::Core
    Qt::Gui
    Qt::WebEngineWidgets
    Qt::WebChannel
    Qt::WebEngineCore
)


# Resources:
set(data_resource_files
    "data/icon.png"
    "data/index_copy.html"
    "data/qwebchannel.js"
)

qt_add_resources(QtJsCommunication "data"
    PREFIX
        "/"
    BASE
        "data"
    FILES
        ${data_resource_files}
)

install(TARGETS QtJsCommunication
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
