#pragma once
class Field
{
public:
	enum Type {
		EMPTY,
		DANGER,
		WELL,
		RELIC
	};
	Field();
	Field(Type);
	Type getType();
	friend class Board;
	bool found;
private:
	Type type;

};

