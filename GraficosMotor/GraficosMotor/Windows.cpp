#include "Windows.h"

Windows::Windows() {

}
Windows::~Windows() {

}
void Windows::Open(int x, int y, std::string name) {
	glewExperimental = true; // Needed for core profile
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	// Open a window and create its OpenGL context
	 // (In the accompanying source code, this variable is global for simplicity)
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
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		SetColorBackground(0.5f,0.5f,0.5f);
		glClearColor(color[0],color[1],color[2],color[3]);
		glClear(GL_COLOR_BUFFER_BIT);
		// Draw nothing, see you in tutorial 2 !

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
}
bool Windows::IsOpen() {
	if (!glfwWindowShouldClose(window)) {
		return true;
	}
	else {
		return false;
	}
}
void Windows::SetColorBackground(float a, float b, float c) {
	color[0] = a;
	color[1] = b;
	color[2] = c;
}
void Windows::setColorBackground(float a, float b, float c, float d) {
	color[0] = a;
	color[1] = b;
	color[2] = c;
	color[3] = d;
}
