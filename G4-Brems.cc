// G4-Brems.cc : Defines the entry point for the application.
//

#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

int main(int argc, char** argv)
{
	// Start (or don't) a UI
	G4UIExecutive* ui = nullptr;
	if (argc == 1) {
		ui = new G4UIExecutive(argc, argv);
	}

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
