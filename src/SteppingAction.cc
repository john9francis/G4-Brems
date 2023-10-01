
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

		// now, check what type of particle it is
		G4Track* track = step->GetTrack();
		G4ParticleDefinition* particleDefinition = track->GetDefinition();
		G4String particleName = particleDefinition->GetParticleName();
		//G4cout << particleName << G4endl;

		// filter out the e- (for now,)
		// TODO: add a separate analysis for electrons
		if (particleName != "gamma") { return; }


		// If it's the first step in the volume, save the position. 
		if (step->IsFirstStepInVolume()) {
			feventAction->SetPosition(step->GetPreStepPoint()->GetPosition());
		}

		// Register all the energy to the eventAction while it's in the detector.
		feventAction->AddEnergy(step->GetTotalEnergyDeposit());

		//TESTING: print velocity to see if it's greater than c
		//G4double velocity = step->GetPreStepPoint()->GetVelocity();
		//
		//G4cout 
		//	<< G4BestUnit(velocity, "Velocity")
		//	<< G4endl;
		
	}
	
}