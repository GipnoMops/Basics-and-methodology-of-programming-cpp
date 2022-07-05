#include <iostream>
#include <memory>
#include <string>

class Expression {
public:
    virtual int Evaluate() const = 0;
    virtual std::string ToString() const {
        return "0";
    }
    virtual ~Expression() {}
};

using ExpressionPtr = std::shared_ptr<Expression>;

class Constant: public Expression {
protected:
    const int value_;

public:
    Constant(const int& a): value_(a) {}

    std::string ToString() {
        return std::to_string(value_);
    }

    int Evaluate() const {
        return value_;
    }

};

template <class T, class Y>
class Summ: public Expression {
private:
    const std::shared_ptr<Expression>& a_;
    const std::shared_ptr<Expression>& b_;

public:
    Summ(const std::shared_ptr<Expression>& a,
         const std::shared_ptr<Expression>& b): a_(a), b_(b) {}

    int Evaluate() const {
        auto b = dynamic_cast<const std::shared_ptr<Constant>>(a_);
        return a_->Evaluate() + b_->Evaluate();
    }
};

template <class T, class Y>
class Multiplication: public Expression {
private:
    const std::shared_ptr<Expression>& a_;
    const std::shared_ptr<Expression>& b_;

public:
    Multiplication(const std::shared_ptr<Expression>& a,
                   const std::shared_ptr<Expression>& b): a_(a), b_(b) {}

    int Evaluate() const {
        return a_->Evaluate() * b_->Evaluate();
    }
};

std::shared_ptr<Constant> Const(const int& a) {
    return std::make_shared<Constant>(a);
}

template <class T, class Y>
std::shared_ptr<Multiplication<T, Y>> Product (const T& a, const Y& b) {
    return std::make_shared<Multiplication<T, Y>>(a, b);
}

template <class T, class Y>
std::shared_ptr<Summ<T, Y>> Sum (const T& a, const Y& b) {
    return std::make_shared<Summ<T, Y>>(a, b);
}


int main() {
    ExpressionPtr ex1 = Sum(Product(Const(3), Const(4)), Const(5));
    //std::cout << ex1->ToString() << "\n";  // 3 * 4 + 5
    std::cout << ex1->Evaluate() << "\n";  // 17

    ExpressionPtr ex2 = Product(Const(6), ex1);
    //std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4 + 5)
    //std::cout << ex2->Evaluate() << "\n";  // 102
}