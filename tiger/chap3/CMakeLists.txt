add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tiger.lex
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tiger.grm
    PRE_BUILD
    COMMAND yacc -o "${CMAKE_CURRENT_BINARY_DIR}/yy.tab.cpp" -dv ${CMAKE_CURRENT_SOURCE_DIR}/tiger.grm
    COMMAND lex -o ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp ${CMAKE_CURRENT_SOURCE_DIR}/tiger.lex)

add_executable(parsetest 
    "parsetest.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp" 
    "${CMAKE_CURRENT_BINARY_DIR}/yy.tab.cpp" 
    "errormsg.cpp"
    "util.cpp")
target_include_directories(parsetest PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
