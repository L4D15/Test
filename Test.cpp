#include "Test.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

Test::Test(QString &filePath)
{
    QFile jsonFile;

    jsonFile.setFileName(filePath);
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QString jsonText;

    jsonText = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument jsonDocument;

    jsonDocument.fromJson(jsonText.toUtf8());

    QJsonArray jsonQuestions;

    jsonQuestions = jsonDocument.object()["questions"].toArray();

    Question* question;
    for (int index = 0; index < jsonQuestions.size(); ++index)
    {
        std::string description;
        std::vector<std::string> options;
        int solution;

        description = jsonQuestions[index].toObject()["description"].toString().toStdString();
        solution = jsonQuestions[index].toObject()["solution"].toInt();

        QJsonArray optionsArray;

        optionsArray = jsonQuestions[index].toObject()["options"].toArray();

        for (int optionsIndex = 0; optionsIndex < optionsArray.size(); ++optionsIndex)
        {
            std::string option;

            option = optionsArray[optionsIndex].toString().toStdString();
            options.push_back(option);
        }

        question = new Question(description, options, solution);
        this->questions.push_back(*question);

        delete question;
    }
}
