all: client.out server.out

client.out: FileDownloader.cpp CommandDownloadResults.cpp DataAdapter.cpp  StandardIO.cpp Command.cpp SocketIO.cpp CLI.cpp finalClient.cpp service.cpp  DistanceCalculator.cpp Knn.cpp  StringUtils.cpp Settings.cpp UpploadUnClassified.cpp IrisFileUtils.cpp DefaultIO.cpp server.cpp CommandAlgorithmSettings.cpp CommandUploadUnClasified.cpp  CommandNotExists.cpp CommandDisplayResults.cpp  CommandExit.cpp CommandClassifyData.cpp
	g++ -g -std=c++11 -pthread FileDownloader.cpp CommandDownloadResults.cpp DataAdapter.cpp StandardIO.cpp  Command.cpp CLI.cpp finalClient.cpp  service.cpp SocketIO.cpp  DistanceCalculator.cpp Knn.cpp  StringUtils.cpp Settings.cpp UpploadUnClassified.cpp IrisFileUtils.cpp DefaultIO.cpp server.cpp CommandAlgorithmSettings.cpp CommandUploadUnClasified.cpp CommandNotExists.cpp CommandDisplayResults.cpp  CommandExit.cpp CommandClassifyData.cpp -o client.out


server.out: FileDownloader.cpp CommandDownloadResults.cpp DataAdapter.cpp serverFinal.cpp StandardIO.cpp Command.cpp SocketIO.cpp CLI.cpp  service.cpp  DistanceCalculator.cpp Knn.cpp StringUtils.cpp Settings.cpp UpploadUnClassified.cpp IrisFileUtils.cpp DefaultIO.cpp server.cpp CommandAlgorithmSettings.cpp CommandUploadUnClasified.cpp  CommandNotExists.cpp CommandDisplayResults.cpp  CommandExit.cpp CommandClassifyData.cpp
	g++  -g -std=c++11 -pthread FileDownloader.cpp CommandDownloadResults.cpp DataAdapter.cpp StandardIO.cpp  Command.cpp CLI.cpp  serverFinal.cpp service.cpp SocketIO.cpp  DistanceCalculator.cpp Knn.cpp StringUtils.cpp Settings.cpp UpploadUnClassified.cpp IrisFileUtils.cpp DefaultIO.cpp server.cpp CommandAlgorithmSettings.cpp CommandUploadUnClasified.cpp CommandNotExists.cpp CommandDisplayResults.cpp  CommandExit.cpp CommandClassifyData.cpp -o server.out

main.out: FileDownloader.cpp CommandDownloadResults.cpp DataAdapter.cpp serverFinal.cpp StandardIO.cpp Command.cpp SocketIO.cpp CLI.cpp finalClient.cpp service.cpp  DistanceCalculator.cpp Knn.cpp main.cpp StringUtils.cpp Settings.cpp UpploadUnClassified.cpp IrisFileUtils.cpp DefaultIO.cpp server.cpp CommandAlgorithmSettings.cpp CommandUploadUnClasified.cpp  CommandNotExists.cpp CommandDisplayResults.cpp  CommandExit.cpp CommandClassifyData.cpp
	g++ -std=c++11 -pthread FileDownloader.cpp CommandDownloadResults.cpp DataAdapter.cpp StandardIO.cpp  Command.cpp CLI.cpp finalClient.cpp serverFinal.cpp service.cpp SocketIO.cpp  DistanceCalculator.cpp Knn.cpp main.cpp StringUtils.cpp Settings.cpp UpploadUnClassified.cpp IrisFileUtils.cpp DefaultIO.cpp server.cpp CommandAlgorithmSettings.cpp CommandUploadUnClasified.cpp CommandNotExists.cpp CommandDisplayResults.cpp  CommandExit.cpp CommandClassifyData.cpp






