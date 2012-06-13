#include <iostream>
#include <stdio.h>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Functions.h"
#include "SupplyDemandManager.h"

using namespace std;
using namespace boost;

int main() {
  // testing variables
  double calculated, answer, difference;

  // exponential function
  shared_ptr<ExponentialFunction> exp_fp(new ExponentialFunction(2,3.4,5));
  cout << "testing the exponential function for correctness:" << endl;
  for (int i=0; i < 11; i++) {
    calculated = exp_fp->value(i);
    answer = 2*exp(3.4*i)+5;
    difference = calculated - answer;
    printf("calculated: %+.4e, answer: %+.4e, difference: %1.1f\n",calculated,answer,difference);
  }

  cout << endl;

  // linear function
  shared_ptr<LinearFunction> lin_fp(new LinearFunction(2,3.4));
  cout << "testing the linear function for correctness:" << endl;
  for (int i=0; i < 11; i++) {
    calculated = lin_fp->value(i);
    answer = 2*i+3.4;
    difference = calculated - answer;
    printf("calculated: %+.4e, answer: %+.4e, difference: %1.1f\n",calculated,answer,difference);
  }
  
  cout << endl;

  // set up products
  Product a("a"), b("b");

  // set up producers
  Producer x_a(a,1,2), y_a(a,2,3);
  vector<Producer> a_vec; a_vec.push_back(x_a); a_vec.push_back(y_a);
  Producer x_b(b,2,2), y_b(b,1,1.1);
  vector<Producer> b_vec; b_vec.push_back(x_b); b_vec.push_back(y_b);

  // set up manager
  SupplyDemandManager manager;
  manager.registerProduct(a,exp_fp,a_vec);
  manager.registerProduct(b,lin_fp,b_vec);

  for (int i=0; i<3; i++) {
    cout << "a demand at " << i << ": " << manager.demand(a,i) << endl;
    cout << "b demand at " << i << ": " << manager.demand(b,i) << endl;
    cout << endl;
    cout << "a supply at " << i << ": " << manager.supply(a) << endl;
    cout << "b supply at " << i << ": " << manager.supply(b) << endl;
    cout << endl;
    manager.increaseSupply(a,manager.demand(a,i)-manager.supply(a));
    manager.increaseSupply(b,manager.demand(b,i)-manager.supply(b));
  }

  return 0;
}
