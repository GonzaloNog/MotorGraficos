#include "Collider.h"

Collider::Collider(){

}
Collider::~Collider(){

}

//Set
void Collider::SetTrigger(bool _trigger) {
	trigger = _trigger;
}
void Collider::SetScale(float _scale){
	scale->x = _scale;
	scale->y = _scale;
	scale->z = _scale;
}
void Collider::SetScale(glm::vec3 _scale) {
	scale->x = _scale.x;
	scale->y = _scale.y;
	scale->z = _scale.z;
}
void Collider::SetPosition(glm::vec3 _position) {
	*position = _position;
}
//Get
glm::vec3 Collider::GetScale() {
	return *scale;
}
bool Collider::GetTrigger() {
	return trigger;
}
glm::vec3 Collider::GetPosition() {
	return *position;
}
void Collider::SetSize(glm::vec2 _size) {
	*size = _size;
}
glm::vec2 Collider::GetSize() {
	return *size;
}

//Estados
bool Collider::GetEnter() {
	return Enter;
}
bool Collider::GetStay() {
	return Stay;
}
bool Collider::GetExit() {
	return Exit;
}
void Collider::SetEnter(bool _enter) {
	Enter = _enter;
}
void Collider::SetStay(bool _stay) {
	Stay = _stay;
}
void Collider::SetExit(bool _exit) {
	Exit = _exit;
}

Collider* Collider::GetCollider() {
	return coll;
}
void Collider::SetCollider(Collider * _coll) {
	coll = _coll;
}

