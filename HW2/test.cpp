#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Linear.hpp"
#include "Tree.hpp"
#include "HashMap.hpp"
#include "catch.hpp"
#include <fstream>
#include <chrono>

class TestClass{//test class for testing the data structures
    public:
        TestClass(){};
        TestClass(int v){val =v;};
        void setVal(int v){val = v;};
        int getVal() const {return(val);};

        bool operator==(const TestClass& t){
            if(this->val == t.val){
                return true;
            }
            return false;
        };

        bool operator>(const TestClass& t){
            if(this->val > t.val){
                return true;
            }
            return false;
        };

        bool operator<(const TestClass& t){
            if(this->val < t.val){
                return true;
            }
            return false;
        };

        friend std::ostream& operator<<(std::ostream& os, const TestClass& t){
            os << t.val;
            return(os);
        };
    private:
        int val;
};

template<>
struct std::hash<TestClass>{
    std::size_t operator() (TestClass const& t)const noexcept{
        std::size_t h1 = std::hash<int>{}(t.getVal());
        std::size_t h2 = std::hash<int>{}(t.getVal());
        return(h1^(h2 << 1));
    }

};

TEST_CASE("Linear","[Linear]"){
    Linear<int> i;
    Linear<bool> b;
    Linear<std::string> s;
    Linear<char> c;
    Linear<double> d;//various types of Linear datastructures for testing

    Linear<TestClass> t;
    SECTION("Insert"){
        i.insertElement(1);
        i.insertElement(2);
        i.insertElement(3);
        i.insertElement(4);

        b.insertElement(true);
        b.insertElement(false);
        b.insertElement(true);

        s.insertElement("hello");
        s.insertElement("world");

        TestClass t1(1);
        TestClass t2(2);
        TestClass t3(3);

        t.insertElement(t1);
        t.insertElement(t2);
        t.insertElement(t3);
        std::stringstream output;

        output << i;
        CHECK(output.str() == "{1, 2, 3, 4}");//checking insert element
        
        output.str("");
        output << b;
        CHECK(output.str() == "{1, 0, 1}");

        output.str("");
        output << s;
        CHECK(output.str() == "{hello, world}");
        
        output.str("");
        output << t;
        CHECK(output.str()=="{1, 2, 3}");
    }
    SECTION("getElementAtIndex"){
        i.insertElement(1);
        i.insertElement(2);
        i.insertElement(3);
        i.insertElement(4);

        s.insertElement("hello");
        s.insertElement("world");

        CHECK(i.getElementAtIndex(1)==2);//checking getElementAtIndex
        CHECK(s.getElementAtIndex(0)=="hello");
    }
    SECTION("search"){
        c.insertElement('a');
        c.insertElement('b');
        c.insertElement('c');
        c.insertElement('d');

        d.insertElement(2.43);
        d.insertElement(1.32);

        TestClass t1(3);
        TestClass tcheck(3);

        t.insertElement(t1);

        CHECK(c.search('b') == true);//checking search
        CHECK(d.search(2.43) == true);
        CHECK(c.search('z') == false);//making sure it doesn't return true for a value not in the data structure
        CHECK(t.search(tcheck)==true);
    }
    SECTION("Delete Element"){
        s.insertElement("hello");
        s.insertElement("world");
        s.insertElement("universe");

        i.insertElement(1);
        i.insertElement(2);
        i.insertElement(3);
        i.insertElement(4);

        s.deleteElement("world");
        i.deleteElement(3);

        TestClass t1(1);
        TestClass t2(2);
        TestClass t3(3);

        t.insertElement(t1);
        t.insertElement(t2);
        t.insertElement(t3);

        t.deleteElement(t2);

        std::stringstream output;
        output << s;
        CHECK(output.str() == "{hello, universe}");//testing deleteElement

        output.str("");
        output << i;

        CHECK(output.str() == "{1, 2, 4}");

        output.str("");
        output << t;
        CHECK(output.str()=="{1, 3}");
    }

}

