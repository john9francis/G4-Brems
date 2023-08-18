
#include "EventAction.hh"


namespace G4_BREMS {
	EventAction::EventAction() {
		// define units (if needed)
		fEnergy = 0.;
	}

	void EventAction::BeginOfEventAction(const G4Event* anEvent) {
		// begin of event actions here
		fEnergy = 0.;

	}

	void EventAction::EndOfEventAction(const G4Event* anEvent) {
		// end of event actions here
		Print();
	}

	void EventAction::Print() {
		if (fEnergy > 0) {
			G4cout
				<< "Particle hit the detector"
				<< G4endl;
			G4cout
				<< "Energy: "
				<< G4BestUnit(fEnergy, "Energy")
				<< G4endl;
			G4cout
				<< "Position: "
				<< G4BestUnit(fPosition.getX(), "Length")
				<< G4BestUnit(fPosition.getY(), "Length")
				<< G4BestUnit(fPosition.getZ(), "Length")
				<< G4endl;
		}
	}


	}