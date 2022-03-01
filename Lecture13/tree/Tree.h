#ifndef TREE_H
#define TREE_H

class Tree {
    public:
        static int numberOfTrees;

        Tree(){numberOfTrees+=1;}

        virtual void Seed() { number_seeds_ += 1; }

        int get_number_seeds() { return number_seeds_; }

    private:
        static int number_seeds_;
};

class Bush: public Tree{
    public:
        Bush(): Tree(){}
        void Seed(){
            Tree::Seed();
            Tree::Seed();
        }
};
#endif // TREE_H
