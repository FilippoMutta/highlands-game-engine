#pragma once
#include <game/component.hpp>

class CameraComponent : public Component {
public:
	void Initialize(Actor *actor) override;
	void Delete() override;
};
