cmake_minimum_required(VERSION 3.20)

project(imguixo)                                # project name

set(ROOT_DIR .)                                 # root source
set(SOURCES ${ROOT_DIR}/src/demo1.cpp)          # demo app source

set(IMGUI_SOURCES                               # imgui source
    ${ROOT_DIR}/thirdparty/imgui/imgui.cpp
    ${ROOT_DIR}/thirdparty/imgui/imgui_demo.cpp
    ${ROOT_DIR}/thirdparty/imgui/imgui_draw.cpp
    ${ROOT_DIR}/thirdparty/imgui/imgui_tables.cpp
    ${ROOT_DIR}/thirdparty/imgui/imgui_widgets.cpp
    ${ROOT_DIR}/thirdparty/imgui/backends/imgui_impl_glfw.cpp
    ${ROOT_DIR}/thirdparty/imgui/backends/imgui_impl_opengl3.cpp
)

# EXE Output (Demo App)
add_executable(${PROJECT_NAME} ${SOURCES} ${IMGUI_SOURCES})

# Imgui Include
target_include_directories(${PROJECT_NAME} PRIVATE ${ROOT_DIR}/thirdparty/imgui)
target_include_directories(${PROJECT_NAME} PRIVATE ${ROOT_DIR}/thirdparty/imgui/backends)

set(CMAKE_CXX_STANDARD 11)              # C Standard

if(UNIX)                                # Linux / Unix: Include Gl / glfw3 Lib
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLFW REQUIRED glfw3)
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARIES} GL)
    target_compile_options(${PROJECT_NAME} PRIVATE ${GLFW_CFLAGS_OTHER})
endif()

if(APPLE)
    find_package(OpenGL REQUIRED)
    target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})
    target_compile_options(${PROJECT_NAME} PRIVATE "-DIMGUI_IMPL_OPENGL_ES2")
endif()

if(WIN32)
    target_link_libraries(${PROJECT_NAME}PRIVATE glfw3 gdi32 opengl32 imm32)
endif()