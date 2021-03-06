//门面(外观)模式
#include <iostream>
using namespace std;

class Carmera {
public:
	void turnOn() {
		cout << "carmera on" << endl;
	}
	void turnOff() {
		cout << "carmera off" << endl;
	}
};

class Light {
public:
	void turnOn() {
		cout << "light on" << endl;
	}
	void turnOff() {
		cout << "light off" << endl;
	}
};

class Sensor {
public:
	void active() {
		cout << "sensor on" << endl;
	}
	void deactive() {
		cout << "sensor off" << endl;
	}
};

class Alarm {
public:
	void active() {
		cout << "alarm on" << endl;
	}
	void deactive() {
		cout << "alarm off" << endl;
	}
};

class SecuritFacade {
public:
	SecuritFacade() {
		Carmera* m_pCarmera = new Carmera;
		Light* m_pLight = new Light;
		Sensor* m_pSensor = new Sensor;
		Alarm* m_pAlaram = new Alarm;
	}
	void active() {
		m_pCarmera->turnOn();
		m_pLight->turnOn();
		m_pSensor->active();
		m_pAlaram->active();
	}
	void deactive() {
		m_pCarmera->turnOff();
		m_pLight->turnOff();
		m_pSensor->deactive();
		m_pAlaram->deactive();
	}
	~SecuritFacade()
	{
		if(m_pCarmera != nullptr)
			m_pCarmera->~Carmera();
		if(m_pLight != nullptr)
			m_pLight->~Light();
		if(m_pSensor != nullptr)
			m_pSensor->~Sensor();
		if(m_pAlaram != nullptr)
			m_pAlaram->~Alarm();

	}
private:
	Carmera* m_pCarmera;
	Light* m_pLight ;
	Sensor* m_pSensor ;
	Alarm* m_pAlaram ;
};

//LOD
int main() {
	SecuritFacade facade;
	
	cout << "---ON---" << endl;
	facade.active();

	cout << "---OFF---" << endl;
	facade.deactive();

	return 0;
}