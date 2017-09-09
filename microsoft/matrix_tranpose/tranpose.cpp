// extract to string
#include <iostream>
#include <string>
#include <vector>

#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main ()
{


  int M[100][100];
  for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
      M[i][j] = -1;

  int T[100][100];

  int i, m,n;
  string line;

  //  vector< vector<int> > T;

  while (getline (cin,line)){
    //    cout << line << "\n";


    istringstream input(line);
    vector<int> result;
    int value;
    while (input >> value)
      {
	result.push_back(value);
	M[n][i] = value;
	i++;
      }
    m = i;
  cout << "m = " << m << "\n";
    i = 0;
    //   T.push_back(result);
    //    m = result.size();
    n++;
  }

  //  cout << "m = " << m << "\n";
  cout << "n = " << n << "\n";

  


  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++)
      { 
	T[i][j] = M[j][i];
	cout << T[i][j] << " ";


      }

    cout << "\n";
  }
  return 0;
}
