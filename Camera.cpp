#include "Camera.h"
#include "Input.h"

using namespace Input;

Camera::Camera() :GameObject(transform)
{
	transform.position = VGet(0, 0, 0);
	transform.rotation = VGet(0, 0, 0);
	transform.scale = VGet(1, 1, 1);
}

void Camera::Init()
{
	
}

void Camera::Update()
{
	Move();
	Zoom();
}

//--------------------------------------------------

void Camera::Move()
{
	if (Mouse::GetMouseButton(MOUSE_INPUT_MIDDLE)) {
		transform.position.x += Mouse::GetMouseMoveDelta().x / 2;
		transform.position.y += Mouse::GetMouseMoveDelta().y / 2;
	}
}

void Camera::Zoom()
{
	// ズームアウト
	if (Mouse::GetIsWheelBack()) {
		if (transform.position.z >= zoomableMin) {
			transform.position.z -= zoomDistance;
		}

		else {
			transform.position.z = zoomableMin;
		}
	}

	// ズームイン
	if (Mouse::GetIsWheelForward()) {
		if (transform.position.z <= zoomableMax) {
			transform.position.z += zoomDistance;
		}

		else {
			transform.position.z = zoomableMax;
		}
	}
}

void Camera::Zoom(int zoomDistance)
{

}