#include<iostream>
#include<iterator> // for iterators
#include<vector> // for vectors
using namespace std;

//https://www.geeksforgeeks.org/vector-in-cpp-stl/
//https://www.cplusplus.com/reference/vector/vector/


int main()
{
   
//    size() – Returns the number of elements in the vector.
// max_size() – Returns the maximum number of elements that the vector can hold.
// capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
// resize(n) – Resizes the container so that it contains ‘n’ elements.
// empty() – Returns whether the container is empty.
// shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
// reserve() – Requests that the vector capacity be at least enough to contain n elements.



    vector<int> g1;
    g1.reserve(5);

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
  
    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();
  
    // resizes the vector size to 4
    g1.resize(4);
  
    // prints the vector size after resize()
    cout << "\nSize : " << g1.size();
  
    // checks if the vector is empty or not
    if (g1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";
  
    // Shrinks the vector
    g1.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";

    
//at(g) – Returns a reference to the element at position ‘g’ in the vector
// front() – Returns a reference to the first element in the vector
// back() – Returns a reference to the last element in the vector

/*
assign() – It assigns new value to the vector elements by replacing old ones
push_back() – It push the elements into a vector from the back
pop_back() – It is used to pop or remove elements from a vector from the back.
insert() – It inserts new elements before the element at the specified position
erase() – It is used to remove elements from a container from the specified position or range.
swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
clear() – It is used to remove all the elements of the vector container
emplace() – It extends the container by inserting new element at position
emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
*/





      
    return 0;    
}