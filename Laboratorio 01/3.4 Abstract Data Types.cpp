#include <iostream>
#include <cstdlib> // Para poder hacer uso de realloc
using namespace std;

template <typename Type> class CVector
{
private:
  
  int m_nMax, // Control the number of allocated elements
  m_nDelta; // To control the growing
  void Init(int delta); // Init our private variables, etc
  void Resize(); // Resize the vector when occurs an overflow
public:
  Type*m_pVect; // Pointer to the buffer
  int m_nCount; // Control how many elements are actually used
  CVector(int delta = 10); // Constructor
  void Insert(Type elem); // Insert a new element
  // ...
  ~CVector();
};
/////////////////////////777

template <typename Type> CVector<Type>::~CVector() {
    delete[] m_pVect;
}
template <typename Type> void CVector<Type>::Init(int delta) {
    m_nMax = delta;
    m_nDelta = delta;
    m_nCount = 0;
    m_pVect = new int[m_nMax];
}
template <typename Type> void CVector<Type>:: Resize()
{
  m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
  m_nMax += m_nDelta;
}
// Class CVector implementation
template <typename Type> CVector<Type>::CVector(int delta)
{
  Init(delta);
}
template <typename Type> void CVector<Type>::Insert(Type elem)
{
  if( m_nCount == m_nMax ) // Verify the overflow
    Resize(); // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}

int main() {
  CVector< int> a;
  for (int j = 100; j > 0; j--) { 
    a.Insert(j);
  }
  for (int i = 0; i < a.m_nCount; i++) {
    cout << a.m_pVect[i] << ", ";
  }
    std::cout << std::endl;
  return 0;
}