#include <iostream>
using namespace std;

class Engine {
    bool isRunning;

public:
    Engine() : isRunning(false) {
        cout<<"Engine constructed"<<endl;
    }

    void start() {
        if (!isRunning) {
            isRunning = true;
            cout << "Engine started" << endl;
        } else {
            cout << "Engine is already running" << endl;
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            cout << "Engine stopped" << endl;
        } else {
            cout << "Engine is already off" << endl;
        }
    }

    bool isEngineRunning() const {
        return isRunning;
    }
    ~Engine(){
        cout<<"Engine destructed"<<endl;
    }
};

class Car {
    Engine engine; 

public:
    Car(){
        cout<<"Car constructed"<<endl;
    }
    void startCar() {
        cout << "Starting the car..." << endl;
        engine.start();
    }

    void stopCar() {
        cout << "Stopping the car..." << endl;
        engine.stop();
    }
    ~Car(){
        cout<<"Car destructed"<<endl;  
    }
};

int main() {
    Car c;
    
    c.startCar(); 
    c.stopCar();  

    return 0;
}   