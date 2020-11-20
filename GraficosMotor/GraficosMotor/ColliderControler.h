#ifndef _COLLIDERCONTROLER_H
#define _COLLIDERCONTROLER_H
#include "Exports.h"
#include <iostream>
#include<list>
#include"BoxCollider2D.h"

namespace  EngineUtils {
	class ZENGINE_API ColliderControler
	{
	private:
		static ColliderControler* sInstance;
		std::list <Collider*> ListColl;
	public:
		static ColliderControler* Instance();
		static void Release();

		void NewCollider(Collider* coll);
		void DeleteCollider(Collider* coll);
		void CalculateCollider();
	private:
		ColliderControler();
		~ColliderControler();
	};
}
#endif

