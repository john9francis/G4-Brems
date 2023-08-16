
#include "EventAction.hh"


namespace G4_BREMS {
	void EventAction::BeginOfEventAction(const G4Event* anEvent) {
		// begin of event actions here
		fEnergy = 0;

	}

	void EventAction::EndOfEventAction(const G4Event* anEvent) {
		// end of event actions here
		G4cout << "Energy deposited for this event: " << fEnergy << G4endl;

	}

	void EventAction::AddEnergy(G4double energy) {
		fEnergy += energy;
	}
}