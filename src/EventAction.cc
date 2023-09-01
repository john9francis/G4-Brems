
#include "EventAction.hh"


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
			Hit* hit = new Hit();
			hit->SetEnergy(fEnergy);
			hit->SetPos(fPosition);

			// send hit over to the run action
			fRunAction->AddToGammaHits(hit);

		}
	}


	}