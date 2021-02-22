# Search Libs
function(search_libs target_name)
    if(_SHATTERED_X64 AND _SHATTERED_WINRT)
		target_link_directories(${target_name} PUBLIC "../libs/UWP/x64")
	endif()
endfunction()

# Copy DLLS
function(copy_dlls)
    ### COPY DLLS ###
    # UWP
    if(_SHATTERED_WINRT)
        if(_SHATTERED_X64)
            file(GLOB dlls "../libs/UWP/x64/*.dll")
            file(COPY ${dlls} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
            target_sources(ShatteredEngine_Testing PUBLIC ${dlls})
            set_property(SOURCE ${dlls} PROPERTY VS_DEPLOYMENT_CONTENT 1)
        endif()
    endif()
endfunction()