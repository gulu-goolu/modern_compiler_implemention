add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
    PRE_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tiger.lex
    COMMAND flex -o ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp ${CMAKE_CURRENT_SOURCE_DIR}/tiger.lex)
set(srcs
    driver.cpp
    "${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp"
    util.cpp
    errormsg.cpp)
add_executable(lextest ${srcs})
target_include_directories(lextest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
