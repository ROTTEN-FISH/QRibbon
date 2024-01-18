#ifndef MOUSEINTERACTORSTYLE5_H
#define MOUSEINTERACTORSTYLE5_H

#include "VTKHeaders.h"
#include <QDebug>


class MouseInteractorStyle5 : public vtkInteractorStyleTrackballActor
{
public:
    MouseInteractorStyle5();
    static MouseInteractorStyle5* New();

    vtkTypeMacro(MouseInteractorStyle5, vtkInteractorStyleTrackballActor);


    virtual void OnLeftButtonDown() override
    {
        vtkInteractorStyleTrackballActor::OnLeftButtonDown();

        if (this->InteractionProp == this->Cube)
        {
            qDebug() << "Picked cube.";

        }
        else if (this->InteractionProp == this->PointCloud)
        {
            qDebug() << "Picked PointCloud.";
        }

    }

    // Cube actor
    vtkActor* Cube;
    // PointCloud actor
    vtkActor* PointCloud;
    vtkInteractorStyleTrackballCamera* style2;
};


#endif // MOUSEINTERACTORSTYLE5_H
