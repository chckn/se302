#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
extern "C"{
#include "mylang.h"
}
#include "QDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int input[2], output[2];
    pipe(input);
    pipe(output);
    if (fork() == 0) {
        dup2(input[0], 0);
        dup2(output[1], 1);
        ::close(output[1]);
        ::close(output[0]);
        ::close(input[1]);
        ::close(input[0]);
        lexical();
        fclose(stdout);
        exit(0);
    }
    ::close(input[0]);
    ::close(output[1]);
    FILE *fin = fdopen(input[1], "w");
    fputs(ui->SrcText->toPlainText().toStdString().c_str(), fin);
    fclose(fin);
    char buffer[256];
    std::string str;
    while (int r = read(output[0], buffer, 256)) {
        if (r < 0) break;
        str.append(buffer, r);
    }
    ::close(output[0]);
    ui->ResText->setText(QString::fromStdString(str));
}

void MainWindow::on_pushButton_2_clicked()
{
    int input[2], output[2];
    pipe(input);
    pipe(output);
    if (fork() == 0) {
        dup2(input[0], 0);
        dup2(output[1], 1);
        ::close(output[1]);
        ::close(output[0]);
        ::close(input[1]);
        ::close(input[0]);
        syntax(1);
        puts("DONE");
        fclose(stdout);
        exit(0);
    }
    ::close(input[0]);
    ::close(output[1]);
    FILE *fin = fdopen(input[1], "w");
    fputs(ui->SrcText->toPlainText().toStdString().c_str(), fin);
    fclose(fin);
    char buffer[256];
    std::string str;
    while (int r = read(output[0], buffer, 256)) {
        if (r < 0) break;
        str.append(buffer, r);
    }
    ::close(output[0]);
    ui->ResText->setText(QString::fromStdString(str));
}

void MainWindow::on_pushButton_3_clicked()
{
    int input[2], output[2];
    pipe(input);
    pipe(output);
    if (fork() == 0) {
        dup2(input[0], 0);
        dup2(output[1], 1);
        ::close(output[1]);
        ::close(output[0]);
        ::close(input[1]);
        ::close(input[0]);
        semantic(1);
	puts("DONE")
        fclose(stdout);
        exit(0);
    }
    ::close(input[0]);
    ::close(output[1]);
    FILE *fin = fdopen(input[1], "w");
    fputs(ui->SrcText->toPlainText().toStdString().c_str(), fin);
    fclose(fin);
    char buffer[256];
    std::string str;
    while (int r = read(output[0], buffer, 256)) {
        if (r < 0) break;
        str.append(buffer, r);
    }
    ::close(output[0]);
    ui->ResText->setText(QString::fromStdString(str));
}


void MainWindow::on_pushButton_4_clicked()
{
    int input[2], output[2];
    pipe(input);
    pipe(output);
    if (fork() == 0) {
        dup2(input[0], 0);
        dup2(output[1], 1);
        ::close(output[1]);
        ::close(output[0]);
        ::close(input[1]);
        ::close(input[0]);
        assembly();
	puts("DONE");
        fclose(stdout);
        exit(0);
    }
    ::close(input[0]);
    ::close(output[1]);
    FILE *fin = fdopen(input[1], "w");
    fputs(ui->SrcText->toPlainText().toStdString().c_str(), fin);
    fclose(fin);
    char buffer[256];
    std::string str;
    while (int r = read(output[0], buffer, 256)) {
        if (r < 0) break;
        str.append(buffer, r);
    }
    ::close(output[0]);
    ui->ResText->setText(QString::fromStdString(str));
}

