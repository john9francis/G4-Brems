// An alternative entrypoint that opens the project in terminal mode.

#include "G4RunManagerFactory.hh"
#include "G4UIsession.hh"
#include "G4UIterminal.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInit.hh"
#include "TestDetConst.hh"

using namespace G4_BREMS;

int main(int argc, char** argv)
{
	// create default runmanager
	auto* runManager =
		G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

	// set 3 required initialization classes
	runManager->SetUserInitialization(new DetectorConstruction());
	runManager->SetUserInitialization(new PhysicsList());
	runManager->SetUserInitialization(new ActionInit());

	// Initialize G4 kernel
	runManager->Initialize();

	// Define UI terminal for interactive mode
	G4UIsession* session = new G4UIterminal;
	session->SessionStart();
	delete session;

	// job termination
	delete runManager;
	return 0;
}