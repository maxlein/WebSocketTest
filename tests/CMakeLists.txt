if(NOT MSVC)
    add_compile_options(-fno-access-control)

    add_executable(parse_test parse_test.cpp)
    target_link_libraries(parse_test simple-websocket-server)
    add_test(parse_test parse_test )
endif()

message("unit test output dir: ${UNIT_TEST_BIN_OUTPUT_DIR}")

add_executable(crypto_test crypto_test.cpp)
target_link_libraries(crypto_test simple-websocket-server)
add_test( crypto_test crypto_test)

#add_executable(io_test io_test.cpp)
#target_link_libraries(io_test simple-websocket-server)
#add_test(io_test io_test)

## googletest ##
add_executable(testfoo dummytest.cpp main.cpp)

target_link_libraries(testfoo
    libgtest
    libgmock
)
add_test(testfoo testfoo) 

set_target_properties( testfoo crypto_test
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${UNIT_TEST_BIN_OUTPUT_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${UNIT_TEST_BIN_OUTPUT_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${UNIT_TEST_BIN_OUTPUT_DIR}"
)
