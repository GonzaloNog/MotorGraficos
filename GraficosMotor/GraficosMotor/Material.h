#include "Exports.h"

class ZENGINE_API Material
{
private:
	int m_Width, m_Height, m_BPP;
	unsigned char* data;
public:
	Material();
	~Material();

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};

