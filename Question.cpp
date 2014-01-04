#include "Question.h"

Question::Question() :
    description("No description"),
    options()
{
    this->solution = 0;
}

Question::Question(const Question &other) :
    description(other.description),
    options(other.options)
{
    this->solution = other.solution;
}

Question::Question(std::string description, std::vector<std::string> &options, unsigned int response) :
    description(description),
    options(options)
{
    this->solution = response;
}

Question::~Question()
{
    this->options.clear();
}
