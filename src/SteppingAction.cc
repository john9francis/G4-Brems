
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "Hit.hh"
#include "HitsCollection.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

namespace G4_BREMS {
	SteppingAction::SteppingAction() {
		// Get our scoring volume 
		const auto detConstruction = static_cast<const DetectorConstruction*>(
			G4RunManager::GetRunManager()->GetUserDetectorConstruction()
			);
		fGammaDetector = detConstruction->GetGammaDetector();

		// Create hits collections


	}

	SteppingAction::~SteppingAction() {
		// delete my hits collections
	}

	void SteppingAction::UserSteppingAction(const G4Step* step) {
		// Register hit if the step is inside the tracking volume
		
		// get volume of the current step
		G4LogicalVolume* volume
			= step->GetPreStepPoint()->GetTouchableHandle()
			->GetVolume()->GetLogicalVolume();

		// if the volume is our gamma detector, create a hit.
		// else, move on. 

		if (volume == fGammaDetector) {

			// Create a hit 
			Hit* hit = new Hit();
			hit->SetParticlePosition(step->GetPreStepPoint()->GetPosition());
			hit->SetParticleEnergy(step->GetPreStepPoint()->GetTotalEnergy());

			// Register that hit to the hits collection


			// Delete that hit
			delete hit;
		
		}
	}
	
}