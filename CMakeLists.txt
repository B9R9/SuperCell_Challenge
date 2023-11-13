cmake_minimum_required(VERSION 3.16)
project(LittleCloud LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Chemins SFML
message(STATUS "SFML source directory: ${SFML_SOURCE_DIR}")
message(STATUS "SFML binary directory: ${SFML_BINARY_DIR}")

# Ajout des fichiers source et headers
set(SRCS
    srcs/main.cpp
    srcs/Event.cpp
    srcs/fadeAnimation.cpp
    srcs/Game.cpp
    srcs/Menu.cpp
    srcs/Text.cpp
    srcs/utils.cpp
    srcs/Platform.cpp
    # Ajoutez ici d'autres fichiers source si nécessaire

)
set(HEADERS
    srcs/sfml.hpp
    srcs/animation.hpp
    srcs/Event.hpp
    srcs/Game.hpp
    srcs/Menu.hpp
    srcs/Parameters.hpp
    srcs/Text.hpp
    srcs/utils.hpp
    srcs/Platform.hpp

    # Ajoutez ici d'autres fichiers d'en-tête si nécessaire
)

add_executable(LittleCloud ${SRCS} ${HEADERS})

target_include_directories(LittleCloud PRIVATE
    ${CMAKE_SOURCE_DIR}/HEADERS # Utilisez le chemin relatif vers vos fichiers d'en-tête
)

target_link_libraries(LittleCloud PRIVATE sfml-graphics sfml-audio sfml-system sfml-network sfml-window)
target_compile_features(LittleCloud PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET LittleCloud
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS LittleCloud)

