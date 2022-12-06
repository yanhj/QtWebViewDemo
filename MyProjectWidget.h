//********************************************************
/// @brief 
/// @author y974183789@gmail.com
/// @date 2022/12/2
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtWidgets/QWidget>
#include "MyProjectWebView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyProjectWidget; }
QT_END_NAMESPACE

class MyProjectWebView;

class MyProjectWidget : public QWidget {
    Q_OBJECT

public:
    explicit MyProjectWidget(QWidget *parent = nullptr);
    ~MyProjectWidget() override;

public Q_SLOTS:
    void onProjectDownloaded(const QString& json);

private:
    Ui::MyProjectWidget *ui;
    MyProjectWebView* m_pWebView;
};
