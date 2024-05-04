#pragma once

/*
 * QcSolid CONFIDENTIAL,  All Rights Reserved.
 * 
 *  email:  1301515859@qq.com
 * __________________
 *
 * 
 *
 */

#include "QcSolid.h"

#include <vector>

#include "Geom2d_Curve.hxx"
#include "Geom2d_TrimmedCurve.hxx"


QCSOLID_BEGIN


class QCSOLID_PUBLIC QcCurve2D_BiArcFit
{
public:


    /**
    *
    *@brief bi-arc fit the curve within tolerance
    * @param[in]  curve2d             input curve2d
    * @param[in]  startParam          the start parameter of curve2d
    * @param[in]  endParam            the end parameter of curve2d
    * @param[in]  tolerance           the specified tolerance
    * @param[out]  arcLines           the bi-arcs, sometimes there exists a line.
    * @param[out]  maxDeviation       the max deviation between the bi-arc fit curve and the input curve
    * @return  the status of execution
    * - True      success
    * - False     failed
    */
    static bool Perform(const Handle(Geom2d_Curve)& curve2d, double startParam, double endParam, double tolerance,
                        std::vector<Handle(Geom2d_TrimmedCurve)>& arcLines, double& maxDeviation);

};


QCSOLID_END