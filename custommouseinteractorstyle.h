#ifndef CUSTOMMOUSEINTERACTORSTYLE_H
#define CUSTOMMOUSEINTERACTORSTYLE_H
//#include "YZ_Includes/public/YZ_Vtypes.h"
#include "VTKHeaders.h"

#include <QDebug>
#include <QObject>
class customMouseInteractorStyle : public QObject,public vtkInteractorStyleTrackballCamera
{
    Q_OBJECT
public:
    customMouseInteractorStyle();

    static customMouseInteractorStyle* New();
    vtkTypeMacro(customMouseInteractorStyle, vtkInteractorStyleTrackballCamera);

    virtual void OnLeftButtonDown() override;

    virtual void OnMiddleButtonDown() override
    {
        qDebug() << "Pressed middle mouse button.";
        vtkInteractorStyleTrackballCamera::OnMiddleButtonDown();
    }

    virtual void OnRightButtonDown() override;
    virtual void OnMouseMove() override;

    virtual void OnLeftButtonUp() override;
    virtual void OnRightButtonUp() override;

    bool move = false;
    bool leftButton = false;
    bool rightButton = false;
    vtkActor* a = nullptr;
    double roiScale[3] = {1,1,1};
    vtkRenderer* rw;
    vtkRenderWindowInteractor* rwi;
    vtkTransform* t;
    bool changesize = true;
protected:
signals:
    void moveSignal(double x,double y,double z,double Scalex,double Scaley,double Scalez);
    void mouseMoveSignal(double x, double y,double z);
//    void sizeChangeSignal(double Scalex,double Scaley,double Scalez);
};

#endif // CUSTOMMOUSEINTERACTORSTYLE_H
