
#include "RunAction.hh"
#include "G4VHit.hh"

namespace G4_BREMS {
	RunAction::RunAction() {
		fGammaHits = new HitsCollection;

		// create analysis manager
		auto analysisManager = G4AnalysisManager::Instance();

		analysisManager->Reset();

		// set default output file type
		analysisManager->SetDefaultFileType("csv");

		analysisManager->SetVerboseLevel(1);

		//analysisManager->SetNtupleMerging(true); DOESNT WORK WITH CSV

		analysisManager->SetNtupleActivation(true);

		analysisManager->SetFileName("Output");

		// create nTuple to store the data:
		analysisManager->CreateNtuple("G4_Brems", "Hits");
		analysisManager->CreateNtupleIColumn("Photon Hit"); // id=0
		// The letters D, I, S, F correspond to types
		analysisManager->CreateNtupleDColumn("Energy"); //  id = 1
		analysisManager->CreateNtupleDColumn("Position"); //id = 2

	}

	RunAction::~RunAction() {
		delete fGammaHits;
	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {
		
	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {
		fGammaHits->PrintAllHits();

		// open an output file:
		auto analysisManager = G4AnalysisManager::Instance();

		analysisManager->OpenFile();

		// write to output file
		analysisManager->Write();

		// fill nTuple columns
		for (int i = 0; i < fGammaHits->entries(); i++) {
			// add the first entry (energy) into the first col (energy)
			Hit* h = static_cast<Hit*>(fGammaHits->GetHit(i));
			double energy = h->GetEnergy();

			analysisManager->FillNtupleDColumn(1, energy);
			analysisManager->AddNtupleRow();
		}

	}

	void RunAction::AddToGammaHits(Hit* h) {
		fGammaHits->insert(h);

		//idea: add to ntuple here:?

	}

}