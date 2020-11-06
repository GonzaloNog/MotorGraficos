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
