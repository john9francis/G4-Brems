// G4-Brems.cc : Defines the entry point for the application.
//

#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4RunManagerFactory.hh"

int main(int argc, char** argv)
{
	// Initialize (or don't) a UI
	G4UIExecutive* ui = nullptr;
	if (argc == 1) {
		ui = new G4UIExecutive(argc, argv);
	}

	// ======================================================================
	// RunManager, + 3 Required additions:
	// PrimaryGeneratorAction,
	// PhysicsList,
	// DetectorConstruction.
	// ======================================================================
	
	// create default runmanager
	auto* runManager =
		G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);
	


	// START UI =============================================================

	// get pointer to UI manager
	G4UImanager* UImanager = G4UImanager::GetUIpointer();

	// Run macro or start UI
	if (!ui) {
		// batch mode
		G4String command = "/control/execute ";
		G4String fileName = argv[1];
		UImanager->ApplyCommand(command + fileName);
	}
	else {
		// use UI
		ui->SessionStart();
		delete ui;
	}

	return 0;
}
