//********************************************************
/// @brief 
/// @author y974183789@gmail.com
/// @date 2022/12/2
/// @note
/// @version 1.0.0
//********************************************************

#include "MyProjectJsProtocol.h"
#include <QDebug>
#include <QMessageBox>

MyProjectJsProtocol::MyProjectJsProtocol(QObject* parent)
: QObject(parent) {

}

MyProjectJsProtocol::~MyProjectJsProtocol() {
}

void MyProjectJsProtocol::onProjectDownloaded(const QString& json) {
    qDebug() << json;
    QMessageBox::information(nullptr, "js Message", json);
    Q_EMIT projectDownloaded(json);
}
