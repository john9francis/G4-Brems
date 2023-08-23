
#include "RunAction.hh"

namespace G4_BREMS {
	RunAction::RunAction() {
		fGammaHits = new HitsCollection;
		fAverage = 0.;
	}

	RunAction::~RunAction() {
		delete fGammaHits;
	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {

	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {
		fGammaHits->PrintAllHits();
		
		// Get the average
		fAverage = GetAverage(fGammaHits);
		G4cout
			<< "Average energy: "
			<< G4BestUnit(fAverage, "Energy")
			<< G4endl;
	}

	void RunAction::AddToGammaHits(Hit* h) {
		fGammaHits->insert(h);
	}

	G4double RunAction::GetAverage(HitsCollection* hitsCol) {
		// Takes the average energy of the hits
		G4double total = 0.;

		// Add up all the hits in hitscollection
		for (Hit* hit : *hitsCol->GetVector()) {
			total += hit->GetEnergy();
		}

		// Divide by the entries
		return total / hitsCol->entries();

	}
}