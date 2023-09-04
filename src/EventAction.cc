
#include "EventAction.hh"
#include "G4AnalysisManager.hh"

namespace G4_BREMS {
	EventAction::EventAction() {
		fEnergy = 0.;
	}

	void EventAction::BeginOfEventAction(const G4Event* anEvent) {
		// begin of event actions here
		fEnergy = 0.;

	}
	
	// setting energy and position
	void EventAction::AddEnergy(G4double e) { fEnergy += e; }
	void EventAction::SetPosition(G4ThreeVector p) { fPosition = p; }

	void EventAction::EndOfEventAction(const G4Event* anEvent) {
		// if there was any energy deposited, tell the analysis manager.
		if (fEnergy > 0) {

			auto analysisManager = G4AnalysisManager::Instance();

			// add all the info to the analysis nTuples
			// set the column id's (see runaction)
			G4int energyColumnId = 0;
			G4int posXColumnId = 1;
			G4int posYColumnId = 2;
			G4int posZColumnId = 3;

			analysisManager->FillNtupleDColumn(energyColumnId, fEnergy);
			analysisManager->FillNtupleDColumn(posXColumnId, fPosition.getX());
			analysisManager->FillNtupleDColumn(posYColumnId, fPosition.getY());
			analysisManager->FillNtupleDColumn(posZColumnId, fPosition.getZ());

			// finally, go to the next ntuple row
			analysisManager->AddNtupleRow();

		}
	}


	}