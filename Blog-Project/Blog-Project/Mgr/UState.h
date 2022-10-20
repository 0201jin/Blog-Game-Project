#pragma once
class UState
{
public:
	UState();
	~UState();

	virtual void Init();

	virtual void Update(float _deltaTime);
	virtual void Redner(float _deltaTime);
};

