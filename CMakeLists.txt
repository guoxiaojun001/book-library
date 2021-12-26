# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(bookLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("/usr/local/mysql-8.0.21-macos10.15-x86_64/include")
include_directories("/usr/local/mysql-8.0.21-macos10.15-x86_64/include/mysql")

link_directories("/usr/local/mysql-8.0.21-macos10.15-x86_64/lib")

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

add_executable(bookLibrary ${DIR_SRCS})

target_link_libraries(bookLibrary
	PUBLIC
	mysqlclient
	ssl
	crypto

	)


# target_link_libraries(path-info
#   PUBLIC
#     Boost::filesystem
#   )
