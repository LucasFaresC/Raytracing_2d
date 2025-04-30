# 1. Versão mínima do CMake e nome do projeto
cmake_minimum_required(VERSION 3.7)
project(raytracing LANGUAGES C CXX)

# 2. Encontrar o SDL2 no sistema
find_package(SDL2 REQUIRED)                                    

# 3. Diretórios de inclusão (headers)
include_directories(${SDL2_INCLUDE_DIRS})                      

# 4. Definir o executável a partir do main.cpp
add_executable(raytracing main.cpp)

# 5. Especificar as opções de compilação (obtidas de sdl2-config) e linkar as bibliotecas SDL2 e math
target_compile_options(raytracing PRIVATE ${SDL2_CFLAGS})
target_link_libraries(raytracing ${SDL2_LIBRARIES} m)
