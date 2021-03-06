# project
SET(PROJECT_NAME exe)
PROJECT(${PROJECT_NAME} CXX C)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
SET(CMAKE_BUILD_TYPE Debug) # Release, RelWithDebInfo
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMakeModules/")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(Boost_USE_MULTITHREADED ON)

# Add plain cmake packages
FIND_PACKAGE(OpenCV REQUIRED)
# FIND_PACKAGE(Boost COMPONENTS system filesystem thread REQUIRED)
# FIND_PACKAGE(Threads REQUIRED)

# Include dirs
INCLUDE_DIRECTORIES(
  include
  ${Eigen_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)


# Set link libraries
LIST(APPEND LINK_LIBS
  ${OpenCV_LIBS}
  ${CMAKE_THREAD_LIBS_INIT}

)


# Set sourcefiles
LIST(APPEND SOURCEFILES
  src/main.cpp
  src/timer.cpp
  src/depth_filter.cpp
)


# Set build flags, set ARM_ARCHITECTURE environment variable on Odroid
set(CMAKE_CXX_FLAGS "-msse3")
set(CMAKE_BUILD_TYPE Debug) # Release, RelWithDebInfo
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg  -m64 -Ofast -flto -march=native -mfpmath=sse")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3  -DEIGEN_NO_DEBUG -fopenmp -DNDEBUG")


################################################################################
# TESTS

ADD_EXECUTABLE(exe ${SOURCEFILES})
TARGET_LINK_LIBRARIES(exe ${LINK_LIBS})
