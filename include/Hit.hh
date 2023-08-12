#ifndef G4_BREMS_HIT_H
#define G4_BREMS_HIT_H 1

// My own Hit class

#include "G4VHit.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

namespace G4_BREMS {
	class Hit : public G4VHit {
	public:
		Hit();
		~Hit();

		//void Draw() override;
		void Print() override;

		void SetParticlePosition(const G4ThreeVector pos) {
			fParticlePosition = pos;
		}
		void SetParticleEnergy(G4double energy) {
			fParticleEnergy = energy;
		}

	private:
		G4ThreeVector fParticlePosition;
		G4double fParticleEnergy;
	};
}

#endif // !G4_BREMS_HIT_H
