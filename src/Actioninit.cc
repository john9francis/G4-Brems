
#include "ActionInit.hh"
#include "PrimaryGeneratorAction.hh"
#include "SteppingAction.hh"
#include "RunAction.hh"

namespace G4_BREMS {

	void ActionInit::Build() const {

		// set the Geant4 actions
		SetUserAction(new PrimaryGeneratorAction);
		SetUserAction(new SteppingAction);
		SetUserAction(new RunAction);
	};

}