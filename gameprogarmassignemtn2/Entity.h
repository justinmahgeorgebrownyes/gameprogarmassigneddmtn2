#pragma once
#include <string>
#include <vector>

using namespace std;


class Entity
{
protected:
	string m_name, m_description;
	string m_color;
	string m_verb;


	vector <string> m_verbssString;

	


public:
	virtual void examine();
	virtual void open() ;
	virtual void close();
	virtual void enter();
	virtual void push() ;
	virtual void take() ;
	virtual void use() ;


	virtual void unlock() ;
	virtual void lock() ;


	virtual void smash();


	void setVerbs(vector<string> s) {
		m_verbssString = s;
	}
	// Getter
	vector<string> getVerbs() {
		return m_verbssString;
	}


	void setName(string s) {
		m_name = s;
	}
	// Getter
	string getName() {
		return m_name;
	}


	Entity(string name, string description, string color) : m_name(name), m_description(description), m_color(color) {}


	Entity();

};

