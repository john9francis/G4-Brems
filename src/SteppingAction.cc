
#include "SteppingAction.hh"

namespace G4_BREMS {
	SteppingAction::SteppingAction() {

	}

	void SteppingAction::UserSteppingAction(const G4Step*) {
		// Register hit if the step is inside the tracking volume
	}
	
}