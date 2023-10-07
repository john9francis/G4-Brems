#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"

#include "G4EmLivermorePhysics.hh"
#include "G4EmPenelopePhysics.hh"

// Different options to test
#include "G4EmStandardPhysics_option1.hh"
#include "G4EmStandardPhysics_option2.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4EmStandardPhysicsWVI.hh"
#include "G4EmStandardPhysicsSS.hh"
#include "G4EmStandardPhysicsGS.hh"

namespace G4_BREMS
{
	PhysicsList::PhysicsList() : G4VModularPhysicsList() {
		// Get the standard EM particles
		RegisterPhysics(new G4EmPenelopePhysics());

		//RegisterPhysics(new G4EmStandardPhysics_option1);
		//RegisterPhysics(new G4EmStandardPhysics_option2);

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