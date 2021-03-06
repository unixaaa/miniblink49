﻿#include "nodeblink.h"
#include <node_object_wrap.h>
#include "wke.h"
#include "electron.h"
#include "dictionary.h"

using namespace v8;
using namespace node;

namespace atom {

// 继承node的ObjectWrap，一般自定义C++类都应该继承node的ObjectWrap
class WebContents : public node::ObjectWrap {
public:
    static void init(Local<Object> target, Environment* env);
    static WebContents* create(Isolate* isolate, gin::Dictionary options);

    explicit WebContents();
    ~WebContents();

private:
    // new方法
    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);
    // _loadURL
    static void _loadURL(const v8::FunctionCallbackInfo<v8::Value>& args);
    
    static void nullFunction(const v8::FunctionCallbackInfo<v8::Value>& args);
    static v8::Persistent<v8::Function> constructor;
public:
    wkeWebView m_view;
};

} // atom