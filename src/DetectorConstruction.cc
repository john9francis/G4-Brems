
#include "DetectorConstruction.hh"

#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"

namespace G4_BREMS
{
	G4VPhysicalVolume* DetectorConstruction::Construct()
	{
		// construct our detectors here

        // defining parameters
        G4double worldSize = 10 * cm;
        // Get nist material manager
        G4NistManager* nist = G4NistManager::Instance();

        // world properties
        //G4Material* worldMaterial = nist->FindOrBuildMaterial("G4_AIR");
        //G4bool checkOverlaps = false;


		// Start with constructing the world:
        auto solidWorld = new G4Box("World",
            worldSize,
            worldSize,
            worldSize);

        auto logicWorld = new G4LogicalVolume(solidWorld, nullptr, "World");

        auto physWorld = new G4PVPlacement(nullptr,
            G4ThreeVector(), logicWorld, "World", nullptr, false, 0);
	
        return physWorld;
    }

}