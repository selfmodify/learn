#include <vector>
using namespace std;

class B {
public:
	B() {
		x = 0;
	}
	int x;
};

//typedef std::vector<const B*> vec;
typedef std::vector<B*> vec;
class A {
public:
	A(){
		for(int i=0; i < 3; ++i) {
			b_.push_back(new B());
		}
	}
	const vec& getB()  { return b_; }
private:
	vec b_;
};

int Test_main() {
	A a;
	const vec& b = a.getB();
	//b.push_back(new B());	 // syntax error
	b.at(0)->x = 5;

	//b.at(0) = new B();
	printf("%d %d\n", b[0]->x, a.getB()[0]->x);
	return 0;
}