
#include "SteppingAction.hh"
#include "G4Step.hh"

namespace G4_BREMS {
	SteppingAction::SteppingAction() {

	}

	void SteppingAction::UserSteppingAction(const G4Step* step) {
		// Register hit if the step is inside the tracking volume
		
		// get volume of the current step (borrowed from B1)
		// ps. this is dynamically allocated
		G4LogicalVolume* volume
			= step->GetPreStepPoint()->GetTouchableHandle()
			->GetVolume()->GetLogicalVolume();

		// if the volume is our gamma detector, create a hit.
		// else, move on. 
		//if (volume = )

	}
	
}