TEST_CASE("Tree","[Tree]"){
    Tree<int> i(10); 
    Tree<std::string> s("hi");
    Tree<double> d(1.5);
    Tree<char> c('m');//Tree data structures for testing

    TestClass tRoot(5);
    Tree<TestClass> t(tRoot);

    SECTION("Insert"){
        i.insertElement(15);
        i.insertElement(7);
        i.insertElement(12);

        s.insertElement("hey");
        s.insertElement("hola");
        
        TestClass t1(7);
        TestClass t2(4);
        TestClass t3(2);

        t.insertElement(t1);
        t.insertElement(t2);
        t.insertElement(t3);

        std::stringstream output;
        output << i;
        CHECK(output.str() == "{7, 10, 12, 15, }");//checkign insertElement

        output.str("");
        output << s;
        CHECK(output.str() == "{hey, hi, hola, }");

        output.str("");
        output << t;
        CHECK(output.str() == "{2, 4, 5, 7, }");
    }

    SECTION("Search"){
        d.insertElement(11.5);
        d.insertElement(.09);

        c.insertElement('a');
        c.insertElement('z');

        TestClass t1(7);
        TestClass tCheck(7);

        t.insertElement(t1);

        CHECK(d.search(11.5) == true);//Checking Search
        CHECK(c.search('z') == true);
        CHECK(c.search('b')== false);//checking search to make sure it doesnt return true for a value that is not in the data structure
        CHECK(t.search(tCheck));
    }

    SECTION("Delete"){
        i.insertElement(15);
        i.insertElement(7);
        i.insertElement(12);

        c.insertElement('a');
        c.insertElement('o');
        c.insertElement('y');

        i.deleteElement(7);

        TestClass t1(7);
        TestClass t2(4);
        TestClass t3(2);

        t.insertElement(t1);
        t.insertElement(t2);
        t.insertElement(t3);

        std::stringstream output;
        output << i;

        CHECK(output.str() == "{10, 12, 15, }");//testing delete

        i.deleteElement(22);
        output.str("");
        output << i;
        CHECK(output.str() == "{10, 12, 15, }");//testing delete on a value not in the datastructure to make sure it doesnt delete anything else

        c.deleteElement('y');
        output.str("");
        output << c;
        CHECK(output.str() == "{a, m, o, }");

        t.deleteElement(t3);
        output.str("");
        output << t;
        CHECK(output.str() == "{4, 5, 7, }");
    }
}

TEST_CASE("HashMap", "[Hash]")
{
    std::vector<int> iVals = {10,17,14,19,2,6,8,4,7,2,9};
    HashMap<int> i(iVals,7);

    std::vector<char> cVals = {'a','c','l','q','w'};
    HashMap<char> c(cVals,3);

    std::vector<std::string> sVals = {"super", "cali", "frag", "ilis", "tice", "xp", "ialido", "cious"};
    HashMap<std::string> s(sVals,7);

    std::vector<double> dVals = {0.1,0.5,0.6,0.9,1.7,5.9,3.7,11.9,2.5,6.8,10.9,15.0,4.3,5.2,6.3,2.2,1.4};
    HashMap<double> d(dVals,11);

    TestClass t1(7);
    TestClass t2(4);
    TestClass t3(2);
    TestClass t4(6);
    std::vector<TestClass> tVals = {t1,t2,t3,t4};
    HashMap<TestClass> t(tVals,3);//hash maps for testing 

    //Since hashKey and insertElement already get tested through the constructor I didn't test them explicitly

    SECTION("search"){
        CHECK(i.search(17) == true);
        CHECK(s.search("frag") == true);//testing search
        CHECK(s.search("not in there") == false);//checking to make sure search doesnt return true for a value not in the data structure
        CHECK(t.search(t2) == true);
    }

    SECTION("delete"){
        c.deleteElement('l');
        std::stringstream output;
        output << c;
        CHECK(output.str() =="{0:[c] 1:[a] 2:[q, w] }");

        
        d.deleteElement(10.9);
        output.str("");
        output << d;
        CHECK(output.str() == "{0:[0.5, 0.9, 6.8] 1:[] 2:[15, 5.2, 2.2] 3:[5.9, 3.7, 11.9] 4:[1.4] 5:[] 6:[0.6] 7:[1.7, 2.5] 8:[] 9:[0.1, 6.3] 10:[4.3] }");//testing delete
        d.deleteElement(16.0);
        output.str("");
        output << d;
        CHECK(output.str() == "{0:[0.5, 0.9, 6.8] 1:[] 2:[15, 5.2, 2.2] 3:[5.9, 3.7, 11.9] 4:[1.4] 5:[] 6:[0.6] 7:[1.7, 2.5] 8:[] 9:[0.1, 6.3] 10:[4.3] }");//testing delete to make sure it doesn't delete a value not in the data structure
        
        t.deleteElement(t3);
        output.str("");
        output << t;
        CHECK(output.str() == "{0:[7, 4] 1:[6] 2:[] }");
    }
}

