add_executable(isacpu isacpu.c)
target_link_libraries(isacpu libisa)

install(TARGETS isacpu RUNTIME DESTINATION bin)
