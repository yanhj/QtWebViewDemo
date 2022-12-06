//********************************************************
/// @brief 
/// @author y974183789@gmail.com
/// @date 2022/12/2
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtWebEngineWidgets/QWebEngineView>

class MyProjectWebView : public QWebEngineView {
    Q_OBJECT

public:
    explicit MyProjectWebView(QWidget* parent = Q_NULLPTR);
    ~MyProjectWebView();

Q_SIGNALS:
    void projectDownloaded(const QString& json);
};
