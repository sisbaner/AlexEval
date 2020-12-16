#ifndef DIALOGGMMPARAMS_H
#define DIALOGGMMPARAMS_H

#include <QDialog>
#include "alexdata.h"

namespace Ui {
class DialogGMMparams;
}

class GMMfitModel
{
    QString name;
    GMMfit *gmm;
public:
    GMMfitModel(GMMfit &gmm,QString name);
    GMMfitModel(GMMfit *gmm,QString name);
    GMMfitModel();
    ~GMMfitModel();
    const QString getName() const {return name;}
    void setName(QString _name) {name=_name;}
    GMMfit *getGMM() {return gmm;}
    void setGMM(GMMfit *_gmm) {if(gmm) delete gmm; gmm=_gmm; }
    void writeToIni(jkINIParser2 &ini, std::string group) const;
    int readFromIni(jkINIParser2 &ini, std::string group);
    QString toString() const;
    QString resultToStringHeader() const;
    QString resultToString(const QString sampleName=QString("")) const;
};


class DialogGMMparams : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogGMMparams(QWidget *parent = 0);
    ~DialogGMMparams();

    void setDimensionName(QStringList &names);
    QList<GMMfitModel> getModels() const {return models;}
    void setModels(QList<GMMfitModel> _models) {models=_models;}
    void addModel(const GMMfitModel &newModel) {models.append(newModel);}
    void setIniFile(const QString &_iniFile) {iniFile=_iniFile;}
    QString getIniFile() const {return iniFile;}
    
private:
    Ui::DialogGMMparams *ui;
    QStringList m_MeanHeader;
    QStringList m_SigmaHeader;
    QStringList m_DimensionHeader;
    QString iniFile;
    QList<GMMfitModel> models;
protected:
//    virtual void closeEvent(QCloseEvent* event);

private slots:
    void fillTable(GMMfit *gmm);
    GMMfit *getFromTable();
    void getFromTable(GMMfit *gmm);
    void fillList();
    int writeToIni(const std::string iniFilename) const;
    int readFromIni(const std::string iniFilename);
    void saveAll();

    void dimChanged(int dim);
    void componentsChanged(int k);

    void updateTables(int index);
    void on_pushButtonSave_clicked();
    void on_pushButtonModel_clicked();
    void on_pushButtonRemove_clicked();
};

#endif // DIALOGGMMPARAMS_H
