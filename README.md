# AdvancedProgragmmingEX4


# Command pattern for menu navigation
In this final milestone, we have implemented the command pattern to navigate the menu of our KNN classifier server. The menu includes options for uploading unclassified data, setting algorithm parameters, classifying data, displaying results, downloading results, and exiting the program.

# Multithreading support
Additionally, we have implemented multithreading support, which allows the server to handle multiple clients simultaneously. This improves the performance and scalability of the server and enables it to process requests from multiple clients in parallel.


### Installation
- After cloning run the command: "make" inorder to compile the project, the command make will load Makefile to the project.
- After compling you should see that the "server.out" and "client.out" file have been created, run "./client.out ip_address port" "./server.out port"  to run the program.

### Documentation:

#### Chebyshev Distance
- In that particular distance we chose a "p" parameter to be a constant of 2, as been shown in the example.

#### StringUtils
- StringUtils is a name space that provides utilities for String manipulation.
- To use functions from StringUtils you should  create an object.
- SplitSting(string str, char splitter) is a function that split string to doubles and returns a vector<double>
##### example of use

vector<double> v = StringUtils::splitString("1231.12312 123123.1231", ' ');



#### DistanceCalculator
- distance_calculator is a namespace which provides 5 different functoin to calculator distance between 2 vectors. 
- getDistance is afunction to calculate the distance by kind of the distance, this function get distance type and two vector.
##### example of use
  
  usenamespace DistanceCalculator;
  void func(){...
    int distance = DistanceCalculator::getDistance("AUC",v1,v2);
  }

#### Dataadapter
- DataAdapter is a class to load data by getting data path and distance type and convert it to vector of tuples .
  
- the information in the load file is a series of number that represent vector and sub-them to the data
- To use functions from Dataadapter you should  create an object.
- the class using the namespace DistanceCalculator to claculate the distance of given vector
- finally the class create vectoe of tuples in this format: tuple<vector<double>, string, double>
##### example of use
  
  DataAdapter::loadData(stream,vec,"AUC");


#### Knn
- Knn is a class to identify vector by values of the vector
- the class sort given vector of tuples and return the most common vector type in the first k places
##### example of use
  
 Knn k=Knn:Knn( distype,  tup,  vec, k);
 std::cout<< k.vecType;<<std::endl

