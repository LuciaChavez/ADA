#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>

using namespace std;

struct Point {
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
};

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}
double distance(const Point& a, const Point& b) {
  double dx = a.x - b.x; // en coordenadas x -- (x2 - x1)
  double dy = a.y - b.y; // en coordenadas y -- (y2 - y1)
  //formula distancia entre dos puntos:  d = √((x2 - x1)² + (y2 - y1)²)  
  return sqrt(dx * dx + dy * dy);
}
double closestPair(vector<Point>& points) {
  int n = points.size();
  // Casos base: si hay menos de 3 puntos, calculamos la distancia entre ellos
  if (n == 2) {
    return distance(points[0], points[1]);
  }
  if (n == 3) {//min retorna el mínimo entre la lsita de numeros dados
    return min({distance(points[0], points[1]), distance(points[1], points[2]), distance(points[0], points[2])});
  }
  // Ordenamos los puntos por coordenada x, con la funcion sort
  sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
    return a.x < b.x;
  });
  // Dividir el conjunto de puntos en dos mitades
  int mid = n / 2; // sólo funciona con 2 :(
  vector<Point> left_half(points.begin(), points.begin() + mid);
  vector<Point> right_half(points.begin() + mid, points.end());
  double delta1 = closestPair(left_half);
  double delta2 = closestPair(right_half);
  
  double delta = min(delta1, delta2);

  vector<Point> strip;
  double mid_x = (points[mid - 1].x + points[mid].x) / 2.0;

  for (const Point& point : points) {
    if (fabs(point.x - mid_x) < delta) {
      strip.push_back(point);
    }
  }
  sort(strip.begin(), strip.end(), compareY);
  for (int i = 0; i < strip.size(); ++i) {
    for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < delta; ++j) {
      delta = min(delta, distance(strip[i], strip[j]));
    }
  }

  return delta;
}

int main() {
  vector<Point> points = {Point(0, 0), Point(1, 2), Point(2, 4), Point(3, 1), Point(4, 3)};
  sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
    return a.x < b.x;
  });

  double closest = closestPair(points);
  cout << "La distancia entre el par de puntos mas cercanos es: " << closest << endl;
  return 0;
}
