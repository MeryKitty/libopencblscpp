from . import capi
from .solver import IntConstraint, IntExpression

class IntAnd(IntConstraint):
    _operand1: IntConstraint
    _operand2: IntConstraint

    def __init__(self, operand1: IntConstraint, operand2: IntConstraint) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_and(self._operand1._get(), self._operand2._get())

class IntOr(IntConstraint):
    _operand1: IntConstraint
    _operand2: IntConstraint

    def __init__(self, operand1: IntConstraint, operand2: IntConstraint) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_or(self._operand1._get(), self._operand2._get())

class IntXor(IntConstraint):
    _operand1: IntConstraint
    _operand2: IntConstraint

    def __init__(self, operand1: IntConstraint, operand2: IntConstraint) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_xor(self._operand1._get(), self._operand2._get())

class IntNot(IntConstraint):
    _operand: IntConstraint

    def __init__(self, operand: IntConstraint) -> None:
        self._operand = operand

    def _get(self):
        return capi.int_constraint_not(self._operand._get())

class IntEqual(IntConstraint):
    _operand1: IntExpression
    _operand2: IntExpression

    def __init__(self, operand1: IntExpression, operand2: IntExpression) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_equal(self._operand1._get(), self._operand2._get())

class IntNotEqual(IntConstraint):
    _operand1: IntExpression
    _operand2: IntExpression

    def __init__(self, operand1: IntExpression, operand2: IntExpression) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_not_equal(self._operand1._get(), self._operand2._get())

class IntLessThan(IntConstraint):
    _operand1: IntExpression
    _operand2: IntExpression

    def __init__(self, operand1: IntExpression, operand2: IntExpression) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_less_than(self._operand1._get(), self._operand2._get())

class IntMoreThan(IntConstraint):
    _operand1: IntExpression
    _operand2: IntExpression

    def __init__(self, operand1: IntExpression, operand2: IntExpression) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_more_than(self._operand1._get(), self._operand2._get())

class IntNotMoreThan(IntConstraint):
    _operand1: IntExpression
    _operand2: IntExpression

    def __init__(self, operand1: IntExpression, operand2: IntExpression) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_not_more_than(self._operand1._get(), self._operand2._get())

class IntNotLessThan(IntConstraint):
    _operand1: IntExpression
    _operand2: IntExpression

    def __init__(self, operand1: IntExpression, operand2: IntExpression) -> None:
        self._operand1 = operand1
        self._operand2 = operand2

    def _get(self):
        return capi.int_constraint_not_less_than(self._operand1._get(), self._operand2._get())


class IntAllNotEqual(IntConstraint):
    _operands: list

    def __init__(self, operands: list) -> None:
        self._operands = operands.copy()

    def _get(self):
        n = len(self._operands)
        temp_operand_list = [ele._get() for ele in self._operands]
        array = capi.new_voidPtrArray(n)
        for i, ptr in enumerate(temp_operand_list):
            capi.voidPtrArray_setitem(array, i, ptr)
        results = capi.int_constraint_all_not_equal(len(self._operands), array)
        capi.delete_voidPtrArray(array)
        return results
