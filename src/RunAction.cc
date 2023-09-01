
#include "RunAction.hh"
#include "G4VHit.hh"

namespace G4_BREMS {
	RunAction::RunAction() {
		fGammaHits = new HitsCollection;

		// create analysis manager
		fAnalysisManager = G4AnalysisManager::Instance();

		// set default output file type
		fAnalysisManager->SetDefaultFileType("csv");

		fAnalysisManager->SetVerboseLevel(1);

		// create nTuple to store the data:
		fAnalysisManager->CreateNtuple("G4_Brems", "Hits");
		fAnalysisManager->CreateNtupleIColumn("Photon Hit"); // id=0
		// apparently the letter, F,D,or I corresponds to type.
		fAnalysisManager->CreateNtupleFColumn("Energy"); //  id = 1
		fAnalysisManager->CreateNtupleDColumn("Position"); //id = 2

		fNTupleFilename = "G4BremsNTuple.csv";
		fAnalysisManager->SetNtupleFileName(0, fNTupleFilename);
	}

	RunAction::~RunAction() {
		delete fGammaHits;
	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {
		// open an output file:
		fAnalysisManager->OpenFile(fNTupleFilename);
	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {
		fGammaHits->PrintAllHits();

		// fill nTuple columns
		for (int i = 0; i < fGammaHits->entries(); i++) {
			// add the first entry (energy) into the first col (energy)
			Hit* h = static_cast<Hit*>(fGammaHits->GetHit(i));
			fAnalysisManager->FillNtupleDColumn(0, h->GetEnergy());
		}


		// write to output file
		fAnalysisManager->Write();
		fAnalysisManager->CloseFile();
	}

	void RunAction::AddToGammaHits(Hit* h) {
		fGammaHits->insert(h);
	}

}