#include "Mainwindow.h"
#include "ui_Mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);//恰当时机出现滚滚动条
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->setCentralWidget(mdiArea);

    this->setWindowTitle("富文本编辑器");
    this->setWindowIcon(QIcon(":/icon/Begin.png"));

    this->CreateFindReplace();


    connect(ui->action_newFile,&QAction::triggered,this,&MainWindow::action_newFile_triggered);
    connect(ui->action_open,&QAction::triggered,this,&MainWindow::action_open_triggered);
    connect(ui->action_save,&QAction::triggered,this,&MainWindow::action_save_triggered);
    connect(ui->action_saveAnother,&QAction::triggered,this,&MainWindow::action_saveAnother_triggered);
    connect(ui->action_close,&QAction::triggered,this,&MainWindow::action_close_triggered);
    connect(ui->action_print,&QAction::triggered,this,&MainWindow::action_print_triggered);
    connect(ui->action_printpreview,&QAction::triggered,this,&MainWindow::action_printpreview_triggered);

    connect(ui->action_redo,&QAction::triggered,this,&MainWindow::action_redo_triggered);
    connect(ui->action_undo,&QAction::triggered,this,&MainWindow::action_undo_triggered);
    connect(ui->action_cut,&QAction::triggered,this,&MainWindow::action_cut_triggered);
    connect(ui->action_copy,&QAction::triggered,this,&MainWindow::action_copy_triggered);
    connect(ui->action_paste,&QAction::triggered,this,&MainWindow::action_paste_triggered);
    connect(ui->action_find,&QAction::triggered,this,&MainWindow::action_find_triggered);
    connect(ui->action_font,&QAction::triggered,this,&MainWindow::action_font_triggered);

    connect(ui->action_closed,&QAction::triggered,this,&MainWindow::action_closed_triggered);
    connect(ui->action_closeAll,&QAction::triggered,this,&MainWindow::action_closeAll_triggered);
    connect(ui->action_tileHorizontal,&QAction::triggered,this,&MainWindow::action_tileHorizontal_triggered);
    connect(ui->action_windowLayer,&QAction::triggered,this,&MainWindow::action_windowLayer_triggered);

    connect(ui->action_bold,&QAction::triggered,this,&MainWindow::action_bold_triggered);
    connect(ui->action_underline,&QAction::triggered,this,&MainWindow::action_underline_triggered);
    connect(ui->action_italic,&QAction::triggered,this,&MainWindow::action_italic_triggered);
    connect(ui->action_left,&QAction::triggered,this,&MainWindow::action_left_triggered);
    connect(ui->action_mid,&QAction::triggered,this,&MainWindow::action_mid_triggered);
    connect(ui->action_right,&QAction::triggered,this,&MainWindow::action_right_triggered);
    connect(ui->action_color,&QAction::triggered,this,&MainWindow::action_color_triggered);

    connect(ui->action_about,&QAction::triggered,this,&MainWindow::action_about_triggered);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::CreateFindReplace(){
    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("查找&替换"));

    findLineEdit = new QLineEdit(findDlg);
    replaceLineEdit = new QLineEdit(findDlg);
    QPushButton *btn= new QPushButton(tr("查找下一个"), findDlg);
    QPushButton *btn2= new QPushButton(tr("替换"), findDlg);

    QVBoxLayout *layout= new QVBoxLayout(findDlg);
    QHBoxLayout *cldlayout0=new QHBoxLayout();
    QHBoxLayout *cldlayout1=new QHBoxLayout();
    QHBoxLayout *cldlayout2=new QHBoxLayout();
    qbtg1 = new QButtonGroup(this);
    qbtg2 = new QButtonGroup(this);
    qbtg3 = new QButtonGroup(this);

    QRadioButton *Button01 = new QRadioButton(this);
    Button01->setText(tr("非大小写匹配"));
    cldlayout0->addWidget(Button01);
    QRadioButton *Button02 = new QRadioButton(this);
    Button02->setText(tr("大小写匹配"));
    cldlayout0->addWidget(Button02);

    qbtg1->addButton(Button01);
    qbtg1->addButton(Button02);
    qbtg1->setId(Button01, 0);
    qbtg1->setId(Button02, 1);
    Button01->setChecked(true);

    QRadioButton *Button11 = new QRadioButton(this);
    Button11->setText(tr("单字匹配"));
    cldlayout1->addWidget(Button11);
    QRadioButton *Button12 = new QRadioButton(this);
    Button12->setText(tr("全字匹配"));
    cldlayout1->addWidget(Button12);

    qbtg2->addButton(Button11);
    qbtg2->addButton(Button12);
    qbtg2->setId(Button11, 0);
    qbtg2->setId(Button12, 1);
    Button11->setChecked(true);

    QRadioButton *Button21 = new QRadioButton(this);
    Button21->setText(tr("单个替换"));
    cldlayout2->addWidget(Button21);
    QRadioButton *Button22 = new QRadioButton(this);
    Button22->setText(tr("全部替换"));
    cldlayout2->addWidget(Button22);

    qbtg3->addButton(Button21);
    qbtg3->addButton(Button22);
    qbtg3->setId(Button21, 0);
    qbtg3->setId(Button22, 1);
    Button21->setChecked(true);

    layout->addLayout(cldlayout0);
    layout->addLayout(cldlayout1);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    layout->addLayout(cldlayout2);
    layout->addWidget(replaceLineEdit);
    layout->addWidget(btn2);

    connect(btn, SIGNAL(clicked()), this, SLOT(showFindText()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(replaceText()));
}
ChildWindow *MainWindow::createChildWindow()
{
    ChildWindow *child=new ChildWindow;
    mdiArea->addSubWindow(child);
    return child;
}
QMdiSubWindow *MainWindow::findChildWindow(const QString &fileName)
{
    //得到规范路径
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach (QMdiSubWindow *window, mdiArea->subWindowList()) {
        ChildWindow *childWindow = qobject_cast<ChildWindow *>(window->widget());//将该widget强转为Childwindow*
        if (childWindow->currentFile() == canonicalFilePath)
            return window;
    }
    return nullptr;
}

