cmake_minimum_required(VERSION 2.4.6)

include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
#set(ROS_BUILD_TYPE RelWithDebInfo)
set(ROS_BUILD_TYPE Debug)
rosbuild_init(doors_core)
rosbuild_gensrv()
rosbuild_genmsg()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# executive interface
rosbuild_add_executable(action_runner
                       src/action_check_path.cpp 
                       src/action_detect_door.cpp 
                       src/action_detect_handle.cpp
                       src/action_grasp_handle.cpp
#                       src/action_touch_door.cpp
#                       src/action_push_door.cpp
                       src/action_open_door.cpp
                       src/action_unlatch_handle.cpp
                       src/action_release_handle.cpp
                       src/action_move_base_door.cpp
		       src/action_runner.cpp
                      )

# test
rosbuild_add_executable(trigger_doors_actions 
                       test/trigger_doors_actions.cpp
                      )

