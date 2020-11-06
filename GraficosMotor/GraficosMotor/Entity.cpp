#include "Entity.h"

Entity::Entity() {

}
Entity::Entity(Renderer * rend) {
	ren = rend;
}
Entity::Entity(float x, float y,Renderer * rend) {
	ren = rend;
	AspectRatio(x, y);
}
Entity::~Entity() {

}
void Entity::FreeMemory() {
	delete position;
	if (material != NULL)
		delete material;
}
void Entity::Draw() {
	unsigned int indices[]{
		0, 1, 3,
		1, 2, 3
	};
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	unsigned int buffer, VAO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &buffer);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	if(material != NULL)
		material->Bild();
	

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glm::mat4 ModelMatrix(1.f);
	ModelMatrix = glm::translate(ModelMatrix, *position);
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotationX), glm::vec3(1.f, 0.f, 0.f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotationY), glm::vec3(0.f, 1.f, 0.f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotationZ), glm::vec3(0.f, 0.f, 1.f));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(scale));
	//ModelMatrix = camera * ModelMatrix;
	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec3 position;\n"
		"layout(location = 1) in vec3 aColor;\n"
		"layout(location = 2) in vec2 aTexCoord;\n"
		"uniform mat4 ModelMatrix;\n"
		"out vec3 ourColor;\n"
		"out vec2 TexCoord;\n"
		"\n"
		"void main()\n"
		"{\n"
		"   gl_Position = ModelMatrix * vec4(position, 1.f);\n"
		"   ourColor = aColor;\n"
		"   TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
		"}\n";
	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"out vec4 FragColor;\n"
		"\n"
		"in vec3 ourColor;\n"
		"in vec2 TexCoord;\n"
		"uniform sampler2D ourTexture;\n"
		"void main()\n"
		"{\n"
		"if(1 == 1)\n"
		"{\n"
		"   FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);\n"
		"}\n"
		"else\n"
		"{\n"
		"	FragColor = vec4(ourColor, 1.0);\n"
		"}\n"
		"}\n";

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);
	glUniformMatrix4fv(glGetUniformLocation(shader, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));

	glBindVertexArray(VAO);
	ren->Draw(6);
}
void Entity::Draw(std::string figure, glm::mat4 camera) {
	//Draw(camera);
}
int Entity::CodeString(std::string figure) {
	if (figure == "Triangle")
		return 1;
	else if (figure == "Up")
		return 10;
	else if (figure == "Down")
		return 11;
	else if (figure == "Left")
		return 12;
	else if (figure == "Right")
		return 13;
	else
		return 0;
}
void Entity::TrasformPosition(float pod[6]) {
	for (int a = 0; a < LongitudArray(); a++) {
		positions[a] = pod[a];
	}
}
void Entity::Scale(float _scale) {
	scale = _scale;
}
void Entity::ModifyScale(float _scale) {
	scale += _scale;
}
void Entity::RotationX(float angle) {
	rotationX += angle;
}
void Entity::RotationY(float angle) {
	rotationY += angle;
}
void Entity::RotationZ(float angle) {
	rotationZ += angle;
}
void Entity::MovePosition(float speed, std::string MoveDirection) {
	switch (CodeString(MoveDirection))
	{
	case 0:
		std::cout << "Error el codigo que uso no tiene una definicion";
		break;
	case 10:
			position->y += speed;
		break;
	case 11:
			position->y -= speed;
		break;
	case 12:
			position->x -= speed;
		break;
	case 13:
			position->x += speed;
		break;
	default:
		break;
	}
}
int Entity::LongitudArray() {
	return sizeof(positions) / sizeof(*positions);
}
void Entity::AspectRatio(float x, float y) {
	int max;
	int aux = 0;
	int aux2 = 1;
	if (x > y)
		max = x;
	else
		max = y;
	while(aux < LongitudArray()) {
		positions[aux] = positions[aux] / max;
		std::cout << "Posicion: " + aux << std::endl;
		if (aux % 2) {
			positions[aux] = positions[aux] * x;
		}
		else
		{
			positions[aux] = positions[aux] * y;
		}
		if(aux >= aux2) {
			aux += 6;
			aux2 = aux + 2;
		}
		aux++;
	}
}
unsigned int Entity::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fs = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}
unsigned int Entity::CompileShader(const std::string& source, unsigned int type) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int lenght;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		char* message = (char*)alloca(lenght * sizeof(char));
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "fragment") << " Shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}
//COmponents
void Entity::AddComponent(std::string comp) {
	if (comp == "Material") {
		material = new Material();
	}
}
Material* Entity::GetMaterial() {
	return material;
}
