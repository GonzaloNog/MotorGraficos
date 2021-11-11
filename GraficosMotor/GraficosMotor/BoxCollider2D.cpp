#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D(glm::vec3 _scale, glm::vec3 _position) {
	SetScale(_scale);
	SetPosition(_position);
	SetSize(_scale);
}
BoxCollider2D::~BoxCollider2D() {

}
