#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTreeView>
#include <QFileSystemModel>
#include <QDockWidget>
#include <QDir>
#include <QDesktopServices>
#include <QTabWidget>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QLabel>
#include "projector.h"
#include "sauvegarder_ou_importer.h"
#include "arborescence_projet.h"
#include "Items/salledespectacle.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:


private:
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QMenu *menuAide;

    Projector *projector;
    SalleDeSpectacle* showroom;
    Save_or_import* SoI;
    QFileSystemModel *modelExplorer; // Modèle pour l'onglet "Explorateur"
    arborescence_projet *arborescence;
    QTabWidget *tabWidget; // Onglets
    QDockWidget *dockGauche; // Panneau latéral
    QDockWidget *dockBas; // Panneau complémentaire


    //list

    QList<Projector*> projector_list;
};
#endif // MAINWINDOW_H
