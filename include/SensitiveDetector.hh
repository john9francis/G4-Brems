#ifndef G4_BREMS_SENSITIVE_DETECTOR_HH
#define G4_BREMS_SENSITIVE_DETECTOR_HH 1

#include "G4VSensitiveDetector.hh"

namespace G4_BREMS {
	class SensitiveDetector : public G4VSensitiveDetector {
	public:
		SensitiveDetector(G4String name);
		~SensitiveDetector() override = default;

		G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist) override;
		void PrintAll() override;
	};

};

#endif 
