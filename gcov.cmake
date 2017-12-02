cmake_minimum_required(VERSION 2.8)

set(build_dir ${CMAKE_CURRENT_LIST_DIR}/build)
file(STRINGS project_name PROJECT_NAME) 
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
include(cmakemodules/Colors.cmake)

if(NOT EXISTS ${build_dir})
  file(MAKE_DIRECTORY ${build_dir})
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ..
  WORKING_DIRECTORY ${build_dir}
)

execute_process(
  COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${build_dir}
)

execute_process(
  COMMAND make ${PROJECT_TEST_NAME}_coverage
  COMMAND sed "s@\\(Open \\)\\(.*coverage report.\\)@${BoldGreen}\\1file://${build_dir}/\\2${Reset}@"
  WORKING_DIRECTORY ${build_dir}
  RESULT_VARIABLE test_result
)

if(${test_result})
  message(FATAL_ERROR "test failed")
endif()
