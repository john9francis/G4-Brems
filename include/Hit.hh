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
		Hit();
		~Hit() override = default;

		void Print() override;

		void SetEnergy(G4double e);
		void SetPos(G4ThreeVector p);

	private:
		G4double hEnergy;
		G4ThreeVector hPosition;
	};
}

#endif // !G4_BREMS_HIT_HH
