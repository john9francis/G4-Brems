
#include "ActionInit.hh"
#include "PrimaryGeneratorAction.hh"
#include "SteppingAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"

namespace G4_BREMS {

	void ActionInit::Build() const {

		// set the Geant4 actions
		SetUserAction(new PrimaryGeneratorAction);

		// create a pointer to the runAction
		RunAction* runAction = new RunAction;
		SetUserAction(runAction);

		EventAction* eventAction = new EventAction;
		SetUserAction(eventAction);

		SetUserAction(new SteppingAction(eventAction));

	};

}