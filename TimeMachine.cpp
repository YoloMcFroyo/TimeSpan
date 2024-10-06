#include <iostream>
#include "TimeSpan.h"

using namespace std;

int main()
{

  TimeSpan checker1(0, 600, 0);
  TimeSpan checker2(10, 0, 0);
  TimeSpan checker3(0, 0, 36000);

  cout << "checker1: " << checker1 << endl;
  cout << "checker2: " << checker2 << endl;
  cout << "checker3: " << checker3 << endl;

  cout << "checker1 is ";

  if (checker1 == checker2)
  {
    cout << "==";
  }
  else
  {
    cout << "!=";
  }

  cout << " to checker2" << endl;

  cout << "______________________" << endl
       << endl;

  TimeSpan checker4(0, -70, 0);
  TimeSpan checker5(0, -1, 10);
  cout << "checker4: " << checker4 << endl;
  cout << "checker5: " << checker5 << endl;

  cout << "checker4 is ";
  if (checker4 == checker5)
  {
    cout << "==";
  }
  else
  {
    cout << "!=";
  }
  cout << " to checker5" << endl;

  cout << "______________________" << endl
       << endl;

  TimeSpan checker6(0, 10, 0);
  TimeSpan checker7(0, 0, 600);

  cout << "checker6: " << checker6 << endl;
  cout << "checker7: " << checker7 << endl;

  checker6 -= checker7;

  cout << "After 'checker6 -= checker7'," << endl
       << "checker6 is: " << checker6 << endl;

  cout << "______________________" << endl
       << endl;

  TimeSpan checker8(1.5, 4, -10);
  cout << "checker8: " << checker8 << endl;

  TimeSpan checker9(1, -380, 24.5);
  cout << "checker9: " << checker9 << endl;

  TimeSpan checker10(-40, 50, -20);
  cout << "checker10: " << checker10 << endl;

  cout << "______________________" << endl
       << endl;

  TimeSpan checker11(8, 20, 40);
  TimeSpan checker12(-8, -20, -40);

  cout << "checker11: " << checker11 << endl;
  cout << "checker12: " << checker12 << endl;

  checker12 = -checker12;
  if (checker11 == checker12)
  {
    cout << "After using Unary Negation, checker11 and checker12 are the same" << endl;
  }

  cout << "______________________" << endl
       << endl;

  TimeSpan checker13(0, 10, 0);
  TimeSpan checker14(0, 6, 0);
  TimeSpan checker15(1, 0, 0);
  TimeSpan checker16;
  TimeSpan checker17;

  checker16 = checker13 - checker14;
  checker17 = checker13 + checker14 + checker15;

  cout << "checker16 should be 0 hours, 4 minutes, 0 seconds" << endl;
  cout << "verifying: " << checker16 << endl;

  cout << "checker17 should be 1 hours, 16 minutes, 0 seconds" << endl;
  cout << "verifying: " << checker17 << endl;

}