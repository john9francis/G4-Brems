
#include "RunAction.hh"
#include "G4VHit.hh"
#include "G4ThreeVector.hh"

namespace G4_BREMS {
	RunAction::RunAction() {
		fGammaHits = new HitsCollection;

		// create analysis manager
		auto analysisManager = G4AnalysisManager::Instance();

		// set default settings
		analysisManager->SetDefaultFileType("root");
		analysisManager->SetNtupleMerging(true);
		analysisManager->SetVerboseLevel(1);
		analysisManager->SetFileName("Output");

		// create nTuple to store the data:
		analysisManager->CreateNtuple("G4_Brems", "Hits");
		// The letters D, I, S, F correspond to types
		analysisManager->CreateNtupleDColumn("Energy"); //  id = 0
		analysisManager->CreateNtupleDColumn("PositionX"); //id = 1
		analysisManager->CreateNtupleDColumn("PositionY"); //id = 2
		analysisManager->CreateNtupleDColumn("PositionZ"); //id = 3
		analysisManager->FinishNtuple();

	}

	RunAction::~RunAction() {
		delete fGammaHits;
	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {
		auto analysisManager = G4AnalysisManager::Instance();

		analysisManager->OpenFile();
	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {
		fGammaHits->PrintAllHits();

		auto analysisManager = G4AnalysisManager::Instance();

		// fill nTuple columns
		/*
		for (int i = 0; i < fGammaHits->entries(); i++) {
			// add the id to the photon hit id column
			analysisManager->FillNtupleIColumn(0, i);


			// add the first entry (energy) into the energy column
			Hit* h = static_cast<Hit*>(fGammaHits->GetHit(i));
			double energy = h->GetEnergy();

			analysisManager->FillNtupleDColumn(1, energy);
			

			// add the position into the position columns
			G4ThreeVector pos = h->GetPos();
			analysisManager->FillNtupleDColumn(2, pos.getX());
			analysisManager->FillNtupleDColumn(3, pos.getY());
			analysisManager->FillNtupleDColumn(4, pos.getZ());

			analysisManager->AddNtupleRow();

		}

		*/

		// write to output file
		analysisManager->Write();
		analysisManager->CloseFile();

	}

	void RunAction::AddToGammaHits(Hit* h) {
		fGammaHits->insert(h);
	}

}