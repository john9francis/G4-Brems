
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
		// and record in 2 ways: 1. the relative energy based on the electron that created it,
		// and 2. the absolute energy of all photons generated. 
		// NOTE: set a condition to make sure it is in the correct volume,
		// if there were other detectors that possible generate secondary gammas, they will be recorded as well.
		

		// set nTuple id's for analysis
		G4int absNTupleID = 0;
		G4int relNTupleID = 1;
	
		// end here if there were no secondaries
		G4int nSecondaryParticles = step->GetNumberOfSecondariesInCurrentStep();
		if (nSecondaryParticles == 0) { return; }


		// create a list of all secondary particles created in this step
		const std::vector<const G4Track*>* secondaries
			= step->GetSecondaryInCurrentStep();

		// loop through, and send the gamma secondaries to analysis manager.
		for (int i = 0; i < secondaries->size(); i++) {

			const G4Track* track = (*secondaries)[i];

			G4String particleName = track->GetParticleDefinition()->GetParticleName();

			// if it's a bremsstrahlung gamma, send the energy over to analysis
			if (particleName == "gamma") {
				G4double energy = track->GetTotalEnergy();

				auto analysisManager = G4AnalysisManager::Instance();
				analysisManager->FillNtupleDColumn(absNTupleID, 0, energy);
				analysisManager->AddNtupleRow(absNTupleID);
			}
		}



		// Now for the relative energies. 

	}
	
}