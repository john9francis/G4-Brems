#ifndef G4_BREMS_DETECTORCONSTRUCTION_H
#define G4_BREMS_DETECTORCONSTRUCTION_H 1

#include "G4VUserDetectorConstruction.hh"

namespace G4_BREMS
{
	class DetectorConstruction : public G4VUserDetectorConstruction
	{
	public:
		DetectorConstruction() = default;
		~DetectorConstruction() override = default;

		G4VPhysicalVolume* Construct() override;
	};
}


#endif