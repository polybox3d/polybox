#include "FolderButton.h"

FolderButton::FolderButton(QWidget *parent) :
    QPushButton(parent)
{
    this->setText("");
    //this->setFlat(true);
    this->setFocusPolicy(Qt::NoFocus);
    QPixmap image(":/img/img/folder.png");
    this->setIcon(image);
    this->setIconSize( QSize(this->width()-5, this->height()-5) );
    //this->setStyleSheet("QPushButton:flat:pressed { border: none; };");
    setOpenFolder();
}
void FolderButton::setOpenFolder()
{
    disconnect(this,SIGNAL(clicked()), this, SLOT(openFileName()));
    connect(this,SIGNAL(clicked()), this, SLOT(openDirectoryName()));
}

void FolderButton::setOpenFile()
{
    disconnect(this,SIGNAL(clicked()), this, SLOT(openDirectoryName()));
    connect(this,SIGNAL(clicked()), this, SLOT(openFileName()));
}

void FolderButton::openFileName()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Selectionner le fichier"), ".", tr("(*)"));
    if ( fileName != NULL && ! fileName.isEmpty() )
    {
        emit opened(fileName);
    }
}

void FolderButton::openDirectoryName()
{
    QString dirName = QFileDialog::getExistingDirectory(this,
                                                         tr("Selectionner un répertoire"),".");
    if ( dirName != NULL && ! dirName.isEmpty() )
    {
       emit opened( dirName );
    }
}
