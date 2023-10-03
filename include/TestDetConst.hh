#ifndef G4_BREMS_TEST_DET_CONST_H
#define G4_BREMS_TEST_DET_CONST_H 1

#include "G4VUserDetectorConstruction.hh"

namespace G4_BREMS
{
	class TestDetConst : public G4VUserDetectorConstruction
	{
	public:
		TestDetConst() = default;
		~TestDetConst() override = default;

		G4VPhysicalVolume* Construct() override;

		G4LogicalVolume* GetGammaDetector() const { return fGammaDetector; }

	private:
		G4LogicalVolume* fGammaDetector = nullptr;
	};
}


#endif