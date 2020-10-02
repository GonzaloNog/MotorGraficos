#include "Input.h"

Input::Input() {
}
Input::~Input() {

}
void Input::Initialize(GLFWwindow* _wind) {
	wind = _wind;
}
bool Input::PressedKey(std::string keyCode, std::string tipe) {
	if(keyCode == "space") {
		if (tipe == "Release") {
			if (glfwGetKey(wind, GLFW_KEY_SPACE) == GLFW_RELEASE) {
				return true;
			}
		}
		if (tipe == "Press") {
			if (glfwGetKey(wind, GLFW_KEY_SPACE) == GLFW_PRESS) {
				return true;
			}
		}
		if (tipe == "Repeat") {
			if (glfwGetKey(wind, GLFW_KEY_SPACE) == GLFW_REPEAT) {
				return true;
			}
		}
	}
	if (keyCode == "w" || keyCode == "W") {
		if (tipe == "Release") {
			if (glfwGetKey(wind, GLFW_KEY_W) == GLFW_RELEASE) {
				return true;
			}
		}
		if (tipe == "Press") {
			if (glfwGetKey(wind, GLFW_KEY_W) == GLFW_PRESS) {
				return true;
			}
		}
		if (tipe == "Repeat") {
			if (glfwGetKey(wind, GLFW_KEY_W) == GLFW_REPEAT) {
				return true;
			}
		}
	}
	if (keyCode == "s" || keyCode == "S") {
		if (tipe == "Release") {
			if (glfwGetKey(wind, GLFW_KEY_S) == GLFW_RELEASE) {
				return true;
			}
		}
		if (tipe == "Press") {
			if (glfwGetKey(wind, GLFW_KEY_S) == GLFW_PRESS) {
				return true;
			}
		}
		if (tipe == "Repeat") {
			if (glfwGetKey(wind, GLFW_KEY_S) == GLFW_REPEAT) {
				return true;
			}
		}
	}
	if (keyCode == "a" || keyCode == "A") {
		if (tipe == "Release") {
			if (glfwGetKey(wind, GLFW_KEY_A) == GLFW_RELEASE) {
				return true;
			}
		}
		if (tipe == "Press") {
			if (glfwGetKey(wind, GLFW_KEY_A) == GLFW_PRESS) {
				return true;
			}
		}
		if (tipe == "Repeat") {
			if (glfwGetKey(wind, GLFW_KEY_A) == GLFW_REPEAT) {
				return true;
			}
		}
	}
	if (keyCode == "d" || keyCode == "D") {
		if (tipe == "Release") {
			if (glfwGetKey(wind, GLFW_KEY_D) == GLFW_RELEASE) {
				return true;
			}
		}
		if (tipe == "Press") {
			if (glfwGetKey(wind, GLFW_KEY_D) == GLFW_PRESS) {
				return true;
			}
		}
		if (tipe == "Repeat") {
			if (glfwGetKey(wind, GLFW_KEY_D) == GLFW_REPEAT) {
				return true;
			}
		}
	}
	if (keyCode == "q" || keyCode == "Q") {
		if (tipe == "Release") {
			if (glfwGetKey(wind, GLFW_KEY_Q) == GLFW_RELEASE) {
				return true;
			}
		}
		if (tipe == "Press") {
			if (glfwGetKey(wind, GLFW_KEY_Q) == GLFW_PRESS) {
				return true;
			}
		}
		if (tipe == "Repeat") {
			if (glfwGetKey(wind, GLFW_KEY_Q) == GLFW_REPEAT) {
				return true;
			}
		}
	}
	if (keyCode == "e" || keyCode == "E") {
		if (tipe == "Release") {
			if (glfwGetKey(wind, GLFW_KEY_E) == GLFW_RELEASE) {
				return true;
			}
		}
		if (tipe == "Press") {
			if (glfwGetKey(wind, GLFW_KEY_E) == GLFW_PRESS) {
				return true;
			}
		}
		if (tipe == "Repeat") {
			if (glfwGetKey(wind, GLFW_KEY_E) == GLFW_REPEAT) {
				return true;
			}
		}
	}
	return false;
}