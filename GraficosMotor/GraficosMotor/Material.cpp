#include "Material.h"

Material::Material() {

}
Material::Material(std::string sprite) {
	currentSprite = sprite;
}
Material::~Material() {

}
void Material::SetCurrentSprite(std::string sprite) {
	currentSprite = sprite;
	StartSprite();
}
void Material::StartSprite() {
	glGenTextures(1, &m_MaterialId);
	glBindTexture(GL_TEXTURE_2D, m_MaterialId);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(currentSprite.c_str(), &m_Width, &m_Height, &m_BPP, 0);
	if (data)
	{
		if(m_BPP ==3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		else if(m_BPP == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	std::cout <<&m_Width<< std::endl;
	stbi_image_free(data);
	
}
void Material::Bild() {
	glBindTexture(GL_TEXTURE_2D, m_MaterialId);
}
bool Material::GetSpriteSheet() {
	return SpriteSheet;
}
void Material::SetSpriteSheet(std::string _SpriteSheet, int _x, int _y) {
	currentSprite = _SpriteSheet;
	SpriteSheet = true;
	StartSprite();
	x = _x;
	y = _y;
	cantFrames = x * y;
	increaseX = 1.0f / x;
	increaseY = 1.0f / y;
}
void Material::GetFrame(float* frame) {
	int aux = idFrame;
	int restY = 0;
	int multX = 1;
	while(x < aux) {
		restY++;
		aux -= x;
	}
	multX = aux;
	//Primer punto (1,1)
	frame[0] = 0.0f + increaseX * multX;
	frame[1] = 0.0f + increaseY * (y - restY);
	//Segundo putno (1,0)
	frame[2] = 0.0f + increaseX * multX;
	frame[3] = 0.0f + increaseY * (y - (restY + 1));
	//tercer putno (0,0)
	frame[4] = 0.0f + increaseX * (multX - 1);
	frame[5] = 0.0f + increaseY * (y - (restY + 1));
	//tercer putno (1,0)
	frame[6] = 0.0f + increaseX * (multX - 1);
	frame[7] = 0.0f + increaseY * (y - restY);
}
void Material::SetIdFrame(int id) {
	if (id <= cantFrames)
		idFrame = id;
	else
		idFrame = cantFrames;
}
int Material::GetIdFrame() {
	return idFrame;
}
