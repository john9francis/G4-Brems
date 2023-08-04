#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

namespace G4_BREMS
{
	PrimaryGeneratorAction::PrimaryGeneratorAction() {
		// set up particle gun
		G4int nParticles = 1;
		fParticleGun = new G4ParticleGun(nParticles);

		// define particle properties
		const G4String& particleName = "electron";
		G4double energy = 6. * MeV;
		G4ThreeVector position = G4ThreeVector(0, 0, -1 * cm);
		G4ThreeVector momentumDirection = G4ThreeVector(0, 0, 1);

		// default particle kinematic
		G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
		G4ParticleDefinition* particle
			= particleTable->FindParticle(particleName);
		fParticleGun->SetParticleDefinition(particle);
		fParticleGun->SetParticleEnergy(energy);
		fParticleGun->SetParticlePosition(position);
		fParticleGun->SetParticleMomentumDirection(momentumDirection);
	}

	PrimaryGeneratorAction::~PrimaryGeneratorAction() {
		delete fParticleGun;
	}

	void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
	{
		// satisfy "generate primaries" here.
		fParticleGun->GeneratePrimaryVertex(event);
	}
}