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
include_directories(source/InteractiveObjectComponents/InteractiveObject)
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
        source/InteractiveObjectComponents/InteractiveObject/InteractiveObject.h
        utils/RandomNumberGenerator/RandomNumberGenerator.cpp
        utils/RandomNumberGenerator/RandomNumberGenerator.h
        main.cpp source/InteractiveObjectComponents/Character/Character.cpp source/InteractiveObjectComponents/Character/Character.h source/InteractiveObjectComponents/Item/Item.cpp source/InteractiveObjectComponents/Item/Item.h source/InteractiveObjectComponents/Equipment/Equipment.cpp source/InteractiveObjectComponents/Equipment/Equipment.h source/InteractiveObjectComponents/Player/Player.cpp source/InteractiveObjectComponents/Player/Player.h source/InteractiveObjectComponents/ItemPlacer/ItemPlacer.cpp source/InteractiveObjectComponents/ItemPlacer/ItemPlacer.h source/InteractiveObjectComponents/Enemy/Enemy.cpp source/InteractiveObjectComponents/Enemy/Enemy.h source/InteractiveObjectComponents/EnemyPlacer/EnemyPlacer.cpp source/InteractiveObjectComponents/EnemyPlacer/EnemyPlacer.h source/GameComponents/Game/Game.cpp source/GameComponents/Game/Game.h source/FieldComponents/FieldAggregate/FieldAggregate.cpp source/FieldComponents/FieldAggregate/FieldAggregate.h source/ControllerComponents/PlayerController/PlayerController.cpp source/ControllerComponents/PlayerController/PlayerController.h source/ControllerComponents/EnemyController/EnemyController.cpp source/ControllerComponents/EnemyController/EnemyController.h source/ControllerComponents/EnemyManageCenter/EnemyManageCenter.cpp source/ControllerComponents/EnemyManageCenter/EnemyManageCenter.h client/PlayerCLI/PlayerCLI.cpp client/PlayerCLI/PlayerCLI.h source/GameComponents/Combat/Combat.cpp source/GameComponents/Combat/Combat.h client/CombatCLI/CombatCLI.cpp client/CombatCLI/CombatCLI.h client/EquipmentCLI/EquipmentCLI.cpp client/EquipmentCLI/EquipmentCLI.h source/GameComponents/Response/Response.cpp source/GameComponents/Response/Response.h source/ControllerComponents/Controller/Controller.cpp source/ControllerComponents/Controller/Controller.h client/Logger/Logger.cpp client/Logger/Logger.h  client/LoggerUnit/LoggerUnit.h client/LoggerUnit/LoggerUnit.cpp source/GameComponents/ControllerObserver/ControllerObserver.cpp source/GameComponents/ControllerObserver/ControllerObserver.h client/MenuComponents/MainMenu/MainMenu.cpp client/MenuComponents/MainMenu/MainMenu.h client/MenuComponents/Controls/Controls.cpp client/MenuComponents/Controls/Controls.h source/FieldComponents/FieldObserver/FieldObserver.cpp source/FieldComponents/FieldObserver/FieldObserver.h source/TaskComponents/KillingSpreeTask/KillingSpreeTask.cpp source/TaskComponents/KillingSpreeTask/KillingSpreeTask.h source/TaskComponents/TaskManager/TaskManager.cpp source/TaskComponents/TaskManager/TaskManager.h client/TaskCLI/TaskCLI.cpp client/TaskCLI/TaskCLI.h source/TaskComponents/CollectionerTask/CollectionerTask.cpp source/TaskComponents/CollectionerTask/CollectionerTask.h source/UserControlsComponents/ControlsInterface/ControlsInterface.h source/UserControlsComponents/ControlsByCLI/ControlsByCLI.cpp source/UserControlsComponents/ControlsByCLI/ControlsByCLI.h source/UserControlsComponents/ControlsManager/ControlsManager.h source/UserControlsComponents/ControlsManager/ControlsManager.cpp source/GameComponents/Level/Level.h source/GameComponents/Level/Level.cpp source/SerializeComponents/SerializeWriter/SerializeWriter.h source/SerializeComponents/SerializeWriter/SerializeWriter.cpp)