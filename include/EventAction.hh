#ifndef G4_BREMS_EVENT_ACTION_HH
#define G4_BREMS_EVENT_ACTION_HH

/*
Class description:

An Event represents one single particle (for now.) As the particle enters
The detector, it will continue to deposit energy until it is stopped. All
that energy will be summed up and kept track of here in the form of a "Hit."
*/

#include "G4UserEventAction.hh"
#include "globals.hh"

namespace G4_BREMS {
	class EventAction : public G4UserEventAction {
	public:
		EventAction() = default;
		~EventAction() override = default;

		void BeginOfEventAction(const G4Event* anEvent) override;
		void EndOfEventAction(const G4Event* anEvent) override;

		void AddEnergy(G4double energy);
	private:
		G4double fEnergy;

	};
}

#endif // !G4_BREMS_EVENT_ACTION_HH
