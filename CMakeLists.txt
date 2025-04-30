
cmake_minimum_required(VERSION 3.10)
project(raytracing2d C)

# 1 Encontra a biblioteca SDL2 instalada no sistema
find_package(SDL2 REQUIRED)                     # :contentReference[oaicite:0]{index=0}

# 2 Adiciona o diretório de cabeçalhos do SDL2
include_directories(${SDL2_INCLUDE_DIRS})       # :contentReference[oaicite:1]{index=1}

# 3 Define o executável a partir do único arquivo-fonte
add_executable(raytracing2d
    main.cpp
)


# 4 Linka as bibliotecas SDL2 e a matemática (-lm)
target_link_libraries(raytracing2d
    ${SDL2_LIBRARIES}
    m                                           # :contentReference[oaicite:2]{index=2}
)
