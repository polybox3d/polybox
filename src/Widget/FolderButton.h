#ifndef FOLDERBUTTON_H
#define FOLDERBUTTON_H

#include <QPushButton>
#include <QFileDialog>

class FolderButton : public QPushButton
{
    Q_OBJECT
public:
    explicit FolderButton(QWidget *parent = 0);
    void setOpenFolder();
    void setOpenFile();

signals:
    void opened( QString name );

public slots:
    void openFileName();
    void openDirectoryName();

private:

};

#endif // FOLDERBUTTON_H
