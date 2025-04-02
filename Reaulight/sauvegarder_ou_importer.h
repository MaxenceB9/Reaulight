#ifndef SAUVEGARDER_OU_IMPORTER_H
#define SAUVEGARDER_OU_IMPORTER_H

//Sauvegarde des données de spectacle #5

#include <QDir>
#include <QDebug>
#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFileDialog>
#include <QFileInfo>
#include <QStandardPaths>
#include <QString>
#include <QSysInfo>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QList>
#include <QLabel>
#include <QObject>
#include <QDate>
#include <QWidget>
#include <QThread>

#include <projecteur.h>

enum dialogType {save, import, saveIfOpen};

class Save_or_import : public QObject
{
    Q_OBJECT

public:
    explicit Save_or_import(QObject *parent = nullptr);
    void init(QWidget *window);
    void saveParty(); // sauvegarder tout dans un seul fichier.
    void savePartyWhenOpen();
    void importParty(QString path);
    void dialog(dialogType type);

    //geter

    //seter
    void setData(QList<Projecteur*> Proj, QJsonDocument Showroom);

signals:
    void isSavingAccept(bool accepted);
private:
    QWidget *MainWindow; //variable pour le widget de la window principale

    QString defaultpath;
    QString pathChoose; // path choisi par l'utilisateur.
    QDialog setOtherFileInfo; // boite de dialog pour choisir le nom du créateur
    QString roomName;
    QString saveDateTime;
    QString creator;
    QString fileSave;
    QString projectName;

    QJsonArray Scenes;
    QJsonArray Scenes_info; // exemple d'utilisation: Scenes.append(QJsonObject{{"Hauteur": "", "Largeur": "", "Position": {"x": "", "y": "", "z": ""}, "Oriantations" : {}, "id": ""}});
    QJsonArray Structures;
    QJsonArray Structures_info;
    QJsonArray Projectors;
    QJsonArray Projector_info;
    QJsonArray Programme_du_show;
    QJsonArray Room;
    QJsonArray Room_info;
    bool savehasRun = false;


    //dialog box for more information
    QPushButton* saveButton;
    QLineEdit* projectNameInput;
    QLineEdit* creatorNameInput;
};


#endif // SAUVEGARDER_OU_IMPORTER_H
