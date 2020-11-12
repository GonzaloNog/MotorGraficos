#include "Shape.h"

Shape::Shape() {

}
Shape::~Shape() {

}
void Shape::Draw(std::string figure, glm::mat4 camera) {

	switch (CodeString(figure))
	{
	case 0:
		std::cout << "Error el codigo que uso no tiene una definicion";
		break;
	case 1:
		DrawTriangle(camera);
	default:
		break;
	}
}
int Shape::CodeString(std::string figure) {
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
void Shape::DrawTriangle(glm::mat4 camera) {
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glm::mat4 ModelMatrix(1.f);
	ModelMatrix = glm::translate(ModelMatrix, *position);
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotationX), glm::vec3(1.f, 0.f, 0.f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotationY), glm::vec3(0.f, 1.f, 0.f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotationZ), glm::vec3(0.f, 0.f, 1.f));
	ModelMatrix = glm::scale(ModelMatrix, *scale);
	//ModelMatrix = camera * ModelMatrix;
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
	glUniformMatrix4fv(glGetUniformLocation(shader, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));
}
