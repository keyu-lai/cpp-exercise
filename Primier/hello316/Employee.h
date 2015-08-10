#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <set>
#include <iostream>

class Message
{
	friend class Folder;
private:
	std::string content;
	std::set<Folder*> folders;
	void add_folder(Folder& f);
	void del_folder(Folder& f);
	void removeFolders();
public:
	explicit Message(const std::string &s = std::string()) : content(s) { }
	Message(const Message &m);
	Message& operator=(Message m);
	~Message();
	void output();

};

#endif

class Folder
{
	friend class Message;
private:
	std::set<Message*> messages;
	void removeMessages();
	std::string content;
public:
	Folder(const std::string &s) : content(s) { }
	Folder(const Folder &f);
	Folder& operator=(Folder f);
	~Folder();
	void add(Message &m);
	void remove(Message &m);
	void output()
	{
		for (auto c : messages)
			std::cout << c->content << std::ends;
		std::cout << std::endl;
	}
};