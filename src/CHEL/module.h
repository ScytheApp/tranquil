#pragma once

#include "pch.h"

// Eye candy for methods
#define METHOD_BIND(T, F) [](JsValueRef call, bool isConstructCall, JsValueRef *args, unsigned short argumentCount, void *callbackState) -> void* { \
  return std::invoke((F), static_cast<std::add_pointer_t<T>>(callbackState), call, isConstructCall, args, argumentCount); }

// Only use this in functions
#define CHECK(cmd) if (cmd != JsNoErr) { return JS_INVALID_REFERENCE; }

// Abstract class for modules
namespace JS {
    class Module {
    public:
        virtual JsValueRef Init() = 0;
    };
}