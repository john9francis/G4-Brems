
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
        G4double worldSize = 1 * m;
        G4Material* vacuum = nist->FindOrBuildMaterial("G4_Galactic");

        auto solidWorld = new G4Box("World",
            worldSize / 2,
            worldSize / 2,
            worldSize);

        auto logicWorld = new G4LogicalVolume(solidWorld,
            vacuum, 
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
        G4double outerTargetRadius = 1.5 * cm;
        G4double targetThickness = 1 * mm;

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
        G4ThreeVector targetPos = G4ThreeVector(); // 0,0,0
        G4RotationMatrix* targetRotation = new G4RotationMatrix();

        // place the target in the world
        new G4PVPlacement(targetRotation, 
            targetPos, 
            logicTarget, 
            "Target",
            logicWorld, 
            false, 
            0);

        /*
        // create a graphite absorber to absorb electrons
        G4Material* graphite = nist->FindOrBuildMaterial("G4_GRAPHITE");

        G4double innerAbsorberRadius = 0.0;
        G4double outerAbsorberRadius = 1.5 * cm;
        G4double absorberThickness = 1.5 * cm;

        G4Tubs* solidAbsorber = new G4Tubs("Absorber",
            innerAbsorberRadius,
            outerAbsorberRadius,
            absorberThickness / 2.0,
            0.0,
            360.0 * deg);

        G4LogicalVolume* logicAbsorber = new G4LogicalVolume(solidAbsorber,
            graphite,
            "Absorber");

        // absorber position and rotation
        G4double absorberZ = targetPos.getZ() + (absorberThickness / 2);
        G4ThreeVector absorberPos = G4ThreeVector(0.0, 0.0, absorberZ);
        G4RotationMatrix* absorberRot = new G4RotationMatrix();

        // place the absorber
        new G4PVPlacement(absorberRot,
            absorberPos,
            logicAbsorber,
            "Absorber",
            logicWorld,
            false,
            0);

        

        // create tungsten collimator
        G4double innerColRadius = 4.0 * cm;
        G4double outerColRadius = 7.0 * cm;
        G4double colThickness = 6.2 * cm;

        G4Tubs* solidCol = new G4Tubs("Collimator",
            innerColRadius,
            outerColRadius,
            colThickness / 2.0,
            0.0,
            360.0 * deg);

        G4LogicalVolume* logicCol = new G4LogicalVolume(solidCol,
            tungsten,
            "Collimator");

        // collimator position and rotation
        G4double colZ =
            absorberZ
            + (absorberThickness / 2)
            + (colThickness / 2);
        G4ThreeVector colPos = G4ThreeVector(0, 0, colZ);
        G4RotationMatrix* colRotation = new G4RotationMatrix();

        // place the collimator in the world
        new G4PVPlacement(colRotation,
            colPos,
            logicCol,
            "Collimator",
            logicWorld,
            false,
            0);
        
        
        // Detector
        G4double detectorSizeXY = 50 * cm;
        G4double detectorSizeZ = 15 * cm;

        // detector materials
        G4Material* lead = nist->FindOrBuildMaterial("G4_Pb");
        //G4Material* leadTungstate = nist->FindOrBuildMaterial("G4_PbWO4");
        //G4Material* BGO = nist->FindOrBuildMaterial("G4_BGO");
        //G4Material* lAr = nist->FindOrBuildMaterial("G4_lAr");
        //G4Material* scin = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");


        G4Box* solidDetector = new G4Box(
            "Detector",
            detectorSizeXY,
            detectorSizeXY,
            detectorSizeZ);

        G4LogicalVolume* logicDetector = new G4LogicalVolume(
            solidDetector,
            lead,
            "Detector");

        G4double detectorZ = targetThickness / 2 + detectorSizeZ + 5*cm;
        G4ThreeVector detectorPos = G4ThreeVector(0, 0, detectorZ);
        G4RotationMatrix* detRotation = new G4RotationMatrix();


        // place the detector
        new G4PVPlacement(detRotation,
            detectorPos,
            logicDetector,
            "Detector",
            logicWorld,
            false,
            0);

        // Define this detector as the gamma detector
        fGammaDetector = logicDetector;
	
        */

        return physWorld;
    }

}