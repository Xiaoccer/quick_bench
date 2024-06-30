set(OUTPUT_DIR "${BUILD_DIR}/output")

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Werror -pedantic -pthread -O3")
set(COMMON_LINK_LIBS ${COMMON_LINK_LIBS} -pthread)
set(BENCHMARK_LINK_LIBS ${COMMON_LINK_LIBS} benchmark::benchmark)

set(BENCHMARK_SOURCES
  reserve.cpp
  string_view.cpp
)

foreach(SOURCE_FILE ${BENCHMARK_SOURCES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)

    add_executable(${FILE_NAME} ${SOURCE_FILE})

    target_link_directories(${FILE_NAME} PRIVATE ${GOOGLE_BENCHMARK_DIR}/include)

    target_link_libraries(${FILE_NAME} ${BENCHMARK_LINK_LIBS})

    install(TARGETS ${FILE_NAME} DESTINATION ${OUTPUT_DIR})
endforeach()

install(FILES
      ${GOOGLE_BENCHMARK_DIR}/tools/compare.py
      ${GOOGLE_BENCHMARK_DIR}/tools/requirements.txt
      PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
      DESTINATION ${OUTPUT_DIR})

install(FILES
      ${GOOGLE_BENCHMARK_DIR}/tools/gbench/__init__.py
      ${GOOGLE_BENCHMARK_DIR}/tools/gbench/report.py
      ${GOOGLE_BENCHMARK_DIR}/tools/gbench/util.py
      DESTINATION ${OUTPUT_DIR}/gbench)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ compiler flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "Benchmark sources: ${BENCHMARK_SOURCES}")
