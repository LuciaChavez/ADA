#include <cstdlib>
#include <iostream>
using namespace std;
int* gpVect; // Buffer to save the elements

struct Vector
{
  int*m_pVect, // Pointer to the buffer
  m_nCount, // Control how many elements are actually used
  m_nMax, // Control how many are allocated as maximum
  m_nDelta; // To control the growing
};


void Resize(Vector *pThis)
{
  pThis->m_pVect =(int*) realloc(gpVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
  // The Max has to be increased by delta
  pThis->m_nMax += pThis->m_nDelta;
}
void Insert(Vector *pThis, int elem)
{
if( pThis->m_nCount == pThis->m_nMax ) // Verify the overflow
Resize(pThis); // Resize the vector before inserting elem
// Insert the element at the end of the sequence
pThis->m_pVect[pThis->m_nCount++] = elem;
}
int main() {
  Vector* a = new Vector(); 
  gpVect = new int[100]; 
  a->m_pVect = gpVect; 
  a->m_nCount = 0;
  a->m_nMax = 100;
  a->m_nDelta = 1;
  for (int j = 100; j > 0; j--) { // Insert 10 elementos
    Insert(a, j);
  }
  for (int i = 0; i < a->m_nCount; i++) {
    cout << a->m_pVect[i] << ", ";
  }
  cout << endl;
    
  delete[] gpVect; 
  delete a;
  return 0;
}