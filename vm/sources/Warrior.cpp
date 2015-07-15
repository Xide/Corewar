#include "Warrior.hpp"

Warrior::Warrior(std::string const& _name,
                 std::string const& _author,
                 std::string const& _version,
                 std::string const& _date) :
  name(_name), author(_author), version(_version), date(_date) {}

unsigned
Warrior::operator++() {
  return ++_pendingTasks;
}

unsigned
Warrior::operator++(int) {
  return _pendingTasks++;
}

unsigned
Warrior::operator--() {
  if (_pendingTasks == 0) throw std::logic_error(
            "trying to decrement an already empty warrior task.");
  return --_pendingTasks;
}

unsigned
Warrior::operator--(int) {
  if (_pendingTasks == 0) throw std::logic_error(
            "trying to decrement an already empty warrior task.");
  return _pendingTasks--;
}

unsigned
Warrior::operator*(void) const {
  return _pendingTasks;
}

std::ostream&
operator<<(std::ostream& os, Warrior const& w) {
  return os << "<Warrior " << w.name << " at " << &w << ">";
}
