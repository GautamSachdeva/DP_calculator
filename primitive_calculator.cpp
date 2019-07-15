#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;


vector<int> optimal_sequence(int n) {
vector <int> min_operations;
vector <int> sequence;
if(n == 1){
	sequence.push_back(1);
	return sequence;
}
if( n == 2){
	sequence.push_back(1);
	sequence.push_back(2);
	return sequence;
}
if( n == 3){
	sequence.push_back(1);
	sequence.push_back(3);
	return sequence;
}
min_operations.resize(n+1);
min_operations[0] = -1;
min_operations[1] = 0;
min_operations[2] = 1;
min_operations[3] = 1;
for(int i = 4 ; i  < min_operations.size() ; i++ ){
	int test;
	int best_test;
	for(int j = 0 ; j < 3 ; j++){
		if(j == 0){
			best_test = i - 1;
		}
		if(j == 1){
			if(i%2 == 0){
				test = i/2;
				if(min_operations[best_test] >= min_operations[test]){
					best_test = test;
				}
			}			
		}
		if(j == 2){
			if(i%3 == 0){
				test = i/3;
				if(min_operations[best_test] >= min_operations[test]){
					best_test = test;
				}
			}
		}
	}
	min_operations[i] = min_operations[best_test] + 1;	
}

int temp = n;
while(temp != 0){
	sequence.push_back(temp);
	int best_test;
	for(int i = 0 ; i < 3 ; i++){
		int test = temp;
		if(i == 0){
			best_test = test - 1;
		}
		if(i == 1){
			if (test%2 == 0){
				test = test/2;
				if(min_operations[test] <= min_operations[best_test]){
					best_test = test;
				}
			}
		}
		if( i == 2){
			if(test%3 == 0){
				test = test/3;
				if(min_operations[test] <= min_operations[best_test]){
					best_test = test;
				}
			}
		}
	}
	temp = best_test;
}
reverse(sequence.begin(),sequence.end());
return sequence;
}

int main(){
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
