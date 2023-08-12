
#include "Hit.hh"

using namespace std;

namespace G4_BREMS {
Hit::Hit() {
	fParticleEnergy = 0;
	fParticlePosition = G4ThreeVector();
}
Hit::~Hit() {}

void Hit::Print() {
	G4cout << "Hit!" << '\n';
	G4cout << "Energy: " << fParticleEnergy << "Position: " << fParticlePosition << '\n';
}

}