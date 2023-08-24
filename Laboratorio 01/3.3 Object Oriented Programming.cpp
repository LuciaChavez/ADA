#include <iostream>
#include <cstdlib> // Para poder hacer uso de realloc
using namespace std;

// Class CVector definition
class CVector
{
private:
  int m_nMax, // Control how many are allocated as maximum
  m_nDelta; // To control the growing
  void Init(int delta); // Init our private variables, etc
  void Resize(); // Resize the vector when occurs an overflow
public:
int *m_pVect, // Pointer to the buffer
  m_nCount; // Control how many elements are actually used
  CVector(int delta = 10); // Constructor
  void Insert(int elem); // Insert a new element
  // More methods go here
  ~CVector();
};

CVector::CVector(int delta) {
    Init(delta);
}

CVector::~CVector() {
    delete[] m_pVect;
}
void CVector::Init(int delta) {
    m_nMax = delta;
    m_nDelta = delta;
    m_nCount = 0;
    m_pVect = new int[m_nMax];
}

void CVector:: Resize()
{
  m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
  m_nMax += m_nDelta;
}
void CVector::Insert(int elem)
{
  if( m_nCount == m_nMax ){// Verify the overflow
    Resize(); // Resize the vector before inserting elem
  }
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}
int main() {
  CVector a;
  for (int j = 100; j > 0; j--) {
    a.Insert(j);
  }

  for (int i = 0; i < a.m_nCount; i++) {
    cout << a.m_pVect[i] << ", ";
  }
    std::cout << std::endl;
  return 0;
}