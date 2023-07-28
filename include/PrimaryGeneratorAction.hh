#ifndef G4_BREMS_PRIMARYGENERATORACTION_HH
#define G4_BREMS_PRIMARYGENERATORACTION_HH 1


#include "G4VUserPrimaryGeneratorAction.hh"


namespace G4_BREMS
{
	class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
	{
	public:

		void GeneratePrimaries(G4Event*) override;
	};
}


#endif // !G4_BREMS_PRIMARYGENERATORACTION_HH
