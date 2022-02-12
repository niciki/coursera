#pragma once

#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>
#include "date.h"

enum class LogicalOperation {
    Or,
    And,
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

class Node {
public:
    Node();
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class LogicalOperationNode: public Node {
public:
    LogicalOperationNode(LogicalOperation l_, std::shared_ptr<Node> left_, std::shared_ptr<Node> right_);
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    LogicalOperation log_oper;
    std::shared_ptr<Node> left, right;
};

class EmptyNode: public Node {
public:
    EmptyNode();
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode: public Node {
public:
    DateComparisonNode(Comparison cmp_, Date data_);
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    Comparison cmp;
    Date data;
};

class EventComparisonNode: public Node {
public:
    EventComparisonNode(Comparison cmp_, const std::string value_);
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    Comparison cmp;
    const std::string value;
};

#endif
