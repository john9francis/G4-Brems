
#include "Hit.hh"

namespace G4_BREMS {
	Hit::Hit() {
		hEnergy = 0.; 
		hPosition = G4ThreeVector();
	}

	void Hit::Print() {
		G4cout
			<< "Energy: "
			<< G4BestUnit(hEnergy, "Energy")
			<< " "
			<< "Position: "
			<< G4BestUnit(hPosition.getX(), "Length")
			<< G4BestUnit(hPosition.getY(), "Length")
			<< G4BestUnit(hPosition.getZ(), "Length")
			<< G4endl;
	}

	void Hit::SetEnergy(G4double e) { hEnergy = e; }
	void Hit::SetPos(G4ThreeVector p) { hPosition = p; }


}