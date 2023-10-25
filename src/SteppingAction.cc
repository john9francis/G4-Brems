
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"


namespace G4_BREMS {
	SteppingAction::SteppingAction(EventAction* eventAction) {

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

		// get the first secondary, it should be a gamma
		const G4Track* track = (*secondaries)[0];

		const G4ParticleDefinition* particle = track->GetParticleDefinition();

		G4String particleName = particle->GetParticleName();


		if (particleName != "gamma") { return; }


		G4double energy = track->GetTotalEnergy();
		G4cout << "Secondary energy: " << G4BestUnit(energy, "Energy") << G4endl;
		feventAction->AddEnergy(energy);


	}
	
}