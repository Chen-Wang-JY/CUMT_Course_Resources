#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "Form_add.h"
#include "ui_Form_add.h"
#include "Form_search.h"
#include "ui_Form_search.h"
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //登录
    IsAdmin=false;



    //“添加/编辑联系人“按钮信号与槽函数的连接
    connect(ui->action_add,SIGNAL(triggered()),this,SLOT(Add()));
    connect(formAdd.ui->Button_confirm,SIGNAL(clicked()),this,SLOT(Button_confirm_clicked()));
    connect(ui->action_edit,&QAction::triggered,this,&MainWindow::Edit);
    //“删除联系人”信号与槽函数连接
    connect(ui->action_delete,&QAction::triggered,this,&MainWindow::Delete);
    //“查找联系人”信号与槽函数连接
    connect(ui->action_search,&QAction::triggered,this,&MainWindow::Search);
    connect(formSearch.ui->Button_Search,&QPushButton::clicked,this,&MainWindow::Button_Search_clicked);
    //“备份”信号与槽函数连接
    connect(ui->action_backup,&QAction::triggered,this,&MainWindow::Back_up);
    //“恢复”信号与槽函数连接
    connect(ui->action_recovery,&QAction::triggered,this,&MainWindow::Recovery);
    //点击TreeView 信号与槽函数连接
    connect(ui->treeView,&QTreeView::clicked,this,&MainWindow::Sorts);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//连接数据库
void MainWindow::connectMySQL(){
    DB=QSqlDatabase::addDatabase("QMYSQL","myContractssql");
    DB.setHostName("localhost");
    DB.setPort(3306);
    DB.setUserName("root");
    DB.setPassword("y25557656755723");
    if(!DB.open()){
        qDebug()<<"连接失败:"<<DB.lastError().text();
        return;
    }
    else {
        qDebug()<<"连接成功！";
    }

}

//刷新操作
void MainWindow::refresh(){
    QSqlQuery query(DB);

    QString ID,Name,Sex,Age,Tell,Address,QQNum,Major;
    query.exec("select * from myContracts.student");

    int i=0;
    while(query.next()){
        ID=query.value(0).toString();
        Name=query.value(1).toString();
        Sex=query.value(2).toString();
        Age=query.value(3).toString();
        Tell=query.value(4).toString();
        Address=query.value(5).toString();
        QQNum=query.value(6).toString();
        Major=query.value(7).toString();

        //树形图，获取当前所有专业
        bool flag=true;
        for(int i=0;i<major.length();i++)
            if(major[i]==Major){
               flag=false;
               break;
            }
        if(flag)
            major.append(Major);


        ui->Table_Student->setItem(i,0,new QTableWidgetItem(ID));
        ui->Table_Student->setItem(i,1,new QTableWidgetItem(Name));
        ui->Table_Student->setItem(i,2,new QTableWidgetItem(Sex));
        ui->Table_Student->setItem(i,3,new QTableWidgetItem(Age));
        ui->Table_Student->setItem(i,4,new QTableWidgetItem(Tell));
        ui->Table_Student->setItem(i,5,new QTableWidgetItem(Address));
        ui->Table_Student->setItem(i,6,new QTableWidgetItem(QQNum));
        ui->Table_Student->setItem(i,7,new QTableWidgetItem(Major));
        i++;
        ui->Table_Student->insertRow(i);
    }
}
void MainWindow::Refresh(){
    QSqlQuery query(DB);
    QString ID,Name,Sex,Age,Tell,Address,QQNum,Major;
    query.exec("select * from myContracts.student");

    int i=0;
    major.clear();
    while(query.next()){
        ID=query.value(0).toString();
        Name=query.value(1).toString();
        Sex=query.value(2).toString();
        Age=query.value(3).toString();
        Tell=query.value(4).toString();
        Address=query.value(5).toString();
        QQNum=query.value(6).toString();
        Major=query.value(7).toString();

        ui->Table_Student->setItem(i,0,new QTableWidgetItem(ID));
        ui->Table_Student->setItem(i,1,new QTableWidgetItem(Name));
        ui->Table_Student->setItem(i,2,new QTableWidgetItem(Sex));
        ui->Table_Student->setItem(i,3,new QTableWidgetItem(Age));
        ui->Table_Student->setItem(i,4,new QTableWidgetItem(Tell));
        ui->Table_Student->setItem(i,5,new QTableWidgetItem(Address));
        ui->Table_Student->setItem(i,6,new QTableWidgetItem(QQNum));
        ui->Table_Student->setItem(i,7,new QTableWidgetItem(Major));
        i++;

        //树形图，获取当前所有专业
        bool flag=true;
        for(int i=0;i<major.length();i++)
            if(major[i]==Major){
               flag=false;
               break;
            }
        if(flag)
            major.append(Major);
    }

    Load();
}

