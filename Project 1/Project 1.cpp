/* Project1
* Joseph Graves
* Code copied from the Project1_hints.pdf
* As well as an if statement that will exit the loop if the principal is negative
* And a print statement that prints the data.
*/
#include <iostream>
using namespace std;
int main() {
  // VARIABLE INITIALIZATION
  double loan = 0;
  double interest = 0;
  double interestTotal = 0;
  double interestRate = 0;
  double interestRateC = 0;
  double monthlyPaid = 0;
  int currentMonth = 0;
  double principal = 0;
  // CURRENCY FORMATTING
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  // USER INPUT
  // NOTE: For valid input, the loan, interest, and monthly payment must
  // be positive. The monthly payment must also be large enough to
  // terminate the loan.
  do {
    cout << "\nLoan Amount: ";
    cin >> loan;
  } while (loan <= 0.0);
  
  do {
    cout << "Interest Rate (% per yer): ";
    cin >> interestRate;
  } while (interestRate <= 0.0);
  
  // GET PROPER INTEREST RATES FOR CALCULATIONS
  interestRate /= 12;
  interestRateC = interestRate / 100;
  
  do {
    cout << "Monthly Payments: ";
    cin >> monthlyPaid;
  } while (monthlyPaid <= 0.0);
  
  cout << endl;
  // AMORTIZATION TABLE
  cout << "*****************************************************************\n"
       << "\tAmortization Table\n"
       << "*****************************************************************\n"
       << "Month\tBalance Payment \tRate \tInterest Principal\n";
  
  // LOOP TO FILL THE TABLE
  while (loan > 0) {
    if (currentMonth == 0) {
      cout << currentMonth++ << "\t$" << loan;
        if (loan < 1000) cout << "\t";
        cout << " N/A\t\tN/A\tN/A\t N/A\n";
      }
      else {
        interest = interestRateC * loan;
        principal = monthlyPaid - interest;
        if (principal < 0) {
          break;
        }
        loan -= principal;
        interestTotal += interest;
        cout << currentMonth++ << "\t$" << loan << "\t $" << monthlyPaid << "\t" << interestRate << " \t$" << interest << "\t $" << principal << "\n";
      }
    }
    cout << "\n****************************************************************\n";
    cout << "\nIt takes " << --currentMonth << " months to pay off " << "the loan.\n" << "Total interest paid is: $" << interestTotal;
    cout << endl << endl;
    return 0;
  }
}
