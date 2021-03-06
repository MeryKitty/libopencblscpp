#ifndef MODEL_NUMERIC_CONSTRAINT_H_INCLUDED
#define MODEL_NUMERIC_CONSTRAINT_H_INCLUDED

#include "basics/constant.h"
#include "basics/raw_ptr.h"
#include "model/expression.h"
#include "model/constraint.h"

namespace opencbls {
	template <class T>
	class constraint_equal : public constraint_t<T> {
	private:
		expr_t<T> _operand1;
		expr_t<T> _operand2;
	protected:
		T violation_delta_helper(std::raw_ptr<var_t<T>> var, T value);
	public:
		constraint_equal(expr_t<T> operand1, expr_t<T> operand2);

		T violation();
	};

	template <class T>
	class constraint_not_equal : public constraint_t<T> {
	private:
		expr_t<T> _operand1;
		expr_t<T> _operand2;
	protected:
		T violation_delta_helper(std::raw_ptr<var_t<T>> var, T value);
	public:
		constraint_not_equal(expr_t<T> operand1, expr_t<T> operand2);

		T violation();
	};

	template <class T>
	class constraint_less_than : public constraint_t<T> {
	private:
		expr_t<T> _operand1;
		expr_t<T> _operand2;
	protected:
		T violation_delta_helper(std::raw_ptr<var_t<T>> var, T value);
	public:
		constraint_less_than(expr_t<T> operand1, expr_t<T> operand2);

		T violation();
	};

	template <class T>
	class constraint_more_than : public constraint_t<T> {
	private:
		expr_t<T> _operand1;
		expr_t<T> _operand2;
	protected:
		T violation_delta_helper(std::raw_ptr<var_t<T>> var, T value);
	public:
		constraint_more_than(expr_t<T> operand1, expr_t<T> operand2);

		T violation();
	};

	template <class T>
	class constraint_not_more_than : public constraint_t<T> {
	private:
		expr_t<T> _operand1;
		expr_t<T> _operand2;
	protected:
		T violation_delta_helper(std::raw_ptr<var_t<T>> var, T value);
	public:
		constraint_not_more_than(expr_t<T> operand1, expr_t<T> operand2);

		T violation();
	};

	template <class T>
	class constraint_not_less_than : public constraint_t<T> {
	private:
		expr_t<T> _operand1;
		expr_t<T> _operand2;
	protected:
		T violation_delta_helper(std::raw_ptr<var_t<T>> var, T value);
	public:
		constraint_not_less_than(expr_t<T> operand1, expr_t<T> operand2);

		T violation();
	};

}

#endif /* MODEL_NUMERIC_CONSTRAINT_H_INCLUDED */
