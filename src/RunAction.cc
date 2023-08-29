
#include "RunAction.hh"

namespace G4_BREMS {
	RunAction::RunAction() {
		fGammaHits = new HitsCollection;

		// create analysis manager
		fAnalysisManager = G4AnalysisManager::Instance();

	}

	RunAction::~RunAction() {
		delete fGammaHits;
	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {

	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {
		fGammaHits->PrintAllHits();

		

	}

	void RunAction::AddToGammaHits(Hit* h) {
		fGammaHits->insert(h);
	}

}