
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

namespace G4_BREMS {
	SteppingAction::SteppingAction(EventAction* eventAction) {
		// Get our detector volume 
		const auto detConstruction = static_cast<const DetectorConstruction*>(
			G4RunManager::GetRunManager()->GetUserDetectorConstruction()
			);
		fGammaDetector = detConstruction->GetGammaDetector();


		if (eventAction) {
			// set the event action
			feventAction = eventAction;

		}

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

		// If it's the first step in the volume, save the position. 
		if (step->IsFirstStepInVolume()) {
			feventAction->SetPosition(step->GetPreStepPoint()->GetPosition());
		}

		// Register all the energy to the eventAction while it's in the detector.
		feventAction->AddEnergy(step->GetTotalEnergyDeposit());
		
	}
	
}