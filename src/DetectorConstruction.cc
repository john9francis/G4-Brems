
#include "DetectorConstruction.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"

namespace G4_BREMS
{
	G4VPhysicalVolume* DetectorConstruction::Construct()
	{
		// construct our detectors here

        // Get nist material manager
        G4NistManager* nist = G4NistManager::Instance();


		// Start with constructing the world:
        G4double worldSize = 10 * cm;
        G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

        auto solidWorld = new G4Box("World",
            worldSize,
            worldSize,
            worldSize);

        // NOTE: the world is made of air... can I make it a vacuum somehow?
        auto logicWorld = new G4LogicalVolume(solidWorld,
            air, 
            "World");

        auto physWorld = new G4PVPlacement(nullptr,
            G4ThreeVector(), 
            logicWorld, 
            "World", 
            nullptr, 
            false, 
            0);


        // create our tungsten target
        G4Material* tungsten = nist->FindOrBuildMaterial("G4_W");

        G4double innerTargetRadius = 0.0;
        G4double outerTargetRadius = 5.0 * cm;
        G4double targetThickness = 0.5 * cm;

        G4Tubs* solidTarget = new G4Tubs("Target",
            innerTargetRadius,
            outerTargetRadius,
            targetThickness / 2.0,
            0.0,
            360.0 * deg);

        G4LogicalVolume* logicTarget = new G4LogicalVolume(solidTarget, 
            tungsten, 
            "Target");

        // target position and rotation
        G4ThreeVector targetPos = G4ThreeVector();
        G4RotationMatrix* targetRotation = new G4RotationMatrix();

        // place the target in the world
        new G4PVPlacement(targetRotation, 
            targetPos, 
            logicTarget, 
            "Target",
            logicWorld, 
            false, 
            0);
	
        return physWorld;
    }

}