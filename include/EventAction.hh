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
#include "G4ThreeVector.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "RunAction.hh"


namespace G4_BREMS {

	class EventAction : public G4UserEventAction {
	public:
		EventAction();
		~EventAction() override = default;

		void BeginOfEventAction(const G4Event* anEvent) override;
		void EndOfEventAction(const G4Event* anEvent) override;

		void AddEnergy(G4double energy);

		void Print();

	private:
		G4double fEnergy;

		G4int fCounter;
	};

	
}

#endif // !G4_BREMS_EVENT_ACTION_HH
