
#include "HitsCollection.hh"

namespace G4_BREMS {
	HitsCollection::HitsCollection() {

	}

	HitsCollection::~HitsCollection() {
		// Make sure we delete all the hits inside
		size_t n = entries();
		for (size_t i = 0; i < n; i++) {
			delete (*this)[i];
		}
	}

	void HitsCollection::PrintAllHits() {
		// call the print function for each hit.
		size_t n = entries();
		for (size_t i = 0; i < n; i++) {
			(*this)[i]->Print();
		}
	}
}