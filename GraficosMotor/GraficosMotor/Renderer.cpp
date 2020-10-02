#include "Renderer.h"


Renderer::Renderer() {
	ent = new Entity();
}
Renderer::~Renderer() {

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
	ent->MovePosition(speed, moveDirection);
}
void Renderer::ScaleEntity(float scale) {
	ent->Scale(scale);
}
void Renderer::UpdateWindow(GLFWwindow* win){
	ent->Draw("Triangle");
	ent->Rotation("x", 60);
	glClearColor(color[0], color[1], color[2], color[3]);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glfwSwapBuffers(win);
	glfwPollEvents();
}

