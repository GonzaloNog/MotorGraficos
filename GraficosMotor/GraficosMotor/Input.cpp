#include "Input.h"

Input::Input() {
}
Input::~Input() {

}
void Input::Initialize(GLFWwindow* _wind) {
	wind = _wind;
}
bool Input::PressedKey(std::string keyCode) {
	if (keyCode == "space") {
		if (glfwGetKey(wind, GLFW_KEY_SPACE) == GLFW_PRESS) {
			return true;
		}
	}
	return false;
}