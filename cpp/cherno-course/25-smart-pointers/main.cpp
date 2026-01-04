#include <iostream>
#include <string>
#include <memory>

// Smart pointers are wrappers around a real "raw" pointer. Smart pointers allow devs to not have to call delete
// and potentially not even have to call new either. The idea is that the pointer is smart enough to keep track of if
// it is still being refernced or in scope and once it is no lnoger referenced or in scope it gets deleted.

class Entity
{
public:
    Entity()
    {
        std::cout << "Creaeted Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print() {}
};

int main()
{
    // A unique pointer cannot be copied. They are to be used when you want a single scoped
    // refenced to a piece of memory. Once the pointer goes out of scope, the underlying object's destructor is called.
    {
        // // This is valid, but not the preffered method due to exception safety.
        // std::unique_ptr<Entity> entity(new Entity());

        // This is preffered method.
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();

        // // Can't do this since oopy constructor and copy assignment operator are deleted for unique pointer. This is done
        // // on purpose so devs don't dig themselves into a grave since the second pointer to go out of scope would try to call
        // // delete on iteelf agin when goign out of scope.
        // std::unique_ptr<Entity> e0 = entity;

        entity->Print();
    }


    // Aother type of smart pointe is a shared pointer. The idea behind a shared pointer is that multiple references to it can be made.
    // The way its managed is that a reference count is maintainted, and when tahat reference count goes to 0 the shared pointer and its
    // underlying object are deleted.
    {
        // In this case, underlying entity will only get deleted once outer scope is exited because e0 still holds
        // a reference to the shared entity.
        std::shared_ptr<Entity> e0;
        {
            // For shared pointed, actually NEED to use make_shared instead as opposed to sahredEntity(new Entity()). This is because
            // shard pointer needs to allocate a control block for the shared pointer. Ultimatley, you end up with two allocations.
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            
            // This works just fine.
            std::shared_ptr<Entity> e1 = sharedEntity;

            // this also works just fine
            e0 = sharedEntity;

            // Using weak pointer does not increase the reference count of the shared pointer.
            // This is useful if you don't want to take ownership over the underlying entity.
            std::weak_ptr<Entity> weakEntity = sharedEntity;
        }
    }

    // Becaues weak_ptr is used, the underlying entity gets deelted once the inner scope is exited.
    // This pointer allows you to query wether or not the underlying object still exists.
    {
        std::weak_ptr<Entity> weakEntity;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            weakEntity = sharedEntity;
        }

        if (weakEntity.expired())
        {
            // If expired.
        }
    }

    std::cin.get();
}