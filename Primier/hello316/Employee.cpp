#include "Employee.h"

using namespace std;

void Message::add_folder(Folder& f)
{
	folders.insert(&f);
	f.messages.insert(this);
}

void Message::del_folder(Folder& f)
{
	folders.erase(&f);
	f.messages.erase(this);
}

void Message::output()
{
		for (auto c : folders)
			std::cout << c->content << std::ends;
		std::cout << std::endl;
}

void Message::removeFolders()
{
	for (auto c : folders)
		c->messages.erase(this);
	folders.erase(folders.begin(), folders.end());
}

Message::Message(const Message &m)
{
	content = m.content;
	for (auto c : m.folders)
		add_folder(*c);
}

Message& Message::operator=(Message m)
{
	removeFolders();
	content = m.content;
	for (auto c : m.folders)
		add_folder(*c);
	return *this;
}

Message::~Message()
{
	removeFolders();
}

Folder::Folder(const Folder& f)
{
	for (auto c : f.messages)
		add(*c);
}

Folder& Folder::operator=(Folder f)
{
	removeMessages();
	for (auto c : f.messages)
		add(*c);
	return *this;
}

void Folder::removeMessages()
{
	for (auto c : messages)
		c->folders.erase(this);
	messages.erase(messages.begin(), messages.end());
}

Folder::~Folder()
{
	removeMessages();
}

void Folder::add(Message &m)
{
	m.add_folder(*this);
}

void Folder::remove(Message &m)
{
	m.del_folder(*this);
}


