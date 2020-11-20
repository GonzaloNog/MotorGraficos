#include "Collider.h"

class ZENGINE_API BoxCollider2D : public Collider
{
protected:
public:
	BoxCollider2D(glm::vec3 _scale, glm::vec3 _position);
	~BoxCollider2D();
	void OnColliderEnter(Collider coll);
};

