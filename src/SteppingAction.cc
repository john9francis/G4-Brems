
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "Hit.hh"
#include "HitsCollection.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

namespace G4_BREMS {
	SteppingAction::SteppingAction() {
		// Get our detector volume 
		const auto detConstruction = static_cast<const DetectorConstruction*>(
			G4RunManager::GetRunManager()->GetUserDetectorConstruction()
			);
		fGammaDetector = detConstruction->GetGammaDetector();

		// Create hits collections
		fGammaHitsCollection = new HitsCollection();


	}

	SteppingAction::~SteppingAction() {
		// print all the hits? (I hope)
		fGammaHitsCollection->PrintAllHits();

		// delete my hits collections
		delete fGammaHitsCollection;

	}

	void SteppingAction::UserSteppingAction(const G4Step* step) {
		// Register hit if the step is inside the tracking volume
		
		// get volume of the current step
		G4LogicalVolume* volume
			= step->GetPreStepPoint()->GetTouchableHandle()
			->GetVolume()->GetLogicalVolume();

		// if the volume is our gamma detector, create a hit.
		// else, move on. 

		if (volume != fGammaDetector) { return;  }

		if (volume == fGammaDetector) {

			//G4cout << "Inside detector..." << G4endl;

			// Create a hit ONLY if it's the first step into the detector.
			if (step->IsFirstStepInVolume()) {
					
				// only works if we have this cout...
				G4cout << "Beginning hit..." << G4endl;

				// create a new hit
				Hit* hit = new Hit();
				hit->SetParticlePosition(step->GetPreStepPoint()->GetPosition());
				hit->SetParticleEnergy(step->GetPreStepPoint()->GetTotalEnergy());
				hit->Print();

				// Register that hit to the hits collection
				fGammaHitsCollection->insert(hit);
			}

		
		}
	}
	
}