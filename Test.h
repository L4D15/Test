#ifndef TEST_H
#define TEST_H

#include <QString>
#include <QVector>
#include "Question.h"

class Test
{
public:
    Test(QString& filePath);

public:
    QVector<Question> questions;
};

#endif // TEST_H
