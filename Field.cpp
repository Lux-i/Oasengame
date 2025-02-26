#include "Field.h"

Field::Field() {
	this->type = EMPTY;
	this->found = false;
}

Field::Field(Field::Type type) {
	this->type = type;
	this->found = false;
}

Field::Type Field::getType() {
	return this->type;
}
