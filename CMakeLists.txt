# CMakeList.txt : CMake project for G4_Brems, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16...3.21)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(G4_Brems)

# TODO: Add tests and install targets if needed.

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)


#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Add sources and headers to this project's executable.
add_executable (G4_Brems "G4-Brems.cc" ${sources} ${headers})
target_link_libraries(G4_Brems ${Geant4_LIBRARIES})

#----------------------------------------------------------------------------
# Set standard to C++20
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET G4_Brems PROPERTY CXX_STANDARD 20)
endif()

#----------------------------------------------------------------------------
# Copy all the mac files from "mac_files" directory into the
# same directory as the executable.
file(GLOB G4_Brems-SCRIPTS ${PROJECT_SOURCE_DIR}/mac_files/*)

foreach(_script ${G4_Brems-SCRIPTS})
  get_filename_component(_script_name ${_script} NAME)
  configure_file(
	  ${_script}
	  ${PROJECT_BINARY_DIR}/Release/${_script_name}
	  COPYONLY
  )
endforeach()

#----------------------------------------------------------------------------
# When the project is WIN32, set release settings.
if(WIN32)
  # remove Debug and other unnecessary configurations
  set(CMAKE_CONFIGURATION_TYPES "Release" CACHE INTERNAL "")
  # https://stackoverflow.com/a/37994396/1801749
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT G4_Brems)
endif()