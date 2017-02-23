class Gameobject{

//Everything in here is public
public:

	//Constructor
	Gameobject();

	//Deconstructor
	~Gameobject();

	void draw();
	bool intersect();	
	Gameobject below();


	void setV(float velocity);
	float getV();

	void setP(float x1, float y1, float z1);
	float* getP();

	void setD(float x1, float y1, float z1);
	float* getD();

	void setA(float x1, float y1, float z1);
	float* getA();

//Everything here can only be used within the class
protected:

	float v;	//Velocity

	float p[3];	//Position represented with 3 coordinates
	
	float d[3];	//Direction, represented with a vector from the
			//origin to the direction of this point
			
	float a[3]; //Acceleration of the ball
	

};