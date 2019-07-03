// własna klasa reprezentująca wektor

template<class T>
class myVector
{
public:
	myVector()
	{
		x = 0;
		y = 0;
	}

	myVector(float fx, float fy)
	{
		x = fx;
		y = fy;
	}

	~myVector()
	{

	}

	//wektor 2D
	T x, y;


	/* OPERATORY */ 
	// dodawanie wektorów
	myVector<T>operator + (myVector<T> vec)
	{
		myVector<T> returnV;
		returnV.x = x + vec.x;
		returnV.y = y + vec.y;
		return returnV;
	}

	// odejmowanie wektorów
	myVector<T> operator - (myVector<T> vec)
	{
		myVector<T> returnV;
		returnV.x = x - vec.x;
		returnV.y = y - vec.y;
		return returnV;
	}

	//mnożenie przez skalar
	myVector<T> operator * (float numb)
	{
		myVector<T> returnV;
		returnV.x = x * numb;
		returnV.y = y * numb;
		return returnV;
	}

	// dzielenie przez skalar
	myVector<T> operator / (float numb)
	{
		myVector<T> returnV;
		returnV.x = x / numb;
		returnV.y = y / numb;
		return returnV;
	}

	// iloczyn wektorowy
	float operator * (myVector<T> vec)
	{
		return (x * vec.x) + (y * vec.y);
	}



};

typedef myVector<float> v2f;
typedef myVector<int> v2i;
