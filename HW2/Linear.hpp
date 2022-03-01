#include <iostream>
#include <vector>

template<typename T>
class Linear{
    public:
        Linear();
        void insertElement(T val);
        T getElementAtIndex(int index) const;
        bool search(T val);
        void deleteElement(T val);
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Linear<U> &l);
    private:
        std::vector<T> vec;
};

template <typename T>
Linear<T>::Linear(){};

template <typename T>
void Linear<T>::insertElement(T val){
    vec.insert(vec.end(),val);//insert value at the end of the vector
}
template <typename T>
T Linear<T>::getElementAtIndex(int index) const{
    return(vec[index]);//return the value at the given index
}
template <typename T>
bool Linear<T>::search(T val){
    for(int i = 0; i < int(vec.size());i++){
        if(vec[i]==val){
            return true;//loop through the vecctor and return true if the value exists
        }
    }
    return false;
}
template <typename T>
void Linear<T>::deleteElement(T val){
    for(int i = 0; i < int(vec.size());i++){
        if(vec[i]==val){
            vec.erase(vec.begin()+i);//if the value exists delete it from vector
        }
    }
}
template <typename U>
std::ostream& operator<<(std::ostream& os, const Linear<U> &l){
    if(l.vec.size() == 0){
        os << "Empty vector";
    }
    else if(l.vec.size() == 1)
    {
        os << "{" << l.vec[0] << "}";
    }
    else {
        os << "{" << l.vec[0];
        for(int i = 1; i < int(l.vec.size());i++){//loop through the vector adding each value to os
            os << ", " << l.vec[i];
        }
        os << "}";
    }
    return os;
}