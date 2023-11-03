
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

#include "G4AnalysisManager.hh"

#include "G4UnitsTable.hh"

namespace G4_BREMS {
	SteppingAction::SteppingAction() {
		fFirstSecondaryRecorded = false;
	}

	SteppingAction::~SteppingAction() {
	}

	void SteppingAction::UserSteppingAction(const G4Step* step) {
		// Check if secondary particles are created (bremsstrahlung photons)
		// and send them over to event action.

		// set a flag to make sure we only get the first secondary
		if (step->IsFirstStepInVolume()) {
			fFirstSecondaryRecorded = false;
		}

		// end here if we already recorded a secondary 
		if (fFirstSecondaryRecorded) { return; }

		// check how many secondaries
		G4int nSecondaryParticles = step->GetNumberOfSecondariesInCurrentStep();

		// end here if there were no secondaries
		if (nSecondaryParticles == 0) { return; }


		// create a list of all secondary particles created in this step
		const std::vector<const G4Track*>* secondaries
			= step->GetSecondaryInCurrentStep();

		// get the first secondary, it should be a gamma
		const G4Track* track = (*secondaries)[0];

		// Check particle name
		const G4ParticleDefinition* particle = track->GetParticleDefinition();
		G4String particleName = particle->GetParticleName();
		if (particleName != "gamma") { return; }


		// if it's a bremsstrahlung gamma, send the energy over to analysis
		G4double energy = track->GetTotalEnergy();

		auto analysisManager = G4AnalysisManager::Instance();
		analysisManager->FillNtupleDColumn(0, energy);
		analysisManager->AddNtupleRow();

		// set the flag because we got the gamma for this track
		fFirstSecondaryRecorded = true;

		// print to see the energy
		//G4cout << G4BestUnit(energy, "Energy") << G4endl;


	}
	
}