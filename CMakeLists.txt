cmake_minimum_required(VERSION 3.20)
project(OOP_GAME)

set(CMAKE_CXX_STANDARD 14)

include_directories(client/CLI)
include_directories(client/FieldCLI)
include_directories(source/CellComponents/Cell)
include_directories(source/CellComponents/CellEntrance)
include_directories(source/CellComponents/CellExit)
include_directories(source/CellComponents/CellFloor)
include_directories(source/CellComponents/CellWall)
include_directories(source/FieldComponents/Field)
include_directories(source/FieldComponents/FieldGenerator)
include_directories(source/FieldComponents/FieldIterator)
include_directories(source/InteractiveObject)
include_directories(utils/RandomNumberGenerator)

add_executable(OOP_GAME
        client/CLI/CLI.cpp
        client/CLI/CLI.h
        client/FieldCLI/FieldCLI.cpp
        client/FieldCLI/FieldCLI.h
        source/CellComponents/Cell/Cell.cpp
        source/CellComponents/Cell/Cell.h
        source/CellComponents/CellEntrance/CellEntrance.cpp
        source/CellComponents/CellEntrance/CellEntrance.h
        source/CellComponents/CellExit/CellExit.cpp
        source/CellComponents/CellExit/CellExit.h
        source/CellComponents/CellFloor/CellFloor.cpp
        source/CellComponents/CellFloor/CellFloor.h
        source/CellComponents/CellWall/CellWall.cpp
        source/CellComponents/CellWall/CellWall.h
        source/FieldComponents/Field/Field.cpp
        source/FieldComponents/Field/Field.h
        source/FieldComponents/FieldGenerator/FieldGenerator.cpp
        source/FieldComponents/FieldGenerator/FieldGenerator.h
        source/FieldComponents/FieldIterator/FieldIterator.cpp
        source/FieldComponents/FieldIterator/FieldIterator.h
        source/InteractiveObject/InteractiveObject.cpp
        source/InteractiveObject/InteractiveObject.h
        utils/RandomNumberGenerator/RandomNumberGenerator.cpp
        utils/RandomNumberGenerator/RandomNumberGenerator.h
        main.cpp)
