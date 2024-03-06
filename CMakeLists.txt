cmake_minimum_required(VERSION 3.27)
project(infboc C)

set(CMAKE_C_STANDARD 11)

add_executable(infboc main.c
        Entities/Player.c
        PlayingField/PlayingField.c
        PlayingField/PlayingField.h
        Entities/Player.h
        Assets/StorageUnit.c
        Assets/StorageUnit.h
)
