cmake_minimum_required(VERSION 2.8)
project( faceDetect )
find_package(OpenCV REQUIRED
NO_MODULE # should be optional, tells CMake to use config mode
PATHS /usr/local # look here
NO_DEFAULT_PATH) # and don't look anywhere else
SET( opencv_core opencv_flann opencv_imgproc opencv_imgcodecs 					
                                     opencv_videoio opencv_highgui
                                     opencv_ml opencv_video opencv_objdetect opencv_features2d
                                     opencv_calib3d opencv_superres
                                     )

add_executable( faceDetect src/facedetect.cpp include/facedetect.hpp)

SET(GCC_COVERAGE_LINK_FLAGS " -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn -lopencv_dpm -lopencv_fuzzy -lopencv_hdf -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_rgbd -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_face -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_flann -lopencv_xobjdetect -lopencv_objdetect -lopencv_ml -lopencv_xphoto -lopencv_highgui -lopencv_videoio -lopencv_photo -lopencv_imgcodecs -lopencv_imgproc -lopencv_core")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

target_link_libraries(faceDetect ${OpenCV_LIBS})
