#include "Field.h"

Field::Field() {
	type = EMPTY;
}

Field::Field(Field::Type type) {
	this->type = type;
}

Field::Type Field::getType() {
	return type;
}
