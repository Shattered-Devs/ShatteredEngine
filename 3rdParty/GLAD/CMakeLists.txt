project(GLAD)

add_library(GLAD STATIC "include/glad/glad.h" "include/KHR/khrplatform.h" "src/glad.c")

target_include_directories(GLAD PRIVATE "include")