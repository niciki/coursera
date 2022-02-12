#pragma once

#ifndef CONDITION_PARSER_H
#define CONDITION_PARSER_H

#include "node.h"

#include <memory>
#include <iostream>

std::shared_ptr<Node> ParseCondition(std::istream& is);

void TestParseCondition();

#endif


// Compile error: Error while compiling unit-tests for contents of file  date.h. Details: