#include <iostream>
#include "Linear.hpp"
#include "Tree.hpp"
#include "HashMap.hpp"
#include <fstream>
int main(){
    std::string line;
    std::vector<double> decimals;
    std::fstream file("decimals.csv", std::ios::in);
    while (getline(file,line)){
        decimals.push_back(std::stod(line));
    }

    std::vector<std::string> strings;
    file.close();
    file.open("strings.csv", std::ios::in);
    while (getline(file,line)){
        strings.push_back(line);
    }

    std::vector<int> integers;
    file.close();
    file.open("integers.csv", std::ios::in);
    while (getline(file,line)){
        integers.push_back(std::stoi(line));
    }

    Linear<int> iL;
    Linear<std::string> sL;
    Linear<double> dL;

    Tree<int> iT(integers[0]);
    Tree<std::string> sT(strings[0]);
    Tree<double> dT(decimals[0]);

    for(int i = 0; i < integers.size(); i++){
        iL.insertElement(integers[i]);
        if(i!=0){
            iT.insertElement(integers[i]);
        }
    }
    for(int i = 0; i < decimals.size(); i++){
        dL.insertElement(decimals[i]);
        if(i!=0){
            dT.insertElement(decimals[i]);
        }
    }
    for(int i = 0; i < strings.size(); i++){
        sL.insertElement(strings[i]);
        if(i!=0){
            sT.insertElement(strings[i]);
        }
    }

    HashMap<int> iH(integers, 2459);
    HashMap<std::string> sH(strings, 2459);
    HashMap<double> dH(decimals, 2459);


    time_t start = time(&start);
    iL.search(integers[0]);
    time_t end = time(&end);

    double timeTaken = double(end-start);
    std::cout << "Time taken for integer linear first position search: "<<timeTaken << std::endl;

    start = time(&start);
    iL.search(integers[integers.size()]);
    end = time(&end);

    timeTaken = double(end-start);
    std::cout << "Time taken for integer linear last position search: "<<timeTaken << std::endl;

    start = time(&start);
    dL.search(decimals[0]);
    end = time(&end);

    timeTaken = double(end-start);
    std::cout << "Time taken for decimal linear first position search: "<<timeTaken << std::endl;
    
    start = time(&start);
    dL.search(decimals[decimals.size()]);
    end = time(&end);

    timeTaken = double(end-start);
    std::cout << "Time taken for decimal linear last position search: "<<timeTaken << std::endl;
    
    start = time(&start);
    sL.search(strings[0]);
    end = time(&end);

    timeTaken = double(end-start);
    std::cout << "Time taken for string linear first position search: "<<timeTaken << std::endl;

    start = time(&start);
    sL.search(strings[strings.size()]);
    end = time(&end);

    timeTaken = double(end-start);
    std::cout << "Time taken for string linear last position search: "<<timeTaken << std::endl;
}