#include <iostream>
#include <vector>
using namespace std;

class A {
public:
	A(int dim1, int dim2) :v(dim1, std::vector<int>(dim2)) {}
private:
	std::vector< std::vector<int> > v;
};

int main(){
	return 0;
}