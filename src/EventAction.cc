
#include "EventAction.hh"
#include "G4AnalysisManager.hh"

namespace G4_BREMS {
	EventAction::EventAction(RunAction* runAction) {
		fEnergy = 0.;

		fRunAction = runAction;
	}

	void EventAction::BeginOfEventAction(const G4Event* anEvent) {
		// begin of event actions here
		fEnergy = 0.;

	}

	void EventAction::EndOfEventAction(const G4Event* anEvent) {
		// Create a new hit
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

			/*
			Hit* hit = new Hit();
			hit->SetEnergy(fEnergy);
			hit->SetPos(fPosition);

			// send hit over to the run action
			fRunAction->AddToGammaHits(hit);
			*/
		}
	}


	}