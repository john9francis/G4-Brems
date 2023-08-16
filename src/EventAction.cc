
#include "EventAction.hh"

/*
Class description:

An Event represents one single particle (for now.) As the particle enters
The detector, it will continue to deposit energy until it is stopped. All
that energy will be summed up and kept track of here in the form of a "Hit."
*/

namespace G4_BREMS {
	void EventAction::BeginOfEventAction(const G4Event* anEvent) {
		// begin of event actions here

	}

	void EventAction::EndOfEventAction(const G4Event* anEvent) {
		// end of event actions here

	}
}