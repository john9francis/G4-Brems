
#include "SensitiveDetector.hh"

namespace G4_BREMS {
	SensitiveDetector::SensitiveDetector(G4String name)
		: G4VSensitiveDetector(name) {
		
	}

	G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist) {
		return false;
	}

	void SensitiveDetector::PrintAll() {

	}
}