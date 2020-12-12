# Search Libs
function(search_libs target_name)
	if(_SHATTERED_WINDOWS_X86)
		target_link_directories(${target_name} PUBLIC "../libs/Windows/x86")
	elseif(_SHATTERED_WINDOWS_X64)
		target_link_directories(${target_name} PUBLIC "../libs/Windows/x64")
	elseif(_SHATTERED_WINRT)
		target_link_directories(${target_name} PUBLIC "../libs/UWP/x64")
	endif()
endfunction()

# Copy DLLS
function(copy_dlls target_name)
    ### COPY DLLS ###
    # Windows
    if((_SHATTERED_MSVC OR _SHATTERED_MINGW) AND NOT _SHATTERED_WINRT)
        if(_SHATTERED_WINDOWS_X86)
            file(GLOB dlls "../libs/Windows/x86/*.dll")
            file(COPY ${dlls} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
            target_sources(${target_name} PUBLIC ${dlls})
            set_property(SOURCE ${dlls} PROPERTY VS_COPY_TO_OUT_DIR Always)
        elseif(_SHATTERED_WINDOWS_X64)
            file(GLOB dlls "../libs/Windows/x64/*.dll")
            file(COPY ${dlls} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
            target_sources(${target_name} PUBLIC ${dlls})
            set_property(SOURCE ${dlls} PROPERTY VS_COPY_TO_OUT_DIR Always)
        endif()
    endif()
    
    # UWP
    if(_SHATTERED_WINRT)
        if(_SHATTERED_WINDOWS_X64)
            file(GLOB dlls "../libs/UWP/x64/*.dll")
            target_sources(${target_name} PUBLIC ${dlls})
            set_property(SOURCE ${dlls} PROPERTY VS_DEPLOYMENT_CONTENT 1)
        endif()
    endif()
endfunction()