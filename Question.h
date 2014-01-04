#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question
{    
public:
    Question();
    Question(std::string description, std::vector<std::string>& options, unsigned int solution);
    Question(const Question& other);
    ~Question();

    inline bool isCorrect(unsigned int index) { return index == solution; }

public:
    std::string description;
    std::vector<std::string> options;
    unsigned int solution;
};

#endif // QUESTION_H
