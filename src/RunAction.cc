
#include "RunAction.hh"
#include "G4ThreeVector.hh"

namespace G4_BREMS {
	RunAction::RunAction() {

		// access analysis manager
		auto analysisManager = G4AnalysisManager::Instance();

		// set default settings
		analysisManager->SetDefaultFileType("root");
		analysisManager->SetNtupleMerging(true);
		analysisManager->SetVerboseLevel(0);
		analysisManager->SetFileName("NTuples");

		// create nTuple to store the data:
		analysisManager->CreateNtuple("G4_Brems", "Hits");
		// The letters D, I, S, F correspond to types
		analysisManager->CreateNtupleDColumn("Energy"); //   id = 0
		analysisManager->CreateNtupleDColumn("PositionX"); //id = 1
		analysisManager->CreateNtupleDColumn("PositionY"); //id = 2
		analysisManager->CreateNtupleDColumn("PositionZ"); //id = 3
		analysisManager->FinishNtuple();

	}

	RunAction::~RunAction() {
	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {
		auto analysisManager = G4AnalysisManager::Instance();

		analysisManager->OpenFile();
	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {

		auto analysisManager = G4AnalysisManager::Instance();

		// write to output file
		analysisManager->Write();
		analysisManager->CloseFile();

	}


}