#include "Common.h"

using namespace std;

class Expression_sum: public Expression {
public:
    Expression_sum(ExpressionPtr left_, ExpressionPtr right_):
        left(std::move(left_)), right(std::move(right_)) {}
    int Evaluate() const override {
        return left->Evaluate() + right->Evaluate();
    }
    std::string ToString() const override {
        return "(" + left->ToString() + ")" + "+" + "("  + right->ToString() + ")";
    }
private:
    ExpressionPtr left;
    ExpressionPtr right;
};

class Expression_prod: public Expression {
public:
    Expression_prod(ExpressionPtr left_, ExpressionPtr right_):
        left(std::move(left_)), right(std::move(right_)) {}
    int Evaluate() const override {
        return left->Evaluate() * right->Evaluate();
    }
    std::string ToString() const override {
        return "(" + left->ToString() + ")" + "*" + "("  + right->ToString() + ")";
    }
private:
    ExpressionPtr left;
    ExpressionPtr right;
};

class Expression_val: public Expression {
public:
    Expression_val (int value): val(value) {}
    int Evaluate() const override {
        return val;
    }
    std::string ToString() const {
        return std::to_string(val);
    }
private:
    int val;
};

// Функции для формирования выражения
ExpressionPtr Value(int value) {
    return std::make_unique<Expression_val>(value);
}
ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right) {
    return std::make_unique<Expression_sum>(std::move(left), std::move(right));
}
ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right) {
    return std::make_unique<Expression_prod>(std::move(left), std::move(right));
}