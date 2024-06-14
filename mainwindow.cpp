#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <algorithm>
#include <random>
#include <QDebug>

std::vector<int> playerBox = {};
std::vector<int> botBox = {};
std::vector<int> emptyBox = {};


int totalMoves;
bool isGameOver;

QLineEdit *result;



void checkWin();
void removeElement(int n);






MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isGameOver = false;

    emptyBox = {1,2,3,4,5,6,7,8,9};

    playerBox = {};

    botBox = {};

    totalMoves = 0;

    ui->one->setText("");
    ui->two->setText("");
    ui->three->setText("");
    ui->four->setText("");
    ui->five->setText("");
    ui->six->setText("");
    ui->seven->setText("");
    ui->eight->setText("");
    ui->nine->setText("");


    result = ui->Result;
    result->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_NewGame_clicked()
{
    isGameOver = false;

    emptyBox = {1,2,3,4,5,6,7,8,9};

    playerBox = {};

    botBox = {};

    totalMoves = 0;

    ui->one->setText("");
    ui->two->setText("");
    ui->three->setText("");
    ui->four->setText("");
    ui->five->setText("");
    ui->six->setText("");
    ui->seven->setText("");
    ui->eight->setText("");
    ui->nine->setText("");

    result->setText("");
}

bool isEmptyBox(int n){


    if(isGameOver) return false;

    auto it = std::find(emptyBox.begin(), emptyBox.end(), n);
    if (it != emptyBox.end()) {
        emptyBox.erase(it);

        totalMoves++;

        return true;
    }
    return false;
}

void removeElement(int n){
    auto it = std::find(emptyBox.begin(), emptyBox.end(), n);
    if (it != emptyBox.end()) {
        emptyBox.erase(it);
    }
}

void MainWindow::checkWin()
{
    //for "O" Wins
    {
        if(
            (ui->one->text() == "O" && ui->two->text() == "O" && ui->three->text() == "O") ||
            (ui->one->text() == "O" && ui->five->text() == "O" && ui->nine->text() == "O") ||
            (ui->one->text() == "O" && ui->four->text() == "O" && ui->seven->text() == "O") ||
            (ui->two->text() == "O" && ui->five->text() == "O" && ui->eight->text() == "O") ||
            (ui->three->text() == "O" && ui->six->text() == "O" && ui->nine->text() == "O") ||
            (ui->three->text() == "O" && ui->five->text() == "O" && ui->seven->text() == "O") ||
            (ui->four->text() == "O" && ui->five->text() == "O" && ui->six->text() == "O") ||
            (ui->seven->text() == "O" && ui->eight->text() == "O" && ui->nine->text() == "O")
        ){
            qDebug() << "O win";
            isGameOver = true;
            result->setText("PLAYER WIN");
        }
    }

    {
        if(
            (ui->one->text() == "X" && ui->two->text() == "X" && ui->three->text() == "X") ||
            (ui->one->text() == "X" && ui->five->text() == "X" && ui->nine->text() == "X") ||
            (ui->one->text() == "X" && ui->four->text() == "X" && ui->seven->text() == "X") ||
            (ui->two->text() == "X" && ui->five->text() == "X" && ui->eight->text() == "X") ||
            (ui->three->text() == "X" && ui->six->text() == "X" && ui->nine->text() == "X") ||
            (ui->three->text() == "X" && ui->five->text() == "X" && ui->seven->text() == "X") ||
            (ui->four->text() == "X" && ui->five->text() == "X" && ui->six->text() == "X") ||
            (ui->seven->text() == "X" && ui->eight->text() == "X" && ui->nine->text() == "X")
            ){
            qDebug() << "X win";
            isGameOver = true;
            result->setText("AI WIN");
        }
    }
}





void MainWindow::AImove(){

    if(isGameOver) return;


    if(totalMoves >= 9){
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, emptyBox.size()-1);

    int randomIndex = dis(gen);
    int randomBox = emptyBox[randomIndex];

    switch(randomBox)
    {
    case 1:
        ui->one->setText("X");
        removeElement(1);
        break;
    case 2:
        ui->two->setText("X");
        removeElement(2);
        break;
    case 3:
        ui->three->setText("X");
        removeElement(3);
        break;
    case 4:
        ui->four->setText("X");
        removeElement(4);
        break;
    case 5:
        ui->five->setText("X");
        removeElement(5);
        break;
    case 6:
        ui->six->setText("X");
        removeElement(6);
        break;
    case 7:
        ui->seven->setText("X");
        removeElement(7);
        break;
    case 8:
        ui->eight->setText("X");
        removeElement(8);
        break;
    case 9:
        ui->nine->setText("X");
        removeElement(9);
        break;
    }

    totalMoves++;
    qDebug() << "AI Num: " << randomBox;


    MainWindow::checkWin();
}


void MainWindow::on_one_clicked()
{

    if(isEmptyBox(1)){
        playerBox.push_back(1);
        ui->one->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}

void MainWindow::on_two_clicked()
{
    if(isEmptyBox(2)){
        playerBox.push_back(2);
        ui->two->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}

void MainWindow::on_three_clicked()
{
    if(isEmptyBox(3)){
        playerBox.push_back(3);
        ui->three->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}

void MainWindow::on_four_clicked()
{
    if(isEmptyBox(4)){
        playerBox.push_back(4);
        ui->four->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}

void MainWindow::on_five_clicked()
{
    if(isEmptyBox(5)){
        playerBox.push_back(5);
        ui->five->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}

void MainWindow::on_six_clicked()
{
    if(isEmptyBox(6)){
        playerBox.push_back(6);
        ui->six->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}


void MainWindow::on_seven_clicked()
{
    if(isEmptyBox(7)){
        playerBox.push_back(7);
        ui->seven->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}


void MainWindow::on_eight_clicked()
{
    if(isEmptyBox(8)){
        playerBox.push_back(8);
        ui->eight->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}


void MainWindow::on_nine_clicked()
{
    if(isEmptyBox(9)){
        playerBox.push_back(9);
        ui->nine->setText("O");
        MainWindow::checkWin();
        AImove();
    }
}

