#include "std_lib_facilities.h"

double convert_to_meters(double value, string unit) {
  double centimeters_to_meters = 1.0/100;
  double inches_to_centimeters = 2.54;
  double feet_to_inches = 12.0;
  double value_in_meters;
  if (unit == "cm")
    value_in_meters = value * centimeters_to_meters;
  else if (unit == "m")
    value_in_meters = value;
  else if (unit == "in")
    value_in_meters = value * inches_to_centimeters * centimeters_to_meters;
  else if (unit == "ft")
    value_in_meters = value * feet_to_inches * inches_to_centimeters * centimeters_to_meters;

  return value_in_meters;
}

int main() {
  double input = 0;
  string unit = "";
  double smallest = numeric_limits<double>::max();
  double largest = numeric_limits<double>::min();
  vector<double> history;

  while(cin >> input >> unit) {
    if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft") {
      input = convert_to_meters(input, unit);

      cout << "Input: " << input << " m" << endl;

      if (input < smallest) {
        cout << "the smallest so far " << endl;
        smallest = input;
      }

      if (input > largest) {
        cout << "the largest so far" << endl;
        largest = input;
      }

      history.push_back(input);

    } else
      cout << "Oops, not a valid unit" << endl;
  }

  sort(history);

  for(double x : history)
    cout << x << "\t";

  return 0;
}
