
#include "TestDetConst.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"

#include "G4Sphere.hh"

namespace G4_BREMS {
    G4VPhysicalVolume* TestDetConst::Construct() {

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


        // create our detector, a hollow sphere around the entire system
        G4double outerRadius = 25 * cm;
        G4double innerRadius = 8 * cm;

        G4Material* lead = nist->FindOrBuildMaterial("G4_Pb");
        G4ThreeVector targetCenterPoint = G4ThreeVector(); // 0,0,0

        G4Sphere* sphereSolid = new G4Sphere("HollowSphereSolid", innerRadius, outerRadius, 0, 360 * deg, 0, 180 * deg);
        G4LogicalVolume* sphereLogical = new G4LogicalVolume(sphereSolid, lead, "HollowSphereLogical");

        G4VPhysicalVolume* spherePhysical = new G4PVPlacement(
            nullptr, // No rotation
            targetCenterPoint, // Position
            sphereLogical, // Logical volume
            "HollowSpherePhysical", // Name
            logicWorld, // Mother volume
            false, // No boolean operations
            0, // Copy number
            true); // Check overlaps


        // set the sphere as our gamma detector
        fGammaDetector = sphereLogical;


        return physWorld;
	}
}