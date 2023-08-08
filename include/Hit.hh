#ifndef G4_BREMS_HIT
#define G4_BREMS_HIT 1

// My own Hit class

#include "G4VHit.hh"

namespace G4_BREMS {
	class Hit : public G4VHit {
	public:
		Hit();
		~Hit();

		//void Draw() override;
		void Print() override;
	};
}

#endif // !G4_BREMS_HIT
