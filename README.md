# FT_CONTAINERS

> 42 project, the implementation of templated classes that behave exactly like the C++ 98 STL containers.

### SUBJECT :
[subject](https://github.com/nowl01/Ft_Containers/blob/main/Files/en.subject.pdf)

## What to implement :

- Iterators :
> Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequence of numbers, characters etc. They reduce the complexity and execution time of program.
- Vector:
> - Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, 
- Stack :
> - A stack is a standard C++ container adapter, designed to be used in a LIFO context, and is implemented with an interface/wrapper to the type passed to it as a template argument, which defaults to a deque.  
- Map :
> - Map is dictionary like data structure. It is a sequence of (key, value) pair, where only single value is associated with each unique key.
- Set (Bonus) :
> - Set is a C++ STL container used to store the unique elements, and all the elements are stored in a sorted manner.

## The Data structure used for imlementing Map & Set :
> So the DT used for implementing those containers is '''RED-BLACK TREE''', and this latter is a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the colour (red or black).
[More info about RBT](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
<img src = "https://github.com/nowl01/Ft_Containers/blob/main/Files/rbt.png" alt="RBT" title = "RBT">

## How to use :
The containers are templated, meaning you can use them with any type, just like you would any other STL containers. Just include the header file of the container you want to use (.hpp) in your main program .

The difference is the namespace ; where you would call std::vector<T>, you now call ft::vector<T>.

If you want to test the containers, just run the script with run arg :
```Bash
./script.sh run
```

## Resources :
-[RBT](https://www.codeproject.com/Articles/5301424/Build-the-Forest-in-Python-Series-Red-Black-Tree) <br>
-[Iterators](https://www.geeksforgeeks.org/iterators-c-stl/) <br>
-[STL Containers](https://www.cplusplus.com/reference/stl/) <br>

<br>