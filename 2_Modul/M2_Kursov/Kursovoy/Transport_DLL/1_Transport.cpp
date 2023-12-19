#include "1_Transport.h"

	Transport::Transport(std::string name) :name(name) {}
	int Transport::get_type() { return 0; }
	int Transport::get_count() { return 0; }
	const std::string& Transport::get_name() const { return "0"; }
	void Transport::set_count(int cn) {};
	void Transport::set_distance(double dist) {};
	double Transport::comp() { return 0; };