//“添加/编辑 联系人”的两个槽函数
void MainWindow::Add(){
    //当前是否是管理员
    if(!IsAdmin){
        QMessageBox::warning(this,"警告","您没有权限！");
        return;
    }

    formAdd.ui->Edit_Name->clear();
    formAdd.ui->Edit_Age->clear();
    formAdd.ui->Edit_ID->clear();
    formAdd.ui->Edit_Tell->clear();
    formAdd.ui->Edit_Major->clear();
    formAdd.ui->Edit_QQNum->clear();
    formAdd.ui->Edit_Address->clear();
    flag=1;
    formAdd.ui->laber_TEXT->setText("添加联系人：");
    formAdd.setWindowTitle("添加联系人");
    formAdd.show();
}
void MainWindow::Edit(){
    //当前是否是管理员
    if(!IsAdmin){
        QMessageBox::warning(this,"警告","您没有权限！");
        return;
    }

    flag=0;
    formAdd.ui->laber_TEXT->setText("编辑联系人：");
    formAdd.setWindowTitle("编辑联系人");
    //若当前没有行被选中，或者选中了空行，直接return
    if(ui->Table_Student->currentRow()==-1||!ui->Table_Student->currentItem())
        return;


    //将选中行的联系人信息打印到编辑表中
    QString ID,Name,Sex,Age,Tell,Address,QQNum,Major;
    ID=ui->Table_Student->item(ui->Table_Student->currentRow(),0)->text();
    Name=ui->Table_Student->item(ui->Table_Student->currentRow(),1)->text();
    Sex=ui->Table_Student->item(ui->Table_Student->currentRow(),2)->text();
    Age=ui->Table_Student->item(ui->Table_Student->currentRow(),3)->text();
    Tell=ui->Table_Student->item(ui->Table_Student->currentRow(),4)->text();
    Address=ui->Table_Student->item(ui->Table_Student->currentRow(),5)->text();
    QQNum=ui->Table_Student->item(ui->Table_Student->currentRow(),6)->text();
    Major=ui->Table_Student->item(ui->Table_Student->currentRow(),7)->text();

    ID0=ID;

    formAdd.ui->Edit_ID->setText(ID);
    formAdd.ui->Edit_Name->setText(Name);
    if(Sex=="男")
        formAdd.ui->Rbutton_Man->setChecked(true);
    else if(Sex=="女")
        formAdd.ui->RButton_Womon->setChecked(true);
    formAdd.ui->Edit_Age->setText(Age);
    formAdd.ui->Edit_Tell->setText(Tell);
    formAdd.ui->Edit_Address->setText(Address);
    formAdd.ui->Edit_QQNum->setText(QQNum);
    formAdd.ui->Edit_Major->setText(Major);
    formAdd.show();
}
void MainWindow::Button_confirm_clicked(){
    //flag=1，添加联系人
    if(flag==1){

        QString ID,Name,Sex,Age,Tell,Address,QQNum,Major;
        ID=formAdd.ui->Edit_ID->text();
        Name=formAdd.ui->Edit_Name->text();
        Age=formAdd.ui->Edit_Age->text();
        Tell=formAdd.ui->Edit_Tell->text();
        Address=formAdd.ui->Edit_Address->text();
        QQNum=formAdd.ui->Edit_QQNum->text();
        Major=formAdd.ui->Edit_Major->text();
        if(formAdd.ui->Rbutton_Man->isChecked())
            Sex="男";
        else if(formAdd.ui->RButton_Womon->isChecked())
            Sex="女";

        if(ID.length()!=8){
            QMessageBox::warning(&formAdd," ","非法学号！");
            return;
        }
        if(Tell.length()!=11&&Tell.length()!=0){
            QMessageBox::warning(&formAdd," ","非法手机号码！");
            return;
        }


        QSqlQuery query(DB);
        query.prepare("insert into mycontracts.student values(?,?,?,?,?,?,?,?)");
        query.bindValue(0,ID);
        query.bindValue(1,Name);
        query.bindValue(2,Sex);
        query.bindValue(3,Age);
        query.bindValue(4,Tell);
        query.bindValue(5,Address);
        query.bindValue(6,QQNum);
        query.bindValue(7,Major);
        query.exec();

        QString error;
        error=query.lastError().type();
        if(error=="\u0002"){
            QMessageBox::warning(&formAdd," ","学号已存在！");
            return;
        }
        else{
            QMessageBox::about(&formAdd," ","添加联系人成功!");
            Refresh();
            ui->Table_Student->insertRow(ui->Table_Student->rowCount());

            formAdd.close();
            formAdd.ui->Edit_ID->clear();
            formAdd.ui->Edit_Name->clear();
            formAdd.ui->Rbutton_Man->setChecked(1);
            formAdd.ui->Edit_Age->clear();
            formAdd.ui->Edit_Tell->clear();
            formAdd.ui->Edit_Address->clear();
            formAdd.ui->Edit_QQNum->clear();
            formAdd.ui->Edit_Major->clear();
        }
    }
    //flag=0，编辑联系人
    else if(flag==0){
        //获取当前编辑栏中的内容
        QString ID,Name,Sex,Age,Tell,Address,QQNum,Major;
        ID=formAdd.ui->Edit_ID->text();
        Name=formAdd.ui->Edit_Name->text();
        Age=formAdd.ui->Edit_Age->text();
        Tell=formAdd.ui->Edit_Tell->text();
        Address=formAdd.ui->Edit_Address->text();
        QQNum=formAdd.ui->Edit_QQNum->text();
        Major=formAdd.ui->Edit_Major->text();
        if(formAdd.ui->Rbutton_Man->isChecked())
            Sex="男";
        else if(formAdd.ui->RButton_Womon->isChecked())
            Sex="女";

        if(ID.length()!=8){
            QMessageBox::warning(&formAdd," ","非法学号！");
            return;
        }
        if(Tell.length()!=11&&Tell.length()!=0){
            QMessageBox::warning(&formAdd," ","非法手机号码！");
            return;
        }

        QSqlQuery query(DB);
        query.prepare("update mycontracts.student set Name = '"+Name+"' where ID = "+ID0);
        query.exec();
        query.prepare("update mycontracts.student set Age = '"+Age+"' where ID = "+ID0);
        query.exec();
        query.prepare("update mycontracts.student set Tell = '"+Tell+"' where ID = "+ID0);
        query.exec();
        query.prepare("update mycontracts.student set Address = '"+Address+"' where ID = "+ID0);
        query.exec();
        query.prepare("update mycontracts.student set QQNum = '"+QQNum+"' where ID = "+ID0);
        query.exec();
        query.prepare("update mycontracts.student set Major = '"+Major+"' where ID = "+ID0);
        query.exec();
        query.prepare("update mycontracts.student set Sex = '"+Sex+"' where ID = "+ID0);
        query.exec();
        query.prepare("update mycontracts.student set ID = '"+ID+"' where ID = "+ID0);
        query.exec();
        ui->Table_Student->clearContents();
        Refresh();

        ID0="";

        formAdd.close();
        formAdd.ui->Edit_ID->clear();
        formAdd.ui->Edit_Name->clear();
        formAdd.ui->Rbutton_Man->setChecked(1);
        formAdd.ui->Edit_Age->clear();
        formAdd.ui->Edit_Tell->clear();
        formAdd.ui->Edit_Address->clear();
        formAdd.ui->Edit_QQNum->clear();
        formAdd.ui->Edit_Major->clear();
        QMessageBox::about(this," ","修改成功！");
    }
}

