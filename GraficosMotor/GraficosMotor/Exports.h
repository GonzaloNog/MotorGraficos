#pragma once

#ifdef ZENGINE_EXPORTS
#define ZENGINE_API __declspec(dllexport)
#else
#define ZENGINE_API __declspec(dllimport)
#endif