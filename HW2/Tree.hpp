#include <iostream>
#include <vector>

template<typename T>
struct Node{
    T val;
    Node *rChild = NULL;
    Node *lChild = NULL;
};

template<typename T>
class Tree{
    public:
        Tree(T val);
        ~Tree();
        void insertElement(T val);
        bool search(T val);
        void deleteElement(T val);
        
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Tree<U> &t);
    private:
        Node<T> *root = new Node<T>;
};

template<typename T>
Tree<T>::Tree(T val){
    root->val = val;
};

template<typename T>
Node<T>* insHelper(Node<T> *cur, T val){//helper function for insert
    if(cur == NULL){
        Node<T> *n = new Node<T>;//if the current node is null add a new one in its place
        n->val = val;
        return(n);
    }
    if(val > cur->val){
        cur->rChild = insHelper(cur->rChild,val);//if val is greater than current val call fuinction again on right child
    }
    else{
        cur->lChild = insHelper(cur->lChild,val);//if val is less than current val call fuinction again on right child
    }
    return(cur);
}

template<typename T>
void Tree<T>::insertElement(T val){
    if(root == NULL){
        Node<T> *n = new Node<T>;
        n->val = val;
        root = n;//if root is null insert at root
    }
    else{
        root = insHelper(root,val);//else call the helper
    }
};

template<typename T>
bool searchHelper(Node<T> *cur, T val){//search helper for search function
    if(cur!=NULL){
        if(cur->val == val){
            return true;//if val is found return true
        }
        else if(val > cur->val){
            return(searchHelper(cur->rChild,val));//if val is greater than current val call function again on right child
        }
        else{
            return(searchHelper(cur->lChild,val));//if val is less than current val call function again on left child
        }
    }
    return false;//else return false
}

template<typename T>
bool Tree<T>::search(T val){
    if(root==NULL){//check if root is empty
        return(false);
    }
    else{
        bool ret = searchHelper(root,val);//else call search helper
        return(ret);
    }
}


template<typename T>
Node<T>* minValue(Node<T>* cur){//to help with deletes of nodes with 2 children
    Node<T>* ret = cur;
    while(ret!=NULL && ret->lChild!=NULL){//keep searchign till we find the left most child
        ret = ret->lChild;
    }
    return(ret);
}

template<typename T>
Node<T>* deleteHelper(Node<T>* cur, T val){
    if(cur == NULL){//if current node is null return null
        return NULL;
    }
    else {
        if(val > cur->val){
            cur-> rChild = deleteHelper(cur->rChild,val);//if val is greater than current val call function again on right child
        }
        else if(val < cur->val){
            cur-> lChild = deleteHelper(cur->lChild,val);//if val is less than current val call function again on left child
        }
        else{
            if(cur->rChild == NULL && cur->lChild == NULL){
                return NULL;//if node has no child
            }
            else if(cur->lChild == NULL){//if node has only a right child
                Node<T> *ret = cur->rChild;
                delete(cur);
                return(ret);
            }
            else if(cur->rChild == NULL){//if node has only a left child
                Node<T> *ret = cur->lChild;
                delete(cur);
                return(ret);
            }

            Node<T> *ret = minValue(cur->rChild);//if node has 2 children
            cur->val = ret->val;
            cur->rChild = deleteHelper(cur->rChild,ret->val);
        }
    }
    return(cur);
}

template<typename T>
void Tree<T>::deleteElement(T val){ 
    if(root!=NULL){
        root = deleteHelper(root,val);
    }
}


template<typename T>
void deconstructHelper(Node<T>* cur){//helper for deconstructor
    if(cur->lChild!=NULL){
        deconstructHelper(cur->lChild);
    }
    else if(cur->rChild!=NULL){
        deconstructHelper(cur->rChild);
    }
    else{
        delete(cur);
    }
}


template<typename T>
Tree<T>::~Tree(){
    deconstructHelper(root);
}

template<typename T>
std::ostream& printHelper(Node<T>* cur, std::ostream& out){//helper for in order printing
    if(cur == NULL){
        return out;
    }
    printHelper(cur->lChild, out);
    out <<cur->val << ", ";
    printHelper(cur->rChild, out);
    return out;
}
template<typename U>
std::ostream& operator<<(std::ostream& os, const Tree<U> &t){
    os << "{";
    printHelper(t.root,os);
    os << "}";
    return(os);
}
