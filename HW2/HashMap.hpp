#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
template<typename T>
class HashMap{
    public:
        HashMap(std::vector<T> vals, int size);
        int hashKey(T val);
        void insertElement(T val);
        bool search(T val);
        void deleteElement(T val);
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const HashMap<U> &m);
    private: 
        int s;
        std::vector<std::vector<T>> map;
        std::hash<T> hash;

};

template<typename T>
HashMap<T>::HashMap(std::vector<T> vals, int size){
    std::vector<std::vector<T>> temp(size);
    map = temp;//initilize map to a vector of vectors of the correct size
    s = size;
    for(int i = 0; i < vals.size(); i++){//insert the elements passed into the constructor
        insertElement(vals[i]);
    }
}

template<typename T>
int HashMap<T>::hashKey(T val){
    int hashval = hash(val);//get the hash val using the hash function 
    return(abs(hashval%s));
}

template<typename T>
void HashMap<T>::insertElement(T val){
    int place = hashKey(val);
    map[place].push_back(val);//add the value into the correct bin denoted by the hashkey
}

template<typename T>
bool HashMap<T>::search(T val){
    int place = hashKey(val);
    for(int i = 0; i < map[place].size(); i++){//search through the bin given to us by the hash key for if the value is there
        if(val == map[place][i]){
            return(true);
        }
    }
    return (false);
}

template<typename T>
void HashMap<T>::deleteElement(T val){
    int place = hashKey(val);
    for(int i = 0; i < map[place].size();i++){
        if(val == map[place][i]){
            map[place].erase(map[place].begin()+i);//using the hashkey delete the value passed in if it exists in the bin
        }
    }
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const HashMap<U> &m){
    os << "{";
    for(int i = 0; i < m.map.size(); i ++){//loop through all bins
        if(m.map[i].size() > 0){
            os<< i << ":[" << m.map[i][0];
        }
        else{
            os<< i << ":[";
        }
        for(int j = 1; j < m.map[i].size(); j++){
            os<< ", " <<m.map[i][j];//loop through each bin adding the values to the os 
        }
        os << "] ";
    }
    os << "}";
    return(os);
}
