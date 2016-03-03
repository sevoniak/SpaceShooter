#include "Torpedo.h"

Torpedo::Torpedo()
{
	XMFLOAT4 torpedoColors[6];
	XMFLOAT4 torpedoBlue = XMFLOAT4(0.0f, 0.0f, 0.75f, 1.0f);
	XMFLOAT4 torpedoOrange = XMFLOAT4(1.0f, 0.5f, 0.1f, 1.0f);
	for(int i = 0; i < 6; i++)
		torpedoColors[i] = torpedoOrange;
	body = new CubeObject(0.2f, 0.2f, 1.0f, true, torpedoColors);

	wing = new PrismObject(0.05f, 0.3f, 3, torpedoBlue);
	wing->setParentMatrix(body->getWorldMatrix());
	wing->translate(0.2f, 0.0f, -0.5f);

	wing2 = new PrismObject(0.05f, 0.3f, 3, torpedoBlue);
	wing2->translate(-0.2f, 0.0f, -0.5f);
	wing2->rotateY(XM_PI);
	wing2->setParentMatrix(body->getWorldMatrix());

	firing = false;
	tPos = XMFLOAT3(0.0f, 0.0f, 0.0f);
	direction = XMFLOAT3(0.0, 0.0, 0.0);
	
	firing = false;
	exploded = false;
	counter = 0;
	objs.push_back(body);
	objs.push_back(wing);
	objs.push_back(wing2);
}

Torpedo::~Torpedo(void)
{
	if(body)
		delete body;
	if(wing)
		delete wing;
	if(wing2)
		delete wing2;
	body = 0;
	wing = 0;
	wing2 = 0;
}

GameObject* Torpedo::getModel() { return body; }

GameObject* Torpedo::getModel2() { return wing; }

GameObject* Torpedo::getModel3() { return wing2; }

vector<GameObject*> Torpedo::getModels() { return objs; }

void Torpedo::spawnTorpedo(XMFLOAT3 pos, XMFLOAT3 camDir, XMFLOAT3 dir)
{
	tPos = XMFLOAT3(pos.x + 4*camDir.x, pos.y + 4*camDir.y, pos.z + 4*camDir.z);
	body->translate(tPos.x, tPos.y, tPos.z);
	direction = dir;
}

void Torpedo::advance()
{
	counter++;

	tPos.x += direction.x * TORPEDO_SPEED;
	tPos.y += direction.y * TORPEDO_SPEED;
	tPos.z += direction.z * TORPEDO_SPEED;
	body->translate(direction.x * TORPEDO_SPEED, direction.y * TORPEDO_SPEED, direction.z * TORPEDO_SPEED);
	if (TORPEDO_REP < counter)
		exploded = true;
}

void Torpedo::resetTorpedo()
{
	firing = false;
	exploded = false;
	counter = 0;

	body->translate(-tPos.x, -tPos.y, -tPos.z);
	tPos.x = 0.0f;
	tPos.y = 0.0f;
	tPos.z = 0.0f;
}

bool Torpedo::isFiring() { return firing; }

XMFLOAT3 Torpedo::getPos() { return tPos; }

void Torpedo::setExploded(bool state){ exploded = state; }

bool Torpedo::hasExploded(){ return exploded; }

void Torpedo::explodeTorpedo() { counter = TORPEDO_REP + 1; }

void Torpedo::setFiring(bool firingState) { firing = firingState; }