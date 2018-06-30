# CMake 最低版本号要求  
cmake_minimum_required(VERSION 2.8)  
  
# 项目名称  
project(Infinity) 
# 头文件查找路径
include_directories(.)
  
# 查找当前目录下的所有源文件  
# 并将名称保存到 DIR_ROOT_SRCS变量  
aux_source_directory(. DIR_ROOT_SRCS)

# 列出所有需要参与编译的cpp源文件
FILE(GLOB_RECURSE SRC_FILES
    "engine/engine.cpp"
    "framework/App.cpp"
    "framework/Mesh.cpp"
    "framework/Texture.cpp"
    "objects/ObjectMesh.cpp"
    "players/Player.cpp"
    "players/PlayerOrbit.cpp"
    "render/Render.cpp"
    "render/RenderState.cpp"
    "render/Visualizer.cpp"
    "render/framework/Material.cpp"
    "render/framework/Shader.cpp"
    "utils/Algorithm.cpp"
    "world/World.cpp"
)

# windows 系统的话需要包含glad库从而能够调用opengl函数
IF (WIN32)
    list(APPEND SRC_FILES "utils/glad.c")
ENDIF ()
  
# 指定生成目标  
add_executable(Infinity main.cpp ${SRC_FILES})

IF (APPLE)
    # 链接mac os下必须的一些framework
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo")
ENDIF ()

# 添加链接库
# SOIL and opengl32 have not been tested on mac osx 
target_link_libraries(Infinity glfw3 SOIL opengl32 assimp zlibstatic IrrXML)

# 下面是第二种方法，需要每个文件夹生成一个库文件，并在最终的生成可执行文件时进行链接
# 添加 Lib子目录  
# add_subdirectory(utils) 

# 按照文件夹生成目标，需要下面的链接库  
# add_executable(Infinity main.cpp ${DIR_ROOT_SRCS})