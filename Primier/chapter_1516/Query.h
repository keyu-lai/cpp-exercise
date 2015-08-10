#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <memory>
#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"

class Query_base;
class Query;
class WordQuery;
class NotQuery;
class BinaryQuery;
class AndQuery;
class OrQuery;

class Query_base{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

class WordQuery : public Query_base{
	friend class Query;
private:
	WordQuery(const std::string &s) : query_word(s) { }
	QueryResult eval(const TextQuery &t) const override
	{
		return t.query(query_word);
	}
	std::string rep() const override { return query_word; }
	std::string query_word;
};

class Query{
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
	friend std::ostream& operator<<(std::ostream &os, const Query &query);
public:
	Query(const std::string& s) : q(new WordQuery(s)){ }
	QueryResult eval(const TextQuery &t) const 
	{
		return q->eval(t);
	}
	std::string rep() const
	{
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) :q(query) { }
	std::shared_ptr<Query_base> q;
};

class NotQuery : public Query_base{
	friend class Query;
	friend Query operator~(const Query &);
private:	
	NotQuery(const Query& q) : query(q) { }
	QueryResult eval(const TextQuery &t) const override;
	std::string rep() const override { return "~+" + query.rep() + ")"; }
	Query query;
};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base{
protected:
	BinaryQuery(const Query &l, const Query &r, const std::string &s) :
		lhs(l), rhs(r), opSym(s) { }
	std::string rep() const { return "(" + lhs.rep() + opSym + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") { }
	QueryResult eval(const TextQuery &) const override;
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery : public BinaryQuery{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "|") { }
	QueryResult eval(const TextQuery &) const override;
};

inline Query operator|(const Query& lhs, const Query& rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif



