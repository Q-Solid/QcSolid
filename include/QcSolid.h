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


#ifdef QCSOLID_EXPORTS
#define QCSOLID_PUBLIC __declspec(dllexport)
#else
#define QCSOLID_PUBLIC __declspec(dllimport)
#endif

#define QCSOLID_NAMESPACE QcSolid


#ifndef QCSOLID_BEGIN
#define QCSOLID_BEGIN namespace QCSOLID_NAMESPACE {
#endif

#ifndef QCSOLID_END
#define QCSOLID_END }
#endif




// macros to declare class.
#define QCSOLID_CLASS(className) \
	QCSOLID_BEGIN \
		class className; \
	QCSOLID_END \
	using namespace QCSOLID_NAMESPACE;


#ifdef QCSOLID_EXPORTS
#define GEOMETRY_CLASS __declspec(dllexport)
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_CLASS __declspec(dllimport)
#define GEOMETRY_API __declspec(dllimport)
#endif

#define QCSOLID_API_C extern "C" GEOMETRY_API
