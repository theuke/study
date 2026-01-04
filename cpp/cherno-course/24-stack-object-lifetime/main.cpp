#include <iostream>
#include <string>

// When an object is allocated on the stack, it has a finite scope. That object
// will only exist on the stack for the duration of its scope. Note that for instances of class
// objects when the object goes out of scope, its destructor is called.

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
};

// This scoped pointer is basically a wrapper over the Entity object which makes it such
// that once the pointer goes out of scope the entity gets deleted thanks to how stack scoping works.
class ScopedPtr
{
private:
    Entity *m_Ptr;
public:
    ScopedPtr(Entity *ptr)
        : m_Ptr(ptr) {}

    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

// This does not work since we are allocating the memory on the stack.
int *CreateArray()
{
    int array[50];
    return array;
}

// This does not work since we are allocating the memory on the stack.
int *CreateArray()
{
    int *array = new int[50];
    return array;
}

int main()
{
    // A scope can just be what is between two curly braces, doesn't hve to be within a conditional statement of loop.
    // Creates the entity on the stack. Once the scope is exited the entity's destructor is called.
    {
        Entity e1;
    }

    // In this case the entity is allocated on the heap and thus will not be destroyed once the scope is exited.
    // The entity will only be destroyed once the delete call is made. If no delete call is made, teh OS will eventually
    // take care of it once the program exits.
    {
        Entity *e2 = new Entity();
    }

    // When Scoped pointer goes out of scope, it gets deleted. When it gets deleted, the scoped pointer's
    // destructor also deletes the underlying entity.
    {
        ScopedPtr e = new Entity();
    }
    
    std::cin.get();
}