#ifndef G4_BREMS_ACTION_INIT_H
#define G4_BREMS_ACTION_INIT_H 1

#include "G4VUserActionInitialization.hh"

namespace G4_BREMS {
	class ActionInit : public G4VUserActionInitialization {
	public:
		ActionInit() = default;
		~ActionInit() override = default;

		void Build() const override;
		//void BuildForMaster() const override;
		// BuildForMaster is not neccesary to override technically
	
	};
}

#endif // !G4_BREMS_ACTION_INIT_H
