
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
		// Check if secondary particles are created (bremsstrahlung photons)
		// and send them over to event action.

		// check how many secondaries
		G4int nSecondaryParticles = step->GetNumberOfSecondariesInCurrentStep();

		// end here if there were no secondaries
		if (nSecondaryParticles == 0) { return; }

		// create a list of all secondary particles created in this step
		const std::vector<const G4Track*>* secondaries
			= step->GetSecondaryInCurrentStep();

		// send each particle to the eventAction
		for (G4int i = 0; i < nSecondaryParticles; i++) {
			// get track object which has kinetic energy and particle definition
			const G4Track* track = (*secondaries)[i];
			
			// get all the info off the particle
			const G4ParticleDefinition* particle = track->GetParticleDefinition();
			G4String name = particle->GetParticleName();
			// testing:
			G4cout << name << G4endl;
			G4double energy = track->GetKineticEnergy();

			// send all the info to eventAction

		}


	}
	
}