TEST_CASE("Time complexity", "[Time]"){//All times are in mili seconds
    
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
    
    auto t0 = std::chrono::high_resolution_clock::now();
    iL.search(integers[0]);
    auto t1 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> ms = t1-t0;
    std::cout << "Time taken for integer linear first position search: "<<ms.count() << std::endl;
    
    int random = rand() % integers.size();
    t0 = std::chrono::high_resolution_clock::now();
    iL.search(integers[random]);
    t1 = std::chrono::high_resolution_clock::now();
    ms = t1-t0;
    std::cout << "Time taken for integer linear random position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    iL.search(integers[integers.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for integer linear last position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    dL.search(decimals[0]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for decimal linear first position search: "<<ms.count() << std::endl;
    
    random = rand() % decimals.size();
    t0 = std::chrono::high_resolution_clock::now();
    dL.search(decimals[random]);
    t1 = std::chrono::high_resolution_clock::now();
    ms = t1-t0;
    std::cout << "Time taken for decimal linear random position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    dL.search(decimals[decimals.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for decimal linear last position search: "<<ms.count() << std::endl;
    
    t0 = std::chrono::high_resolution_clock::now();
    sL.search(strings[0]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for string linear first position search: "<<ms.count() << std::endl;

    random = rand() % strings.size();
    t0 = std::chrono::high_resolution_clock::now();
    sL.search(strings[random]);
    t1 = std::chrono::high_resolution_clock::now();
    ms = t1-t0;
    std::cout << "Time taken for string linear random position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    sL.search(strings[strings.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for string linear last position search: "<<ms.count() << std::endl;



    t0 = std::chrono::high_resolution_clock::now();
    iT.search(integers[0]);
    t1 = std::chrono::high_resolution_clock::now();
    
    ms = t1-t0;
    std::cout << "Time taken for integer Tree first position search: "<<ms.count() << std::endl;

    random = rand() % integers.size();
    t0 = std::chrono::high_resolution_clock::now();
    iT.search(integers[random]);
    t1 = std::chrono::high_resolution_clock::now();
    ms = t1-t0;
    std::cout << "Time taken for integer Tree random position search: "<<ms.count() << std::endl;
    
    t0 = std::chrono::high_resolution_clock::now();
    iT.search(integers[integers.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for integer Tree last position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    dT.search(decimals[0]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for decimal Tree first position search: "<<ms.count() << std::endl;

    random = rand() %decimals.size();
    t0 = std::chrono::high_resolution_clock::now();
    dT.search(decimals[random]);
    t1 = std::chrono::high_resolution_clock::now();
    ms = t1-t0;
    std::cout << "Time taken for decimal Tree random position search: "<<ms.count() << std::endl;
    
    t0 = std::chrono::high_resolution_clock::now();
    dT.search(decimals[decimals.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for decimal Tree last position search: "<<ms.count() << std::endl;
    
    t0 = std::chrono::high_resolution_clock::now();
    sT.search(strings[0]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for string Tree first position search: "<<ms.count() << std::endl;

    random = rand() % strings.size();
    t0 = std::chrono::high_resolution_clock::now();
    sT.search(strings[random]);
    t1 = std::chrono::high_resolution_clock::now();
    ms = t1-t0;
    std::cout << "Time taken for string Tree random position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    sT.search(strings[strings.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for string Tree last position search: "<<ms.count() << std::endl;



    t0 = std::chrono::high_resolution_clock::now();
    iH.search(integers[0]);
    t1 = std::chrono::high_resolution_clock::now();
    ms = t1-t0;

    std::cout << "Time taken for integer Hash first position search: "<<ms.count() << std::endl;

    random = rand() % integers.size();
    t0 = std::chrono::high_resolution_clock::now();
    iH.search(integers[random]);
    t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken for integer Hash random position search: "<<ms.count() << std::endl;
    
    t0 = std::chrono::high_resolution_clock::now();
    iH.search(integers[integers.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for integer Hash last position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    dH.search(decimals[0]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for decimal Hash first position search: "<<ms.count() << std::endl;
    
    random = rand() % decimals.size();
    t0 = std::chrono::high_resolution_clock::now();
    dH.search(decimals[random]);
    t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken for decimal Hash random position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    dH.search(decimals[decimals.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for decimal Hash last position search: "<<ms.count() << std::endl;
    
    t0 = std::chrono::high_resolution_clock::now();
    sH.search(strings[0]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for string Hash first position search: "<<ms.count() << std::endl;

    random = rand() % strings.size();
    t0 = std::chrono::high_resolution_clock::now();
    sH.search(strings[random]);
    t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken for string Hash random position search: "<<ms.count() << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    sH.search(strings[strings.size()]);
    t1 = std::chrono::high_resolution_clock::now();

    ms = t1-t0;
    std::cout << "Time taken for string Hash last position search: "<<ms.count() << std::endl;

}

//It appears that in the linear data structure, the last position was in general the longest search which is to be expected, and the string searches overal took longer than decimal or integer searches
//For the tree data structure, random position serach was often the longest with decimal and string searches taking longer than integer searches on average
//For the Hash function all search positions took about the same time within the data type, which makes sense, but strings took on average longer than decimals or integers to search through