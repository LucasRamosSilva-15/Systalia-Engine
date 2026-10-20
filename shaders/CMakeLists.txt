qt_add_shaders(systalia_glass_engine systalia_glass_shaders
    NOGLSL
    NOHLSL
    NOMSL
    OPTIMIZED
    PREFIX "/systalia/shaders"
    BASE "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/kawase_down.frag
        ${CMAKE_CURRENT_SOURCE_DIR}/kawase_up.frag
        ${CMAKE_CURRENT_SOURCE_DIR}/valo_glass.frag
        ${CMAKE_CURRENT_SOURCE_DIR}/valo_glass.vert
)
