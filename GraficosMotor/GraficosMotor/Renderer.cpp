#include "Renderer.h"
<<<<<<< Updated upstream
=======

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
void Renderer::UpdateWindow(GLFWwindow* win){
	ent->MovePosition(0.001, "Up");
	ent->Draw("Triangle");
	glClearColor(color[0], color[1], color[2], color[3]);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glfwSwapBuffers(win);
	glfwPollEvents();
}

>>>>>>> Stashed changes
