#ifndef G4_BREMS_PHYSICS_LIST_HH
#define G4_BREMS_PHYSICS_LIST_HH 1

#include "G4VModularPhysicsList.hh"

namespace G4_BREMS
{
	class PhysicsList : public G4VModularPhysicsList
	{
	public:
		PhysicsList();
		virtual ~PhysicsList();

		// Mandatory methods to override;
		virtual void ConstructParticle() override;
		virtual void ConstructProcess() override;
	};
}

#endif