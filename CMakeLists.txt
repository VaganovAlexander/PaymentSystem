cmake_minimum_required(VERSION 3.20)

project(PaymentSystem)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

include_directories(Tests)
link_directories(Tests)

add_executable(AccountTests Tests/AccountTests.cpp src/AccountSystem/Account.cpp)

target_link_libraries(AccountTests GTest::Main)