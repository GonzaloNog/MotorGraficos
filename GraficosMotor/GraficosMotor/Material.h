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
	int m_Width, m_Height, m_BPP;
	unsigned char* data;
	std::string currentSprite;
	bool SpriteSheet = false;
	int cantFrames = 0;
	float increaseX;
	float increaseY;
	int x;
	int y;
	int idFrame = 1;
public:
	Material();
	Material(std::string sprite);
	~Material();
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	void SetCurrentSprite(std::string currentSprite);
	void SetSpriteSheet(std::string Sprite, int x, int y);
	void StartSprite();
	void GetFrame(float *frame);
	void Bild();
	bool GetSpriteSheet();
	void SetIdFrame(int id);
	int GetIdFrame();
};

