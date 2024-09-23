cmake_minimum_required(VERSION 3.10)  # 设置最低CMake版本要求

# 项目基本信息
project(design-patterns VERSION 1.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#生产编译命令
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 源文件路径
# 自动展开 src/ 目录下的所有 .cpp 文件
file(GLOB SOURCE_FILES "src/*.cpp")

# 添加可执行文件
 foreach(SRC ${SOURCE_FILES})
     get_filename_component(FILENAME "${SRC}" NAME_WE)
     message("${FILENAME}")
     add_executable(${PROJECT_NAME}-${FILENAME} ${SRC})
 endforeach()

#add_executable(${PROJECT_NAME} ${SOURCE_FILES})

