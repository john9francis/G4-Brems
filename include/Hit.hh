#ifndef G4_BREMS_HIT_HH
#define G4_BREMS_HIT_HH

#include "G4VHit.hh"
#include "G4ThreeVector.hh"

namespace G4_BREMS {
	// My own hit class
	class Hit : G4VHit {
	public:
		Hit() { hEnergy = 0.; hPosition = G4ThreeVector(); };
		~Hit() {};

		void SetEnergy(G4double e) { hEnergy = e; }
		void SetPos(G4ThreeVector p) { hPosition = p; }

	private:
		G4double hEnergy;
		G4ThreeVector hPosition;
	};
}

#endif // !G4_BREMS_HIT_HH
