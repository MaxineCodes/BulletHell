/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	Singleton.h
//
//	Description:
//	 Singleton base class with the basics, such as making it impossible to create a new
//	 instance, and a basic static function to get the singleton instance.
// 
//   Making it a base class that other classes inherit, it adds a nice little sign that the
//	 class is a singleton: "Class SomeClassName : public Singleton" 
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

class Singleton
{
public:
	Singleton(const Singleton&) = delete;

	static Singleton& get()
	{
		static Singleton instance;
		return instance;
	}

private:
	Singleton() {}
};

