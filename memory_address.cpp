#include <iostream>
#include <string>
#include <chrono>

using namespace std;

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class Alpha{
    public:

        int data(){
            return 1;
        }
};

class Beta{
    public:
        int dataInt1; //8 byte
        int dataInt2; //8 byte
        double dataDouble; //8byte
        string dataStr; //24byte
};

class User{
    public:
        string Name;

    User(const char* Name){
      User::Name = Name;
    }
};


int main(int argc, char const *argv[])
{
    //memory size for object
    //showing memory from class Alpha
    cout << "Class Alpha Alocation is: " << sizeof(Alpha) << " byte" << endl;
    cout << "Class Beta Alocation is: " << sizeof(Beta) << " byte" << endl;

    //address
    string a;
    string b;
    User object1 = User("Malzx");
    User* object2 = new User("Avalon");
    string c;
    string d;
    cout << "\nAddress stack" << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &object1 << endl;
    cout << &object2 << endl;
    cout << object2 <<endl;
    cout << &c << endl;
    cout << &d << endl;

    //how fast you create object in each memory

    TimePoint *tStackStart =new TimePoint();
    TimePoint *tStackEnd =new TimePoint();
    TimePoint *tHeapStart =new TimePoint();
    TimePoint *tHeapEnd =new TimePoint();

    
    *tStackStart = Clock::now();
    User object3 = User("Malzx");
    *tStackEnd = Clock::now();

    cin.get();
    *tHeapStart = Clock::now();
    User* object4 = new User("Avalon");
    *tHeapEnd = Clock::now();

    chrono::duration<double> durasi = *tStackEnd - *tStackStart;
    cout << "object creation time on stack is : " << durasi.count() << endl;
    durasi = *tHeapEnd - *tHeapStart;
    cout << "object creation time on heap is : " << durasi.count() << endl;
    return 0;
}