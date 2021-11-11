#include "Exports.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>



class ZENGINE_API Collider
{
protected:
	bool trigger = false;
	glm::vec3* scale = new glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3* position = new glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec2* size = new glm::vec2(1.0f,1.0f);
	bool Enter = false;
	bool Stay = false;
	bool Exit = false;
	Collider* coll;
public:
	Collider();
	~Collider();
	void SetTrigger(bool _trigger);
	bool GetTrigger();

	void SetScale(float _scale);
	void SetScale(glm::vec3 scale);
	glm::vec3 GetScale();

	void SetPosition(glm::vec3 _position);
	glm::vec3 GetPosition();

	void SetSize(glm::vec2 _size);
	glm::vec2 GetSize();

	//Estados
	bool GetEnter();
	bool GetStay();
	bool GetExit();
	void SetEnter(bool _enter);
	void SetStay(bool _stay);
	void SetExit(bool _exit);

	Collider* GetCollider();
	void SetCollider(Collider * coll);
};

