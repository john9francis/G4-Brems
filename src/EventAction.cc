
#include "EventAction.hh"
#include "G4AnalysisManager.hh"

namespace G4_BREMS {
	EventAction::EventAction() {
		fEnergy = 0.;
		fCounter = 0;
	}

	void EventAction::BeginOfEventAction(const G4Event* anEvent) {
		// begin of event actions here
		fEnergy = 0.;
		fCounter = 0;
	}
	
	// setting energy and position
	void EventAction::AddEnergy(G4double e) { 
		if (fCounter == 0) {
			fEnergy += e;
		}
		
		fCounter++;
	}

	void EventAction::EndOfEventAction(const G4Event* anEvent) {

		// if there was any energy deposited, tell the analysis manager.
		if (fEnergy > 0) {

			auto analysisManager = G4AnalysisManager::Instance();

			// add all the info to the analysis nTuples
			G4int energyColumnId = 0;
			G4int posXColumnId = 1;
			G4int posYColumnId = 2;
			G4int posZColumnId = 3;

			analysisManager->FillNtupleDColumn(energyColumnId, fEnergy);

			// finally, go to the next ntuple row
			analysisManager->AddNtupleRow();

			// print to console
			//Print();

		}
	}

	void EventAction::Print() {
		G4cout
			<< "Energy: "
			<< G4BestUnit(fEnergy, "Energy")
			<< G4endl;
	}


	}