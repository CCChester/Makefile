#include "makefile.h"
#include <iostream>
#include <string>
using namespace std;

Makefile::Makefile(ostream &out) : out{out} {
}

Makefile::~Makefile() {
}

void Makefile::addDepend(const string &t, const string &d) {
}

void Makefile::changeTarget(const string &t) {
}

void Makefile::rebuild(const string &t) {
}

