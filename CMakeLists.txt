cmake_minimum_required(VERSION 3.21)

project(SystaliaGlassEngine
    VERSION 0.1.0
    DESCRIPTION "Systalia Glass Engine Vulkan and Qt Quick test harness"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 6.8 REQUIRED COMPONENTS
    Core
    Gui
    Qml
    Quick
    QuickControls2
    WaylandCompositor
    WaylandCompositorXdgShell
    ShaderTools
)
find_package(Vulkan REQUIRED)

qt_standard_project_setup(REQUIRES 6.8)

set(systalia_qml_files
    qml/main.qml
    qml/compositor.qml
    qml/SystaliaClientWindow.qml
    qml/AnimatedBackdrop.qml
    qml/controls/GlassWindow.qml
    qml/controls/MetricOverlay.qml
)

set_source_files_properties(qml/main.qml PROPERTIES
    QT_RESOURCE_ALIAS "main.qml"
)
set_source_files_properties(qml/compositor.qml PROPERTIES
    QT_RESOURCE_ALIAS "compositor.qml"
)
set_source_files_properties(qml/SystaliaClientWindow.qml PROPERTIES
    QT_RESOURCE_ALIAS "SystaliaClientWindow.qml"
)
set_source_files_properties(qml/AnimatedBackdrop.qml PROPERTIES
    QT_RESOURCE_ALIAS "AnimatedBackdrop.qml"
)
set_source_files_properties(qml/controls/GlassWindow.qml PROPERTIES
    QT_RESOURCE_ALIAS "controls/GlassWindow.qml"
)
set_source_files_properties(qml/controls/MetricOverlay.qml PROPERTIES
    QT_RESOURCE_ALIAS "controls/MetricOverlay.qml"
)

qt_add_executable(systalia_glass_engine
    src/main.cpp
)

qt_add_qml_module(systalia_glass_engine
    URI Systalia.Glass
    QML_FILES
        ${systalia_qml_files}
    SOURCES
        src/core/EngineConfig.hpp
        src/core/HarmonicSpring.hpp
        src/render/SystaliaGlassItem.hpp
        src/render/SystaliaGlassItem.cpp
        src/render/SystaliaGlassMaterial.hpp
        src/render/SystaliaGlassMaterial.cpp
)

target_include_directories(systalia_glass_engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core
        ${CMAKE_CURRENT_SOURCE_DIR}/src/render
)

target_link_libraries(systalia_glass_engine
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        Qt6::QuickControls2
        Qt6::WaylandCompositor
        Qt6::WaylandCompositorXdgShell
        Vulkan::Vulkan
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(systalia_glass_engine PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
elseif(MSVC)
    target_compile_options(systalia_glass_engine PRIVATE /W4)
endif()

add_subdirectory(shaders)

set_target_properties(systalia_glass_engine PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
