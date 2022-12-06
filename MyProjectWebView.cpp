//********************************************************
/// @brief 
/// @author y974183789@gmail.com
/// @date 2022/12/2
/// @note
/// @version 1.0.0
//********************************************************

#include "MyProjectWebView.h"
#include "MyProjectJsProtocol.h"
#include <QWebEngineProfile>
#include <QWebChannel>
#include<QTimer>

MyProjectWebView::MyProjectWebView(QWidget* parent)
: QWebEngineView(parent) {
    auto jsProtocol = new MyProjectJsProtocol(this);
    connect(jsProtocol, &MyProjectJsProtocol::projectDownloaded, this, &MyProjectWebView::projectDownloaded);

    QWebEnginePage *pWebPage = new QWebEnginePage(this);
    setPage(pWebPage);
    QWebChannel *pWebChannel = new QWebChannel(this);
    pWebChannel->registerObject("myProjectInterface", jsProtocol);
    pWebPage->setWebChannel(pWebChannel);
    QTimer::singleShot(5000, this, [pWebPage](){
        //发送消息到js
        pWebPage->runJavaScript(QString("recvMessageFromQt('%1');").arg("hello js, i am Qter"));
    });

    setContextMenuPolicy(Qt::NoContextMenu);
}

MyProjectWebView::~MyProjectWebView() {
}
