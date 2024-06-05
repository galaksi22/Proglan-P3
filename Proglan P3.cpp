#include <iostream>
using namespace std;

class Moveable {
protected:
    int x_position;
    int y_position;
    int darah;

public:
    Moveable(int posisix, int posisiy, int health) : x_position(posisix), y_position(posisiy), darah(health) {}
    
    int getXposition() const {
        return x_position;
    }
    int getYposition() const {
        return y_position;
    }
    int getHP() const {
        return darah;
    }
    
    void setDarah(int plusDarah) {
        darah = plusDarah;
    }

    virtual void attack(Moveable &target) {
        cout << "attack" << endl;
    }
};

class Attackable {
protected:
    int attackPower;

public:
    Attackable(int attack) : attackPower(attack) {}
    
    int getAttackpower() const {
        return attackPower;
    }
    void setAttackpower(int attack) {
        attackPower = attack;
    }
    
    virtual void attack(Moveable &target) {
        cout << "slash" << attackPower << "starburst stream" << endl;
        target.setDarah(target.getHP() - attackPower);
    }
};

class Defendable {
protected:
    int defensePower = 2;

public:
    Defendable(int defense) : defensePower(defense) {}
    
    int getDefensePower() const {
        return defensePower;
    }
    
    void setDefensePower(int defense) {
        defensePower = defense;
    }
};

class Warrior : public Moveable, public Attackable {
public:
    Warrior(int posisix, int posisiy, int health, int attack, int defense) 
        : Moveable(posisix, posisiy, health), Attackable(attack) {}
    
    void attack(Moveable &target) override {
        cout << "Warrior slash with starburst stream with power " << getAttackpower() << endl;
    }
};

class Mage : public Moveable, public Attackable {
public:
    Mage(int posisix, int posisiy, int health, int attack) 
        : Moveable(posisix, posisiy, health), Attackable(attack) {}
    
    void attack(Moveable &target) override {
        cout << "Mage casts a spell with power " << getAttackpower() << endl;
    }
};

class Healer : public Moveable {
public:
    Healer(int posisix, int posisiy, int health) 
        : Moveable(posisix, posisiy, health) {}
    
    void heal(Moveable &target) {
        int currentHP = target.getHP();
        target.setDarah(currentHP + 15); 
        std::cout << "plus 15 hp :" << target.getHP() << std::endl;
    }
    
    virtual void attack(Moveable &target) override {
        cout << "Healer cannot attack!" << endl;
    }
};

int main() {
    Warrior Kirito(0, 0, 100, 20, 5);
    Mage Leafa(2, 3, 80, 15);
    Healer Yui(3, 3, 70);
    
    Kirito.attack(Yui);
    Leafa.attack(Kirito);
    Yui.heal(Kirito);
    Yui.heal(Leafa); 
    
    return 0;
}
