/* Animal Shelter:
 * An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first
 * out" basis. People must a dopt either the "older" (based on arrival time) of all animals at the shelter,
 * or they can select whether they would prefer a dog or a cat (and will receive the oldest anumal of that
 * type). They cannot select which specific anumal they would like. Create the data structures to maintain
 * this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may
 * use the built-in LinkeList data structure.
*/

// The easiest solution is to have the animalShelter class simply maintain both a dog and cat queue
// which are implemented as linked lists and assign. Additionally, we maintain a global ticket count
// and increment it on each enqueue operation. Hence, dequeueAny() would just need to check whether
// the ticket number of the oldest dog or cat is smaller and dequeue that one.
//
// The only downside to this method is that it breaks once the ticket numbers roll-over (i.e. ticket
// number goes past MAX_INT). A true solution then would need to account for this.

// The more proper solution (but it is more involved) would be to maintatin a third linked list with
// both dogs and cats. For dequeueAny, the oldest animal is dequeued from the shared linked list as
// well as from the animal type linked list. For dequeDog, the oldest dog is dequed from the dog list
// and then the dequeud dog must be found in the shard linked list and removed from there as well. In order
// to make this operation fast, need to maintain a pointer to the element in the shared linked list which
// points to the oldest dog (and do the same for the cat). One of them will always be the tail and the other
// will always be the opposite animal. I.e. if the oldest animal is a cat, then the element prior to the
// oldest dog must be a cat. The element pointign to the oldest cat then can just be set to NULL in order
// to mark this.