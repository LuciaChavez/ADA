#include <cstdlib> // Para poder hacer uso de realloc
#include <iostream>
using namespace std;
int *gpVect = NULL; // Dynamic buffer to save the elements int
int gnCount = 0;    // Counter to know the number of used elements int
int gnMax = 0;      // Variable containing the size of the allocated
// memory

void Resize() {
  const int delta = 10; // Used to increase the vector size
  // gpVect = realloc(gpVect, sizeof(int) * (gnMax + delta));
  //  You can also use the following code:
  int *pTemp, i;
  pTemp = new int[gnMax + delta]; // Alloc a new vector
  for (i = 0; i < gnMax; i++)     // Transfer the elements
    pTemp[i] = gpVect[i];         // we can also use the function memcpy
  delete[] gpVect;                // delete the old vector
  gpVect = pTemp;                 // Update the pointer
  gnMax += delta;                 // The Max has to be increased by delta
}
void Insert(int elem) {
  if (gnCount == gnMax)     // There is no space at this moment for elem
    Resize();               // Resize the vector before inserting elem
  gpVect[gnCount++] = elem; // Insert the element at the end of the sequence
}
int main() {
  for (int j = 10; j > 0; j--) { // inserte 30 elementos
    Insert(j);
  }
  cout << "gnCount:" << gnCount << endl;
  for (int i = 0; i < gnCount; gpVect++, i++) {
    cout << *gpVect << ", ";
  }
  cout << endl;
  return 0;
}