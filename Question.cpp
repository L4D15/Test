#include "Question.h"

Question::Question() :
    description("No description"),
    options()
{
    this->response = 0;
}

Question::Question(const Question &other) :
    description(other.description),
    options(other.options)
{
    this->response = other.response;
}

Question::Question(std::string description, std::vector<std::string> &options, unsigned int response) :
    description(description),
    options(options)
{
    this->response = response;
}

Question::~Question()
{
    this->options.clear();
}
