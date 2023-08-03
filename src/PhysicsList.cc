#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"
#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"
#include "G4Electron.hh"
#include "G4eBremsstrahlung.hh"

namespace G4_BREMS
{
	PhysicsList::PhysicsList() : G4VModularPhysicsList() {
		//G4Electron::ElectronDefinition();
		// Get the standard EM particles
		RegisterPhysics(new G4EmStandardPhysics());
	}
	PhysicsList::~PhysicsList() {}

	void PhysicsList::ConstructParticle() {
		// Construct particle here
		G4VModularPhysicsList::ConstructParticle();
		
	}
	void PhysicsList::ConstructProcess() {
		// Construct processes here
		G4VModularPhysicsList::ConstructProcess();

		G4ProcessManager* electronProcessManager = G4Electron::Electron()->GetProcessManager();

		// Creating Bremsstrahlung process
		G4eBremsstrahlung* bremsProcess = new G4eBremsstrahlung();

		// add it to the electrons processes
		electronProcessManager->AddProcess(bremsProcess);

	}
}