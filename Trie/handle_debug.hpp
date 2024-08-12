#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> 
ostream& operator<<( ostream& out, const pair<A, B>& x) {
	out << '(' << x.first << ',' << x.second << ')';
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& x) {
	for (long long int i = 0; i < x.size(); i++)out << x[i] << ' ';
	return out;
}

template<typename A, typename B>
ostream& operator<<( ostream& out, const vector<pair<A, B>>& x) {
	for (long long int i = 0; i < x.size(); i++)out << x[i]<<' ';
	return out;
}

template<typename T>
ostream& operator<<( ostream& out, const set<T>& x) {
	auto it = x.begin();
	out << '{';
	while (it != x.end()) {
		out << (*it) << ' ';
		it++;
	}
	out << '}';
	return out;
}

template<typename T>
ostream& operator<<( ostream& out, const multiset<T>& x) {
	auto it = x.begin();
	out << '{';
	while (it != x.end()) {
		out << (*it) << ' ';
		it++;
	}
	out << '}';
	return out;
}

template<typename A, typename B>
ostream& operator<<( ostream& out, const set<pair<A, B>>& x) {
	auto it = x.begin();
	out << '{';
	while (it != x.end()) {
		out << *it;
		it++;
	}
	out << '}';
	return out;
}

template<typename A, typename B>
ostream& operator<<( ostream& out, const multiset<pair<A, B>>& x) {
	auto it = x.begin();
	out << '{';
	while (it != x.end()) {
		out << *it;
		it++;
	}
	out << '}';
	return out;
}

template<typename A, typename B>
ostream& operator<<(ostream& out, const map<A, B>& x) {
	auto it = x.begin();
	out << '<';
	while (it != x.end()) {
		out << it->first << ':' << it->second << ' ';
		it++;
	}
	out << '>';
	return out;
}

template<typename A, typename B>
ostream& operator<<(ostream& out, const unordered_map<A, B>& x) {
	auto it = x.begin();
	out << '<';
	while (it != x.end()) {
		out << it->first << ':' << it->second << ' ';
		it++;
	}
	out << '>';
	return out;
}

template<typename A, typename B, typename C>
ostream& operator<<(ostream& out, const map<pair<A, B>, C>& x) {
	auto it = x.begin();
	out << '<';
	while (it != x.end()) {
		out << it->first << ':' << it->second << ' ';
		it++;
	}
	out << '>';
	return out;
}

template<typename A, typename B, typename C>
ostream& operator<<(ostream& out, const unordered_map<pair<A, B>, C>& x) {
	auto it = x.begin();
	out << '<';
	while (it != x.end()) {
		out << it->first << ':' << it->second << ' ';
		it++;
	}
	out << '>';
	return out;
}

template<typename A, typename B, typename C>
ostream& operator<<(ostream& out, const map<A, pair<B, C>>& x) {
	auto it = x.begin();
	out << '<';
	while (it != x.end()) {
		out << it->first << ':' << it->second << ' ';
		it++;
	}
	out << '>';
	return out;
}

template<typename A, typename B, typename C>
ostream& operator<<(ostream& out, const unordered_map<A, pair<B, C>>& x) {
	auto it = x.begin();
	out << '<';
	while (it != x.end()) {
		out << it->first << ':' << it->second << ' ';
		it++;
	}
	out << '>';
	return out;
}

/* Code for compiler not supporting C++17 standards*/

// template<typename T>
// void debug_print(const string& var_name, T var) {
// 	cout << var_name << " = " << var;
// }

// template<typename T, typename ... Var_Types>
// void debug_print(const string& vars_name, T var, Var_Types ... rest) {
// 	auto comma_pos = vars_name.find(',');
// 	cout << vars_name.substr(0, comma_pos) << " = " << var;
// 	auto next_comma = vars_name.find(',', comma_pos + 1);
// 	debug_print(vars_name.substr(comma_pos + 1, vars_name.size()), rest...);
// }

/* using C++17 folding expression to do the same thing */
template<typename ... Types>
void debug_print(const string& vars_name, const Types& ... var) {
	auto p1 = vars_name.find(vars_name[0]), p2 = vars_name.find(',');
	auto likh_de_bhai = ([&]() {cout << vars_name.substr(p1, p2 - p1) << " = " << var << ' '; p1 = p2 + 1; p2 = vars_name.find(',', p1); return 0;}() + ...);
}