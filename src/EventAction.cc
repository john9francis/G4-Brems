
#include "EventAction.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"


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
		if (fEnergy > 0) {
			G4cout
				<< "Particle hit the detector"
				<< G4endl;
			G4cout 
				<< "Energy of this particle for this event: " 
				<< G4BestUnit(fEnergy, "Energy")
				<< G4endl;
			G4cout
				<< "Position of this particle: "
				<< "X: "
				<< G4BestUnit(fPosition.getX(), "Length")
				<< G4endl;
		}

	}

	void EventAction::AddEnergy(G4double energy) {
		fEnergy += energy;
	}

	void EventAction::SetPosition(G4ThreeVector pos) {
		fPosition = pos;
	}
}