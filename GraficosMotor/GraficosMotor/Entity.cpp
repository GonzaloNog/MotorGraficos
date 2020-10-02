#include "Entity.h"

Entity::Entity() {

}
Entity::~Entity() {

}
void Entity::Draw(std::string figure) {

	switch (CodeString(figure))
	{
	case 0:
		std::cout << "Error el codigo que uso no tiene una definicion";
		break;
	case 1:
		DrawTriangle();
	default:
		break;
	}
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
		for (int a = 1; a < LongitudArray(); a += 2) {
			position->y += speed;
		}
		break;
	case 11:
		for (int a = 1; a < LongitudArray(); a += 2) {
			position->y -= speed;
		}
		break;
	case 12:
		for (int a = 0; a < LongitudArray(); a += 2) {
			position->x -= speed;
		}
		break;
	case 13:
		for (int a = 0; a < LongitudArray(); a += 2) {
			position->x += speed;
		}
		break;
	default:
		break;
	}
}
int Entity::LongitudArray() {
	return sizeof(positions) / sizeof(*positions);
}
void Entity::DrawTriangle() {
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glm::mat4 ModelMatrix(1.f);
	ModelMatrix = glm::translate(ModelMatrix, *position);
	ModelMatrix = glm::rotate(ModelMatrix,glm::radians(rotationX), glm::vec3(1.f, 0.f, 0.f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotationY), glm::vec3(0.f, 1.f, 0.f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotationZ), glm::vec3(0.f, 0.f, 1.f));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(scale));
	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec3 position;\n"
		"uniform mat4 ModelMatrix;\n"
		"\n"
		"void main()\n"
		"{\n"
		"   gl_Position = ModelMatrix * vec4(position, 1.f);\n"
		"}\n";
	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"   color = vec4(0.5,0.0,0.0,1.0);\n"
		"}\n";

	

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);
	glUniformMatrix4fv(glGetUniformLocation(shader, "ModelMatrix"),1,GL_FALSE, glm::value_ptr(ModelMatrix));
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
