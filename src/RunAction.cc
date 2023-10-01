
#include "RunAction.hh"
#include "G4ThreeVector.hh"
#include "G4UnitsTable.hh"


namespace G4_BREMS {
	RunAction::RunAction() {

		// access analysis manager
		auto analysisManager = G4AnalysisManager::Instance();

		// set default settings
		analysisManager->SetDefaultFileType("root");
		analysisManager->SetNtupleMerging(true);
		analysisManager->SetVerboseLevel(0);
		analysisManager->SetFileName("NTuples");

		// create nTuple to store the gamma energies
		const G4int ntupleId1 = analysisManager->CreateNtuple("Ntuple1", "GammaEnergies");
		// The letters D, I, S, F correspond to types
		analysisManager->CreateNtupleDColumn(ntupleId1, "gEnergy"); //   id = 0
		analysisManager->CreateNtupleDColumn(ntupleId1, "gPositionX"); //id = 1
		analysisManager->CreateNtupleDColumn(ntupleId1, "gPositionY"); //id = 2
		analysisManager->CreateNtupleDColumn(ntupleId1, "gPositionZ"); //id = 3
		analysisManager->FinishNtuple(ntupleId1);


		// create the second nTuple to store the electron energies
		const G4int ntupleId2 = analysisManager->CreateNtuple("Ntuple2", "ElectronEnergies");
		analysisManager->CreateNtupleDColumn(ntupleId2, "eEnergy"); // id = 0
		analysisManager->CreateNtupleDColumn(ntupleId2, "ePositionX"); // id = 1
		analysisManager->CreateNtupleDColumn(ntupleId2, "ePositionY"); // id = 2
		analysisManager->CreateNtupleDColumn(ntupleId2, "ePositionZ"); // id = 3
		analysisManager->FinishNtuple(ntupleId2);
	}

	RunAction::~RunAction() {
	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {
		// start time
		fTimer.Start();

		auto analysisManager = G4AnalysisManager::Instance();

		analysisManager->OpenFile();
	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {

		auto analysisManager = G4AnalysisManager::Instance();

		// write to output file
		analysisManager->Write();
		analysisManager->CloseFile();

		// end time
		fTimer.Stop();

		// print out the time it took
		PrintTime();
	}

	void RunAction::PrintTime() {
		auto time = fTimer.GetRealElapsed();

		G4cout
			<< "Elapsed time: "
			<< time
			<< " Seconds."
			<< G4endl;

	}
}