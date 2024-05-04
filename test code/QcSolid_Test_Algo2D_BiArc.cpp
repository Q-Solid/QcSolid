#include "gtest/gtest.h"


//OCC
#include "Geom2d_BSplineCurve.hxx"

//
#include "QcSolid.h"
#include "QcCurve2D_BiArcFit.h"


using namespace QcSolid;


TEST(QSolidAPI_Test_Algo2D_BiArc, Test1)
{

    Standard_Integer degree = 4;
    int nPoles = 5;

    TColgp_Array1OfPnt2d poles(1, nPoles);
    TColStd_Array1OfReal knots(1, 2);
    TColStd_Array1OfInteger multiplicities(1, 2);
    
    poles.SetValue(1, gp_Pnt2d(0.0, 0.0));
    poles.SetValue(2, gp_Pnt2d(20.0, 20.0));
    poles.SetValue(3, gp_Pnt2d(50.0, 0.0));
    poles.SetValue(4, gp_Pnt2d(60.0, -40.0));
    poles.SetValue(5, gp_Pnt2d(80.0, 60.0));

    //
    knots.SetValue(1, 0.0);
    knots.SetValue(2, 1.0);

    multiplicities.SetValue(1, 5);
    multiplicities.SetValue(2, 5);

    Handle(Geom2d_BSplineCurve) bCurve = new Geom2d_BSplineCurve(poles, knots, multiplicities, degree);

    //
    double tolerance = 0.001;
    std::vector<Handle(Geom2d_TrimmedCurve)> arcLines;
    double maxDeviation = 0.0;

    bool success = QcCurve2D_BiArcFit::Perform(bCurve,0.0, 1.0, tolerance,
                                          arcLines,maxDeviation);
    EXPECT_TRUE(success);
    EXPECT_TRUE(maxDeviation < tolerance);
}