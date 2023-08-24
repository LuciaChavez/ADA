#include <iostream>
using namespace std;
int gVect[100]; // Buffer to save the elements
int gnCount;    // Counter to know the number of elements used

void Insert(int elem) {
  if (gnCount < 100) { // we can only insert if there is space
    gVect[gnCount++] = elem;
  } // Insert the element at the end
}
int main() {
  for (int j = 100; j > 0; j--) { // inserte 30 elementos
    Insert(j);
  }
  cout << "gnCount:" << gnCount << endl;
  cout << "gVect[100]: " << endl;
  for (int i = 0; i < 100; i++) {
    cout << gVect[i] << ", ";
  }
  cout << endl;
  return 0;
}