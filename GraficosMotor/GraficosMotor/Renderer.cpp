#include "Renderer.h"


Renderer::Renderer(GLFWwindow * win) {
	wind = win;
}
Renderer::~Renderer() {

}
void Renderer::FreeMemory() {
	//delete ent;
}
void Renderer::SetColorBackground(float a, float b, float c) {
	color[0] = a;
	color[1] = b;
	color[2] = c;
}
void Renderer::setColorBackground(float a, float b, float c, float d) {
	color[0] = a;
	color[1] = b;
	color[2] = c;
	color[3] = d;
}
void Renderer::MoveEntity(float speed, std::string moveDirection) {
	//ent->MovePosition(speed, moveDirection);
}
void Renderer::ScaleEntity(float scale) {
	//ent->Scale(scale);
}
void Renderer::ModifyScaleEntity(float scale) {
	//ent->ModifyScale(scale);
}
void Renderer::RotationXEntity(float _angle) {
	//ent->RotationX(_angle);
}
void Renderer::RotationYEntity(float _angle) {
	//ent->RotationY(_angle);
}
void Renderer::RotationZEntity(float _angle) {
	//ent->RotationZ(_angle);
}
void Renderer::UpdateWindow(){
	ConfigCamera();
	glfwPollEvents();
	glClearColor(color[0], color[1], color[2], color[3]);
	glfwSwapBuffers(wind);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::ConfigCamera() {
	ViewMatrix = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, 3.0f));
	CameraMatrix = glm::lookAt(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0, 0, 1));
	projectionMatrix = glm::perspective(45.0f, 4.0f /3.0f, 0.1f, 100.0f);
	MVPmatrix = projectionMatrix * ViewMatrix;
}
void Renderer::Draw(int count) {
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}

