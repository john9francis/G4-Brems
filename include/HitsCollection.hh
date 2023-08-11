#ifndef G4_BREMS_HITS_COLLECTION_H
#define G4_BREMS_HITS_COLLECTION_H 1

#include "G4THitsCollection.hh"
#include "Hit.hh"

class Hit;

namespace G4_BREMS {
	class HitsCollection : public G4THitsCollection<Hit> {
	public:
		HitsCollection();
		~HitsCollection();

		void PrintAllHits();
	};
}

#endif // !G4_BREMS_HITS_COLLECTION_H
