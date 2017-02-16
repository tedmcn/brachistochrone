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
	*float getV();

	void setP(float x1, float y1, float z1);
	*float getP();

	void setD(float x1, float y1, float z1);
	*float getD();

	

//Everything here can only be used within the class
protected:

	float v;	//Velocity

	float p[3];	//Position represented with 3 coordinates
	
	float d[3];	//Direction, represented with a vector from the
			//origin to the direction of this point
			
	

};

//Constructor
Gameobject::Gameobject(){

}

//Deconstructor
Gameobject::~Gameobject(){

}

//Set the velocity of the object
void Gameobject::setV(float velocity){
	v = velocity;
}

//Read the velocity of the object
float Gameobject::getV(){
	return v;
}

//Set the game objects main coordinates
void Gameobject::setP(float x1, float y1, float z1){
	p[0]=x1;
	p[1]=y1;
	p[2]=z1;
}

//Read the game objects coordinates
float* Gameobject::getP(){
	return p;
}

//Set the Direction of the object
void Gameobject::setD(float x, float y, float z){
	d[0]=x;
	d[1]=y;
	d[2]=z;
}

//Read the direction of the object
float* Gameobject::getD(){
	return d;
}

//Different for every child class
void Gameobject::draw(){
}


//Return true if the two objects have points where they overlap
bool Gameobject::intersect(Gameobject obj){
	return false;
}

//Returns the object that is directly below this object (any distance)
Gameobject Gameobject::below(){
	return null;
}