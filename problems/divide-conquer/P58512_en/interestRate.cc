#include <iostream>

using namespace std;

double fastestExp(double c, int n) { //Double interés int días
	if (n == 0) return 1;
	double tmp = fastestExp(c, n/2);
	if (n % 2 == 0) return tmp * tmp;
	else return tmp * tmp * c;
}

int numDays(double money_lend, double interest_oak, double interest_bank, int current_day, int max_day) {
  if (current_day <= max_day) {
    int mid = (max_day + current_day) / 2;
    double money_bank = fastestExp(interest_bank, mid) * money_lend;
    double money_oak = interest_oak * mid + money_lend;
    if (money_oak > money_bank) return numDays(money_lend, interest_oak, interest_bank, mid + 1, max_day);
    if (money_oak < money_bank) return numDays(money_lend, interest_oak, interest_bank, current_day, mid - 1);
    return mid;
  }

  return current_day;
}

//hago como cerca dicotómica ---> he juntado fastestExp con dicotomicSearch

//interest_bank es /100 + 1 para hacerlo lo que aumenta sobre 1 --->está en porcien y quiero tanto por uno


int main() {
    double money_lend, interest_oak, interest_bank;
	int current_day, max_day;

	max_day = 100000;
	current_day = 1;

    while (cin >> money_lend >> interest_oak >> interest_bank) {
        cout << numDays(money_lend, interest_oak, (interest_bank/100)+1, current_day, max_day) << endl;
    }

    return 0;
}
