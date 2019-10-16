#include <iostream>

using namespace std;

template <class T>
class GenStack
{
     public:
          GenStack()   //default constructor
          {
               size = 0;
               top = -1;
          }
          GenStack(int maxSize)   //overloaded constructor
          {
               myArray = new T[maxSize];  //dynamic memory allocation
               size = maxSize;
               top = -1;
          }
          // ~GenStack()  //destructor - it was throwing this:
          //*** Error in `./a.out': double free or corruption (!prev): 0x000055fb3741dc20 ***
          //so it hated this i am sorry
          // {
          //      delete myArray;
          // }

          void push(T d);       //adds item to top
          T pop();          //removes item from top
          T peek();         //checks item on top

          bool isFull();
          bool isEmpty();
          T* getArray();

          int size;      //size of stack
          int top;       //index of top of stack

          T *myArray;      //pointer to array of any type 'myArray'
};

template <class T>
void GenStack<T>::push(T d)
{
     if(!isFull())
          myArray[++top] = d;
     else
          cerr << "Stack is full!" << endl;
}

template <class T>
T GenStack<T>::pop()
{
     if(!isEmpty())
          return myArray[top--];
     else
          cerr << "Stack is empty!" << endl;
}

template <class T>
T GenStack<T>::peek()
{
     return myArray[top];
}

template <class T>
bool GenStack<T>::isFull()
{
     return (top == size - 1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
     return (top == -1);
}

template <class T>
T* GenStack<T>::getArray()
{
     return myArray;
}
