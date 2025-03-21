# memento bank test
add_executable(memento_bank_test ./memento_bank_test.cpp)
target_link_libraries(memento_bank_test gtest_main memento_bank)
target_include_directories(memento_bank_test PRIVATE ../include)

# link to ctest
include(GoogleTest)
add_test(NAME memento_bank_test COMMAND memento_bank_test)
