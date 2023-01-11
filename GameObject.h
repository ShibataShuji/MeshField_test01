#pragma once

class GameObject
{
protected://�A�N�Z�X�w��q

	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;

public:
	virtual void Init() = 0;//�������z�֐�
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;


	D3DXVECTOR3 GetPosition()
	{
		return m_Position;
	}


	D3DXVECTOR3 GetForward()//�S�����x�N�g���擾
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.x, m_Rotation.y, m_Rotation.z);

		D3DXVECTOR3 forward;
		forward.x = rot._31;//�O
		forward.y = rot._32;
		forward.z = rot._33;

		return forward;

	}

	D3DXVECTOR3 GetRight()//�S�����x�N�g���擾
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.x, m_Rotation.y, m_Rotation.z);

		D3DXVECTOR3 right;
		right.x = rot._11;//�E
		right.y = rot._12;
		right.z = rot._13;

		return right;

	}

};

