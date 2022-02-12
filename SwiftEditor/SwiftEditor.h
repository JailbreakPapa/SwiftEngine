#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SwiftEditor.h"

class SwiftEditor : public QMainWindow
{
    Q_OBJECT

public:
    SwiftEditor(QWidget *parent = Q_NULLPTR);

private:
    Ui::SwiftEditorClass ui;
};
