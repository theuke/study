#include <iostream>

// // No virtual functions used.
// class Entity
// {
// public:
//     std::string GetName() { return "Entity"; }
// };

// class Player : public Entity
// {
// private:
//     std::string m_Name;
// public:
//     Player(const std::string& name)
//         : m_Name(name) {}

//     std::string GetName() { return m_Name; }
// };

// void PrintName(Entity *entity)
// {
//     std::cout << entity->GetName() << std::endl;
// }

// int main()
// {
//     // Prints "Entity" as expected
//     Entity *e = new Entity();
//     std::cout << e->GetName() << std::endl;

//     // Prints "Cherno" as expected
//     Player *p = new Player("Cherno");
//     std::cout << p->GetName() << std::endl;

//     // Prints "Entity" which isn't desired. Would expect "Cherno".
//     Entity *entity = p;
//     std::cout << entity->GetName() << std::endl;


//     // Prints "Entity" as expected
//     Entity *e1 = new Entity();
//     PrintName(e1);

//     // Prints "Entity" which isn't desired. Would expect "Cherno".
//     Player *p1 = new Player("Cherno");
//     PrintName(p1);

//     std::cin.get();
// }


// Virtual function used. Virtual functions come at a runtime cost.
//     - Additional memory cost due to need to store A V-table as well
//       as a member variable in each base class instance that points to
//       the correct function in the V-Table.
//     - CPU cost due to need to iterate through the V-table to figure out
//       which table to actually map to.
//     - Because of these costs some people avoid virtual functions. In most cases
//       virtual functions are worth it, but in constrained environemtns such as embedded
//       applications it may not be worth it.
class Entity
{
public:
    virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}

    // Always make sure to use the override keyword even though it isn't strictly needed.
    //     - Improves readability
    //     - Prevents bugs due to spellign errors. If not matchign virtual function in the base class
    //       then compiler error gets thrown.
    std::string GetName() override { return m_Name; }
};

void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    // Prints "Entity" as expected
    Entity *e1 = new Entity();
    PrintName(e1);

    // Prints "Cherno" as expected
    Player *p1 = new Player("Cherno");
    PrintName(p1);

    std::cin.get();
}