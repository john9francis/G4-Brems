
#include "ActionInit.hh"
#include "PrimaryGeneratorAction.hh"
#include "SteppingAction.hh"
#include "EventAction.hh"

namespace G4_BREMS {

	void ActionInit::Build() const {

		// set the Geant4 actions
		SetUserAction(new PrimaryGeneratorAction);

		EventAction* eventAction = new EventAction;
		SetUserAction(eventAction);

		SetUserAction(new SteppingAction(eventAction));

	};

}