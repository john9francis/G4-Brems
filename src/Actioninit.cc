
#include "ActionInit.hh"
#include "PrimaryGeneratorAction.hh"
#include "SteppingAction.hh"
#include "EventAction.hh"
#include "RunAction.hh"

namespace G4_BREMS {

	void ActionInit::Build() const {
		// Multithreaded

		// set the Geant4 actions
		SetUserAction(new PrimaryGeneratorAction);

		SetUserAction(new RunAction());

		EventAction* eventAction = new EventAction();
		SetUserAction(eventAction);

		SetUserAction(new SteppingAction(eventAction));

	};

	void ActionInit::BuildForMaster() const {
		// Sequential

		SetUserAction(new RunAction());

	}

}