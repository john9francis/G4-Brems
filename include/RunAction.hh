#ifndef G4_BREMS_RUN_ACTION_HH
#define	G4_BREMS_RUN_ACTION_HH

#include "G4UserRunAction.hh"

namespace G4_BREMS {
	class RunAction : public G4UserRunAction {
		RunAction() = default;
		~RunAction() override = default;

		void BeginOfRunAction(const G4Run*);

		void EndOfRunAction(const G4Run*);
	};
}

#endif // !G4_BREMS_RUN_ACTION_HH
