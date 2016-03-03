#pragma once
#include "Shapes/CubeObject.h"
#include "Shapes/PrismObject.h"
#include <vector>
using namespace std;

const float TORPEDO_REP = 150.0f;
const float TORPEDO_SPEED = 0.519f;

class Torpedo
{
private:
	CubeObject* body;
	PrismObject* wing;
	PrismObject* wing2;

	vector<GameObject*> objs;
	XMFLOAT4X4* parentMatrix;
    XMFLOAT3 tPos;
	XMFLOAT3 direction;
    bool exploded;
	bool firing;
	int counter;

public:
	Torpedo(void);
	~Torpedo(void);

	GameObject* getModel();
	GameObject* getModel2();
	GameObject* getModel3();
	vector<GameObject*> getModels();

    void spawnTorpedo(XMFLOAT3, XMFLOAT3, XMFLOAT3);
	void setFiring(bool);
	bool isFiring();
	XMFLOAT3 getPos();
	void advance();
	void explodeTorpedo();
	bool hasExploded();
	void setExploded(bool);
	void resetTorpedo();
};
