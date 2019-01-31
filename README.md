# STL-Implementation
Some of the containers and algorithmic functions from STL(Standard Template Library) are implemented generically using C++

DOCUMENTATION OF A PROJECT
(Implementation of some functions and containers with corresponding iterators of STANDARD TEMPLATE LIBRARY)

1)Understanding STL first :

The C++ STL (Standard Template Library) is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks.
There are some great resources available for STL on the internet,Some of them are:
    [STL - GeeksForGeeks](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
    and
    [STL - HackerEarth](https://www.hackerearth.com/practice/notes/standard-template-library/)
    
2)About the Project :

In this Project we have tried to implement some basic algorithmic functions and some useful data structures from STANDARD TEMPLATE LIBRARY.STL is mainly divided into three parts :

    • Algorithms
    
    • Containers
    
    • Iterators
    
So here we have created one "Algorithm.h" file in which some algorithmic functions are defined.After that for the containers we have created a separate file for each container such as for vector "Vector.h",for set "Set.h",etc.Now for iterators,if you have gone through the STL tutorials you have noticed that there are several types of iterators are used according to the need of the container.It is a standard practice that the several types of iterator files should be created first and then those should be used according to the requirement but instead of doing this we have created iterator as a component of a container in the container file itself and used it there,But stil it works like a standard iterator file only.

3)Let's have a look :

Now we will go through each and every function and container.

I)Algorithm File :

*Kindly notice that the name of the file is "Algorithm.h".

    • sort(first_iterator,last_iterator) :It sorts the given array or vector in ascending order.
    
    • binary_search(first_element,last_element,search element) :This function will return true if the element will be in the given range or else it will return false.The precondition required here is that the elements in the given range should be sorted in ascending order.
    
    • reverse(first_iterator,last_iterator) :This function reverses the given array or vector.
    
    • max_element(first_iterator,last_iterator) :This function returns the iterator(pointer) to the maximum element in the given range.
    
    • min_element(first_iterator,last_iterator) :This function returns the iterator(pointer) to the minimum element in the given range.
    
    • accumulate(first_iterator,last_iterator,sum) :This function does the summation of all elements of an array or a vector and adds it to the sum parameter and return it.
    
    • count(first_iterator,last_iterator,element) :This function counts the occurences of provided element and returns it.
    
    • find(first_iterator,last_iterator,element) :This function searches the provided element in the given array or vector linearly and returns the pointer to the given element.If the element will not be in the range,it returns the last address of an array or the vector.
    
    • distance(first_iterator,desired_position) :It returns the distance of desired position from the first iterator.This function is very useful while finding the index.
    
    • next_permutation(first_iterator,last_iterator) :This modified the vector to its next permutation.
    
II)Vector File :

*Remember the file name is "Vector.h".

    • begin() : Returns an iterator pointing to the first element in the vector
    
    • end() : Returns an iterator pointing to the theoretical element that follows the last element in the vector
    
    • size() : Returns the number of elements in the vector.
    
    • capacity() : Returns the size of the storage space currently allocated to the vector expressed as number of elements.
    
    • push_back(element) : It push the elements into a vector from the back.
    
    • pop_back() : It is used to pop or remove elements from a vector from the back.
    
    • empty() : Returns whether the container is empty.
    
    • front() : Returns a reference to the first element in the vector.
    
    • back() : Returns a reference to the last element in the vector
    
    • clear() : It is used to remove all the elements of the vector container.
    
    • erase(position) : It is used to remove elements from a container from the specified position.
    
III)Stack File :

*Remember the file name is "Stack.h".

    • empty() : Returns whether the stack is empty.
    
    • size() : Returns the size of the stack.
    
    • push(g) : Adds the element ‘g’ at the top of the stack.
    
    • top() : Returns a reference to the top most element of the stack.
    
    • pop() : Deletes the top most element of the stack.
    
IV)Queue File :

*Remember the file name is "Queue.h".

    • push(g) : This function adds the element ‘g’ at the end of the queue.
    
    • pop() : This function deletes the first element of the queue.
    
    • front() : This function returns a reference to the first element of the queue.
    
    • back() : This function returns a reference to the last element of the queue.
    
    • size() : Returns the size of the queue.
    
    • empty() : Returns whether the queue is empty.
    
V)List File :

*Rememberthe file name is "List.h".

    • front() : Returns the value of the first element in the list.
    
    • back() : Returns the value of the last element in the list.
    
    • push_front(g) : Adds a new element ‘g’ at the beginning of the list.
    
    • push_back(g) : Adds a new element ‘g’ at the end of the list.
    
    • begin() : This function returns an iterator pointing to the first element of the list.
    
    • end() : This function returns an iterator pointing to the theoretical last element which follows the last element.
    
    • display() : This function displays all the elements in the list.
    
    • delAll() : This function deletes all the elements in the list.
    
    • pop_front() : Removes the first element of the list, and reduces size of the list by 1.
    
    • pop_back() : Removes the last element of the list, and reduces size of the list by 1.
    
    • empty() : Returns whether the list is empty(1) or not(0).
    
    • insert(position,g) : This function inserts the element 'g' at the specified position.
    
    • erase(position) : This function erases the element at a specified position.
    
    • assign(count,g) : This function assigns the element 'g' 'count' number of times to the list.
    
    • assign(second_list.begin(),second_list.end()) : This function copies the elements from an existing list to the second
    list.
    
    • remove(g) : This function deletes all the elements with value 'g' from the list.
    
    • reverse() : This function reverses the list.
    
    • size() : Returns the number of elements in the list.
    
    • Sort() : This function sorts the list in an increasing order.
    
    • clear() : This function is same as the delAll() function which deletes all the elements in the list.
    
VI)Pair File :

*Rememberthe file name is "Pair.h".

The pair container is a simple container consisting of two data elements or objects.

    • The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
    
    • Pair is used to combine together two values which may be different in type. Pair provides a way to store two heterogeneous objects as a single unit.
    
    • Pair can be assigned, copied and compared. The array of objects allocated in a map or hash_map are of type ‘pair’ by default in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.
    
    • To access the elements, we use variable name followed by dot operator followed by the keyword first or second.
    
    • Make_pair() : This template function allows to create a value pair without writing the types explicitly.
    
    • Operators(=,==,!=,>=,<=) : These operators can be directly used with pairs.
    
    • Swap() : This function swaps the contents of one pair object with the contents of another pair object. The pairs must be of same type.
    
VII)Set File :

*Remember the file name is "Set.h".

    • insert(g) : This function inserts the element 'g' in the ordered set.
    
    • size() : This function returns the size(number of elements) of the set.
    
    • empty() : This function returns true if set container is empty else returns false.
    
    • search(g) : This function searches the value 'g' in the set container and returns true if found else returns falase.
    
    • getroot() : This function returns the root of the BST(Binary search tree) in which elements are stored.
    
    • begin() : This function returns the beginning iterator of the set.
    
    • end() : This function returns the ending iterator of the set.
    
    • display(Iterator_root) : This function displays the elements in the set container in INORDER manner.
    

