#include "PhysicsList.hh"

#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"
#include "G4Electron.hh"
#include "G4eBremsstrahlung.hh"

namespace G4_BREMS
{
	PhysicsList::PhysicsList() : G4VModularPhysicsList() {}
	PhysicsList::~PhysicsList() {}

	void PhysicsList::ConstructParticle() {
		// Construct particle here
		G4Electron::ElectronDefinition();
		
	}
	void PhysicsList::ConstructProcess() {
		// Construct processes here
		G4ProcessManager* electronProcessManager = G4Electron::Electron()->GetProcessManager();
	
		// Creating Bremsstrahlung process
		G4eBremsstrahlung* bremsProcess = new G4eBremsstrahlung();

		// add it to the electrons processes
		electronProcessManager->AddProcess(bremsProcess);
	}
}