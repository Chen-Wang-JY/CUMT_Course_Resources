#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPushButton>
#include <QMdiSubWindow>
#include <QFontComboBox>
#include <QComboBox>
#include <QMdiArea>
#include <QString>
#include <QDebug>
#include <QColor>
#include <QColorDialog>
#include <QFontDialog>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>
#include <QRadioButton>
#include "Childwindow.h"
#include "About.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private:
    QMdiArea* mdiArea;

    //是否加粗、斜体、下划线
    bool isBold=true;
    bool isItalic=true;
    bool isUnderline=true;

private:
    //当前活跃窗口
    ChildWindow* activeChildWindow();
    //新建文件
    ChildWindow* createChildWindow();
                    //void enabledText();
    //打开文件
    QMdiSubWindow* findChildWindow(const QString& fileName);

    About ab;


private:
    QLineEdit *findLineEdit;
    QLineEdit *replaceLineEdit;
    QDialog *findDlg;

    QButtonGroup *qbtg1;
    QButtonGroup *qbtg2;
    QButtonGroup *qbtg3;

    bool findstr=false;
    bool replacestr=false;

    void CreateFindReplace();

private slots:
    //文件
    void action_newFile_triggered();
    void action_open_triggered();
    void action_save_triggered();
    void action_saveAnother_triggered();
    void action_close_triggered();
    void action_print_triggered();
    void action_printpreview_triggered();

    //编辑
    void action_undo_triggered();
    void action_redo_triggered();
    void action_cut_triggered();
    void action_paste_triggered();
    void action_copy_triggered();
    void action_find_triggered();
    void action_font_triggered();

    //窗口
    void action_closed_triggered();
    void action_closeAll_triggered();
    void action_windowLayer_triggered();
    void action_tileHorizontal_triggered();

    //格式
    void action_bold_triggered();
    void action_italic_triggered();
    void action_underline_triggered();
    void action_left_triggered();
    void action_mid_triggered();
    void action_right_triggered();
    void action_color_triggered();

    //关于
    void action_about_triggered();

    //查找替换窗体
    void showFindText();
    void replaceText();
};

#endif // MAINWINDOW_H
