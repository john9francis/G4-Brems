
#include "ActionInit.hh"
#include "PrimaryGeneratorAction.hh"
#include "SteppingAction.hh"
#include "EventAction.hh"
#include "RunAction.hh"

namespace G4_BREMS {

	void ActionInit::Build() const {

		// set the Geant4 actions
		SetUserAction(new PrimaryGeneratorAction);

		RunAction* runAction = new RunAction();
		SetUserAction(runAction);

		EventAction* eventAction = new EventAction(runAction);
		SetUserAction(eventAction);

		SetUserAction(new SteppingAction(eventAction));

	};

}