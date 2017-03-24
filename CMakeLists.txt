cmake_minimum_required(VERSION 2.8)
project( mapping )
find_package(OpenCV REQUIRED
NO_MODULE # should be optional, tells CMake to use config mode
PATHS /usr/local # look here
NO_DEFAULT_PATH) # and don't look anywhere else
find_package(PCL 1.2 REQUIRED)
find_package(CUDA REQUIRED)
SET(OPENCV_CUDA_SAMPLES_REQUIRED_DEPS opencv_core opencv_flann opencv_imgproc opencv_imgcodecs 					opencv_videoio opencv_highgui
                                     opencv_ml opencv_video opencv_objdetect opencv_features2d
                                     opencv_calib3d opencv_superres
                                     opencv_cudaarithm opencv_cudafilters opencv_cudawarping opencv_cudaimgproc
                                     opencv_cudafeatures2d opencv_cudaoptflow opencv_cudabgsegm
                                     opencv_cudastereo opencv_cudaobjdetect)

ocv_check_dependencies(${OPENCV_CUDA_SAMPLES_REQUIRED_DEPS})

add_executable( mapping src/mapping.cpp headers/mapping.hpp)

SET(GCC_COVERAGE_LINK_FLAGS "-lopencv_cudabgsegm -lopencv_cudaobjdetect -lopencv_cudastereo -lopencv_stitching -lopencv_cudafeatures2d -lopencv_superres -lopencv_cudacodec -lopencv_videostab -lopencv_cudaoptflow -lopencv_cudalegacy -lopencv_cudawarping -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn -lopencv_dpm -lopencv_fuzzy -lopencv_hdf -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_rgbd -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_face -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_flann -lopencv_xobjdetect -lopencv_objdetect -lopencv_ml -lopencv_xphoto -lopencv_highgui -lopencv_videoio -lopencv_photo -lopencv_imgcodecs -lopencv_cudaimgproc -lopencv_cudafilters -lopencv_imgproc -lopencv_cudaarithm -lopencv_core -lopencv_cudev")

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

target_link_libraries(mapping ${PCL_LIBRARIES} ${OpenCV_LIBS})
