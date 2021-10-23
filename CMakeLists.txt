# CMake最低版本需求
cmake_minimum_required(VERSION 3.17)
# 工程名
project(GetForce)
# 确定编程语言
set(CMAKE_CXX_STANDARD 14)
#确定头文件所在的文件夹
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# 动态链接库路径
link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)

# 生成可执行文件
add_executable(GetForce main.cpp)
# AD采集卡链接库
target_link_libraries(GetForce -l_usbdaq_v20 -lusb-1.0)