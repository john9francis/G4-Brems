#ifndef G4_BREMS_HIT_HH
#define G4_BREMS_HIT_HH

#include "G4VHit.hh"
#include "G4ThreeVector.hh"

#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

namespace G4_BREMS {
	// My own hit class
	class Hit : public G4VHit {
	public:
		Hit() { hEnergy = 0.; hPosition = G4ThreeVector(); };
		~Hit() {};

		void Print() override {
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

		void SetEnergy(G4double e) { hEnergy = e; }
		void SetPos(G4ThreeVector p) { hPosition = p; }

	private:
		G4double hEnergy;
		G4ThreeVector hPosition;
	};
}

#endif // !G4_BREMS_HIT_HH
