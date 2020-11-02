#include "Entity.h"

Entity::Entity() {

}
Entity::~Entity() {

}
void Entity::FreeMemory() {
	delete position;
	if (material != NULL)
		delete material;
}
void Entity::Draw(glm::mat4 camera, GLFWwindow* win) {
	unsigned int indices[]{
		0, 1, 3,
		1, 2, 3
	};
	unsigned int buffer, VAO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &buffer);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture
	stbi_set_flip_vertically_on_load(true); 
	int width, height, nrChannels;
	unsigned char* data = stbi_load("img1.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

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
		"   FragColor = texture(ourTexture, TexCoord);\n"
		"}\n";
	glClearColor(0.2f,0.3f,0.3f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindTexture(GL_TEXTURE_2D, texture);

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);
	glUniformMatrix4fv(glGetUniformLocation(shader, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(win);
	glfwPollEvents();
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
