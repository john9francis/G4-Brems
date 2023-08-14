#ifndef G4_BREMS_EVENT_ACTION_HH
#define G4_BREMS_EVENT_ACTION_HH

#include "G4UserEventAction.hh"

namespace G4_BREMS {
	class EventAction : public G4UserEventAction {
	public:
		EventAction() = default;
		~EventAction() override = default;

		void BeginOfEventAction(const G4Event* anEvent) override;
		void EndOfEventAction(const G4Event* anEvent) override;

	};
}

#endif // !G4_BREMS_EVENT_ACTION_HH
