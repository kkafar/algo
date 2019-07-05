// własna klasa reprezentująca wektor

template<class T>
class myVector
{
public:

	//wektor 2D
	T x, y;


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

	// funkcja zwracająca dł. wektora
	float getLength()
	{
		return sqrt(x * x + y * y);
	}

	// funkcja przerabiająca wektor na rzecz którego jest wywoływana na wektor jednostkowy
	void normalizeVector() 
	{
		(*this) = (*this) / getLength();
	}

	// funkcja zwracająca wektor jednostkowy
	myVector<T> getNormalizedVector()
	{
		myVector<T> returnV;
		returnV = ((*this) / getLength());
		return returnV;
	}


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

	// iloczyn skalarny
	float operator * (myVector<T> vec)
	{
		return (x * vec.x) + (y * vec.y);
	}

	// przypisanie
	myVector<T> operator = (myVector<T> vec)
	{
		myVector<T> returnV;
		returnV.x = vec.x;
		returnV.y = vec.y;
		x = vec.x;
		y = vec.y;
		return returnV;
	}

	bool operator == (myVector<T> vec)
	{
		return (x == vec.x && y == vec.y);
	}
};

// operator mnożenia przez skalar, ale w zmienionej kolejności czynników
// nie: wektor * skalar
// tylko: skalar * wektor
template<class T>
myVector<T> operator * (float numb, myVector<T> vec)
{
	myVector<T> returnV;
	returnV.x = vec.x * numb;
	returnV.y = vec.y * numb;
	return returnV;
}


typedef myVector<float> v2f;
typedef myVector<int> v2i;
typedef myVector<double> v2d;
