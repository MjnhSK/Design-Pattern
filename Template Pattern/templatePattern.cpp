#include <iostream>
using namespace std;

// Abstract base class
class CaffeineBeverage {
public:
    // This is the template method
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }

    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    void boilWater() {
        cout << "Boiling water\n";
    }

    void pourInCup() {
        cout << "Pouring into cup\n";
    }

    // This is a hook method
    virtual bool customerWantsCondiments() {
        return true;
    }
};

// Concrete class
class Coffee : public CaffeineBeverage {
public:
    void brew() override {
        cout << "Dripping Coffee through filter\n";
    }

    void addCondiments() override {
        cout << "Adding Sugar and Milk\n";
    }

    bool customerWantsCondiments() override {
        char answer;
        cout << "Do you want sugar and milk with your coffee? (y/n)\n";
        cin >> answer;
        return answer == 'y';
    }
};

// Concrete class
class Tea : public CaffeineBeverage {
public:
    void brew() override {
        cout << "Steeping the tea\n";
    }

    void addCondiments() override {
        cout << "Adding Lemon\n";
    }

    bool customerWantsCondiments() override {
        char answer;
        cout << "Do you want lemon with your tea? (y/n)\n";
        cin >> answer;
        return answer == 'y';
    }
};

// Client code
int main() {
    CaffeineBeverage* beverage = new Coffee();
    beverage->prepareRecipe();

    cout << "\n";

    beverage = new Tea();
    beverage->prepareRecipe();

    return 0;
}