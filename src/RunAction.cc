#include "RunAction.hh"

namespace G4_BREMS {

	void RunAction::BeginOfRunAction(const G4Run*) {
		// create a HitsCollection object
		fGammaHitsCollection = new HitsCollection();
	}

	void RunAction::EndOfRunAction(const G4Run*) {
		// delete our hits collection
		delete fGammaHitsCollection;
	}

}