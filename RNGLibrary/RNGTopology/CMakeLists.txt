add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Interface/Input/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Interface/Output/")

set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/RNGTopology.fpp"
    "${CMAKE_CURRENT_LIST_DIR}/intentionally-empty.cpp"
)

register_fprime_module()

set_target_properties(
    ${FPRIME_CURRENT_MODULE}
    PROPERTIES
    SOURCES "${CMAKE_CURRENT_LIST_DIR}/intentionally-empty.cpp"
)
