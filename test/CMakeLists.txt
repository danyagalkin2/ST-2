include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  tests.cpp)
target_include_directories(${PROJECT_NAME}.test
  PRIVATE ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME} gtest pthread)
target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")
add_test(NAME ${PROJECT_NAME}.test COMMAND ${PROJECT_NAME}.test)

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")
