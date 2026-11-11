#include <iostream>

using namespace std;

double sumGreaterThan(const double values[], int count, double threshold) {
  double sum = 0.0;

  for (int elementIndex = 0; elementIndex < count; ++elementIndex) {
    if (values[elementIndex] > threshold) {
      sum += values[elementIndex];
    }
  }

  return sum;
}

int main() {
  constexpr int maxCount = 100;
  constexpr double maxMagnitude = 1000.0;
  double threshold;
  int wCount;
  int dCount;
  double wValues[maxCount];
  double dValues[maxCount];

  if (!(cin >> threshold) || !(cin >> wCount) || wCount < 1 || wCount > maxCount || !(cin >> dCount) || dCount < 1 || dCount > maxCount) {
    cout << "INVALID" << endl;
    return 1;
  }

  for (int elementIndex = 0; elementIndex < wCount; ++elementIndex) {
    if (!(cin >> wValues[elementIndex]) || wValues[elementIndex] < -maxMagnitude || wValues[elementIndex] > maxMagnitude) {
      cout << "INVALID" << endl;
      return 1;
    }
  }

  for (int elementIndex = 0; elementIndex < dCount; ++elementIndex) {
    if (!(cin >> dValues[elementIndex]) || dValues[elementIndex] < -maxMagnitude || dValues[elementIndex] > maxMagnitude) {
      cout << "INVALID" << endl;
      return 1;
    }
  }

  double wSum = sumGreaterThan(wValues, wCount, threshold);
  double dSum = sumGreaterThan(dValues, dCount, threshold);

  cout << "Sum of W elements greater than r: " << wSum << endl;
  cout << "Sum of D elements greater than r: " << dSum << endl;

  return 0;
}