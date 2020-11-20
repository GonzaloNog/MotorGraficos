#include "ColliderControler.h"

namespace  EngineUtils {
	ColliderControler* ColliderControler::sInstance = nullptr;

	ColliderControler* ColliderControler::Instance() {
		if (sInstance == nullptr)
			sInstance = new ColliderControler();

		return sInstance;
	}

	ColliderControler::ColliderControler(){

	}
	ColliderControler::~ColliderControler(){

	}

	void ColliderControler::NewCollider(Collider* coll) {
		ListColl.push_back(coll);
	}
	void ColliderControler::DeleteCollider(Collider* coll) {
		std::list<Collider*>::iterator IterratorColl;
		
		for (IterratorColl = ListColl.begin(); IterratorColl != ListColl.end(); IterratorColl++) {
			if (coll == *IterratorColl) {

			}
		}
	}

	void ColliderControler::CalculateCollider() {
		std::list<Collider*> aux = ListColl;
		std::list<Collider*> aux2 = ListColl;

		while(!aux.empty()){
			aux2 = ListColl;
			while (!aux2.empty()) {
				if (aux.front() != aux2.front()) {
					if ((aux.front()->GetPosition().x + aux.front()->GetSize().x / 2) >= (aux2.front()->GetPosition().x - aux2.front()->GetSize().x / 2) && (aux.front()->GetPosition().x + aux.front()->GetSize().x / 2) <= (aux2.front()->GetPosition().x + aux2.front()->GetSize().x / 2) || (aux.front()->GetPosition().x - aux.front()->GetSize().x / 2) >= (aux2.front()->GetPosition().x - aux2.front()->GetSize().x / 2) && (aux.front()->GetPosition().x - aux.front()->GetSize().x / 2) <= (aux2.front()->GetPosition().x + aux2.front()->GetSize().x / 2)) {
						if ((aux.front()->GetPosition().y + aux.front()->GetSize().y / 2) >= (aux2.front()->GetPosition().y - aux2.front()->GetSize().y / 2) && (aux.front()->GetPosition().y + aux.front()->GetSize().y / 2) <= (aux2.front()->GetPosition().y + aux2.front()->GetSize().y / 2) || (aux.front()->GetPosition().y - aux.front()->GetSize().y / 2) >= (aux2.front()->GetPosition().y - aux2.front()->GetSize().y / 2) && (aux.front()->GetPosition().y - aux.front()->GetSize().y / 2) <= (aux2.front()->GetPosition().y + aux2.front()->GetSize().y / 2)) {
							if (aux.front()->GetEnter() || aux.front()->GetStay()) {
								aux.front()->SetEnter(false);
								aux.front()->SetStay(true);
							}
							else
								aux.front()->SetEnter(true);
						}
						else {
							if (aux.front()->GetStay()) {
								aux.front()->SetStay(false);
								aux.front()->SetExit(true);
							}
						}
					}
					else {
						if (aux.front()->GetStay()) {
							aux.front()->SetStay(false);
							aux.front()->SetExit(true);
						}
					}
				}
				aux2.pop_front();
			}
			aux.pop_front();
		}
	}
}
