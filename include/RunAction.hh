#ifndef G4_BREMS_RUN_ACTION_HH
#define G4_BREMS_RUN_ACTION_HH

#include "G4UserRunAction.hh"

#include "G4THitsCollection.hh"
#include "Hit.hh"

namespace G4_BREMS {

	class HitsCollection;

	class RunAction : public G4UserRunAction {
	public:
		RunAction();
		~RunAction();

		void BeginOfRunAction(const G4Run* aRun) override;
		void EndOfRunAction(const G4Run* aRun) override;

		void AddToGammaHits(Hit* h);

	private:
		HitsCollection* fGammaHits;
	};

	class HitsCollection : public G4THitsCollection<Hit> {
		
	};


}

#endif // !G4_BREMS_RUN_ACTION_HH
