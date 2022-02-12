#include "node.h"
#include <memory>

Node::Node() {}


LogicalOperationNode::LogicalOperationNode(LogicalOperation l_, std::shared_ptr<Node> left_, std::shared_ptr<Node> right_):
    Node(), log_oper(l_), left(left_), right(right_) {}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const {
    switch (log_oper) {
        case LogicalOperation::Or:
            return left->Evaluate(date, event) || right->Evaluate(date, event);
        case LogicalOperation::And:
            return left->Evaluate(date, event) && right->Evaluate(date, event);
        default:
            return 0;
    }
}

EmptyNode::EmptyNode(): Node() {}

bool EmptyNode::Evaluate(const Date& date, const std::string& event) const {
    return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp_, Date data_):
    Node(), cmp(cmp_), data(data_) {}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const {
    switch(cmp) {
        case Comparison::Less:
            return data > date;
        case Comparison::LessOrEqual:
            return data >= date;
        case Comparison::Greater:
            return data < date;
        case Comparison::GreaterOrEqual:
            return data <= date;
        case Comparison::Equal:
            return data == date;
        case Comparison::NotEqual:
            return data != date;
        default:
            return false;
    }
}

EventComparisonNode::EventComparisonNode(Comparison cmp_, const std::string value_):
    Node(), cmp(cmp_), value(value_) {}

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const {
    switch(cmp) {
        case Comparison::Less:
            return value > event;
        case Comparison::LessOrEqual:
            return value >= event;
        case Comparison::Greater:
            return value < event;
        case Comparison::GreaterOrEqual:
            return value <= event;
        case Comparison::Equal:
            return value == event;
        case Comparison::NotEqual:
            return value != event;
        default:
            return false;
    }
}