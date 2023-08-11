#ifndef G4_BREMS_STEPPING_ACTION_H
#define G4_BREMS_STEPPING_ACTION_H 1

#include "G4UserSteppingAction.hh"

namespace G4_BREMS {

	class SteppingAction : public G4UserSteppingAction {

		SteppingAction();
		~SteppingAction() override = default;

		void UserSteppingAction(const G4Step*) override;
	};

}


#endif // !G4_BREMS_STEPPING_ACTION_H
