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

//interest_bank es /100 + 1 para hacerlo lo que aumenta sobre 1 --->está en porcentaje
