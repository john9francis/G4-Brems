
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "Hit.hh"
#include "HitsCollection.hh"
#include "RunAction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

namespace G4_BREMS {
	SteppingAction::SteppingAction(RunAction* runAction) {
		// Get our detector volume 
		const auto detConstruction = static_cast<const DetectorConstruction*>(
			G4RunManager::GetRunManager()->GetUserDetectorConstruction()
			);
		fGammaDetector = detConstruction->GetGammaDetector();

		G4cout << "created stepping action" << G4endl;

		if (runAction) {
			// set the run action
			frunAction = runAction;

			G4cout << "put a runaction into stepping action" << G4endl;
		}

		// initialize the first step
		firstStep = true;
	}

	SteppingAction::~SteppingAction() {

	}

	void SteppingAction::UserSteppingAction(const G4Step* step) {
		// Register hit if the step is inside the tracking volume
		
		// get volume of the current step
		G4LogicalVolume* volume
			= step->GetPreStepPoint()->GetTouchableHandle()
			->GetVolume()->GetLogicalVolume();

		// end here if the particle isn't in the detector
		if (volume != fGammaDetector) { return;  }

		// Create a hit ONLY if it's the first step into the detector.
		if (step->IsFirstStepInVolume()) {

			// only works if we have this cout...
			G4cout << "Beginning hit..." << G4endl;

			// create a new hit
			Hit* hit = new Hit();
			hit->SetParticlePosition(step->GetPreStepPoint()->GetPosition());
			hit->SetParticleEnergy(step->GetPreStepPoint()->GetTotalEnergy());
			// NOTE: this isn't even working
			hit->Print(); 

			// Register that hit to the hits collection
				
			// NOTE: this doesn't seem to be working...
			//if (frunAction) {
			//	frunAction->AddHit(hit);
			//	frunAction->PrintHits();
			//}

		}

		
		
	}
	
}