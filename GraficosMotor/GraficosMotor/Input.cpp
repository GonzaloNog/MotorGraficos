#include "Input.h"

Input::Input() {
}
Input::~Input() {

}
void Input::Initialize(Windows* _wind) {
	wind = _wind;
}
bool Input::PressedKey(std::string keyCode) {
	if (keyCode == "space") {
		if (glfwGetKey(wind->GetWindows(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			return true;
		}
	}
	return false;
}