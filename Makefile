g++ -c main.cpp -o main.o -fopenmp
g++ main.o -o sort -fopenmp -lpthread