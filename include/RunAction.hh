#ifndef G4_BREMS_RUN_ACTION_HH
#define G4_BREMS_RUN_ACTION_HH

#include "G4UserRunAction.hh"

#include "G4AnalysisManager.hh"

// timing the run
using namespace std::chrono;


namespace G4_BREMS {

	class HitsCollection;

	class RunAction : public G4UserRunAction {
	public:
		RunAction();
		~RunAction();

		void BeginOfRunAction(const G4Run* aRun) override;
		void EndOfRunAction(const G4Run* aRun) override;

	private:

		// std::chrono time points
		time_point<high_resolution_clock> _beginTime;
		time_point<high_resolution_clock> _endTime;

		void PrintTime();

	};


}

#endif // !G4_BREMS_RUN_ACTION_HH
