cmake_minimum_required(VERSION 3.11)

project(KillSwitchHold)

add_prx_module(${PROJECT_NAME}
    main.c
    exports.exp
)

target_compile_definitions(
    # If the debug configuration pass the DEBUG define to the compiler
    ${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:DEBUG>
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pspdebug
    pspdisplay
    psppower
    pspctrl
    pspge
)
