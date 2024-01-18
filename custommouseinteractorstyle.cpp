//3DROI
#include "custommouseinteractorstyle.h"

vtkStandardNewMacro(customMouseInteractorStyle);

customMouseInteractorStyle::customMouseInteractorStyle(){}

void customMouseInteractorStyle::OnLeftButtonDown()
{
    leftButton = true;
//    qDebug() << "Pressed left mouse button.";

    int* clickPos = this->GetInteractor()->GetEventPosition();

    // Pick from this location
    vtkSmartPointer<vtkPropPicker> picker =
            vtkSmartPointer<vtkPropPicker>::New();
    picker->Pick(clickPos[0], clickPos[1], 0, rw);

    double* pos = picker->GetPickPosition();
//    qDebug() << "Pick position(world coordinate) is:";
//    qDebug() << pos[0] << " " << pos[1] << " " << pos[2];
//    qDebug() << "Picked actor:" << picker->GetActor();

    if (a == picker->GetActor())
    {
        move = true;
//        qDebug() << "Picked cube.";
        return;
    }

//    rw->AddActor(a);

    // Forward events(转发事件)
    vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
}

void customMouseInteractorStyle::OnMouseMove()
{
    double* obj_center = a->GetCenter();
    double disp_obj_center[3], new_pick_point[4];
    double old_pick_point[4], motion_vector[3];

    // ComputeWorldToDisplay
    this->ComputeWorldToDisplay(obj_center[0],obj_center[1],obj_center[2],disp_obj_center);
    this->ComputeDisplayToWorld(rwi->GetEventPosition()[0],
            rwi->GetEventPosition()[1],
            disp_obj_center[2],
            new_pick_point);

    //
    this->ComputeDisplayToWorld(rwi->GetLastEventPosition()[0],
            rwi->GetLastEventPosition()[1],
            disp_obj_center[2],
            old_pick_point);
//    qDebug() << "new_pick_point:" << new_pick_point[0] << " " << new_pick_point[1] << " " << new_pick_point[2];
    emit mouseMoveSignal(new_pick_point[0],new_pick_point[1],new_pick_point[2]);
    if (move == true)
    {
//        qDebug() << "old_pick_point:" << old_pick_point[0] << " " << old_pick_point[1] << " " << old_pick_point[2];
//        qDebug() << "new_pick_point:" << new_pick_point[0] << " " << new_pick_point[1] << " " << new_pick_point[2];

        // postion's distance
        motion_vector[0] = new_pick_point[0] - old_pick_point[0];
        motion_vector[1] = new_pick_point[1] - old_pick_point[1];
        motion_vector[2] = new_pick_point[2] - old_pick_point[2];
        if(motion_vector[0]>1e4 || motion_vector[0]<-1e4){
            motion_vector[0] = 0;
        }
        if(motion_vector[1]>1e4 || motion_vector[1]<-1e4){
            motion_vector[1] = 0;
        }
        if(motion_vector[2]>1e4 || motion_vector[2]<-1e4){
            motion_vector[2] = 0;
        }
        if(a->GetUserMatrix() != NULL)
        {
//            t = vtkTransform::New();
//            // Do not understand
//            t->PostMultiply();
//            t->SetMatrix(a->GetUserMatrix());
//            t->Translate(motion_vector[0],motion_vector[1],motion_vector[2]);
//            a->GetUserMatrix()->DeepCopy(t->GetMatrix());
//            t->Delete();
        }
        else
        {

            if(leftButton == true){
//                a->SetPosition(100,100,100);
                a->AddPosition(motion_vector[0],motion_vector[1],motion_vector[2]);
//                a->AddPosition(1,1,1);
            }
            if(rightButton == true && changesize){
                float speed = 0.05;
                double* CurrentScale = a->GetScale();
                roiScale[0] = CurrentScale[0] + motion_vector[0]*speed;
                roiScale[1] = CurrentScale[1] + motion_vector[1]*speed;
                roiScale[2] = CurrentScale[2] + motion_vector[2]*speed;
                 a->SetScale(roiScale[0],roiScale[1],roiScale[2]);
//                 qDebug() << roiScale[0] << " " << roiScale[1] << " " << roiScale[2];
            }
            double* movePos = a->GetPosition();
            double* scaleNum = a->GetScale();
//            double* xrange = a->GetXRange();
//            double* yrange = a->GetYRange();
//            double* zrange = a->GetZRange();
            emit moveSignal(movePos[0],movePos[1],movePos[2],scaleNum[0],scaleNum[1],scaleNum[2]);
        }
        rwi->Render();

    }
    // Forward events
    vtkInteractorStyleTrackballCamera::OnMouseMove();
}

void customMouseInteractorStyle::OnLeftButtonUp()
{
//    qDebug() << "Left button up.";

    move = false;
    leftButton = false;
    vtkInteractorStyleTrackballCamera::OnLeftButtonUp();

}

void customMouseInteractorStyle::OnRightButtonDown()
{
    rightButton = true;
//  qDebug() << "Pressed right mouse button.";
  int* clickPos = this->GetInteractor()->GetEventPosition();
  vtkSmartPointer<vtkPropPicker> picker =vtkSmartPointer<vtkPropPicker>::New();
  picker->Pick(clickPos[0], clickPos[1], 0, rw);
  double* pos = picker->GetPickPosition();
//  qDebug() << "Pick position(world coordinate) is:";
//  qDebug() << pos[0] << " " << pos[1] << " " << pos[2];
//  qDebug() << "Picked actor:" << picker->GetActor();

  if (a == picker->GetActor())
  {
      move = true;
//      qDebug() << "Picked cube.";
      return;
  }
  // Forward events
//  vtkInteractorStyleTrackballCamera::OnRightButtonDown();
}
void customMouseInteractorStyle::OnRightButtonUp()
{
    rightButton = false;
    move = false;
//  qDebug() << "Pressed right mouse up.";
  // Forward events
//  vtkInteractorStyleTrackballCamera::OnRightButtonDown();
}


