#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "model/expression.h"
#include "model/constraint.h"
#include "algorithm/algorithm.h"

namespace opencbls {
	template <class T>
	void simple_hill_climbing(std::vector<std::raw_ptr<var_t<T>>>& variables,
			std::vector<std::pair<T, std::unique_ptr<constraint_t<T>>>>& constraints,
			std::any parameters) {
		std::cout << "Number of variables: " << variables.size() << std::endl;
		std::cout << "Number of constraints: " << constraints.size() << std::endl;
		auto violation = [&variables, &constraints]() {
			T _violation = T(0);
			for (auto&& constraint : constraints) {
				_violation += constraint.first * constraint.second->violation();
			}
			return _violation;
		};

		auto delta = [&variables, &constraints](std::raw_ptr<var_t<T>> var, T value) {
			T _delta = T(0);
			for (auto&& constraint : constraints) {
				_delta += constraint.first * constraint.second->violation_delta(var, value);
			}
			return _delta;
		};

		auto search = [&variables, &constraints, delta]() {
			for (auto&& _var : variables) {
				for (T _value = _var->min(); _value < _var->max(); _value += constant::tolerance<T>) {
					T _delta = delta(_var, _value);
					if (_delta < 0) {
						_var->assign(_value);
						return true;
					}
				}
			}
			return false;
		};

		while (true) {
			std::cout << "Current violation: " << violation() << std::endl;
			if (!search()) {
				break;
			}
		}
	}

	template void simple_hill_climbing<int>(std::vector<std::raw_ptr<var_t<int>>>& variables,
			std::vector<std::pair<int, std::unique_ptr<constraint_t<int>>>>& constraints,
			std::any parameters);
}
