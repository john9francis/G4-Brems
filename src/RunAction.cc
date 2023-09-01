
#include "RunAction.hh"

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
		fAnalysisManager->CreateNtupleIColumn("Photon Hits");
		fAnalysisManager->CreateNtupleDColumn("Energy");
		fAnalysisManager->CreateNtupleDColumn("PosX");
		fAnalysisManager->CreateNtupleDColumn("PosY");
		fAnalysisManager->CreateNtupleDColumn("PosZ");

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

		// write to output file
		fAnalysisManager->Write();
		fAnalysisManager->CloseFile();
	}

	void RunAction::AddToGammaHits(Hit* h) {
		fGammaHits->insert(h);
	}

}