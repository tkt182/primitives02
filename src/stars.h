#ifndef __STARS_H_
#define __STARS_H_

#include "ofMain.h"

class Stars{

public:

	Stars(int num = 1000, float radius = 4.0);
	virtual ~Stars();

	void setup();
	void draw();


private:

	int      _num;      // �\�����鋅�̐�
	float    _radius;   // ���̔��a
	float    _limit;    // ���̍��W�𐶐�����ۂ�MAX�l
	ofVec3f* _pos;      // ���̒��S���W

	ofFloatColor  _color;    // ���̐F


};


#endif /* __STARS_H_ */