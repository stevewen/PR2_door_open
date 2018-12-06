cmake_minimum_required(VERSION 2.4.6)

include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
set(ROS_BUILD_TYPE RelWithDebInfo)
rosbuild_init()
rosbuild_gensrv()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# door detector
rosbuild_add_executable (doors_detector_laser
                        src/geometric_helper.cpp
                        src/cloud_geometry/nearest.cpp
                        src/cloud_geometry/statistics.cpp
                        src/cloud_geometry/areas.cpp
                        src/cloud_geometry/point.cpp
                        src/cloud_geometry/intersections.cpp
                        src/cloud_geometry/distances.cpp
                        src/cloud_geometry/transforms.cpp
                        src/cloud_kdtree/kdtree_ann.cpp
                        src/sample_consensus/sac_model_oriented_line.cpp
                        src/sample_consensus/ransac.cpp
                        src/sample_consensus/sac_model_plane.cpp
                        src/sample_consensus/sac_model_line.cpp
                        src/sample_consensus/sac_model.cpp
                        src/doors_detector.cpp
                       )

# handle detector
rosbuild_add_executable (handle_detector_laser
                        src/geometric_helper.cpp
                        src/cloud_geometry/nearest.cpp
                        src/cloud_geometry/statistics.cpp
                        src/cloud_geometry/areas.cpp
                        src/cloud_geometry/point.cpp
                        src/cloud_geometry/intersections.cpp
                        src/cloud_geometry/distances.cpp
                        src/cloud_geometry/transforms.cpp
                        src/cloud_kdtree/kdtree_ann.cpp
                        src/sample_consensus/sac_model_oriented_line.cpp
                        src/sample_consensus/ransac.cpp
                        src/sample_consensus/sac_model_plane.cpp
                        src/sample_consensus/sac_model_line.cpp
                        src/sample_consensus/sac_model.cpp
                        src/handle_detector.cpp
                       )

# handle detector
rosbuild_add_executable(handle_detector_vision
                       src/handle_detector_vision.cpp 
                      )

#rosbuild_add_executable(handle_detector_vision src/handle_detector_vision.cpp)
rosbuild_add_executable(test_detect_service test/test_detect_service.cpp)
rosbuild_add_executable(test_preempt_service test/test_preempt_service.cpp)

##############################################
# Regression testing

# Helper macro
macro(rostest_door_handle _test_name _md5)
    rosbuild_download_test_data(http://pr.willowgarage.com/data/door_handle_detector/${_test_name}_indexed.bag test/${_test_name}.bag ${_md5})
    # Temporarily labeling these tests "disabled" to stop Hudson from running
    # them.
    rosbuild_add_rostest_labeled(disabled test/${_test_name}.launch)
    #rosbuild_add_rostest(test/${_test_name}.launch)
endmacro(rostest_door_handle)

# We use the point_cloud_cropper in the tests, to simulate a narrow scan of
# the handle
rosbuild_add_executable(point_cloud_cropper test/point_cloud_cropper.cpp)

rostest_door_handle(door_closed_39 f989df140e811c0804d616ac8824c72c) 
rostest_door_handle(door_closed_conference_1 434f223fda025e7b8292f86714138257) 
rostest_door_handle(door_closed_josh 656c9bd2762229860563ac82efa16dd1) 
rostest_door_handle(door_closed_kurt 6a203e9d80833f0c92913930da4e9564) 
rostest_door_handle(door_closed_tully 5318bf89547d700afd20149c3a3f64a6) 
rostest_door_handle(door_closed_alex 89971f486a47e49f3acbc5e842dfbb8d) 
rostest_door_handle(door_closed_ethan 1480a32b60b80a2cc3afbd137b4290fe) 
rostest_door_handle(door_closed_john cfb19906553d36a0b1e593b6b6b09b8b) 
rostest_door_handle(door_closed_melonee_3 4dececd18ed463dce6d6e0eb3c732bfe) 
rostest_door_handle(door_closed_victoria 58cf207d475c391b149258d4de8eec5a) 
rostest_door_handle(door_closed_vijay 3cd2e907a059cee5799adb13314c856e) 


# Currently failing tests below
#rostest_door_handle(door_closed_sachin )
#rostest_door_handle(door_closed_melonee )
#rostest_door_handle(door_closed_40 )
#rostest_door_handle(door_closed_blaise )
#rostest_door_handle(door_closed_conor )
#rostest_door_handle(door_closed_curt )
#rostest_door_handle(door_closed_daniel )
#rostest_door_handle(door_closed_melonee_2 )
#rostest_door_handle(door_closed_patrick )
