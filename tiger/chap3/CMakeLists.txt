file(GLOB srcs "*.cpp")
add_executable(parsetest ${srcs})

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/)
