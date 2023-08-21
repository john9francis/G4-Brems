#ifndef G4_BREMS_RUN_ACTION_HH
#define G4_BREMS_RUN_ACTION_HH

#include "G4UserRunAction.hh"

namespace G4_BREMS {

	class RunAction : G4UserRunAction {
	public:
		RunAction();
		~RunAction();

		void BeginOfRunAction(const G4Run* aRun) override;
		void EndOfRunAction(const G4Run* aRun) override;
	};


}

#endif // !G4_BREMS_RUN_ACTION_HH
