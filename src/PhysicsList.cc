#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"
#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"
#include "G4Electron.hh"
#include "G4eBremsstrahlung.hh"

namespace G4_BREMS
{
	PhysicsList::PhysicsList() : G4VModularPhysicsList() {
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

	}
}