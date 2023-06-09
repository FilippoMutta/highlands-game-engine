#pragma once

class Actor;

class Component {
public:
	virtual void Initialize(Actor *actor) = 0;
	virtual void Delete() = 0;
protected:
	Actor *Owner;
};
