#include "mouseinteractorstyle5.h"

vtkStandardNewMacro(MouseInteractorStyle5);
MouseInteractorStyle5::MouseInteractorStyle5()
{
    style2 = vtkInteractorStyleTrackballCamera::New();
}