ChildWindow* MainWindow::activeChildWindow(){
    //如果当前存在活跃窗口，将其类型强转为ChhildWindow
    if(QMdiSubWindow* activeSubWindow=mdiArea->activeSubWindow())
        return qobject_cast<ChildWindow*>(activeSubWindow->widget());
    return nullptr;
}
/*—————————————————————————————————————————————————————槽函数——————————————————————————————————————————————*/


/*——————————————————————————————————————————————————————文件————————————————————————————————————————————————*/
void MainWindow::action_newFile_triggered(){
    //加入到mdiarea中
    ChildWindow* child=createChildWindow();
    //新建文件
    child->newFile();
    child->show();
}
void MainWindow::action_open_triggered(){
    QString fileName = QFileDialog::getOpenFileName(this,"打开",QString(),tr("HTML 文档 (*.htm *.html);;所有文件 (*.*)"));
    if(!fileName.isEmpty()){
        //如果该文件已经打开，则将其设置为活跃窗口
        QMdiSubWindow* existing=findChildWindow(fileName);
        if(existing){
            mdiArea->setActiveSubWindow(existing);
            QMessageBox::about(this," ","该窗口已经打开");
            return;
        }
        //否则，创建新的子窗体来显示该文件内容
        ChildWindow* child = createChildWindow();//显示窗口
        if(child->loadFile(fileName)){           //载入文件
            statusBar()->showMessage("文件已载入",2000);
            child->show();
        }
        else
            child->close();
    }
}
void MainWindow::action_save_triggered(){
    if(activeChildWindow()&&activeChildWindow()->save())
        statusBar()->showMessage(tr("保存成功"),2000);
}
void MainWindow::action_saveAnother_triggered(){
    if(activeChildWindow()&&activeChildWindow()->saveAnother())
        statusBar()->showMessage(tr("保存成功"),2000);
}
void MainWindow::action_close_triggered(){
    this->close();
}
void MainWindow::action_print_triggered(){
    QMessageBox::about(this," ","功能开发中，敬请期待");
}
void MainWindow::action_printpreview_triggered(){
    QMessageBox::about(this," ","功能开发中，敬请期待");
}


/*——————————————————————————————————————————————————————编辑————————————————————————————————————————————————*/
void MainWindow::action_undo_triggered(){
    //如果没有活跃窗口，什么都不发生
    if(activeChildWindow())
        activeChildWindow()->undo();
}
void MainWindow::action_redo_triggered(){
    if(activeChildWindow())
        activeChildWindow()->redo();
}
void MainWindow::action_cut_triggered(){
    if(activeChildWindow())
        activeChildWindow()->cut();
}
void MainWindow::action_paste_triggered(){
    if(activeChildWindow())
        activeChildWindow()->paste();
}
void MainWindow::action_copy_triggered(){
    if(activeChildWindow())
        activeChildWindow()->copy();
}
void MainWindow::action_find_triggered(){
    activeChildWindow()->moveCursor(QTextCursor::Start);
    findstr=false;
    replacestr=false;
    findDlg->show();
}
void MainWindow::action_font_triggered(){
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok&&activeChildWindow()){
        QTextCharFormat fmt;
        fmt.setFont(font);
        activeChildWindow()->fontFormat(fmt);
    }
}

