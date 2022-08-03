Implementation of an Integer Linked List without the use of Java ArrayList or LinkedList library classes.  IntLinkedList.java contains multiple functions to manpulate nodes of the linked list.
List of functions and their pruposes:  
1. public int getLength(): takes no parameters and returns the number of elements
in the list. For example, the list (3 5 9 3 2 4) would return length 6.
2. public void addTail(int dataItem): takes integer dataItem as a parameter,
which is the value of a node. It creates a new node and adds it to the end of
the list.
3. public IntLinkedList copyList(): takes no parameters and returns a new
IntLinkedList that begins a list containing the same numbers (but not the same
IntLinkedList objects) as the original list.
4. public Node findItem(int dataItem): takes an integer dataItem (i.e. a target)
and returns the first node in the list that contains the given number. If the
dataItem does not occur in the list, then null is returned.
5. public int maxValue():returns the largest number in the list. Initialization
must be done carefully. Hint: You know that the maximum value must be at least
as large as the number in the first node.
6. public IntLinkedList scaleBy(int n): (Already done for you. Please take this
as an example). This method takes an integer n and returns a new IntLinkedList
by multiplying each number in the original list by the given number n. For
example, given list ( 3 2 6 2 3 ) and input 3, the return value would be a new
list ( 9 6 18 6 9 ).
7. public IntLinkedList divisibleBy(int divisor): takes an integer divisor and
returns a new IntLinkedList that contains all the elements from the original
list, which are divisible by the given divisor. For example, given list (3 2 6
2 3) and input 3, the return value would be a new list (3 6 3).
8. public IntLinkedList filter(int n): takes an integer data and return a new
list. The new list is similar to the original one, except that it contains no
occurrences of the number n. For example, given input list (3 2 6 3 4) and 3,
the return value would be the list (2 6 4)
9. (Option; with 1 extra point) public IntLinkedList reverseCopy():takes no
parameters and returns a new IntLinkedList that is the reverse copy of the
original list. For instance, the original one is (12 16 24 8 12 20), and the
return result would be a new list (20 12 8 24 16 12)
