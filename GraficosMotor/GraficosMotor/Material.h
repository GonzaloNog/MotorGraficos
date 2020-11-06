#include "Exports.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glew.h>
#include <glfw3.h>
#include "stb_image.h"

class ZENGINE_API Material
{
private:
	unsigned int  m_MaterialId;
private:
	int m_Width, m_Height, m_BPP;
	unsigned char* data;
	std::string currentSprite;
public:
	Material();
	Material(std::string sprite);
	~Material();
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	void SetCurrentSprite(std::string currentSprite);
	void StartSprite();
	void Bild();
};

