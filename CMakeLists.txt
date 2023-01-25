cmake_minimum_required(VERSION 3.16)
project(finalStone)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:/Users/lioze/CLionProjects/finalStone/cmake-build-debug)

string(APPEND CMAKE_EXE_LINKER_FLAGS "-pthread")

add_executable(finalStone
        DataAdapter.cpp
        DataAdapter.h
        serverFinal.cpp
        serverFinal.h
        SocketIO.h
        SocketIO.cpp
        service.h
        Globals.h
        Globals.h
        service.cpp
        DistanceCalculator.cpp
        DistanceCalculator.h
        Knn.cpp
        Knn.h
        main.cpp
        Settings.cpp
        Settings.h
        StringUtils.cpp
        StringUtils.h server.cpp server.h DefaultIO.cpp DefaultIO.h StandardIO.cpp StandardIO.h UpploadUnClassified.cpp UpploadUnClassified.h IrisFileUtils.cpp IrisFileUtils.h CLI.cpp CLI.h Command.cpp Command.h CommandUploadUnClasified.cpp CommandUploadUnClasified.h CommandAlgorithmSettings.cpp CommandAlgorithmSettings.h CommandClassifyData.cpp CommandClassifyData.h CommandDownloadResults.cpp CommandDownloadResults.h CommandDisplayResults.cpp CommandDisplayResults.h CommandExit.cpp CommandExit.h CommandNotExists.cpp CommandNotExists.h finalClient.cpp finalClient.h)