//“删除联系人”的槽函数
void MainWindow::Delete(){
    //当前是否是管理员
    if(!IsAdmin){
        QMessageBox::warning(this,"警告","您没有权限！");
        return;
    }


    QSqlQuery query(DB);
    //如果当前没有选中任何一行，则直接return
    if(ui->Table_Student->currentRow()==-1)
        return;
    //如果当前选中空白行，则直接return
    if(!ui->Table_Student->currentItem())
        return;

    QString ID=ui->Table_Student->item(ui->Table_Student->currentRow(),0)->text();
    QString Name=ui->Table_Student->item(ui->Table_Student->currentRow(),1)->text();
    QMessageBox::StandardButton result=QMessageBox::question(this,"警告","您确定要删除 "+Name+" 吗?");
    //判断用户是否选择要进行删除
    switch(result){
    case QMessageBox::Yes:
        query.prepare("delete from mycontracts.Student where ID = ?");
        query.bindValue(0,ID);
        query.exec();
        QMessageBox::about(this," ","删除联系人成功！");
        ui->Table_Student->clearContents();
        Refresh();
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
    return;
}


//查找操作
void MainWindow::Search(){
    formSearch.show();
}
void MainWindow::Button_Search_clicked(){
    //查询前，清空表中内容并修改行数为1
    formSearch.ui->Table_Search->clearContents();
    formSearch.ui->Table_Search->setRowCount(1);

    QString ID,Name,Sex,Age,Tell,Address,QQNum,Major;
    QString Edit_Search=formSearch.ui->Edit_Search->text();
    Edit_Search="%"+Edit_Search+"%";
    QString Combobox_Search=formSearch.ui->Combobox_Search->currentText();
    QSqlQuery query(DB);
    //Edit_Search中无内容，则显示所有信息
    if(Combobox_Search==""){
        query.exec("select * from myContracts.student");

        int i=0;
        while(query.next()){
            ID=query.value(0).toString();
            Name=query.value(1).toString();
            Sex=query.value(2).toString();
            Age=query.value(3).toString();
            Tell=query.value(4).toString();
            Address=query.value(5).toString();
            QQNum=query.value(6).toString();
            Major=query.value(7).toString();

            formSearch.ui->Table_Search->setItem(i,0,new QTableWidgetItem(ID));
            formSearch.ui->Table_Search->setItem(i,1,new QTableWidgetItem(Name));
            formSearch.ui->Table_Search->setItem(i,2,new QTableWidgetItem(Sex));
            formSearch.ui->Table_Search->setItem(i,3,new QTableWidgetItem(Age));
            formSearch.ui->Table_Search->setItem(i,4,new QTableWidgetItem(Tell));
            formSearch.ui->Table_Search->setItem(i,5,new QTableWidgetItem(Address));
            formSearch.ui->Table_Search->setItem(i,6,new QTableWidgetItem(QQNum));
            formSearch.ui->Table_Search->setItem(i,7,new QTableWidgetItem(Major));
            i++;
            formSearch.ui->Table_Search->insertRow(i);
        }
    }
    else{
        if(Combobox_Search=="学号")
            Combobox_Search="ID";
        else if(Combobox_Search=="姓名")
            Combobox_Search="Name";
        else if(Combobox_Search=="年龄")
            Combobox_Search="Age";
        else if(Combobox_Search=="手机号码")
            Combobox_Search="Tell";
        else if(Combobox_Search=="家庭地址")
            Combobox_Search="Address";
        else if(Combobox_Search=="QQ号码")
            Combobox_Search="QQNum";
        else if(Combobox_Search=="专业")
            Combobox_Search="Major";
        else if(Combobox_Search=="性别")
            Combobox_Search="Sex";

        QString s="select * from mycontracts.student where "+Combobox_Search+" like '"+Edit_Search+"'";
        query.exec(s);

        int i=0;
        while(query.next()){
            ID=query.value(0).toString();
            Name=query.value(1).toString();
            Sex=query.value(2).toString();
            Age=query.value(3).toString();
            Tell=query.value(4).toString();
            Address=query.value(5).toString();
            QQNum=query.value(6).toString();
            Major=query.value(7).toString();

            formSearch.ui->Table_Search->setItem(i,0,new QTableWidgetItem(ID));
            formSearch.ui->Table_Search->setItem(i,1,new QTableWidgetItem(Name));
            formSearch.ui->Table_Search->setItem(i,2,new QTableWidgetItem(Sex));
            formSearch.ui->Table_Search->setItem(i,3,new QTableWidgetItem(Age));
            formSearch.ui->Table_Search->setItem(i,4,new QTableWidgetItem(Tell));
            formSearch.ui->Table_Search->setItem(i,5,new QTableWidgetItem(Address));
            formSearch.ui->Table_Search->setItem(i,6,new QTableWidgetItem(QQNum));
            formSearch.ui->Table_Search->setItem(i,7,new QTableWidgetItem(Major));

            i++;
            formSearch.ui->Table_Search->insertRow(i);
        }
    }
}


//备份与恢复
void MainWindow::Back_up(){
    //当前是否是管理员
    if(!IsAdmin){
        QMessageBox::warning(this,"警告","您没有权限！");
        return;
    }


    QString path=QFileDialog::getExistingDirectory(nullptr,"备份到",".");

    //用户点击关闭，则直接return
    if(path=="")
        return;

    path=path+"/Contracts.sql";
    QString Cmd="mysqldump -uroot -py25557656755723 mycontracts > "+path;
    qDebug()<<Cmd;
    QProcess p(this);
    p.start("cmd",QStringList()<<"/c"<<Cmd);
    p.waitForStarted();
    p.waitForFinished();
    QMessageBox::about(this," ","备份成功！");
}
void MainWindow::Recovery(){
    //当前是否是管理员
    if(!IsAdmin){
        QMessageBox::warning(this,"警告","您没有权限！");
        return;
    }


    QString path=QFileDialog::getOpenFileName(nullptr,"选择",".","*.sql");

    //用户点击关闭，则直接return
    if(path=="")
        return;

    QString Cmd="mysql -uroot -py25557656755723 mycontracts < "+path;
    QProcess p(this);
    p.start("cmd",QStringList()<<"/c"<<Cmd);
    p.waitForStarted();
    p.waitForFinished();
    QMessageBox::about(this," ","恢复成功！");
    ui->Table_Student->clearContents();
    ui->Table_Student->setRowCount(1);
    refresh();
}


//左侧树形图
void MainWindow::Load(){
    QStandardItemModel* model=new QStandardItemModel(ui->treeView);
    QStandardItem* item=new QStandardItem("全部");
    model->appendRow(item);

    for(int i=0;i<major.length();i++){
        QStandardItem* item1=new QStandardItem(major[i]);
        model->appendRow(item1);
    }
    ui->treeView->setModel(model);
}

void MainWindow::Sorts(){
    int s=ui->treeView->currentIndex().row();
    QString str;
    ui->Table_Student->clearContents();

    if(s==0){
        Refresh();
    }
    else{
        QSqlQuery query(DB);
        str=major[s-1];
        query.prepare("select * from mycontracts.student where Major = ?");
        query.addBindValue(str);
        query.exec();

        QString ID,Name,Sex,Age,Tell,Address,QQNum,Major;
        int i=0;
        while(query.next()){
            ID=query.value(0).toString();
            Name=query.value(1).toString();
            Sex=query.value(2).toString();
            Age=query.value(3).toString();
            Tell=query.value(4).toString();
            Address=query.value(5).toString();
            QQNum=query.value(6).toString();
            Major=query.value(7).toString();

            ui->Table_Student->setItem(i,0,new QTableWidgetItem(ID));
            ui->Table_Student->setItem(i,1,new QTableWidgetItem(Name));
            ui->Table_Student->setItem(i,2,new QTableWidgetItem(Sex));
            ui->Table_Student->setItem(i,3,new QTableWidgetItem(Age));
            ui->Table_Student->setItem(i,4,new QTableWidgetItem(Tell));
            ui->Table_Student->setItem(i,5,new QTableWidgetItem(Address));
            ui->Table_Student->setItem(i,6,new QTableWidgetItem(QQNum));
            ui->Table_Student->setItem(i,7,new QTableWidgetItem(Major));
            i++;
        }
    }
}