/*——————————————————————————————————————————————————————窗口————————————————————————————————————————————————*/
void MainWindow::action_closed_triggered(){
    mdiArea->closeActiveSubWindow();
}
void MainWindow::action_closeAll_triggered(){
    mdiArea->closeAllSubWindows();
}
void MainWindow::action_windowLayer_triggered(){
    mdiArea->cascadeSubWindows();
}
void MainWindow::action_tileHorizontal_triggered(){
    mdiArea->tileSubWindows();
}

/*——————————————————————————————————————————————————————格式————————————————————————————————————————————————*/
void MainWindow::action_bold_triggered(){
    QTextCharFormat fmt;
    fmt.setFontWeight(isBold?QFont::Bold:QFont::Normal);
    isBold=isBold?false:true;
    if(activeChildWindow())
        activeChildWindow()->fontFormat(fmt);
}
void MainWindow::action_italic_triggered(){
    QTextCharFormat fmt;
    fmt.setFontItalic(isItalic);
    isItalic=isItalic?false:true;
    if(activeChildWindow())
        activeChildWindow()->fontFormat(fmt);
}
void MainWindow::action_underline_triggered(){
    QTextCharFormat fmt;
    fmt.setFontUnderline(isUnderline);
    isUnderline=isUnderline?false:true;
    if(activeChildWindow())
        activeChildWindow()->fontFormat(fmt);
}
void MainWindow::action_left_triggered(){
    if(activeChildWindow())
        activeChildWindow()->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
}
void MainWindow::action_mid_triggered(){
    if(activeChildWindow())
        activeChildWindow()->setAlignment(Qt::AlignHCenter);
}
void MainWindow::action_right_triggered(){
    if(activeChildWindow())
        activeChildWindow()->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
}
void MainWindow::action_color_triggered(){
    if(activeChildWindow()){
        QColor color=QColorDialog::getColor(activeChildWindow()->textColor(),this);
        if(!color.isValid())
            return;
        QTextCharFormat fmt;
        fmt.setForeground(color);
        activeChildWindow()->fontFormat(fmt);
    }
}

/*——————————————————————————————————————————————————————关于————————————————————————————————————————————————*/
void MainWindow::action_about_triggered(){
    ab.show();
}

/*——————————————————————————————————————————————————————查找替换———————————————————————————————————————————————*/


void MainWindow::showFindText()
{
    if(!findstr)
    {
        activeChildWindow()->moveCursor(QTextCursor::Start);
        findstr=true;
    }
    int a = qbtg1->checkedId();
    int b = qbtg2->checkedId();
    QString str = findLineEdit->text();
    if(activeChildWindow())
        {
        switch (a)
        {
        case 0:
        {
            switch (b)
            {
            case 0:
            {
                qDebug()<<"00";
                if (!activeChildWindow()->find(str))
                {
                   QMessageBox::warning(this, tr("查找"),
                            tr("找不到  %1").arg(str));
                }
                break;
            }
            case 1:
            {
                qDebug()<<"01";
                if (!activeChildWindow()->find(str,QTextDocument::FindWholeWords))
                {
                   QMessageBox::warning(this, tr("查找"),
                            tr("找不到  %1").arg(str));
                }
                break;
            }
            }
            break;
        }
        case 1:
            {
                switch (b)
                {
                case 0:
                {
                    qDebug()<<"10";
                    if (!activeChildWindow()->find(str,QTextDocument::FindCaseSensitively))
                    {
                       QMessageBox::warning(this, tr("查找"),
                                tr("找不到  %1").arg(str));
                    }
                    break;
                }
                case 1:
                {
                    qDebug()<<"11";
                    if (!activeChildWindow()->find(str,QTextDocument::FindCaseSensitively|QTextDocument::FindWholeWords))
                    {
                       QMessageBox::warning(this, tr("查找"),
                                tr("找不到  %1").arg(str));
                    }
                    break;
                }
                }
             break;
            }
        }

        }
}

void MainWindow::replaceText()
{
    if(!replacestr)
    {
        activeChildWindow()->moveCursor(QTextCursor::Start);
        replacestr=true;
    }
    int c = qbtg3->checkedId();
    QString str = findLineEdit->text();
    QString str2=replaceLineEdit->text();

    if(activeChildWindow())
        {
        switch (c) {
        case 0:
        {
            if (!activeChildWindow()->find(str))
            {
               QMessageBox::warning(this, tr("替换"),
                        tr("不存在  %1").arg(str));
            }
            else
            {
                activeChildWindow()->moveCursor(QTextCursor::WordLeft);
                activeChildWindow()->insertPlainText(str2);
            }
            break;
        }
        case 1:
        {
            while(activeChildWindow()->find(str))
                activeChildWindow()->insertPlainText(str2);
            break;
        }
        }
    }
}
