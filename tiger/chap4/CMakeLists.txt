cmake_minimum_required(VERSION 3.20)
project(tiger-chap4)

add_custom_command(OUTPUT 
        ${CMAKE_CURRENT_BINARY_DIR}/yy.tab.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
    PRE_BUILD
    DEPENDS 
        ${CMAKE_CURRENT_SOURCE_DIR}/tiger.lex 
        ${CMAKE_CURRENT_SOURCE_DIR}/tiger.grm
    COMMAND yacc -o "${CMAKE_CURRENT_BINARY_DIR}/yy.tab.cpp" -dv ${CMAKE_CURRENT_SOURCE_DIR}/tiger.grm
    COMMAND lex -o ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp ${CMAKE_CURRENT_SOURCE_DIR}/tiger.lex)

file(GLOB_RECURSE srcs "*.h" "*.cpp")
add_executable(parsetest ${srcs} 
    ${CMAKE_CURRENT_BINARY_DIR}/yy.tab.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)
target_include_directories(parsetest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 测试
set(testcase_dir "${CMAKE_CURRENT_SOURCE_DIR}/../testcases")
set(parsetest_path "${CMAKE_CURRENT_BINARY_DIR}/parsetest")
add_custom_target(test_all
    DEPENDS parsetest
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND sh -c "for f in $(ls ${testcase_dir}/); do ${parsetest_path} ${testcase_dir}/$f; done")
