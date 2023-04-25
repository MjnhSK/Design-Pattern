#include <iostream>

// Strategy interface
class FlyBehavior {
public:
    virtual void fly() = 0;
};

// Concrete strategies
class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        std::cout << "I'm flying with wings!" << std::endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override {
        std::cout << "I can't fly." << std::endl;
    }
};

// Strategy interface
class QuackBehavior {
public:
    virtual void quack() = 0;
};

// Concrete strategies
class Quack : public QuackBehavior {
public:
    void quack() override {
        std::cout << "Quack!" << std::endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    void quack() override {
        std::cout << "<< Silence >>" << std::endl;
    }
};

class Squeak : public QuackBehavior {
public:
    void quack() override {
        std::cout << "Squeak!" << std::endl;
    }
};

// Context
class Duck {
public:
    Duck(FlyBehavior& flyBehavior, QuackBehavior& quackBehavior)
        : flyBehavior_(flyBehavior), quackBehavior_(quackBehavior) {}

    void performFly() {
        flyBehavior_.fly();
    }

    void performQuack() {
        quackBehavior_.quack();
    }

    void swim() {
        std::cout << "All ducks float, even decoys!" << std::endl;
    }

    void setFlyBehavior(FlyBehavior& flyBehavior) {
        flyBehavior_ = flyBehavior;
    }

    void setQuackBehavior(QuackBehavior& quackBehavior) {
        quackBehavior_ = quackBehavior;
    }

private:
    FlyBehavior& flyBehavior_;
    QuackBehavior& quackBehavior_;
};

int main() {
    FlyWithWings flyWithWings;
    FlyNoWay flyNoWay;
    Quack quack;
    MuteQuack muteQuack;
    Squeak squeak;

    Duck mallardDuck(flyWithWings, quack);
    mallardDuck.performFly();
    mallardDuck.performQuack();

    Duck rubberDuck(flyNoWay, squeak);
    rubberDuck.performFly();
    rubberDuck.performQuack();
    rubberDuck.swim();

    rubberDuck.setFlyBehavior(flyWithWings);
    rubberDuck.performFly();

    return 0;
}
