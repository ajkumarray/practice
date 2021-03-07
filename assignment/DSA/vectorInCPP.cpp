/*
 Vectors In CPP
 
 Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.
 Vectors elements are placed in contiguous storage so that they can be accessed and traversed using iterators.
 In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array.
 Removing the last element takes only constant time because no resizing happens.
 Inserting and erasing at the beginning or in the middle is linear in time.
 
 */
#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    
    vector<int> vectoray;               //assign vector
    /*
    Syntax:
       vector<object_type> identifier;
     
    push_back() -- It push the element into a vector from the back
    */
    for(int i=0;i<=5;i++)
        vectoray.push_back(i+1);
    
    cout << "Output of begin and end: ";
    for(auto i=vectoray.begin();i!=vectoray.end();++i)
        cout << *i << " ";
    /*
     Iterators: --
     
     begin() -- Returns an iterator pointing to the first element in the vector
     end() -- Returns an iterator pointing to the theoretical element that follows the last element in the vector
     cbegin() -- Returns a constant iterator pointing to the first element in the vector
     cend() -- Returns a constant iterator pointing to the theoretical element that follows the last element in the vector
     */
    cout << "\nOutput of cbegin and cend: ";
    for(auto i=vectoray.cbegin(); i!= vectoray.cend(); ++i)
        cout << *i << " ";
    
    cout << "\nOutput of rbegin and rend: ";
    for(auto i=vectoray.rbegin(); i!= vectoray.rend(); ++i)
        cout << *i << " ";
    /*
     rbegin() -- Returns a reverse iterator pointing to the last element in the vector. It moves from last to first element.
     rend() -- returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
     crbegin() -- Returns a constant reverse iterator pointing to the last element in the vector. It moves from last to first element.
     crend() -- Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector.
     */
    cout << "\nOutput of crbegin and crend: ";
    for(auto i=vectoray.crbegin(); i!= vectoray.crend(); ++i)
        cout << *i << " ";
    
    cout << "\nSize: " << vectoray.size();
    cout << "\nMax_Size: " << vectoray.max_size();
    cout << "\nCapacity: " << vectoray.capacity();
    /*
     Capacity: --
     
     size() -- Returns the number of elements in the vector.
     max_size() -- Returns the maximum number of elements that the vector can hold.
     capacity() -- Returns the size of the storage space currently allocated to the vector expressed as number of elements.
     resize(n) -- Resizes the container so that it contains 'n' elements.
     empty() -- Returns whether the container is empty.
     shrink_to_fit() -- Reduces the capacity of the container to fit its size and destroy all elements beyond the capacity.
     reverse() -- Requests that the vector capacity be at last enough to contain n elements
     */
    vectoray.resize(5);                 //resizes the vector size to 5
    cout << "\nSize after resize: " << vectoray.size();
    if(vectoray.empty())                //checks if the vector is empty or not
        cout << "\nVector is empty" << endl;
    else
        cout << "\nvector is not empty" << endl;
    vectoray.shrink_to_fit();           //shrinks the vector
    cout << "Vector elements are: ";
    for(auto it = vectoray.begin(); it != vectoray.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    cout << "Reference operator [r]: vectoray[2] = " << vectoray[2] << endl;
    cout << "at: vectoray.at(4) = " << vectoray.at(4) << endl;
    cout << "front(): vectoray.front() = " << vectoray.front() << endl;
    cout << "back(): vectoray.back() = " << vectoray.back() << endl;
    int* pos = vectoray.data();         //pointer to the first element
    cout << "The first element is: " << *pos << endl;
    /*
     Element access: --
     
     reference_operator[r] -- Returns a reference to the element at position 'r' in the vector
     at(r) -- Returns a reference to the element at position 'g' in the vector
     front() -- Returns a reference to the first element in the vector
     back() -- Returns a reference to the last element in the vector
     data() -- Returns a direct pointer to the memory array used internally by the vector to store its owned elements
     
     Modifiers: --
     
     assign() -- It assigns new value to the vector elements by replacing old ones
     push_back() -- It push the elements into a vector from the back
     pop_back() -- It is used to pop or remove elements from a vector from the back
     insert() -- It inserts new elements before the element at the specified position
     erase() -- It is used to remove elements from a container from the specified position or range
     swap() -- It is used to swap the contents of one vector with another vector of same type. Size may differ.
     emplace() -- It extends the container by inserting new element at position
     emplace_back() -- It is used to insert a new element into the vector container, the new element is added to the end of the vector
     */
    
    vector<int> vectoray2;          //assign vector
    vectoray2.assign(5,10);         //fill the array with 10 five times
    cout << "The vector elements are: ";
    for(int i=0; i < vectoray2.size(); i++)
        cout << vectoray2[i] << " ";
    cout << endl;
    vectoray2.push_back(15);        //inserts 15 to the last position
    int n = vectoray2.size();
    cout << "The last element is: " << vectoray2[n-1] << endl;
    vectoray2.pop_back();           //removes last element
    cout << "The vector elements are: ";
       for(int i=0; i < vectoray2.size(); i++)
           cout << vectoray2[i] << " ";
       cout << endl;
    vectoray2.insert(vectoray2.begin(),5);      //inserts 5 at the beginning
    cout << "The first element is: " << vectoray2[0] << endl;
    vectoray2.erase(vectoray2.begin());         //removes the first element
    cout << "The first element is: " << vectoray2[0] << endl;
    vectoray2.emplace(vectoray2.begin(),5);     //inserts at the beginning
    cout << "The first element is: " << vectoray2[0] << endl;
    vectoray2.emplace_back(20);                 //inserts 20 at the end
    n = vectoray2.size();
    cout << "The last element is: " << vectoray2[n-1] << endl;
    vectoray2.clear();                          //erases the vector
    cout << "Vector size after erase(): " << vectoray2.size() << endl;
    cout << "Vector1 elements are: ";
       for(int i=0; i < vectoray.size(); i++)
           cout << vectoray[i] << " ";
       cout << endl;
    vectoray2.assign(5,10);
    cout << "Vector2 elements are: ";
       for(int i=0; i < vectoray2.size(); i++)
           cout << vectoray2[i] << " ";
       cout << endl;
    vectoray.swap(vectoray2);                   //swaps vectoray and vectoray2
    cout << "After swap\nVector1 elements are: ";
       for(int i=0; i < vectoray.size(); i++)
           cout << vectoray[i] << " ";
       cout << endl;
    cout << "Vector elements are: ";
       for(int i=0; i < vectoray2.size(); i++)
           cout << vectoray2[i] << " ";
       cout << endl;
    return 0;
}
