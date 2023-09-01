
#include "RunAction.hh"
#include "G4VHit.hh"

namespace G4_BREMS {
	RunAction::RunAction() {
		fGammaHits = new HitsCollection;

		// create analysis manager
		auto analysisManager = G4AnalysisManager::Instance();

		// set default output file type
		analysisManager->SetDefaultFileType("csv");

		analysisManager->SetVerboseLevel(1);

		// create nTuple to store the data:
		analysisManager->CreateNtuple("G4_Brems", "Hits");
		analysisManager->CreateNtupleIColumn("Photon Hit"); // id=0
		// The letters D, I, S, F correspond to types
		analysisManager->CreateNtupleDColumn("Energy"); //  id = 1
		analysisManager->CreateNtupleDColumn("Position"); //id = 2

		fNTupleFilename = "G4BremsNTuple.root";
		analysisManager->SetNtupleFileName(0, fNTupleFilename);
	}

	RunAction::~RunAction() {
		delete fGammaHits;
	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {
		// open an output file:
		auto analysisManager = G4AnalysisManager::Instance();

		analysisManager->OpenFile(fNTupleFilename);
	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {
		fGammaHits->PrintAllHits();

		auto analysisManager = G4AnalysisManager::Instance();

		// fill nTuple columns
		for (int i = 0; i < fGammaHits->entries(); i++) {
			// add the first entry (energy) into the first col (energy)
			Hit* h = static_cast<Hit*>(fGammaHits->GetHit(i));
			double energy = h->GetEnergy();

			analysisManager->FillNtupleDColumn(1, energy);
		}


		// write to output file
		analysisManager->Write();
		analysisManager->CloseFile();
	}

	void RunAction::AddToGammaHits(Hit* h) {
		fGammaHits->insert(h);
	}

}