#include "RunAction.hh"

namespace G4_BREMS {

	void RunAction::BeginOfRunAction(const G4Run*) {
		// create a HitsCollection object
		fGammaHitsCollection = new HitsCollection();
	}

	void RunAction::AddHit(Hit* aHit) {
		// adds a hit to the hitcollection
		fGammaHitsCollection->insert(aHit);

	}

	void RunAction::EndOfRunAction(const G4Run*) {
		// print all the hits
		fGammaHitsCollection->PrintAllHits();

		// delete our hits collection
		delete fGammaHitsCollection;
	}

}