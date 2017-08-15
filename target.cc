#include "target.h"
#include <string>
using namespace std;

bool Target::isLeaf() const {
  return true;
}

void Target::addDepend(Target *d) {
}

Target::Target(const string &name, ostream &out) : out{out}, name{name} {}

void Target::update(int time) {
}

int Target::lastUpdated() const {
  return 0;
}

void Target::build() {
}
