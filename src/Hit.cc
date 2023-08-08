
#include "Hit.hh"

using namespace std;

namespace G4_BREMS {
Hit::Hit() {}
Hit::~Hit() {}

void Hit::Print() {
	std::cout << "Hit!" << '\n';
}

}