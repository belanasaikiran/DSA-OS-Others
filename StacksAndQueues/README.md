## **Stack**

Stack is a LIFO(Last In First Out)

### Example:

Used in Web Page of a single Web window
In one tab,

- first open facebook.com - in same tab

- next open youtube.com - in same tab

- next open instagram.com - in same

when you go back, it goes to the last opened and so on following LIFO.

### Using Vectors:
> If we use `Vector` for Stack, to add or remove the left most element, it will be O(n)  and  right most element(AKA top most), it will be O(1).


### Efficient way:

Use `LinkedList` which will be O(1) on both the sides.

- Head -> Top --- NOTE: We call it Top instead of Head
- Tail -> Bottom ( We don't even need Tail for Stack )


## **Queue**:

 A FIFO(First In First Out)

### Example: Jobs in HPC

We can use Vector for Queue, but it will be O(n) to remove the left most element.

Removing the right most element will be O(1) but we don't need that since we can't keep track of previous right..

### Efficient way:

Use `LinkedList` which will be O(1) on both the sides.

- Enqueue -> Tail
- Dequeue -> Head
