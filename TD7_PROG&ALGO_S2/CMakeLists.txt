cmake_minimum_required(VERSION 3.20)
# get_filename_component(FolderName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(TP5_Project)

# Trouve tous les fichiers .cpp dans mon répertoire src
file(GLOB CPP_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${CPP_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)