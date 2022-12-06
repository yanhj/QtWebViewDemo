//********************************************************
/// @brief 
/// @author y974183789@gmail.com
/// @date 2022/12/2
/// @note
/// @version 1.0.0
//********************************************************

#include "MyProjectWidget.h"
#include "ui_MyProjectWidget.h"
#include <QtCore/QSysInfo>
#include <QtCore/qglobal.h>
#include <QtNetwork/QHostInfo>
#include "MyProjectWebView.h"

MyProjectWidget::MyProjectWidget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::MyProjectWidget) {
    ui->setupUi(this);

    m_pWebView = new MyProjectWebView(this);
    m_pWebView->setUrl(QStringLiteral("qrc:/index_copy.html"));
    ui->vLayMain->addWidget(m_pWebView);
    connect(m_pWebView, &QWebEngineView::loadFinished, [=] {
        QHostInfo hostInfo = QHostInfo::fromName(QString("mcp.meitu.com"));
        if (hostInfo.addresses().isEmpty())
        {
        }
    });
}

MyProjectWidget::~MyProjectWidget() {
    delete ui;
}

void MyProjectWidget::onProjectDownloaded(const QString& json) {
    //TODO: 解析json
}
