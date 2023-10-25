
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

		// using counter to make sure we only get one particle's energy
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
			analysisManager->FillNtupleDColumn(0, fEnergy);
			//G4cout << "Energy recorded: " << G4BestUnit(fEnergy, "Energy") << G4endl;

			// finally, go to the next ntuple row
			analysisManager->AddNtupleRow();

			// print to console
			//Print();

		}

		//G4cout << "Event energy: " << G4BestUnit(fEnergy, "Energy") << G4endl;
	}

	void EventAction::Print() {
		G4cout
			<< "Energy: "
			<< G4BestUnit(fEnergy, "Energy")
			<< G4endl;
	}


	}