#include "Windows.h"

Windows::Windows() {

}
Windows::~Windows() {

}
void Windows::FreeMemory() {

}
void Windows::Open(int x, int y, std::string name) {
	glewExperimental = true; // Needed for core profile
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
	}
	window = glfwCreateWindow(x, y, name.c_str(), NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
	}
	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
	}
}
bool Windows::IsOpen() {
	if (!glfwWindowShouldClose(window)) {
		return true;
	}
	else {
		return false;
	}
}
void Windows::Close() {
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}
GLFWwindow* Windows::GetWindows() {
	return window;
}