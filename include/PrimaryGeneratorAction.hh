#ifndef G4_BREMS_PRIMARYGENERATORACTION_HH
#define G4_BREMS_PRIMARYGENERATORACTION_HH 1


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleGun.hh"



namespace G4_BREMS
{

	class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
	{
	public:
		PrimaryGeneratorAction();
		~PrimaryGeneratorAction();

		virtual void GeneratePrimaries(G4Event*);

		G4ParticleGun* fParticleGun;
	};
}


#endif // !G4_BREMS_PRIMARYGENERATORACTION_HH
