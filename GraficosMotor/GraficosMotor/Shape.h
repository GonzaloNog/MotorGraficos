#include "Entity.h"

class ZENGINE_API Shape: public Entity
{
public:
	void Draw(std::string figure, glm::mat4 camera);
	Shape();
	~Shape();
	int CodeString(std::string code);
private:
	void DrawTriangle(glm::mat4 camera);
};

