//********************************************************
/// @brief 
/// @author y974183789@gmail.com
/// @date 2022/12/2
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtCore/QObject>

class MyProjectJsProtocol : public QObject {
    Q_OBJECT

public:
    MyProjectJsProtocol(QObject* parent = nullptr);
    ~MyProjectJsProtocol() override;

Q_SIGNALS:
    void projectDownloaded(const QString& json);

public Q_SLOTS:
    void onProjectDownloaded(const QString& json);
};
