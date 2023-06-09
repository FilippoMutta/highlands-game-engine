#include <game/component/camera.hpp>

void CameraComponent::Initialize(Actor *actor) {
	Owner = actor;
}

void CameraComponent::Delete() {

}
